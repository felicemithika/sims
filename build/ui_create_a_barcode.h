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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_create_a_barcode_widget
{
public:
    QLabel *batch_code_label;
    QLineEdit *batch_code_lineEdit;
    QLabel *issued_by_label;
    QLineEdit *issued_by_lineEdit;
    QLabel *issued_to_label;
    QLineEdit *issued_to_lineEdit;
    QLabel *date_picked_label;
    QLineEdit *date_picked_lineEdit;
    QLabel *time_picked_label;
    QLineEdit *time_picked_lineEdit;
    QLabel *type_of_surgery_label;
    QLineEdit *type_of_surgery_lineEdit;
    QLabel *patient_name_label;
    QLineEdit *patient_name_lineEdit;
    QLabel *patient_phone_no_label;
    QLineEdit *patient_phone_no_lineEdit;
    QLabel *patient_other_phone_no_label;
    QLineEdit *patient_other_phone_no_lineEdit;
    QLabel *next_of_kins_name_label;
    QLineEdit *next_of_kins_name_lineEdit;
    QLabel *next_of_kins_phone_no_label;
    QLineEdit *next_of_kins_phone_no_lineEdit;
    QLabel *next_of_kins_other_phone_no_label;
    QLineEdit *next_of_kins_other_phone_no_lineEdit;
    QLabel *select_items_label;
    QPushButton *plus_pushButton;
    QTableView *selected_items_tableView;
    QLabel *information_label;
    QPushButton *create_barcode_pushButton;
    QPushButton *exit_pushButton;
    QGridLayout *gridLayout;

    void setupUi(QWidget *create_a_barcode_widget)
    {
        if (create_a_barcode_widget->objectName().isEmpty())
            create_a_barcode_widget->setObjectName("create_a_barcode_widget");
        create_a_barcode_widget->resize(884, 812);
        create_a_barcode_widget->setMinimumSize(QSize(884, 812));
        create_a_barcode_widget->setMaximumSize(QSize(884, 812));
        create_a_barcode_widget->setStyleSheet(QString::fromUtf8("QWidget#create_a_barcode_widget {\n"
"	background-color: rgb(0, 0, 0);\n"
"}"));
        batch_code_label = new QLabel(create_a_barcode_widget);
        batch_code_label->setObjectName("batch_code_label");
        batch_code_label->setGeometry(QRect(150, 30, 91, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Open Sans")});
        font.setPointSize(11);
        batch_code_label->setFont(font);
        batch_code_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        batch_code_lineEdit = new QLineEdit(create_a_barcode_widget);
        batch_code_lineEdit->setObjectName("batch_code_lineEdit");
        batch_code_lineEdit->setEnabled(false);
        batch_code_lineEdit->setGeometry(QRect(250, 40, 421, 31));
        batch_code_lineEdit->setMaximumSize(QSize(421, 31));
        batch_code_lineEdit->setFont(font);
        issued_by_label = new QLabel(create_a_barcode_widget);
        issued_by_label->setObjectName("issued_by_label");
        issued_by_label->setGeometry(QRect(10, 80, 91, 31));
        issued_by_label->setFont(font);
        issued_by_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        issued_by_lineEdit = new QLineEdit(create_a_barcode_widget);
        issued_by_lineEdit->setObjectName("issued_by_lineEdit");
        issued_by_lineEdit->setEnabled(false);
        issued_by_lineEdit->setGeometry(QRect(110, 90, 291, 31));
        issued_by_lineEdit->setMaximumSize(QSize(421, 31));
        issued_by_lineEdit->setFont(font);
        issued_to_label = new QLabel(create_a_barcode_widget);
        issued_to_label->setObjectName("issued_to_label");
        issued_to_label->setGeometry(QRect(420, 80, 91, 31));
        issued_to_label->setFont(font);
        issued_to_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        issued_to_lineEdit = new QLineEdit(create_a_barcode_widget);
        issued_to_lineEdit->setObjectName("issued_to_lineEdit");
        issued_to_lineEdit->setGeometry(QRect(520, 90, 291, 31));
        issued_to_lineEdit->setMaximumSize(QSize(421, 31));
        issued_to_lineEdit->setFont(font);
        date_picked_label = new QLabel(create_a_barcode_widget);
        date_picked_label->setObjectName("date_picked_label");
        date_picked_label->setGeometry(QRect(10, 140, 181, 31));
        date_picked_label->setFont(font);
        date_picked_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        date_picked_lineEdit = new QLineEdit(create_a_barcode_widget);
        date_picked_lineEdit->setObjectName("date_picked_lineEdit");
        date_picked_lineEdit->setEnabled(false);
        date_picked_lineEdit->setGeometry(QRect(200, 150, 161, 31));
        date_picked_lineEdit->setMaximumSize(QSize(421, 31));
        date_picked_lineEdit->setFont(font);
        date_picked_lineEdit->setInputMethodHints(Qt::InputMethodHint::ImhDate);
        time_picked_label = new QLabel(create_a_barcode_widget);
        time_picked_label->setObjectName("time_picked_label");
        time_picked_label->setGeometry(QRect(380, 140, 181, 31));
        time_picked_label->setFont(font);
        time_picked_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        time_picked_lineEdit = new QLineEdit(create_a_barcode_widget);
        time_picked_lineEdit->setObjectName("time_picked_lineEdit");
        time_picked_lineEdit->setEnabled(false);
        time_picked_lineEdit->setGeometry(QRect(570, 150, 161, 31));
        time_picked_lineEdit->setMaximumSize(QSize(421, 31));
        time_picked_lineEdit->setFont(font);
        time_picked_lineEdit->setInputMethodHints(Qt::InputMethodHint::ImhTime);
        type_of_surgery_label = new QLabel(create_a_barcode_widget);
        type_of_surgery_label->setObjectName("type_of_surgery_label");
        type_of_surgery_label->setGeometry(QRect(110, 190, 131, 31));
        type_of_surgery_label->setFont(font);
        type_of_surgery_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        type_of_surgery_lineEdit = new QLineEdit(create_a_barcode_widget);
        type_of_surgery_lineEdit->setObjectName("type_of_surgery_lineEdit");
        type_of_surgery_lineEdit->setGeometry(QRect(250, 200, 421, 31));
        type_of_surgery_lineEdit->setMaximumSize(QSize(421, 31));
        type_of_surgery_lineEdit->setFont(font);
        patient_name_label = new QLabel(create_a_barcode_widget);
        patient_name_label->setObjectName("patient_name_label");
        patient_name_label->setGeometry(QRect(10, 240, 111, 31));
        patient_name_label->setFont(font);
        patient_name_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        patient_name_lineEdit = new QLineEdit(create_a_barcode_widget);
        patient_name_lineEdit->setObjectName("patient_name_lineEdit");
        patient_name_lineEdit->setGeometry(QRect(130, 250, 291, 31));
        patient_name_lineEdit->setMaximumSize(QSize(421, 31));
        patient_name_lineEdit->setFont(font);
        patient_phone_no_label = new QLabel(create_a_barcode_widget);
        patient_phone_no_label->setObjectName("patient_phone_no_label");
        patient_phone_no_label->setGeometry(QRect(430, 240, 141, 31));
        patient_phone_no_label->setFont(font);
        patient_phone_no_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        patient_phone_no_lineEdit = new QLineEdit(create_a_barcode_widget);
        patient_phone_no_lineEdit->setObjectName("patient_phone_no_lineEdit");
        patient_phone_no_lineEdit->setGeometry(QRect(580, 250, 161, 31));
        patient_phone_no_lineEdit->setMaximumSize(QSize(421, 31));
        patient_phone_no_lineEdit->setFont(font);
        patient_phone_no_lineEdit->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly);
        patient_other_phone_no_label = new QLabel(create_a_barcode_widget);
        patient_other_phone_no_label->setObjectName("patient_other_phone_no_label");
        patient_other_phone_no_label->setGeometry(QRect(370, 290, 201, 31));
        patient_other_phone_no_label->setFont(font);
        patient_other_phone_no_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        patient_other_phone_no_lineEdit = new QLineEdit(create_a_barcode_widget);
        patient_other_phone_no_lineEdit->setObjectName("patient_other_phone_no_lineEdit");
        patient_other_phone_no_lineEdit->setGeometry(QRect(580, 300, 161, 31));
        patient_other_phone_no_lineEdit->setMaximumSize(QSize(421, 31));
        patient_other_phone_no_lineEdit->setFont(font);
        patient_other_phone_no_lineEdit->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly);
        next_of_kins_name_label = new QLabel(create_a_barcode_widget);
        next_of_kins_name_label->setObjectName("next_of_kins_name_label");
        next_of_kins_name_label->setGeometry(QRect(10, 340, 141, 31));
        next_of_kins_name_label->setFont(font);
        next_of_kins_name_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        next_of_kins_name_lineEdit = new QLineEdit(create_a_barcode_widget);
        next_of_kins_name_lineEdit->setObjectName("next_of_kins_name_lineEdit");
        next_of_kins_name_lineEdit->setGeometry(QRect(160, 350, 291, 31));
        next_of_kins_name_lineEdit->setMaximumSize(QSize(421, 31));
        next_of_kins_name_lineEdit->setFont(font);
        next_of_kins_phone_no_label = new QLabel(create_a_barcode_widget);
        next_of_kins_phone_no_label->setObjectName("next_of_kins_phone_no_label");
        next_of_kins_phone_no_label->setGeometry(QRect(470, 340, 161, 31));
        next_of_kins_phone_no_label->setFont(font);
        next_of_kins_phone_no_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        next_of_kins_phone_no_lineEdit = new QLineEdit(create_a_barcode_widget);
        next_of_kins_phone_no_lineEdit->setObjectName("next_of_kins_phone_no_lineEdit");
        next_of_kins_phone_no_lineEdit->setGeometry(QRect(640, 350, 161, 31));
        next_of_kins_phone_no_lineEdit->setMaximumSize(QSize(421, 31));
        next_of_kins_phone_no_lineEdit->setFont(font);
        next_of_kins_phone_no_lineEdit->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly);
        next_of_kins_other_phone_no_label = new QLabel(create_a_barcode_widget);
        next_of_kins_other_phone_no_label->setObjectName("next_of_kins_other_phone_no_label");
        next_of_kins_other_phone_no_label->setGeometry(QRect(430, 400, 201, 31));
        next_of_kins_other_phone_no_label->setFont(font);
        next_of_kins_other_phone_no_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        next_of_kins_other_phone_no_lineEdit = new QLineEdit(create_a_barcode_widget);
        next_of_kins_other_phone_no_lineEdit->setObjectName("next_of_kins_other_phone_no_lineEdit");
        next_of_kins_other_phone_no_lineEdit->setGeometry(QRect(640, 410, 161, 31));
        next_of_kins_other_phone_no_lineEdit->setMaximumSize(QSize(421, 31));
        next_of_kins_other_phone_no_lineEdit->setFont(font);
        next_of_kins_other_phone_no_lineEdit->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly);
        select_items_label = new QLabel(create_a_barcode_widget);
        select_items_label->setObjectName("select_items_label");
        select_items_label->setGeometry(QRect(320, 450, 91, 41));
        select_items_label->setFont(font);
        select_items_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        plus_pushButton = new QPushButton(create_a_barcode_widget);
        plus_pushButton->setObjectName("plus_pushButton");
        plus_pushButton->setGeometry(QRect(430, 460, 31, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Open Sans")});
        font1.setPointSize(17);
        font1.setBold(true);
        plus_pushButton->setFont(font1);
        plus_pushButton->setStyleSheet(QString::fromUtf8("QPushButton#plus_pushButton {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        selected_items_tableView = new QTableView(create_a_barcode_widget);
        selected_items_tableView->setObjectName("selected_items_tableView");
        selected_items_tableView->setGeometry(QRect(30, 530, 811, 192));
        selected_items_tableView->setFont(font);
        selected_items_tableView->setSortingEnabled(true);
        selected_items_tableView->horizontalHeader()->setMinimumSectionSize(90);
        selected_items_tableView->horizontalHeader()->setStretchLastSection(false);
        information_label = new QLabel(create_a_barcode_widget);
        information_label->setObjectName("information_label");
        information_label->setGeometry(QRect(10, 495, 811, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Open Sans")});
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setItalic(true);
        information_label->setFont(font2);
        information_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        create_barcode_pushButton = new QPushButton(create_a_barcode_widget);
        create_barcode_pushButton->setObjectName("create_barcode_pushButton");
        create_barcode_pushButton->setGeometry(QRect(230, 760, 91, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Open Sans")});
        font3.setPointSize(11);
        font3.setItalic(true);
        create_barcode_pushButton->setFont(font3);
        exit_pushButton = new QPushButton(create_a_barcode_widget);
        exit_pushButton->setObjectName("exit_pushButton");
        exit_pushButton->setGeometry(QRect(590, 760, 91, 31));
        exit_pushButton->setFont(font3);
        gridLayout = new QGridLayout(create_a_barcode_widget);
        gridLayout->setObjectName("gridLayout");

        retranslateUi(create_a_barcode_widget);

        QMetaObject::connectSlotsByName(create_a_barcode_widget);
    } // setupUi

    void retranslateUi(QWidget *create_a_barcode_widget)
    {
        create_a_barcode_widget->setWindowTitle(QCoreApplication::translate("create_a_barcode_widget", "Create a barcode", nullptr));
        batch_code_label->setText(QCoreApplication::translate("create_a_barcode_widget", "Batch Code:", nullptr));
        issued_by_label->setText(QCoreApplication::translate("create_a_barcode_widget", "Issued By:", nullptr));
        issued_to_label->setText(QCoreApplication::translate("create_a_barcode_widget", "Issued To:", nullptr));
        date_picked_label->setText(QCoreApplication::translate("create_a_barcode_widget", "Date the item was picked:", nullptr));
        time_picked_label->setText(QCoreApplication::translate("create_a_barcode_widget", "Time the item was picked:", nullptr));
        type_of_surgery_label->setText(QCoreApplication::translate("create_a_barcode_widget", "Type of surgery:", nullptr));
        patient_name_label->setText(QCoreApplication::translate("create_a_barcode_widget", "Patient's name:", nullptr));
        patient_phone_no_label->setText(QCoreApplication::translate("create_a_barcode_widget", "Patient's phone no:", nullptr));
        patient_other_phone_no_label->setText(QCoreApplication::translate("create_a_barcode_widget", "Patient's other phone no:", nullptr));
        next_of_kins_name_label->setText(QCoreApplication::translate("create_a_barcode_widget", "Next of kin's name:", nullptr));
        next_of_kins_phone_no_label->setText(QCoreApplication::translate("create_a_barcode_widget", "Next of kin's phone no:", nullptr));
        next_of_kins_other_phone_no_label->setText(QCoreApplication::translate("create_a_barcode_widget", "Next of kin's other phone no:", nullptr));
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
