#ifndef CREATE_A_BARCODE_H
#define CREATE_A_BARCODE_H

#include "../build/ui_create_a_barcode.h"
#include "add_items_into_the_barcode.h"
#include <QWidget>
#include <QDateTime>
#include <QTimer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QProcess>


class create_a_barcode_widget : public QWidget {
    Q_OBJECT

    public:
        explicit create_a_barcode_widget(QWidget* parent = nullptr);

    private slots:
        void autoFillDateTime();
        void on_plus_pushButton_clicked();
        void on_create_barcode_pushButton_clicked();
        void on_exit_pushButton_clicked();
        void on_barcode_generated(int exit_code, QProcess::ExitStatus exit_status);

    private:
        Ui::create_a_barcode_widget ui;
        QTimer* timer;
        QSqlDatabase db;
        bool transaction_started = false;
        QProcess* python_process;

        void setUp_selected_items_tableView();
        bool generate_barcode(const QString& data, const QString& filename);
};

#endif