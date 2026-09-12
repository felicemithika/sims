/*#include "main_window.h"
#include <QStyle>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    this->setObjectName("MainWindow");
    ui.setupUi(this);
    showMaximized();

    select_surgery = nullptr;
    addintoinventory = nullptr;
    viewcreatedbatches = nullptr;
    viewitemsintheinventory = nullptr;

    style_button_as_link(ui.go_into_surgery_pushButton);
    style_button_as_link(ui.add_items_into_inventory_pushButton);
    style_button_as_link(ui.view_created_batches_pushButton);
    style_button_as_link(ui.check_items_in_the_inventory_pushButton);

    ui.scrollArea->setWidgetResizable(true);
    ui.scrollArea->setAlignment(Qt::AlignCenter);

    show_empty_placeholder("Select an option from above");
}

QWidget* MainWindow::wrapInCenteredContainer(QWidget* content)
{
    QWidget* container = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(container);

    container->setAttribute(Qt::WA_DeleteOnClose);

    layout->setContentsMargins(0, 0, 0, 0);
    layout->setAlignment(Qt::AlignCenter);

    content->setParent(container);
    layout->addWidget(content);

    return container;
}


void MainWindow::style_button_as_link(QPushButton* button) {
    if (!button) return;
    
    QString linkStyle = 
        "QPushButton {"
        "    color: white;"
        "    background-color: transparent;"
        "    border: none;"
        "    text-align: left;"
        "    padding: 8px;"
        "}"
        "QPushButton:hover {"
        "    color: white;"
        "    background-color: #010101;"
        "    border-radius: 4px;"
        "}"
        "QPushButton:pressed {"
        "    color: white;"
        "    background-color: #030303;"
        "}";
    
    button->setStyleSheet(linkStyle);
    button->setCursor(Qt::PointingHandCursor);
    button->setFlat(true);
}

void MainWindow::set_active_button(QPushButton* activeButton) {
    QString defaultStyle = 
        "QPushButton {"
        "    color: white;"
        "    background-color: transparent;"
        "    border: none;"
        "    text-align: left;"
        "    padding: 8px;"
        "}"
        "QPushButton:hover {"
        "    color: white;"
        "    background-color: #020202;"
        "    border-radius: 4px;"
        "}";
    
    QString activeStyle = 
        "QPushButton {"
        "    color: black;"
        "    font-weight: bold;"
        "    background-color: #e8f0fe;"
        "    border: 1px solid #c6d9f1;"
        "    border-radius: 4px;"
        "    text-align: left;"
        "    padding: 8px;"
        "}";
    
    ui.go_into_surgery_pushButton->setStyleSheet(defaultStyle);
    ui.add_items_into_inventory_pushButton->setStyleSheet(defaultStyle);
    ui.view_created_batches_pushButton->setStyleSheet(defaultStyle);
    ui.check_items_in_the_inventory_pushButton->setStyleSheet(defaultStyle);
    
    if (activeButton) {
        activeButton->setStyleSheet(activeStyle);
    }
}

void MainWindow::show_empty_placeholder(const QString& message) {

    QWidget* placeholderWidget = new QWidget();
    placeholderWidget->setAttribute(Qt::WA_DeleteOnClose);
    QVBoxLayout* placeholderLayout = new QVBoxLayout(placeholderWidget);
    placeholderLayout->setAlignment(Qt::AlignCenter);

    
    

    QLabel* placeholderLabel = new QLabel(message.isEmpty() ? "Select an option from above." : message);
    placeholderLabel->setAlignment(Qt::AlignCenter);
    placeholderLabel->setStyleSheet("font-size: 16px; color:gray");

    placeholderLabel->setAttribute(Qt::WA_DeleteOnClose);

    placeholderLayout->addWidget(placeholderLabel);
    ui.scrollArea->takeWidget();
    ui.scrollArea->setWidget(wrapInCenteredContainer(placeholderWidget));

    if (select_surgery && select_surgery->parent() != placeholderWidget) {
        delete select_surgery;
        select_surgery = nullptr;
    }
    if (addintoinventory && addintoinventory->parent() != placeholderWidget) {
        delete addintoinventory;
        addintoinventory = nullptr;
    }
    if (viewcreatedbatches && viewcreatedbatches->parent() != placeholderWidget) {
        delete viewcreatedbatches;
        viewcreatedbatches = nullptr;
    }
    if (viewitemsintheinventory && viewitemsintheinventory->parent() != placeholderWidget) {
        delete viewitemsintheinventory;
        viewitemsintheinventory = nullptr;
    }

}

/*void MainWindow::on_go_into_surgery_pushButton_clicked() {

    if (!select_surgery) {
        select_surgery = new select_the_surgery_widget();
        select_surgery->setAttribute(Qt::WA_DeleteOnClose);
        connect(select_surgery, &QObject::destroyed, this, [this]() {
            select_surgery=nullptr;
        });
    }

    ui.scrollArea->takeWidget();
    ui.scrollArea->setWidget(wrapInCenteredContainer(select_surgery));

    select_surgery->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    if (addintoinventory) {
        delete addintoinventory;
        addintoinventory = nullptr;
    } else if (viewcreatedbatches) {
        delete viewcreatedbatches;
        viewcreatedbatches = nullptr;
    } else if (viewitemsintheinventory) {
        delete viewitemsintheinventory;
        viewitemsintheinventory = nullptr;
    }

    set_active_button(ui.go_into_surgery_pushButton);
}

void MainWindow::on_add_items_into_inventory_pushButton_clicked() {

    if (!addintoinventory) {
        addintoinventory = new add_items_into_inventory();
        addintoinventory->setAttribute(Qt::WA_DeleteOnClose);
    }
;

    ui.scrollArea->takeWidget();
    ui.scrollArea->setWidget(wrapInCenteredContainer(addintoinventory));

    addintoinventory->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    if (select_surgery) {
        delete select_surgery;
        select_surgery = nullptr;
    } else if (viewcreatedbatches) {
        delete viewcreatedbatches;
        viewcreatedbatches = nullptr;
    } else if (viewitemsintheinventory) {
        delete viewitemsintheinventory;
        viewitemsintheinventory = nullptr;
    }
    
    set_active_button(ui.add_items_into_inventory_pushButton);
}

void MainWindow::on_view_created_batches_pushButton_clicked() {

    if (!viewcreatedbatches) {
        viewcreatedbatches = new view_created_batches();
        viewcreatedbatches->setAttribute(Qt::WA_DeleteOnClose);
    }

    ui.scrollArea->takeWidget();
    ui.scrollArea->setWidget(wrapInCenteredContainer(viewcreatedbatches));

    viewcreatedbatches->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    if (addintoinventory) {
        delete addintoinventory;
        addintoinventory = nullptr;
    } else if (select_surgery) {
        delete select_surgery;
        select_surgery = nullptr;
    } else if (viewitemsintheinventory) {
        delete viewitemsintheinventory;
        viewitemsintheinventory = nullptr;
    }

    set_active_button(ui.view_created_batches_pushButton);
}

void MainWindow::on_check_items_in_the_inventory_pushButton_clicked() {
    if (!viewitemsintheinventory) {
        viewitemsintheinventory = new view_items_in_the_inventory_Form();
        viewitemsintheinventory->setAttribute(Qt::WA_DeleteOnClose);
    }

    ui.scrollArea->takeWidget();
    ui.scrollArea->setWidget(wrapInCenteredContainer(viewitemsintheinventory));

    viewitemsintheinventory->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    if (addintoinventory) {
        delete addintoinventory;
        addintoinventory = nullptr;
    } else if (viewcreatedbatches) {
        delete viewcreatedbatches;
        viewcreatedbatches = nullptr;
    } else if (select_surgery) {
        delete select_surgery;
        select_surgery = nullptr;
    }

    set_active_button(ui.check_items_in_the_inventory_pushButton);
}*/