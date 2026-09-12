/*#include "select_the_surgery.h"

select_the_surgery_widget::select_the_surgery_widget(QWidget* parent) : QWidget(parent) {
    this->setObjectName("select_the_surgery_widget");
    ui.setupUi(this);

    db = database_manager::instance().get_database();
    type_of_surgery_dropdown();
}

//fill the dropdown with types of surgeries from the created batches table
void select_the_surgery_widget::type_of_surgery_dropdown(){
    ui.type_of_surgery_comboBox->clear();

    if (!db.isOpen()) {
        if (!db.isOpen()) {
            QMessageBox::critical (this, "Database Error", "Failed to connect to the database"+db.lastError().text());
        }
        return;
    }
 
    QSqlQuery query(db);

    query.prepare("SELECT DISTINCT type_of_surgery FROM created_batches WHERE status = :status AND sterilised = :sterilised");
    query.bindValue(":status", "complete");
    query.bindValue(":sterilised", true);
    if (query.exec()) {
        while (query.next()) {
            QString type_of_surgery = query.value("type_of_surgery").toString();
            ui.type_of_surgery_comboBox->addItem(type_of_surgery);
        }
    }

}

void select_the_surgery_widget::on_new_batch_pushButton_clicked() {
   /* create_a_batch = new create_a_barcode_widget();
    create_a_batch->setAttribute(Qt::WA_DeleteOnClose);
    create_a_batch->show();
    this->close();*/
/*}

void select_the_surgery_widget::on_patients_details_pushButton_clicked() {
    QString type_of_surgery = ui.type_of_surgery_comboBox->currentText();
    go_to_surgery = new pick_a_set_widget(pick_a_set_widget::from_select_the_surgery_widget, type_of_surgery);
    go_to_surgery->setAttribute(Qt::WA_DeleteOnClose);

    go_to_surgery->show();
    this->close();
}

void select_the_surgery_widget::on_exit_pushButton_clicked() {
    this->close();
}*/