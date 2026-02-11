#ifndef ADD_ITEMS_INTO_INVENTORY_H
#define ADD_ITEMS_INTO_INVENTORY_H

#include "../build/ui_add_items_in_the_inventory.h"
#include "user_session.h"
#include <QWidget>
#include <QDate>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class add_items_into_inventory : public QWidget {
    Q_OBJECT

    public:
        explicit add_items_into_inventory(QWidget* parent = nullptr);

    private slots:
        void on_add_item_pushButton_clicked();

    private:
        Ui::add_items_into_inventory_widget ui;
        QSqlDatabase db;

};

#endif