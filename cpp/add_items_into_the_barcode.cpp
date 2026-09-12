#include "add_items_into_the_barcode.h"
#include <QDebug>

/*
####################################################################################################
This widget is responsible for adding instruments going to surgery for a specific batch number.
####################################################################################################
Pass  batch_code from create_a_barcode as string and store it as currentBatchCode
    this will help us associate the batch with the items that will be added by this widget.(see query in on_add_instrument_pushButton_clicked())
parentdb enables us to use the db connection from create_a_barcode. This will enable us to track the db transaction.
    it will enable us to reverse the changes in the db incase the exit button is clicked in create_a_barcode_widget.
    without this items will be added and get associated with a batch the was never created.
*/

add_items_Form::add_items_Form(const QString &batch_code, QSqlDatabase* parentdb, QObject* parent) 
: QObject(parent), currentBatchCode(batch_code) {
    //Use the parent db ie from the create_a_barcode class
    if (parentdb) {
        db = *parentdb;
    }

    m_category_list = {"Graspers", "Clamps", "Surgical Scissors", "Needle Drivers", "Retractors"};
    m_category_list.sort();
    
    emit category_list_changed();

    load_surgical_instruments(m_category_list.first());
}

//feed the surgical instrument combox with items
void add_items_Form::load_surgical_instruments(const QString &category) {

    m_surgical_instrument_list.clear();

    if (!db.isOpen()) {
            if (!db.open())
        {
            qDebug()
                << "Failed to connect to database:"
                << db.lastError().text();
            return;
        }
        }

    QSqlQuery query(db);

    //insert the surgical instruments name into the combobox from the db.
    query.prepare("SELECT name FROM inventory WHERE category = :category");
    query.bindValue(":category", category);
    if (query.exec()) {
        while (query.next()) {
            QString name_data = query.value("name").toString();
            m_surgical_instrument_list.append(name_data);
        }
    } else {
        qDebug()
            << "Failed to read the table:"
            << query.lastError().text();
    }

    emit surgical_instrument_list_changed();

}

QStringList add_items_Form::category_list() const {
    return m_category_list;
}

QStringList add_items_Form::surgical_instrument_list() const {
    return m_surgical_instrument_list;
}

//insert the surgical instruments going for surgery into the database
void add_items_Form::add_requested_item(const QString &category, int instrument_count, const QString &surgical_instrument, const QString &comments) {
    if (!db.isOpen()) {
            if (!db.open())
        {
            emit error_message("Failed to connect to database: " + db.lastError().text());
            return;
        }
        }
    

    //This query add items selected by the user inside the widget to the database
    QSqlQuery query(db);
    query.prepare("INSERT INTO add_items_into_barcode (batch_code, category, instrument_count, surgical_instrument, comments) VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(currentBatchCode);
    query.addBindValue(category);
    query.addBindValue(instrument_count);
    query.addBindValue(surgical_instrument);
    query.addBindValue(comments);

    int current_picked_item_count = 0;
    int current_items_count = 0;
    
    /*This query fetches items count and picked item count from the inventory table
    These two will be updated by query2 to update the inventory to the correct no after items were picked for surgery
    picked_item_count ==> Total no of items that have been taken from the inventory
    items_count ==> Totals no of items remaining in the inventory.*/
    QSqlQuery query3(db);
    query3.prepare("SELECT picked_item_count, items_count FROM inventory WHERE name = :surgical_instrument");
    query3.bindValue(":surgical_instrument", surgical_instrument);
    if (query3.exec()) {
        if (query3.next()) {
            current_picked_item_count = query3.value("picked_item_count").toInt();
            current_items_count = query3.value("items_count").toInt();
        }
    }  else {
        emit error_message("Failed to read inventory:" + query3.lastError().text());
        return;
    }

    /*new_picked_items_count ==> Total no items taken from the inventory. eg 
                if picked_item_count of surgical scisors was 10,
                a nurse asks for 4 surgical scissors for some surgery(instrument_count), the new_picked_items_count will be
                            10 picked_items_count + 4 instrument_count = 14
    new_items_count ==> Total no of remaining stock in the inventory
                using the above the analogy 4 surgical scissors were taken
                so if the current_items_count was 34 then the new_item_count will be
                    34 - 4 = 30 remaining surgical scissors for future use.*/
    int new_picked_item_count = current_picked_item_count + instrument_count;
    int new_items_count = current_items_count - instrument_count;

    if (instrument_count > current_items_count) {
        emit warning_message(
            QString("Not enough items in inventory!!\n\n"
                    "Available: %1\n"
                    "Requested: %2")
                .arg(current_items_count)
                .arg(instrument_count)
        );
        return;
    }

    //update the db with these new values.
    QSqlQuery query2(db);
    query2.prepare("UPDATE inventory SET items_count = :new_items_count, picked_item_count = :new_picked_item_count WHERE name = :surgical_instrument");
    query2.bindValue(":new_picked_item_count", new_picked_item_count);
    query2.bindValue(":new_items_count", new_items_count);
    query2.bindValue(":surgical_instrument", surgical_instrument);

    if (!query.exec()) {
        qDebug() << "Failed to add item:"
                << query.lastError().text();
        return;
    }

    if (!query2.exec()) {
        qDebug() << "Failed to update inventory:"
                << query2.lastError().text();
        return;
    }

    emit success_message("Item successfuly added to the barcode.");

    emit items_added();

    qDebug() << "Items added";

} 

void add_items_Form::set_batch_code(const QString &batch_code) {
    currentBatchCode = batch_code.trimmed();

    qDebug() << "Current batch code set to:" << currentBatchCode;
}