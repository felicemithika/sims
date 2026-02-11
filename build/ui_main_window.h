/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralContainer;
    QHBoxLayout *horizontalLayout;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QFrame *links_frame;
    QGridLayout *gridLayout;
    QPushButton *check_items_in_the_inventory_pushButton;
    QPushButton *create_a_barcode_pushButton;
    QPushButton *add_items_into_inventory_pushButton;
    QPushButton *view_created_batches_pushButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1304, 589);
        centralContainer = new QWidget(MainWindow);
        centralContainer->setObjectName("centralContainer");
        horizontalLayout = new QHBoxLayout(centralContainer);
        horizontalLayout->setObjectName("horizontalLayout");
        centralWidget = new QWidget(centralContainer);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName("verticalLayout");
        links_frame = new QFrame(centralWidget);
        links_frame->setObjectName("links_frame");
        links_frame->setFrameShape(QFrame::StyledPanel);
        links_frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(links_frame);
        gridLayout->setObjectName("gridLayout");
        check_items_in_the_inventory_pushButton = new QPushButton(links_frame);
        check_items_in_the_inventory_pushButton->setObjectName("check_items_in_the_inventory_pushButton");
        check_items_in_the_inventory_pushButton->setFlat(true);

        gridLayout->addWidget(check_items_in_the_inventory_pushButton, 0, 3, 1, 1);

        create_a_barcode_pushButton = new QPushButton(links_frame);
        create_a_barcode_pushButton->setObjectName("create_a_barcode_pushButton");
        create_a_barcode_pushButton->setFlat(true);

        gridLayout->addWidget(create_a_barcode_pushButton, 0, 0, 1, 1);

        add_items_into_inventory_pushButton = new QPushButton(links_frame);
        add_items_into_inventory_pushButton->setObjectName("add_items_into_inventory_pushButton");
        add_items_into_inventory_pushButton->setFlat(true);

        gridLayout->addWidget(add_items_into_inventory_pushButton, 0, 1, 1, 1);

        view_created_batches_pushButton = new QPushButton(links_frame);
        view_created_batches_pushButton->setObjectName("view_created_batches_pushButton");
        view_created_batches_pushButton->setFlat(true);

        gridLayout->addWidget(view_created_batches_pushButton, 0, 2, 1, 1);


        verticalLayout->addWidget(links_frame);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setFrameShape(QFrame::WinPanel);
        scrollArea->setFrameShadow(QFrame::Sunken);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1268, 464));
        scrollAreaWidgetContents->setLayoutDirection(Qt::LeftToRight);
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        horizontalLayout->addWidget(centralWidget);

        MainWindow->setCentralWidget(centralContainer);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1304, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        check_items_in_the_inventory_pushButton->setText(QCoreApplication::translate("MainWindow", "Check items inside the inventory", nullptr));
        create_a_barcode_pushButton->setText(QCoreApplication::translate("MainWindow", "Create a Barcode", nullptr));
        add_items_into_inventory_pushButton->setText(QCoreApplication::translate("MainWindow", "add items into the inventory", nullptr));
        view_created_batches_pushButton->setText(QCoreApplication::translate("MainWindow", "View created batches", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
