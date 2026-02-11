#include "add_items_into_inventory.h"
/*
###########################################################################################
 This widget adds surgical instruments into the inventory.
 ##########################################################################################
 */
add_items_into_inventory::add_items_into_inventory(QWidget* parent) : QWidget(parent) {
    this->setObjectName("add_items_into_inventory_widget");
    ui.setupUi(this);

    //autofill date added
    QDate date = QDate::currentDate();
    ui.date_added_lineEdit->setText(date.toString());

    //autofill entered by
    QString username = UserSession::getInstance().getCurrentUser();
    ui.entered_by_lineEdit->setText(username);

    // add items into the combo box
    QStringList items_in_status = {"Usable", "Unusable"};
    ui.status_comboBox->addItems(items_in_status);

    QStringList items_in_category = {"Graspers", "Clamps", "Surgical Scissors", "Needle Drivers", "Retractors"};
    ui.category_comboBox->addItems(items_in_category);

}

//function that controls the add button. Inserts data in the widget into the database.
void add_items_into_inventory::on_add_item_pushButton_clicked() {
    QString name = ui.name_of_item_lineEdit->text();
    QString items_count = ui.items_count_spinBox->text();
    QString status = ui.status_comboBox->currentText();
    QString date_added = ui.date_added_lineEdit->text();
    QString entered_by = ui.entered_by_lineEdit->text();
    QString category = ui.category_comboBox->currentText();

    //check whether name_of_item_lineedit is expty else insert the data into the db.
    if (name.isEmpty()) {
        QMessageBox::information (this, "Missing field", "Please enter the name of the instrument before proceeding.");
        ui.name_of_item_lineEdit->setFocus();
    } else {
        db = QSqlDatabase::addDatabase("QMARIADB", "login_connection");
        db.setHostName("localhost");
        db.setDatabaseName("sims_db");
        db.setUserName("root");
        db.setPassword("");

        if (!db.open())
        {
            QMessageBox::critical(this, "Database Error",
                                "Failed to connect to database: " + db.lastError().text());
            return;
        }

        QSqlQuery query(db);

        query.prepare("INSERT INTO inventory (name, items_count, status, date_added, entered_by, category) VALUES (?, ?, ?, ?, ?, ?)");
        query.addBindValue(name);
        query.addBindValue(items_count);
        query.addBindValue(status);
        query.addBindValue(date_added);
        query.addBindValue(entered_by);
        query.addBindValue(category);

        if (query.exec()) {
            QMessageBox::information(this, "Success", "Inventory has been successfully added.");

            // updathe date_added_linedit with the current time. Ensures that the nex item that is added is correct.
            QDate date = QDate::currentDate();
            ui.date_added_lineEdit->setText(date.toString());

            QString username = UserSession::getInstance().getCurrentUser();
            ui.entered_by_lineEdit->setText(username);

            ui.name_of_item_lineEdit->clear();
            ui.items_count_spinBox->setValue(1);
        } else {
            QString error = query.lastError().text();
            qDebug() << "SQL Error:" << error;
            qDebug() << "Last query:" << query.lastQuery();
            QMessageBox::warning(this, "Something went wrong", "Check your entries and try again.");
        }

        db.close();
    }
}