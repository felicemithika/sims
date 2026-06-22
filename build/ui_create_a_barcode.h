/********************************************************************************
** Form generated from reading UI file 'create_a_barcode.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_A_BARCODE_H
#define UI_CREATE_A_BARCODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_create_a_barcode_widget
{
public:
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout_3;
    QLabel *batch_code_label;
    QLineEdit *batch_code_lineEdit;
    QFormLayout *formLayout_2;
    QLabel *type_of_surgery_label;
    QLineEdit *type_of_surgery_lineEdit;
    QGridLayout *gridLayout;
    QLabel *created_by_label;
    QLineEdit *created_by_lineEdit;
    QLabel *date_created_label;
    QLineEdit *date_created_lineEdit;
    QLabel *time_created_label;
    QLineEdit *time_created_lineEdit;
    QFormLayout *formLayout_4;
    QLabel *select_items_label;
    QPushButton *plus_pushButton;
    QVBoxLayout *verticalLayout;
    QLabel *information_label;
    QVBoxLayout *verticalLayout_2;
    QTableView *selected_items_tableView;
    QFormLayout *formLayout_5;
    QPushButton *create_barcode_pushButton;
    QPushButton *exit_pushButton;

    void setupUi(QWidget *create_a_barcode_widget)
    {
        if (create_a_barcode_widget->objectName().isEmpty())
            create_a_barcode_widget->setObjectName("create_a_barcode_widget");
        create_a_barcode_widget->resize(884, 522);
        create_a_barcode_widget->setMinimumSize(QSize(0, 0));
        create_a_barcode_widget->setMaximumSize(QSize(884, 812));
        create_a_barcode_widget->setStyleSheet(QString::fromUtf8("QWidget#create_a_barcode_widget {\n"
"	background-color: rgb(0, 0, 0);\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(create_a_barcode_widget);
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setObjectName("verticalLayout_3");
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setLabelAlignment(Qt::AlignmentFlag::AlignCenter);
        formLayout_3->setFormAlignment(Qt::AlignmentFlag::AlignCenter);
        formLayout_3->setContentsMargins(-1, 5, -1, 5);
        batch_code_label = new QLabel(create_a_barcode_widget);
        batch_code_label->setObjectName("batch_code_label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Open Sans")});
        font.setPointSize(11);
        batch_code_label->setFont(font);
        batch_code_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, batch_code_label);

        batch_code_lineEdit = new QLineEdit(create_a_barcode_widget);
        batch_code_lineEdit->setObjectName("batch_code_lineEdit");
        batch_code_lineEdit->setEnabled(false);
        batch_code_lineEdit->setMaximumSize(QSize(421, 31));
        batch_code_lineEdit->setFont(font);
        batch_code_lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, batch_code_lineEdit);


        verticalLayout_3->addLayout(formLayout_3);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setLabelAlignment(Qt::AlignmentFlag::AlignCenter);
        formLayout_2->setFormAlignment(Qt::AlignmentFlag::AlignCenter);
        formLayout_2->setContentsMargins(-1, 5, -1, 5);
        type_of_surgery_label = new QLabel(create_a_barcode_widget);
        type_of_surgery_label->setObjectName("type_of_surgery_label");
        type_of_surgery_label->setFont(font);
        type_of_surgery_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, type_of_surgery_label);

        type_of_surgery_lineEdit = new QLineEdit(create_a_barcode_widget);
        type_of_surgery_lineEdit->setObjectName("type_of_surgery_lineEdit");
        type_of_surgery_lineEdit->setMaximumSize(QSize(671, 31));
        type_of_surgery_lineEdit->setFont(font);
        type_of_surgery_lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, type_of_surgery_lineEdit);


        verticalLayout_3->addLayout(formLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(20);
        created_by_label = new QLabel(create_a_barcode_widget);
        created_by_label->setObjectName("created_by_label");
        created_by_label->setFont(font);
        created_by_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(created_by_label, 0, 0, 1, 1);

        created_by_lineEdit = new QLineEdit(create_a_barcode_widget);
        created_by_lineEdit->setObjectName("created_by_lineEdit");
        created_by_lineEdit->setEnabled(false);
        created_by_lineEdit->setMaximumSize(QSize(421, 31));
        created_by_lineEdit->setFont(font);
        created_by_lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(created_by_lineEdit, 0, 1, 1, 1);

        date_created_label = new QLabel(create_a_barcode_widget);
        date_created_label->setObjectName("date_created_label");
        date_created_label->setFont(font);
        date_created_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(date_created_label, 0, 3, 1, 1);

        date_created_lineEdit = new QLineEdit(create_a_barcode_widget);
        date_created_lineEdit->setObjectName("date_created_lineEdit");
        date_created_lineEdit->setEnabled(false);
        date_created_lineEdit->setMaximumSize(QSize(421, 31));
        date_created_lineEdit->setFont(font);
        date_created_lineEdit->setInputMethodHints(Qt::InputMethodHint::ImhDate);
        date_created_lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(date_created_lineEdit, 0, 4, 1, 1);

        time_created_label = new QLabel(create_a_barcode_widget);
        time_created_label->setObjectName("time_created_label");
        time_created_label->setFont(font);
        time_created_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(time_created_label, 1, 1, 1, 1);

        time_created_lineEdit = new QLineEdit(create_a_barcode_widget);
        time_created_lineEdit->setObjectName("time_created_lineEdit");
        time_created_lineEdit->setEnabled(false);
        time_created_lineEdit->setMaximumSize(QSize(421, 31));
        time_created_lineEdit->setFont(font);
        time_created_lineEdit->setInputMethodHints(Qt::InputMethodHint::ImhTime);
        time_created_lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(time_created_lineEdit, 1, 3, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        formLayout_4->setLabelAlignment(Qt::AlignmentFlag::AlignCenter);
        formLayout_4->setFormAlignment(Qt::AlignmentFlag::AlignCenter);
        formLayout_4->setContentsMargins(-1, 5, -1, 5);
        select_items_label = new QLabel(create_a_barcode_widget);
        select_items_label->setObjectName("select_items_label");
        select_items_label->setFont(font);
        select_items_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, select_items_label);

        plus_pushButton = new QPushButton(create_a_barcode_widget);
        plus_pushButton->setObjectName("plus_pushButton");
        plus_pushButton->setMinimumSize(QSize(31, 21));
        plus_pushButton->setMaximumSize(QSize(31, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Open Sans")});
        font1.setPointSize(17);
        font1.setBold(true);
        plus_pushButton->setFont(font1);
        plus_pushButton->setStyleSheet(QString::fromUtf8("QPushButton#plus_pushButton {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, plus_pushButton);


        verticalLayout_3->addLayout(formLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        information_label = new QLabel(create_a_barcode_widget);
        information_label->setObjectName("information_label");
        information_label->setMinimumSize(QSize(0, 21));
        information_label->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Open Sans")});
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setItalic(true);
        information_label->setFont(font2);
        information_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(information_label);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(25, -1, -1, -1);
        selected_items_tableView = new QTableView(create_a_barcode_widget);
        selected_items_tableView->setObjectName("selected_items_tableView");
        selected_items_tableView->setMinimumSize(QSize(811, 192));
        selected_items_tableView->setMaximumSize(QSize(811, 192));
        selected_items_tableView->setFont(font);
        selected_items_tableView->setSortingEnabled(true);
        selected_items_tableView->horizontalHeader()->setMinimumSectionSize(90);
        selected_items_tableView->horizontalHeader()->setStretchLastSection(false);

        verticalLayout_2->addWidget(selected_items_tableView);


        verticalLayout_3->addLayout(verticalLayout_2);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName("formLayout_5");
        formLayout_5->setLabelAlignment(Qt::AlignmentFlag::AlignCenter);
        formLayout_5->setFormAlignment(Qt::AlignmentFlag::AlignCenter);
        formLayout_5->setHorizontalSpacing(50);
        formLayout_5->setContentsMargins(-1, 5, -1, 5);
        create_barcode_pushButton = new QPushButton(create_a_barcode_widget);
        create_barcode_pushButton->setObjectName("create_barcode_pushButton");
        create_barcode_pushButton->setMinimumSize(QSize(91, 31));
        create_barcode_pushButton->setMaximumSize(QSize(91, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Open Sans")});
        font3.setPointSize(11);
        font3.setItalic(true);
        create_barcode_pushButton->setFont(font3);

        formLayout_5->setWidget(0, QFormLayout::LabelRole, create_barcode_pushButton);

        exit_pushButton = new QPushButton(create_a_barcode_widget);
        exit_pushButton->setObjectName("exit_pushButton");
        exit_pushButton->setMinimumSize(QSize(91, 31));
        exit_pushButton->setMaximumSize(QSize(91, 31));
        exit_pushButton->setFont(font3);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, exit_pushButton);


        verticalLayout_3->addLayout(formLayout_5);


        retranslateUi(create_a_barcode_widget);

        QMetaObject::connectSlotsByName(create_a_barcode_widget);
    } // setupUi

    void retranslateUi(QWidget *create_a_barcode_widget)
    {
        create_a_barcode_widget->setWindowTitle(QCoreApplication::translate("create_a_barcode_widget", "Create a barcode", nullptr));
        batch_code_label->setText(QCoreApplication::translate("create_a_barcode_widget", "Batch Code:", nullptr));
        type_of_surgery_label->setText(QCoreApplication::translate("create_a_barcode_widget", "Type of surgery:", nullptr));
        type_of_surgery_lineEdit->setPlaceholderText(QCoreApplication::translate("create_a_barcode_widget", "         Use approved surgical terms \342\200\224 verify before saving\342\200\246", nullptr));
        created_by_label->setText(QCoreApplication::translate("create_a_barcode_widget", "Created By:", nullptr));
        date_created_label->setText(QCoreApplication::translate("create_a_barcode_widget", "Date created:", nullptr));
        time_created_label->setText(QCoreApplication::translate("create_a_barcode_widget", "Time created:", nullptr));
        select_items_label->setText(QCoreApplication::translate("create_a_barcode_widget", "Select items:", nullptr));
        plus_pushButton->setText(QCoreApplication::translate("create_a_barcode_widget", "+", nullptr));
        information_label->setText(QCoreApplication::translate("create_a_barcode_widget", "NB: Check to confirm the items that are going into surgery here:", nullptr));
        create_barcode_pushButton->setText(QCoreApplication::translate("create_a_barcode_widget", "Create", nullptr));
        exit_pushButton->setText(QCoreApplication::translate("create_a_barcode_widget", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class create_a_barcode_widget: public Ui_create_a_barcode_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_A_BARCODE_H
