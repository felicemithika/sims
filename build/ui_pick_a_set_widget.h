/********************************************************************************
** Form generated from reading UI file 'pick_a_set_widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICK_A_SET_WIDGET_H
#define UI_PICK_A_SET_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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

class Ui_pick_a_set_widget
{
public:
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout;
    QLabel *batch_code_label;
    QLineEdit *batch_code_lineEdit;
    QFormLayout *formLayout_2;
    QLabel *type_of_surgery_label;
    QLineEdit *type_of_surgery_lineEdit;
    QGridLayout *gridLayout;
    QLineEdit *patient_name_lineEdit;
    QLineEdit *patient_phone_no_lineEdit;
    QLabel *patient_phone_no_label;
    QLabel *patient_name_label;
    QLabel *patient_other_phone_no_label;
    QLineEdit *patient_other_phone_no_lineEdit;
    QGridLayout *gridLayout_2;
    QLineEdit *next_of_kins_phone_no_lineEdit;
    QLabel *next_of_kins_phone_no_label;
    QLabel *next_of_kins_name_label;
    QLineEdit *next_of_kins_name_lineEdit;
    QLabel *next_of_kins_other_phone_no_label;
    QLineEdit *next_of_kins_other_phone_no_lineEdit;
    QGridLayout *gridLayout_3;
    QComboBox *theatre_name_comboBox;
    QLabel *theatre_label;
    QLabel *issued_to_label;
    QLineEdit *issued_to_lineEdit;
    QLabel *issued_by_label;
    QLineEdit *issued_by_lineEdit;
    QLabel *date_and_time_picked_label;
    QLineEdit *date_and_time_picked_lineEdit;
    QFormLayout *formLayout_3;
    QLabel *select_items_label;
    QPushButton *plus_pushButton;
    QVBoxLayout *verticalLayout;
    QLabel *information_label;
    QVBoxLayout *verticalLayout_2;
    QTableView *selected_items_tableView;
    QFormLayout *formLayout_4;
    QPushButton *done_pushButton;
    QPushButton *exit_pushButton;

    void setupUi(QWidget *pick_a_set_widget)
    {
        if (pick_a_set_widget->objectName().isEmpty())
            pick_a_set_widget->setObjectName("pick_a_set_widget");
        pick_a_set_widget->setWindowModality(Qt::WindowModality::ApplicationModal);
        pick_a_set_widget->resize(854, 690);
        pick_a_set_widget->setStyleSheet(QString::fromUtf8("QWidget#pick_a_set_widget {\n"
"	background-color: rgb(0, 0, 0);\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(pick_a_set_widget);
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName("verticalLayout_3");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignmentFlag::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignmentFlag::AlignCenter);
        batch_code_label = new QLabel(pick_a_set_widget);
        batch_code_label->setObjectName("batch_code_label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Open Sans")});
        font.setPointSize(11);
        batch_code_label->setFont(font);
        batch_code_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, batch_code_label);

        batch_code_lineEdit = new QLineEdit(pick_a_set_widget);
        batch_code_lineEdit->setObjectName("batch_code_lineEdit");
        batch_code_lineEdit->setEnabled(false);
        batch_code_lineEdit->setMaximumSize(QSize(421, 31));
        batch_code_lineEdit->setFont(font);
        batch_code_lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, batch_code_lineEdit);


        verticalLayout_3->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setLabelAlignment(Qt::AlignmentFlag::AlignCenter);
        formLayout_2->setFormAlignment(Qt::AlignmentFlag::AlignCenter);
        type_of_surgery_label = new QLabel(pick_a_set_widget);
        type_of_surgery_label->setObjectName("type_of_surgery_label");
        type_of_surgery_label->setFont(font);
        type_of_surgery_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, type_of_surgery_label);

        type_of_surgery_lineEdit = new QLineEdit(pick_a_set_widget);
        type_of_surgery_lineEdit->setObjectName("type_of_surgery_lineEdit");
        type_of_surgery_lineEdit->setEnabled(false);
        type_of_surgery_lineEdit->setMaximumSize(QSize(671, 31));
        type_of_surgery_lineEdit->setFont(font);
        type_of_surgery_lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, type_of_surgery_lineEdit);


        verticalLayout_3->addLayout(formLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(20);
        patient_name_lineEdit = new QLineEdit(pick_a_set_widget);
        patient_name_lineEdit->setObjectName("patient_name_lineEdit");
        patient_name_lineEdit->setMaximumSize(QSize(421, 31));
        patient_name_lineEdit->setFont(font);
        patient_name_lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(patient_name_lineEdit, 0, 1, 1, 1);

        patient_phone_no_lineEdit = new QLineEdit(pick_a_set_widget);
        patient_phone_no_lineEdit->setObjectName("patient_phone_no_lineEdit");
        patient_phone_no_lineEdit->setMaximumSize(QSize(421, 31));
        patient_phone_no_lineEdit->setFont(font);
        patient_phone_no_lineEdit->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly);
        patient_phone_no_lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(patient_phone_no_lineEdit, 0, 3, 1, 1);

        patient_phone_no_label = new QLabel(pick_a_set_widget);
        patient_phone_no_label->setObjectName("patient_phone_no_label");
        patient_phone_no_label->setFont(font);
        patient_phone_no_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(patient_phone_no_label, 0, 2, 1, 1);

        patient_name_label = new QLabel(pick_a_set_widget);
        patient_name_label->setObjectName("patient_name_label");
        patient_name_label->setFont(font);
        patient_name_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(patient_name_label, 0, 0, 1, 1);

        patient_other_phone_no_label = new QLabel(pick_a_set_widget);
        patient_other_phone_no_label->setObjectName("patient_other_phone_no_label");
        patient_other_phone_no_label->setFont(font);
        patient_other_phone_no_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(patient_other_phone_no_label, 1, 2, 1, 1);

        patient_other_phone_no_lineEdit = new QLineEdit(pick_a_set_widget);
        patient_other_phone_no_lineEdit->setObjectName("patient_other_phone_no_lineEdit");
        patient_other_phone_no_lineEdit->setMaximumSize(QSize(421, 31));
        patient_other_phone_no_lineEdit->setFont(font);
        patient_other_phone_no_lineEdit->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly);
        patient_other_phone_no_lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(patient_other_phone_no_lineEdit, 1, 3, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setVerticalSpacing(20);
        next_of_kins_phone_no_lineEdit = new QLineEdit(pick_a_set_widget);
        next_of_kins_phone_no_lineEdit->setObjectName("next_of_kins_phone_no_lineEdit");
        next_of_kins_phone_no_lineEdit->setMaximumSize(QSize(421, 31));
        next_of_kins_phone_no_lineEdit->setFont(font);
        next_of_kins_phone_no_lineEdit->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly);
        next_of_kins_phone_no_lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(next_of_kins_phone_no_lineEdit, 0, 3, 1, 1);

        next_of_kins_phone_no_label = new QLabel(pick_a_set_widget);
        next_of_kins_phone_no_label->setObjectName("next_of_kins_phone_no_label");
        next_of_kins_phone_no_label->setFont(font);
        next_of_kins_phone_no_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_2->addWidget(next_of_kins_phone_no_label, 0, 2, 1, 1);

        next_of_kins_name_label = new QLabel(pick_a_set_widget);
        next_of_kins_name_label->setObjectName("next_of_kins_name_label");
        next_of_kins_name_label->setFont(font);
        next_of_kins_name_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_2->addWidget(next_of_kins_name_label, 0, 0, 1, 1);

        next_of_kins_name_lineEdit = new QLineEdit(pick_a_set_widget);
        next_of_kins_name_lineEdit->setObjectName("next_of_kins_name_lineEdit");
        next_of_kins_name_lineEdit->setMaximumSize(QSize(421, 31));
        next_of_kins_name_lineEdit->setFont(font);
        next_of_kins_name_lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(next_of_kins_name_lineEdit, 0, 1, 1, 1);

        next_of_kins_other_phone_no_label = new QLabel(pick_a_set_widget);
        next_of_kins_other_phone_no_label->setObjectName("next_of_kins_other_phone_no_label");
        next_of_kins_other_phone_no_label->setFont(font);
        next_of_kins_other_phone_no_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_2->addWidget(next_of_kins_other_phone_no_label, 1, 2, 1, 1);

        next_of_kins_other_phone_no_lineEdit = new QLineEdit(pick_a_set_widget);
        next_of_kins_other_phone_no_lineEdit->setObjectName("next_of_kins_other_phone_no_lineEdit");
        next_of_kins_other_phone_no_lineEdit->setMaximumSize(QSize(421, 31));
        next_of_kins_other_phone_no_lineEdit->setFont(font);
        next_of_kins_other_phone_no_lineEdit->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly);
        next_of_kins_other_phone_no_lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(next_of_kins_other_phone_no_lineEdit, 1, 3, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setVerticalSpacing(20);
        theatre_name_comboBox = new QComboBox(pick_a_set_widget);
        theatre_name_comboBox->setObjectName("theatre_name_comboBox");

        gridLayout_3->addWidget(theatre_name_comboBox, 0, 1, 1, 1);

        theatre_label = new QLabel(pick_a_set_widget);
        theatre_label->setObjectName("theatre_label");
        theatre_label->setMaximumSize(QSize(70, 31));

        gridLayout_3->addWidget(theatre_label, 0, 0, 1, 1);

        issued_to_label = new QLabel(pick_a_set_widget);
        issued_to_label->setObjectName("issued_to_label");
        issued_to_label->setFont(font);
        issued_to_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_3->addWidget(issued_to_label, 0, 2, 1, 1);

        issued_to_lineEdit = new QLineEdit(pick_a_set_widget);
        issued_to_lineEdit->setObjectName("issued_to_lineEdit");
        issued_to_lineEdit->setMaximumSize(QSize(300, 31));
        issued_to_lineEdit->setFont(font);
        issued_to_lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(issued_to_lineEdit, 0, 3, 1, 1);

        issued_by_label = new QLabel(pick_a_set_widget);
        issued_by_label->setObjectName("issued_by_label");
        issued_by_label->setFont(font);
        issued_by_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_3->addWidget(issued_by_label, 1, 0, 1, 1);

        issued_by_lineEdit = new QLineEdit(pick_a_set_widget);
        issued_by_lineEdit->setObjectName("issued_by_lineEdit");
        issued_by_lineEdit->setEnabled(false);
        issued_by_lineEdit->setMaximumSize(QSize(421, 31));
        issued_by_lineEdit->setFont(font);
        issued_by_lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(issued_by_lineEdit, 1, 1, 1, 1);

        date_and_time_picked_label = new QLabel(pick_a_set_widget);
        date_and_time_picked_label->setObjectName("date_and_time_picked_label");
        date_and_time_picked_label->setFont(font);
        date_and_time_picked_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_3->addWidget(date_and_time_picked_label, 1, 2, 1, 1);

        date_and_time_picked_lineEdit = new QLineEdit(pick_a_set_widget);
        date_and_time_picked_lineEdit->setObjectName("date_and_time_picked_lineEdit");
        date_and_time_picked_lineEdit->setEnabled(false);
        date_and_time_picked_lineEdit->setMaximumSize(QSize(421, 31));
        date_and_time_picked_lineEdit->setFont(font);
        date_and_time_picked_lineEdit->setInputMethodHints(Qt::InputMethodHint::ImhDate);
        date_and_time_picked_lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(date_and_time_picked_lineEdit, 1, 3, 1, 1);


        verticalLayout_3->addLayout(gridLayout_3);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setLabelAlignment(Qt::AlignmentFlag::AlignCenter);
        formLayout_3->setFormAlignment(Qt::AlignmentFlag::AlignCenter);
        select_items_label = new QLabel(pick_a_set_widget);
        select_items_label->setObjectName("select_items_label");
        select_items_label->setFont(font);
        select_items_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, select_items_label);

        plus_pushButton = new QPushButton(pick_a_set_widget);
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

        formLayout_3->setWidget(0, QFormLayout::FieldRole, plus_pushButton);


        verticalLayout_3->addLayout(formLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        information_label = new QLabel(pick_a_set_widget);
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
        verticalLayout_2->setContentsMargins(15, -1, -1, -1);
        selected_items_tableView = new QTableView(pick_a_set_widget);
        selected_items_tableView->setObjectName("selected_items_tableView");
        selected_items_tableView->setMinimumSize(QSize(811, 192));
        selected_items_tableView->setMaximumSize(QSize(811, 192));
        selected_items_tableView->setFont(font);
        selected_items_tableView->setSortingEnabled(true);
        selected_items_tableView->horizontalHeader()->setMinimumSectionSize(90);
        selected_items_tableView->horizontalHeader()->setStretchLastSection(false);

        verticalLayout_2->addWidget(selected_items_tableView);


        verticalLayout_3->addLayout(verticalLayout_2);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        formLayout_4->setLabelAlignment(Qt::AlignmentFlag::AlignCenter);
        formLayout_4->setFormAlignment(Qt::AlignmentFlag::AlignCenter);
        formLayout_4->setHorizontalSpacing(50);
        formLayout_4->setContentsMargins(0, -1, 0, -1);
        done_pushButton = new QPushButton(pick_a_set_widget);
        done_pushButton->setObjectName("done_pushButton");
        done_pushButton->setMinimumSize(QSize(91, 31));
        done_pushButton->setMaximumSize(QSize(91, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Open Sans")});
        font3.setPointSize(11);
        font3.setItalic(true);
        done_pushButton->setFont(font3);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, done_pushButton);

        exit_pushButton = new QPushButton(pick_a_set_widget);
        exit_pushButton->setObjectName("exit_pushButton");
        exit_pushButton->setMinimumSize(QSize(91, 31));
        exit_pushButton->setMaximumSize(QSize(91, 31));
        exit_pushButton->setFont(font3);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, exit_pushButton);


        verticalLayout_3->addLayout(formLayout_4);


        retranslateUi(pick_a_set_widget);

        QMetaObject::connectSlotsByName(pick_a_set_widget);
    } // setupUi

    void retranslateUi(QWidget *pick_a_set_widget)
    {
        pick_a_set_widget->setWindowTitle(QCoreApplication::translate("pick_a_set_widget", "Patient's surgical details.", nullptr));
        batch_code_label->setText(QCoreApplication::translate("pick_a_set_widget", "Batch Code:", nullptr));
        type_of_surgery_label->setText(QCoreApplication::translate("pick_a_set_widget", "Type of surgery:", nullptr));
        patient_phone_no_label->setText(QCoreApplication::translate("pick_a_set_widget", "Patient's phone no:", nullptr));
        patient_name_label->setText(QCoreApplication::translate("pick_a_set_widget", "Patient's name:", nullptr));
        patient_other_phone_no_label->setText(QCoreApplication::translate("pick_a_set_widget", "Patient's other phone no:", nullptr));
        next_of_kins_phone_no_label->setText(QCoreApplication::translate("pick_a_set_widget", "Next of kin's phone no:", nullptr));
        next_of_kins_name_label->setText(QCoreApplication::translate("pick_a_set_widget", "Next of kin's name:", nullptr));
        next_of_kins_other_phone_no_label->setText(QCoreApplication::translate("pick_a_set_widget", "Next of kin's other phone no:", nullptr));
        theatre_label->setText(QCoreApplication::translate("pick_a_set_widget", "Theatre:", nullptr));
        issued_to_label->setText(QCoreApplication::translate("pick_a_set_widget", "Issued To:", nullptr));
        issued_by_label->setText(QCoreApplication::translate("pick_a_set_widget", "Issued By:", nullptr));
        date_and_time_picked_label->setText(QCoreApplication::translate("pick_a_set_widget", "Date and time picked:", nullptr));
        select_items_label->setText(QCoreApplication::translate("pick_a_set_widget", "Select items:", nullptr));
        plus_pushButton->setText(QCoreApplication::translate("pick_a_set_widget", "+", nullptr));
        information_label->setText(QCoreApplication::translate("pick_a_set_widget", "NB: Check to confirm the items that are going into surgery here:", nullptr));
        done_pushButton->setText(QCoreApplication::translate("pick_a_set_widget", "Done", nullptr));
        exit_pushButton->setText(QCoreApplication::translate("pick_a_set_widget", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pick_a_set_widget: public Ui_pick_a_set_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICK_A_SET_WIDGET_H
