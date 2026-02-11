#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "../build/ui_main_window.h"
#include "create_a_barcode.h"
#include "add_items_into_inventory.h"
#include "view_created_batches.h"
#include "view_the_inventory.h"
#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget* parent = nullptr);
    
    private slots:
        void on_create_a_barcode_pushButton_clicked();
        void on_add_items_into_inventory_pushButton_clicked();
        void on_view_created_batches_pushButton_clicked();
        void on_check_items_in_the_inventory_pushButton_clicked();

    private:
        Ui::MainWindow ui;
        create_a_barcode_widget* barcodewidget;
        add_items_into_inventory* addintoinventory;
        view_created_batches* viewcreatedbatches;
        view_items_in_the_inventory_Form* viewitemsintheinventory;

        void style_button_as_link(QPushButton* button);
        void set_active_button(QPushButton* activeButton);
        void show_empty_placeholder(const QString& message);
        QWidget* wrapInCenteredContainer(QWidget* content);


};

#endif