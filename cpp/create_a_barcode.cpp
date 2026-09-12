 #include "create_a_barcode.h"
#include "login_screen.h"
#include "user_session.h"
#include "DBManager.h"
#include <QVBoxLayout>
#include <QStringBuilder>
#include <QDir>
#include <QPixmap>
#include <QLabel>
#include <QVariantMap>


/*
##################################################################################
Widget responsible with the task of creating batches and barcodes
##################################################################################
*/

create_a_barcode_widget::create_a_barcode_widget(QObject *parent) : QObject(parent)
{
    //this->setObjectName("create_a_barcode_widget");
    //ui.setupUi(this);

    //connect to the database.
    db = database_manager::instance().get_database();

    python_process = nullptr;

    QDir dir("barcodes");
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    //autoFillDateTime();

    //fetch the logged in user from user_session.h
    //ui.created_by_lineEdit->setText(username);

    //populate the table with items that are going into the surgery.
    setUp_selected_items_tableView();

    //move the focus to the next input field or button when you press enter
    //ui.type_of_surgery_lineEdit->setFocus();
    //connect(ui.type_of_surgery_lineEdit, &QLineEdit::returnPressed, [this]() {
   //     ui.plus_pushButton->setFocus();
   // });
   // connect(ui.plus_pushButton, &QPushButton::clicked, [this]() {
      //  ui.create_barcode_pushButton->setFocus();
    //});
}

bool create_a_barcode_widget::generate_barcode(const QString& data, const QString& filename) {
    if (python_process) {
        qDebug() << "Barcode generation already running";
        return false;
    }
    
    python_process = new QProcess(this);
    
    connect(
        python_process,
        QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
        this,
        &create_a_barcode_widget::on_barcode_generated   
    );
    
    QString scriptPath = "../python/barcode_generator.py";
    
    QStringList arguments;
    arguments << scriptPath << data << filename;

    // Use Python from virtual environment
    QString pythonExecutable = "../python/my_env/bin/python3";
    
    qDebug() << "Running Python script with args:" << arguments;
    
    // Start the process with virtual environment Python
    python_process->start(pythonExecutable, arguments);
    
    if (!python_process->waitForStarted()) {
        qDebug() << "Failed to start Python process:" << python_process->errorString();
        python_process->deleteLater();
        python_process = nullptr;

        return false;
    }
    
    return true; 
}

void create_a_barcode_widget::on_barcode_generated(int exitCode, QProcess::ExitStatus exitStatus) {
    if (!python_process) {
        return;
    }

    QString output = python_process->readAllStandardOutput();
    QString error = python_process->readAllStandardError();
    
    qDebug() << "Barcode generator output:" << output;
    qDebug() << "Barcode generator error" << error;

    bool success = exitStatus == QProcess::NormalExit && exitCode == 0 && output.contains("SUCCESS:");

    if (!success) {
        qDebug() << "Barcode generation failed.";

        create_in_progress = false;

        if (transaction_started && db.isOpen()) {
            db.rollback();

            transaction_started = false;

            qDebug() << "Transaction rolled back because barcode generation failed.";
        }

        QString message = "Barcode generation failed.";

        if (!error.trimmed().isEmpty()) {
            message += "\n\n" + error.trimmed();
        }

        emit error_message(message);

        python_process->deleteLater();

        return;
    }

    qDebug() << "Barcode generated successfully.";

    if (transaction_started) {
        if (!db.commit()) {
            qDebug() << "Failed to commit transaction:" << db.lastError().text();

            create_in_progress = false;

            emit error_message("The barcode was generated, but the database transaction could not commited:\n" + db.lastError().text());

            python_process->deleteLater();
            python_process = nullptr;

            return;
        }

        transaction_started = false;
        qDebug() << "Transaction committed.";
    }

    create_in_progress = false;

    QString generated_file;

    QStringList output_lines = output.split('\n', Qt::SkipEmptyParts);

    for (const QString &line : output_lines) {
        if (line.startsWith("SUCCESS:")) {
            generated_file = line.mid(QString("SUCCESS:").length()).trimmed();
            break;
        }
    }
    qDebug() << "Barcode file:" << generated_file;

    emit batch_created(pending_batch_code);

    emit success_message("Batch created successfully.\n\nThe barcode has also been generated");

    python_process->deleteLater();
    python_process = nullptr;

    pending_batch_code.clear();
    pending_barcode_filename.clear();
}


//generate the batch_code and auto fill batch_code_lineEdit, date_picked_lineEdit, and time_picked_lineEdit
void create_a_barcode_widget::auto_fill_items() {
    QDateTime current = QDateTime::currentDateTime();
    QTime time = current.time();
    QDate date = QDate::currentDate();

    QString formatted =
        current.toString("dd") %
        current.toString("MM") %
        current.toString("yyyy") %
        time.toString("HH") %
        time.toString("mm") %
        time.toString("ss");

    int ms = time.msec();
    formatted += QString("%1").arg(ms / 10, 2, 10, QChar('0'));

    QString username = UserSession::getInstance().getCurrentUser();

    m_batch_code = formatted;
    m_date_created = date.toString();
    m_time_created = time.toString();
    m_session_user = username;

    emit batch_code_changed();
    emit date_created_changed();
    emit time_created_changed();
    emit session_user_changed();
}

QString create_a_barcode_widget::batch_code() const {
    return m_batch_code;
}

QString create_a_barcode_widget::date_created() const {
    return m_date_created;
}

QString create_a_barcode_widget::time_created() const {
    return m_time_created;
}

QString create_a_barcode_widget::session_user() const {
    return m_session_user;
}

//open add_items_into_barcode.h widget
/*void create_a_barcode_widget::on_plus_pushButton_clicked()
{
    //start a transaction to track the changes in the db.
    db.transaction();
    transaction_started = true;

    /*fetch the text in batch_code_lineEdit, and db connection and pass it to the add_items_form class in add_items_into_barcode.h.*/
    /*QString batch_code = ui.batch_code_lineEdit->text().trimmed();
    add_items_Form *itemsinbarcode = new add_items_Form(batch_code, &db);
    
    //Delete this widget once it closes
    itemsinbarcode->setAttribute(Qt::WA_DeleteOnClose);

    /*connect the signal in add_items_into_barcode.h so signal items have been added.
    then setUp_selected_items_tableView will update the table with this data*/
    /*connect(itemsinbarcode, &add_items_Form::items_added, 
                      this, &create_a_barcode_widget::setUp_selected_items_tableView);
   itemsinbarcode->show();
}*/

void create_a_barcode_widget::start_items_transaction() {
    if (!db.isOpen()) {
        if (!db.open()) {
            qDebug() <<"Failed to open database:" << db.lastError().text();
            return;
        }
    }

    if (transaction_started) {
        qDebug() <<"Transaction already started";
        return;
    }

    if (db.transaction()) {
        transaction_started = true;
        qDebug() << "Transction started";
    } else {
        qDebug() << "Failed to start transction:" << db.lastError().text();
    }
}

void create_a_barcode_widget::rollback_items_transaction() {
    if (!transaction_started) {
        qDebug() << "No active transaction to rollback";
        return;
    }
    if (db.rollback()) {
        transaction_started = false;
        qDebug() << "Transaction rolled back";
    } else {
        qDebug() << "Failed to rollback transaction:" << db.lastError().text();
    }
}

//button that add this batch to the database and then generates the barcode. TODO

void create_a_barcode_widget::create_batch(const QString &surgery_type) {
    if (create_in_progress) {
        qDebug() << "Create operation already in progress";
        return;
    }

    QString type_of_surgery = surgery_type.trimmed();

    //check if the fields are empty
    if (type_of_surgery.isEmpty()) {
        emit warning_message("Please enter the type of surgery.");
        return;
    }

    if (!transaction_started) {
        emit warning_message("No active batch transaction was found.");
        return;
    }

    if (!db.isOpen()) {
        if (!db.open()) {
            emit error_message("Failed to connect to the database:\n" + db.lastError().text());
            return;
        }
    }
    
    //display an error message box if there are empty fields that should be field
    QSqlQuery count_query(db);

    count_query.prepare("SELECT COUNT(*) FROM add_items_into_barcode WHERE batch_code = :batch_code");
    count_query.bindValue(":batch_code", m_batch_code);

    if (!count_query.exec()) {
        emit error_message("Failed to check batch items:\n" + count_query.lastError().text());
        return;
    }

    if (!count_query.next()) {
        emit error_message("Failed to verify the items in this batch.");
        return;
    }

    int item_count = count_query.value(0).toInt();

    if (item_count == 0) {
        emit warning_message("No surgical items have been added to this batch.");
        return;
    }

    //update the db with the data in the widget

    QSqlQuery query(db);

    query.prepare("INSERT INTO created_batches (batch_code, type_of_surgery, created_by, date_created, time_created ) VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(m_batch_code);
    query.addBindValue(type_of_surgery);
    query.addBindValue(m_session_user);
    query.addBindValue(m_date_created);
    query.addBindValue(m_time_created);

    if (!query.exec()) {

        qDebug() << "Failed to create batch:" << query.lastError().text();

        if (transaction_started && db.isOpen()) {
            db.rollback();
            transaction_started = false;
        }

        emit error_message("Failed to save the batch:\n" + query.lastError().text());

        return;
    }

    // Generate barcode using the batch code
    QString barcodeFilename = "barcodes/batch_" + m_batch_code;

    pending_batch_code = m_batch_code;
    pending_barcode_filename = barcodeFilename;

    create_in_progress = true;
    
    // Generate barcode (async)
    bool barcode_started = generate_barcode(m_batch_code, barcodeFilename);
    
    if (!barcode_started) {
        create_in_progress = false;

        if (transaction_started) {
            db.rollback();
            transaction_started = false;
        }

        emit error_message("The batch could not be created because barcode generation could not be started.");

        return;
    }

    qDebug() << "Batch inserted successfully."
                << "Waitng for barcode generation before committing.";

   /*// Commit transaction if everything succeeded
    if (transaction_started) {
        db.commit();
        transaction_started = false;
        qDebug() << "Transaction committed";
    }
    

    QMessageBox::information(this, "Success", 
        "Batch saved to database. Barcode generation started...");
    
    reply = QMessageBox::question(this, "Confirm Patient Information Entry",
        "Do you want to continue and enter the patient’s information for this surgery type?",
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        pick_a_set_widget *go_to_surgery = new pick_a_set_widget(pick_a_set_widget::from_create_a_barcode_widget, batch_code);
        qDebug() << batch_code;
        go_to_surgery->setAttribute(Qt::WA_DeleteOnClose);

        go_to_surgery->show();

        this->close();
    } else {
        // Clear fields for next entry
        autoFillDateTime();
        ui.created_by_lineEdit->setText(UserSession::getInstance().getCurrentUser());
        ui.type_of_surgery_lineEdit->clear();
        
        // Clear the table
        QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui.selected_items_tableView->model());
        if (model) {
            model->removeRows(0, model->rowCount());
        }

        // Reset styles
        QLineEdit* fields[] = { ui.type_of_surgery_lineEdit };
        
        for (QLineEdit* field : fields) {
            field->setPlaceholderText("");
            field->setStyleSheet("");
        }

    }
} */
}
//exit button
/*void create_a_barcode_widget::on_exit_pushButton_clicked() {
    //reverse changes made to the database if a user exits the widget without pressing create
    if (transaction_started && db.isOpen()) {
        db.rollback();
        qDebug() << "transaction rolled back";
    }

    this->close();
 
}*/

//inserts data into the table
void create_a_barcode_widget::setUp_selected_items_tableView() {

    QString batch_code = m_batch_code.trimmed();

    if (batch_code.isEmpty()) {
        qDebug() << "Cannot refresh items table: batch code is empty";
        return;
    }

     if (!db.isOpen()) {
            if (!db.open())
        {
            qDebug() << "Database error" << db.lastError().text();
            return;
        }
        }

    //fetch the items from the database. it fetches only for the items associated with the batch_code in batch_code_lineEdit
    QSqlQuery query(db);

    query.prepare("SELECT category, instrument_count, surgical_instrument FROM add_items_into_barcode WHERE batch_code = :batch_code");
    query.bindValue(":batch_code", batch_code);

    if (!query.exec()) {
        qDebug() <<"query error:" << query.lastError().text();
        return;
    }

    QVariantList items;

    while (query.next()) {
        QVariantMap item;

        item["category"] = query.value(0).toString();
        item["count"] = query.value(1).toString();
        item["instrument"] = query.value(2).toString();

        items.append(item);
    }

    emit selected_items_updated(items);
}
