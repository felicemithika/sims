#ifndef PICK_A_SET_WIDGET_H
#define PICK_A_SET_WIDGET_H

#include "../build/ui_pick_a_set_widget.h"
#include "DBManager.h"
#include "user_session.h"
#include "add_items_into_the_barcode.h"
#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QDateTime>


class pick_a_set_widget : public QWidget {
    Q_OBJECT

    private slots:
        void on_done_pushButton_clicked();
        void on_plus_pushButton_clicked();
        void on_exit_pushButton_clicked();

    public:
        enum open_source {
            from_create_a_barcode_widget,
            from_select_the_surgery_widget
        };
        
        explicit pick_a_set_widget(open_source source, QString value, QWidget* parent=nullptr);

    private:
        Ui::pick_a_set_widget ui;
        open_source m_source;
        QString m_value;
        QSqlDatabase db;
        bool transaction_started = false;

        void load_data();
        void setUp_selected_items_tableView();
};

#endif