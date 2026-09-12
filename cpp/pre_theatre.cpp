#include "pre_theatre.h"

#include <QDebug>
#include <QTextStream>
#include <unistd.h>

pre_theatre::pre_theatre(QSqlDatabase database, QObject *parent) : QObject(parent), db(database) {
    stdin_notifier = nullptr;
}

void pre_theatre::start_barcode_scanning() {
    if (stdin_notifier) {
        return;
    }

    stdin_notifier = new QSocketNotifier(
        STDIN_FILENO,
        QSocketNotifier::Read,
        this
    );

    connect(
        stdin_notifier,
        &QSocketNotifier::activated,
        this,
        &pre_theatre::read_terminal_input
    );

    qDebug() << "Paste barcode into terminal and press Enter.";
}

void pre_theatre::stop_barcode_scanning() {
    if (stdin_notifier) {
        stdin_notifier->deleteLater();
        stdin_notifier = nullptr;
    }
}

void pre_theatre::read_terminal_input() {
    QTextStream input(stdin);

    QString barcode = input.readLine().trimmed();

    if (barcode.isEmpty()) {
        return;
    }

    process_barcode(barcode);
}

QString pre_theatre::batch_code() const {
    return m_batch_code;
}

QString pre_theatre::type_of_surgery() const {
    return m_type_of_surgery;
}

QString pre_theatre::patients_name() const {
    return m_patients_name;
}

QString pre_theatre::last_scan_date_n_time() const {
    return m_last_scan_date_n_time;
}

void pre_theatre::process_barcode(const QString &barcode) {
    QString cleaned_barcode = barcode.trimmed();

    if (cleaned_barcode.isEmpty()) {
        emit barcode_rejected("No barcode was entered.");
        return;
    }

    qDebug() << "Pre-Theatre barcode received:" << cleaned_barcode;

    if (!fetch_batch(cleaned_barcode)) {
        return;
    }

    QVariantList items = fetch_batch_items(m_batch_code);

    emit items_loaded(items);

    auto_fill();

    emit barcode_accepted();
}

bool pre_theatre::fetch_batch(const QString &barcode) {
    if (!db.isOpen()) {
        emit barcode_rejected("Database connection is not open.");
        return false;
    }

    QSqlQuery batch_query(db);

    batch_query.prepare("SELECT created_batches.batch_code, created_batches.type_of_surgery, surgeries.patients_name, surgeries.date_and_time_picked FROM created_batches INNER JOIN surgeries ON created_batches.batch_code = surgeries.batch_code WHERE created_batches.batch_code = :barcode AND surgeries.cycle_complete = :complete");

    batch_query.bindValue(":barcode", barcode);
    batch_query.bindValue(":complete", false);

    if (!batch_query.exec()) {
        qDebug() << "Failed to fetch batch:" << batch_query.lastError().text();
        return false;
    }

    if (!batch_query.next()) {
        qDebug() << "Barcode not found:" << batch_query.lastError().text();
        return false;
    }

    m_batch_code = batch_query.value("batch_code").toString();
    m_type_of_surgery = batch_query.value("type_of_surgery").toString();
    m_patients_name = batch_query.value("patients_name").toString();
    m_last_scan_date_n_time = batch_query.value("date_and_time_picked").toString();

    QSqlQuery check_query(db);

    check_query.prepare("SELECT created_batches.pre_theatre, surgeries.cycle_complete FROM created_batches INNER JOIN surgeries ON created_batches.batch_code = surgeries.batch_code WHERE created_batches.batch_code = :barcode AND surgeries.patients_name = :patient");

    check_query.bindValue(":barcode", m_batch_code);
    check_query.bindValue(":patient", m_patients_name);

    if (!check_query.exec()) {
        qDebug() << "Error:" << check_query.lastError().text();
        return false;
    }

    if (!check_query.next()) {
        qDebug() << "Error:" << check_query.lastError().text();
        return false;
    }

    bool pre_theatre_status = check_query.value("pre_theatre").toBool();
    bool cycle_complete_status = check_query.value("cycle_complete").toBool();

    if (!pre_theatre_status && !cycle_complete_status) {
        emit batch_code_changed();
        emit type_of_surgery_changed();
        emit patients_name_changed();
        emit last_scan_date_n_time_changed();

        return true;
    } else if (pre_theatre_status && !cycle_complete_status) {
        emit warning_message("Scanning at pre theatre stage has already occured. Please proceed to the next stage.");

        return false;
    } else {
        emit warning_message("Surgery cycle already complete. Contact admin if you think this was a mistake.");

        return false;
    }
}

QVariantList pre_theatre::fetch_batch_items(const QString &batch_code) {
    QVariantList items;

    if (!db.isOpen()) {
        qDebug() << "Database connection is not open.";
        return items;
    }

    QSqlQuery items_query(db);

    items_query.prepare("SELECT surgical_instrument, instrument_count, category FROM add_items_into_barcode WHERE batch_code = :barcode");

    items_query.bindValue(":barcode", batch_code);

    if (!items_query.exec()) {
        qDebug() << "Failed to fetch batch items:" << items_query.lastError().text();
        emit warning_message("Failed to fetch batch items:" + items_query.lastError().text());
        return items;
    }

    while (items_query.next()) {
        QVariantMap item;

        item["instrument"] = items_query.value("surgical_instrument").toString();

        item["count"] = items_query.value("instrument_count").toInt();

        item["category"] = items_query.value("category").toString();

        items.append(item);
    }

    return items;
}

void pre_theatre::auto_fill() {
    QDateTime current_date_time = QDateTime::currentDateTime();

    QString username = UserSession::getInstance().getCurrentUser();

    m_current_scan_date_n_time = current_date_time.toString();
    m_session_user = username;

    emit current_scan_date_n_time_changed();
    emit session_user_changed();
}

QString pre_theatre::session_user() const {
    return m_session_user;
}

QString pre_theatre::current_scan_date_n_time() const {
    return m_current_scan_date_n_time;
}

void pre_theatre::confirm_batch(const QString &nurse_name, const QString &scanned_by, const QString &current_scan_date_n_time) {
    QString cleaned_nurse_name = nurse_name.trimmed();

    if (cleaned_nurse_name.isEmpty()) {
        emit error_message("Nurse's name cannot be empty.");
        return;
    }

    if (m_batch_code.isEmpty()) {
        emit error_message("No barcode has been scanned.");
        return;
    }

    if (!db.isOpen()) {
        emit error_message("Database connection is not open.");
        return;
    }

    QSqlQuery query(db);

    query.prepare("UPDATE surgeries SET pre_theatre_nurse_name = :nurse_name, pre_theatre_scanned_by = :scanned_by, pre_theatre_scanned_timestamp = :timestamp WHERE batch_code = :barcode AND patients_name = :patient");

    query.bindValue(":barcode", m_batch_code);
    query.bindValue(":patient", m_patients_name);
    query.bindValue(":nurse_name", cleaned_nurse_name);
    query.bindValue(":scanned_by", scanned_by);
    query.bindValue(":timestamp", current_scan_date_n_time);

    if (!query.exec()) {
        qDebug() << "Failed to confirm batch:" << query.lastError().text();
        emit warning_message("Failed to save the Pre-Theatre record." + query.lastError().text());
        return;
    }

    QSqlQuery stage_update_query(db);

    stage_update_query.prepare("UPDATE created_batches SET pre_theatre = :theatre WHERE batch_code = :barcode");

    stage_update_query.bindValue(":barcode", m_batch_code);
    stage_update_query.bindValue(":theatre", true);

    if (!stage_update_query.exec()) {
        qDebug() << "Failed the stage update:" << stage_update_query.lastError().text();
        emit warning_message("Failed the stage update:" + stage_update_query.lastError().text());
        return;
    }

    emit success_message("Batch confirmed successfully.");

}

void pre_theatre::reject_batch(const QString &nurse_name, const QString &comment) {
    QString rejection_stage = "pre_theatre";
    QString cleaned_comment = comment.trimmed();
    QString cleaned_nurse_name = nurse_name.trimmed();

    if (cleaned_comment.isEmpty()) {
        emit error_message("A rejection comment is required.");
        return;
    }

    if (m_batch_code.isEmpty()) {
        emit error_message("No batch has been scanned.");
        return;
    }

    if (!db.isOpen()) {
        emit error_message("Database connection is not open.");
        return;
    }

    QSqlQuery query(db);

    query.prepare("INSERT INTO rejected_batches (batch_code, patients_name, nurses_name, rejected_by, rejection_stage, reason, rejected_timestamp) VALUES (?, ?, ?, ?, ?, ?, CURRENT_TIMESTAMP)");

    query.addBindValue(m_batch_code);
    query.addBindValue(m_patients_name);
    query.addBindValue(cleaned_nurse_name);
    query.addBindValue(m_session_user);
    query.addBindValue(rejection_stage);
    query.addBindValue(cleaned_comment);

    if (!query.exec()) {
        qDebug() << "Failed to reject batch:" << query.lastError().text();

        emit warning_message("Failed to save the rejected batch." + query.lastError().text());

        return;
    }

    emit success_message("Batch rejected successfully.");

}