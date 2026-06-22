#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "../build/ui_main_window.h"
#include "create_a_barcode.h"
#include "add_items_into_inventory.h"
#include "view_created_batches.h"
#include "view_the_inventory.h"
#include "pick_a_set_widget.h"
#include "select_the_surgery.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget* parent = nullptr);
    
    private slots:
        void on_go_into_surgery_pushButton_clicked();
        void on_add_items_into_inventory_pushButton_clicked();
        void on_view_created_batches_pushButton_clicked();
        void on_check_items_in_the_inventory_pushButton_clicked();

    private:
        Ui::MainWindow ui;
        select_the_surgery_widget* select_surgery;
        add_items_into_inventory* addintoinventory;
        view_created_batches* viewcreatedbatches;
        view_items_in_the_inventory_Form* viewitemsintheinventory;
        
        void style_button_as_link(QPushButton* button);
        void set_active_button(QPushButton* activeButton);
        void show_empty_placeholder(const QString& message);
        QWidget* wrapInCenteredContainer(QWidget* content);

        friend class create_a_barcode_widget;
        
};

#endif