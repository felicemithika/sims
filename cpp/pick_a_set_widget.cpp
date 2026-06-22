#include "pick_a_set_widget.h"
#include "DBManager.h"
#include <QDebug>


pick_a_set_widget::pick_a_set_widget(
                        open_source source,
                        QString value,
                        QWidget* parent) 
                        : QWidget(parent),
                          m_source(source),
                          m_value(value) {

    this->setObjectName("pick_a_set_widget");
    ui.setupUi(this);

    db = database_manager::instance().get_database();

    load_data();
    QString username = UserSession::getInstance().getCurrentUser();
    ui.issued_by_lineEdit->setText(username);

    //fill date and time picked linedit
    QDateTime current = QDateTime::currentDateTime();
    ui.date_and_time_picked_lineEdit->setText(current.toString());

    ui.theatre_name_comboBox->addItems({"Theatre A", "Theatre B", "Theatre C"});

     setUp_selected_items_tableView();

    //focus on an input box when enter is pressed
    ui.patient_name_lineEdit->setFocus();
    connect(ui.patient_name_lineEdit, &QLineEdit::returnPressed, [this]{
        ui.patient_phone_no_lineEdit->setFocus();
    });
    connect(ui.patient_phone_no_lineEdit, &QLineEdit::returnPressed, [this]{
        ui.patient_other_phone_no_lineEdit->setFocus();
    });
    connect(ui.patient_other_phone_no_lineEdit, &QLineEdit::returnPressed, [this]{
        ui.next_of_kins_name_lineEdit->setFocus();
    });
    connect(ui.next_of_kins_name_lineEdit, &QLineEdit::returnPressed, [this]{
        ui.next_of_kins_phone_no_lineEdit->setFocus();
    });
    connect(ui.next_of_kins_phone_no_lineEdit, &QLineEdit::returnPressed, [this]{
        ui.next_of_kins_other_phone_no_lineEdit->setFocus();
    });
    connect(ui.next_of_kins_other_phone_no_lineEdit, &QLineEdit::returnPressed, [this]{
        ui.theatre_name_comboBox->setFocus();
    });
    connect(ui.theatre_name_comboBox, &QComboBox::currentTextChanged, [this]{
        ui.plus_pushButton->setFocus();
    });
    connect(ui.plus_pushButton, &QPushButton::clicked, [this]{
        ui.done_pushButton->setFocus();
    });
}

void pick_a_set_widget::load_data(){
    QSqlQuery query(db);

    if (m_source == from_create_a_barcode_widget) {
        query.prepare("SELECT type_of_surgery FROM created_batches WHERE batch_code = :code");
        query.bindValue(":code", m_value);

        if (query.exec()) {
            if (query.next()) {
                QString type_of_surgery = query.value("type_of_surgery").toString();
                ui.type_of_surgery_lineEdit->setText(type_of_surgery);
                ui.batch_code_lineEdit->setText(m_value);

            } else {
                QMessageBox::warning(this, "Batch not found", "No batch found." + query.lastError().text());
            }
        } else {
            QMessageBox::warning(this, "Database Error", query.lastError().text());
        }
    } else if (m_source == from_select_the_surgery_widget) {
        query.prepare("SELECT batch_code FROM created_batches WHERE type_of_surgery = :type_of_surgery AND status = :status AND sterilised = :sterilised LIMIT 1");
        query.bindValue(":type_of_surgery", m_value);
        query.bindValue(":status", "complete");
        query.bindValue(":sterilised", true);
    }
    if (query.exec()) {
        if (query.next()) {
            QString batch_code = query.value("batch_code").toString();
            ui.batch_code_lineEdit->setText(batch_code);
            ui.type_of_surgery_lineEdit->setText(m_value);
        }
    } else {
        qDebug() << query.lastError().text();
    }
    
}

void pick_a_set_widget::on_done_pushButton_clicked() {
    QString batch_code = ui.batch_code_lineEdit->text();
    QString type_of_surgery = ui.type_of_surgery_lineEdit->text();
    QString patients_name = ui.patient_name_lineEdit->text();
    QString patients_phone_no = ui.patient_phone_no_lineEdit->text();
    QString patients_other_phone_no = ui.patient_other_phone_no_lineEdit->text();
    QString next_of_kins_name = ui.next_of_kins_name_lineEdit->text();
    QString next_of_kins_phone_no = ui.next_of_kins_phone_no_lineEdit->text();
    QString next_of_kins_other_phone_no = ui.next_of_kins_other_phone_no_lineEdit->text();
    QString theatre = ui.theatre_name_comboBox->currentText();
    QString issued_to = ui.issued_to_lineEdit->text();
    QString issued_by = ui.issued_by_lineEdit->text();
    QString date_and_time_picked = ui.date_and_time_picked_lineEdit->text();

    QStringList missing_fields;

    if (issued_to.isEmpty())
    {
        missing_fields << "Issued To";
        ui.issued_to_lineEdit->setPlaceholderText(" * Required *");
        ui.issued_to_lineEdit->setStyleSheet("border: 1px solid red;");
    }
    if (patients_name.isEmpty())
    {
        missing_fields << "Patient's name";
        ui.patient_name_lineEdit->setPlaceholderText(" * Required *");
        ui.patient_name_lineEdit->setStyleSheet("border: 1px solid red;");
    }
    if (patients_phone_no.isEmpty())
    {
        missing_fields << "Patient's phone no";
        ui.patient_phone_no_lineEdit->setPlaceholderText(" * Required *");
        ui.patient_phone_no_lineEdit->setStyleSheet("border: 1px solid red;");
    }
    if (next_of_kins_name.isEmpty())
    {
        missing_fields << "Next of kin name";
        ui.next_of_kins_name_lineEdit->setPlaceholderText(" * Required *");
        ui.next_of_kins_name_lineEdit->setStyleSheet("border: 1px solid red;");
    }
    if (next_of_kins_phone_no.isEmpty())
    {
        missing_fields << "Next of kin phone no";
        ui.next_of_kins_phone_no_lineEdit->setPlaceholderText(" * Required *");
        ui.next_of_kins_phone_no_lineEdit->setStyleSheet("border: 1px solid red;");
    }

    if (!missing_fields.isEmpty()) {
        if (transaction_started && db.isOpen()) {
            db.rollback();
            transaction_started = false;
        }

        QMessageBox::warning(this, "Missing fields", "Please fill in all the required fields");

        } else {
            if (!db.open()) {
                bool opened = db.open();
                if (!opened) {
                    QMessageBox::critical(this, "Database Error", 
                        "Failed to connect to the database:" + db.lastError().text());
                }
            }
            QSqlQuery query(db);

            query.prepare("INSERT INTO surgeries(batch_code, type_of_surgery, patients_name, patients_phone_no, patients_other_phone_no, next_of_kins_name, next_of_kins_phone_no, next_of_kins_other_phone_no, theatre, issued_to, issued_by, date_and_time_picked) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
            query.addBindValue(batch_code);
            query.addBindValue(type_of_surgery);
            query.addBindValue(patients_name);
            query.addBindValue(patients_phone_no);
            query.addBindValue(patients_other_phone_no);
            query.addBindValue(next_of_kins_name);
            query.addBindValue(next_of_kins_phone_no);
            query.addBindValue(next_of_kins_other_phone_no);
            query.addBindValue(theatre);
            query.addBindValue(issued_to);
            query.addBindValue(issued_by);
            query.addBindValue(date_and_time_picked);

            if (!query.exec()) {
                if (transaction_started && db.isOpen()) {
                    db.rollback();
                    transaction_started = false;
                }

                QMessageBox::warning(this, "Something went wrong", 
                    "Your information was not submitted to the database: " + query.lastError().text());

            } else {
                if (transaction_started) {
                    db.commit();
                    transaction_started = false;

                } else {
                    QMessageBox::warning(this, "Something went wrong",
                    "Your data has not been committed" + query.lastError().text());
                }

                QSqlQuery query2(db);

                query2.prepare("UPDATE created_batches SET status = :status, sterilised = :sterilised WHERE batch_code = :batch_code");
                query2.bindValue(":batch_code", batch_code);
                query2.bindValue(":status", "in_surgery");
                query2.bindValue(":sterilised", false);

                if (!query2.exec()) {
                    qDebug() << query2.lastError().text();
                }

                QMessageBox::information(this, "Success", 
                    "The patient's details have been successfully added to the database");
                
                this->close();
                //TODO: Instead of closing open the widget that selects the surgery.
            }
    }

}

void pick_a_set_widget::on_plus_pushButton_clicked() {
    db.transaction();
    transaction_started = true;

    /*fetch the text in batch_code_lineEdit, and db connection and pass it to the add_items_form class in add_items_into_barcode.h.*/
    QString batch_code = ui.batch_code_lineEdit->text().trimmed();
    add_items_Form *itemsinbarcode = new add_items_Form(batch_code, &db);
    
    //Delete this widget once it closes
    itemsinbarcode->setAttribute(Qt::WA_DeleteOnClose);

    /*connect the signal in add_items_into_barcode.h so signal items have been added.
    then setUp_selected_items_tableView will update the table with this data*/
    connect(itemsinbarcode, &add_items_Form::items_added, 
                        this, &pick_a_set_widget::setUp_selected_items_tableView);
    itemsinbarcode->show();
}

void pick_a_set_widget::setUp_selected_items_tableView() {
    QString batch_code = ui.batch_code_lineEdit->text().trimmed();

    QSqlQuery query(db);

    query.prepare("SELECT category, instrument_count, surgical_instrument FROM add_items_into_barcode WHERE batch_code = :batch_code");
    query.bindValue(":batch_code", batch_code);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", 
            "Failed to execute query: " + query.lastError().text());
        return;
    }

    QStandardItemModel* customModel = new QStandardItemModel(this);

    //the headers of the table
    QStringList headers;
    headers << "surgical_instrument" << "Instrument_count" << "category";
    customModel->setHorizontalHeaderLabels(headers);

    int row = 0;
    while (query.next()) {
        QStandardItem* item1 = new QStandardItem(query.value(0).toString());
        QStandardItem* item2 = new QStandardItem(query.value(1).toString());
        QStandardItem* item3 = new QStandardItem(query.value(2).toString());

        customModel->setItem(row, 2, item1);
        customModel->setItem(row, 1, item2);
        customModel->setItem(row, 0, item3);

        row++;
    }

    ui.selected_items_tableView->setModel(customModel);

    ui.selected_items_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void pick_a_set_widget::on_exit_pushButton_clicked(){
    if (transaction_started && db.isOpen()) {
        db.rollback();
    }

    this->close();
}