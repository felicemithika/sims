 #include "create_a_barcode.h"
#include "login_screen.h"
#include "user_session.h"
#include "DBManager.h"
#include <QVBoxLayout>
#include <QStringBuilder>
#include <QDir>
#include <QPixmap>
#include <QLabel>


/*
##################################################################################
Widget responsible with the task of creating batches and barcodes
##################################################################################
*/

create_a_barcode_widget::create_a_barcode_widget(QWidget *parent) : QWidget(parent)
{
    this->setObjectName("create_a_barcode_widget");
    ui.setupUi(this);

    //connect to the database.
    db = database_manager::instance().get_database();

    python_process = nullptr;

    QDir dir("barcodes");
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    autoFillDateTime();

    //fetch the logged in user from user_session.h
    QString username = UserSession::getInstance().getCurrentUser();
    ui.created_by_lineEdit->setText(username);

    //populate the table with items that are going into the surgery.
    setUp_selected_items_tableView();

    //move the focus to the next input field or button when you press enter
    ui.type_of_surgery_lineEdit->setFocus();
    connect(ui.type_of_surgery_lineEdit, &QLineEdit::returnPressed, [this]() {
        ui.plus_pushButton->setFocus();
    });
    connect(ui.plus_pushButton, &QPushButton::clicked, [this]() {
        ui.create_barcode_pushButton->setFocus();
    });
}

bool create_a_barcode_widget::generate_barcode(const QString& data, const QString& filename) {
    python_process = new QProcess(this);
    
    connect(python_process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, [this](int exitCode, QProcess::ExitStatus exitStatus) {
                this->on_barcode_generated(exitCode, exitStatus);
            });
    
    QString scriptPath = "../python/barcode_generator.py";
    
    QStringList arguments;
    arguments << scriptPath << data << filename;

    // Use Python from virtual environment
    QString pythonExecutable = "../python/my_env/bin/python3";
    
    qDebug() << "Running Python script with args:" << arguments;
    
    // Start the process with virtual environment Python
    python_process->start(pythonExecutable, arguments);
    
    if (!python_process->waitForStarted()) {
        qDebug() << "Failed to start Python process";
        return false;
    }
    
    return true;
}

void create_a_barcode_widget::on_barcode_generated(int exitCode, QProcess::ExitStatus exitStatus) {
    if (exitStatus == QProcess::NormalExit && exitCode == 0) {
        QString output = python_process->readAllStandardOutput();
        QString error = python_process->readAllStandardError();
        
        qDebug() << "Python output:" << output;
        
        if (output.contains("SUCCESS:")) {
            // Extract filename from output
            QString barcodeFile = output.split(":").last().trimmed();
            qDebug() << "Barcode saved to:" << barcodeFile;
            
            // You can now display the barcode image in your UI if needed
            QPixmap pixmap(barcodeFile);
            if (!pixmap.isNull()) {
                // Create a label to show the barcode
                QLabel* barcodeLabel = new QLabel(this);
                barcodeLabel->setPixmap(pixmap.scaled(300, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                barcodeLabel->setAlignment(Qt::AlignCenter);
                
                // Add to layout or show in a dialog
                QMessageBox msgBox;
                msgBox.setWindowTitle("Barcode Generated");
                msgBox.setText("Barcode has been generated successfully!");
                msgBox.setIcon(QMessageBox::Information);
                msgBox.layout()->addWidget(barcodeLabel);
                msgBox.exec();
            }
        }
    } else {
        QString error = python_process->readAllStandardError();
        qDebug() << "Python error:" << error;
        QMessageBox::warning(this, "Barcode Error", 
            "Failed to generate barcode:\n" + error);
    }
    
    python_process->deleteLater();
    python_process = nullptr;
}


//generate the batch_code and auto fill batch_code_lineEdit, date_picked_lineEdit, and time_picked_lineEdit
void create_a_barcode_widget::autoFillDateTime()
{
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

    ui.batch_code_lineEdit->setText(formatted);
    ui.date_created_lineEdit->setText(date.toString());
    ui.time_created_lineEdit->setText(time.toString());
}

//open add_items_into_barcode.h widget
void create_a_barcode_widget::on_plus_pushButton_clicked()
{
    //start a transaction to track the changes in the db.
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
                        this, &create_a_barcode_widget::setUp_selected_items_tableView);
    itemsinbarcode->show();
}

//button that add this batch to the database and then generates the barcode. TODO
void create_a_barcode_widget::on_create_barcode_pushButton_clicked()
{

    QStringList missing_fields;

    QString batch_code = ui.batch_code_lineEdit->text().trimmed();
    QString type_of_surgery = ui.type_of_surgery_lineEdit->text();
    QString created_by = ui.created_by_lineEdit->text();
    QString date_created = ui.date_created_lineEdit->text();
    QString time_created = ui.time_created_lineEdit->text();
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui.selected_items_tableView->model());

    //check if the fields are empty
    if (type_of_surgery.isEmpty())
    {
        missing_fields << "Issued To";
        ui.type_of_surgery_lineEdit->setPlaceholderText(" * Required *");
        ui.type_of_surgery_lineEdit->setStyleSheet("border: 1px solid red;");
    }
    
    //display an error message box if there are empty fields that should be field
    if (!missing_fields.isEmpty())
    {
        if (transaction_started && db.isOpen()) {
            db.rollback();
            transaction_started = false;
        }
        QString errorMsg = "The following fields are required:\n";
        for (const QString &field : missing_fields)
        {
            errorMsg += ". " + field + "\n";
        }

        QMessageBox::warning(this, "Missing information", errorMsg);

    } else if (!model || model->rowCount() == 0) {

        QMessageBox::warning(this, "Empty table", "Add surgical equipment for the surgery to the table by pressing the plus (+) button above.");

    } else {
        if (!db.isOpen()) {
            if (!db.open())
        {
            QMessageBox::critical(this, "Database Error",
                                "Failed to connect to database: " + db.lastError().text());
            return;
        }
        }

        //update the db with the data in the widget

        QSqlQuery query(db);

        query.prepare("INSERT INTO created_batches (batch_code, type_of_surgery, created_by, date_created, time_created ) VALUES (?, ?, ?, ?, ?)");
        query.addBindValue(batch_code);
        query.addBindValue(type_of_surgery);
        query.addBindValue(created_by);
        query.addBindValue(date_created);
        query.addBindValue(time_created);

        if (!query.exec()) {
            if (transaction_started && db.isOpen()) {
                db.rollback();
                transaction_started = false;
            }
            QMessageBox::warning(this, "Database Error", 
                "Failed to save batch: " + query.lastError().text());
            return;
        }

        // Generate barcode using the batch code
        QString barcodeFilename = "barcodes/batch_" + batch_code;
        
        // Generate barcode (async)
        bool barcodeStarted = generate_barcode(batch_code, barcodeFilename);
        
        if (!barcodeStarted) {
            QMessageBox::warning(this, "Barcode Generation", 
                "Failed to start barcode generation process.");
            return;
        }

        // Commit transaction if everything succeeded
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
    }
}
//exit button
void create_a_barcode_widget::on_exit_pushButton_clicked() {
    //reverse changes made to the database if a user exits the widget without pressing create
    if (transaction_started && db.isOpen()) {
        db.rollback();
        qDebug() << "transaction rolled back";
    }

    this->close();
 
}

//inserts data into the table
void create_a_barcode_widget::setUp_selected_items_tableView() {

    QString batch_code = ui.batch_code_lineEdit->text().trimmed();

     if (!db.isOpen()) {
            if (!db.open())
        {
            QMessageBox::critical(this, "Database Error",
                                "Failed to connect to database: " + db.lastError().text());
            return;
        }
        }

    //fetch the items from the database. it fetches only for the items associated with the batch_code in batch_code_lineEdit
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
