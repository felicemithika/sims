#ifndef ADD_ITEMS_INTO_THE_BARCODE_H
#define ADD_ITEMS_INTO_THE_BARCODE_H

#include "../build/ui_add_items_into_the_barcode.h"
#include "../build/ui_create_a_barcode.h"
#include "create_a_barcode.h"
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>

class add_items_Form : public QWidget {
    Q_OBJECT

    public:
        explicit add_items_Form(const QString &batch_code, QSqlDatabase* parentdb = nullptr, QWidget* parent = nullptr);

    signals:
        void items_added();

    private slots:
        void on_add_instrument_pushButton_clicked();
        void on_exit_pushButton_clicked();
    
    private:
        Ui::add_items_Form ui;
        QSqlDatabase db;
        QString currentBatchCode;

        void add_items_into_surgical_instrument_combobox(const QString &category);
};

#endif