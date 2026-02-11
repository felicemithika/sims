/********************************************************************************
** Form generated from reading UI file 'items_inside_a_batch.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMS_INSIDE_A_BATCH_H
#define UI_ITEMS_INSIDE_A_BATCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_view_items_in_a_batch_Form
{
public:
    QLabel *batch_details_label;
    QTableView *item_inside_the_batch_tableView;
    QPushButton *print_pushButton;
    QPushButton *exit_pushButton;

    void setupUi(QWidget *view_items_in_a_batch_Form)
    {
        if (view_items_in_a_batch_Form->objectName().isEmpty())
            view_items_in_a_batch_Form->setObjectName("view_items_in_a_batch_Form");
        view_items_in_a_batch_Form->resize(748, 485);
        view_items_in_a_batch_Form->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        batch_details_label = new QLabel(view_items_in_a_batch_Form);
        batch_details_label->setObjectName("batch_details_label");
        batch_details_label->setGeometry(QRect(10, 10, 731, 101));
        QFont font;
        font.setFamilies({QString::fromUtf8("Open Sans")});
        font.setPointSize(11);
        font.setItalic(true);
        batch_details_label->setFont(font);
        item_inside_the_batch_tableView = new QTableView(view_items_in_a_batch_Form);
        item_inside_the_batch_tableView->setObjectName("item_inside_the_batch_tableView");
        item_inside_the_batch_tableView->setGeometry(QRect(10, 150, 721, 231));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Open Sans")});
        font1.setPointSize(11);
        item_inside_the_batch_tableView->setFont(font1);
        print_pushButton = new QPushButton(view_items_in_a_batch_Form);
        print_pushButton->setObjectName("print_pushButton");
        print_pushButton->setGeometry(QRect(150, 420, 111, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Open Sans")});
        font2.setPointSize(12);
        font2.setItalic(true);
        print_pushButton->setFont(font2);
        print_pushButton->setStyleSheet(QString::fromUtf8("QPushButton#print_pushButton {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        exit_pushButton = new QPushButton(view_items_in_a_batch_Form);
        exit_pushButton->setObjectName("exit_pushButton");
        exit_pushButton->setGeometry(QRect(450, 420, 111, 31));
        exit_pushButton->setFont(font2);
        exit_pushButton->setStyleSheet(QString::fromUtf8("QPushButton#exit_pushButton {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        retranslateUi(view_items_in_a_batch_Form);

        QMetaObject::connectSlotsByName(view_items_in_a_batch_Form);
    } // setupUi

    void retranslateUi(QWidget *view_items_in_a_batch_Form)
    {
        view_items_in_a_batch_Form->setWindowTitle(QCoreApplication::translate("view_items_in_a_batch_Form", "Items in the batch", nullptr));
        batch_details_label->setText(QCoreApplication::translate("view_items_in_a_batch_Form", "Here all the columns will be here ie, batch code, date an time issued by and to etc (TODO later)", nullptr));
        print_pushButton->setText(QCoreApplication::translate("view_items_in_a_batch_Form", "Print", nullptr));
        exit_pushButton->setText(QCoreApplication::translate("view_items_in_a_batch_Form", "View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class view_items_in_a_batch_Form: public Ui_view_items_in_a_batch_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMS_INSIDE_A_BATCH_H
