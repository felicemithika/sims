/*#ifndef SELECT_THE_SURGERY_H
#define SELECT_THE_SURGERY_H

#include "../build/ui_select_the_surgery_widget.h"
#include "DBManager.h"
#include "create_a_barcode.h"
#include "pick_a_set_widget.h"
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

class select_the_surgery_widget : public QWidget {
    Q_OBJECT

    public:
        explicit select_the_surgery_widget(QWidget* parent=nullptr);

    private slots:
        void on_new_batch_pushButton_clicked();
        void on_exit_pushButton_clicked();
        void on_patients_details_pushButton_clicked();

    private:
        Ui::select_the_surgery_widget ui;
        void type_of_surgery_dropdown();
        QSqlDatabase db;

        create_a_barcode_widget* create_a_batch;
        pick_a_set_widget* go_to_surgery;
        
};
#endif*/