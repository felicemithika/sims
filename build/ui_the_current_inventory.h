/********************************************************************************
** Form generated from reading UI file 'the_current_inventory.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THE_CURRENT_INVENTORY_H
#define UI_THE_CURRENT_INVENTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_view_items_in_the_inventory_Form
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QTableView *the_inventory_tableView;
    QFormLayout *formLayout;
    QPushButton *print_pushButton;
    QPushButton *exit_pushButton;

    void setupUi(QWidget *view_items_in_the_inventory_Form)
    {
        if (view_items_in_the_inventory_Form->objectName().isEmpty())
            view_items_in_the_inventory_Form->setObjectName("view_items_in_the_inventory_Form");
        view_items_in_the_inventory_Form->resize(1136, 694);
        view_items_in_the_inventory_Form->setMinimumSize(QSize(1136, 694));
        view_items_in_the_inventory_Form->setMaximumSize(QSize(1136, 694));
        view_items_in_the_inventory_Form->setStyleSheet(QString::fromUtf8("Qwidget#view_items_in_the_inventory_Form {\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
""));
        verticalLayout_3 = new QVBoxLayout(view_items_in_the_inventory_Form);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(view_items_in_the_inventory_Form);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(34);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        the_inventory_tableView = new QTableView(view_items_in_the_inventory_Form);
        the_inventory_tableView->setObjectName("the_inventory_tableView");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Open Sans")});
        font1.setPointSize(11);
        the_inventory_tableView->setFont(font1);

        verticalLayout_2->addWidget(the_inventory_tableView);


        verticalLayout_3->addLayout(verticalLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignCenter);
        formLayout->setHorizontalSpacing(80);
        formLayout->setContentsMargins(10, 30, 80, 30);
        print_pushButton = new QPushButton(view_items_in_the_inventory_Form);
        print_pushButton->setObjectName("print_pushButton");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Open Sans")});
        font2.setPointSize(12);
        font2.setItalic(true);
        print_pushButton->setFont(font2);
        print_pushButton->setStyleSheet(QString::fromUtf8("QPushButton#print_pushButton {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        formLayout->setWidget(0, QFormLayout::LabelRole, print_pushButton);

        exit_pushButton = new QPushButton(view_items_in_the_inventory_Form);
        exit_pushButton->setObjectName("exit_pushButton");
        exit_pushButton->setFont(font2);
        exit_pushButton->setStyleSheet(QString::fromUtf8("QPushButton#exit_pushButton {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        formLayout->setWidget(0, QFormLayout::FieldRole, exit_pushButton);


        verticalLayout_3->addLayout(formLayout);


        retranslateUi(view_items_in_the_inventory_Form);

        QMetaObject::connectSlotsByName(view_items_in_the_inventory_Form);
    } // setupUi

    void retranslateUi(QWidget *view_items_in_the_inventory_Form)
    {
        view_items_in_the_inventory_Form->setWindowTitle(QCoreApplication::translate("view_items_in_the_inventory_Form", "The current Inventory", nullptr));
        label->setText(QCoreApplication::translate("view_items_in_the_inventory_Form", "THE INVENTORY", nullptr));
        print_pushButton->setText(QCoreApplication::translate("view_items_in_the_inventory_Form", "Print", nullptr));
        exit_pushButton->setText(QCoreApplication::translate("view_items_in_the_inventory_Form", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class view_items_in_the_inventory_Form: public Ui_view_items_in_the_inventory_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THE_CURRENT_INVENTORY_H
