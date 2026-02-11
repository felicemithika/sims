/********************************************************************************
** Form generated from reading UI file 'add_items_in_the_inventory.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_ITEMS_IN_THE_INVENTORY_H
#define UI_ADD_ITEMS_IN_THE_INVENTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_add_items_into_inventory_widget
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *search_by_label;
    QLineEdit *search_for_items_lineEdit;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *Name_of_item_label;
    QLineEdit *name_of_item_lineEdit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *items_count_label;
    QSpinBox *items_count_spinBox;
    QLabel *status_label;
    QComboBox *status_comboBox;
    QLabel *date_added_label;
    QLineEdit *date_added_lineEdit;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *entered_by_label;
    QLineEdit *entered_by_lineEdit;
    QLabel *category_label;
    QComboBox *category_comboBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_4;
    QPushButton *add_item_pushButton;
    QPushButton *exit_pushButton;
    QPushButton *edit_pushButton;

    void setupUi(QWidget *add_items_into_inventory_widget)
    {
        if (add_items_into_inventory_widget->objectName().isEmpty())
            add_items_into_inventory_widget->setObjectName("add_items_into_inventory_widget");
        add_items_into_inventory_widget->resize(684, 399);
        add_items_into_inventory_widget->setMinimumSize(QSize(684, 399));
        add_items_into_inventory_widget->setMaximumSize(QSize(684, 399));
        formLayoutWidget = new QWidget(add_items_into_inventory_widget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(0, 9, 681, 41));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignCenter);
        formLayout->setContentsMargins(0, 0, 0, 0);
        search_by_label = new QLabel(formLayoutWidget);
        search_by_label->setObjectName("search_by_label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Open Sans")});
        font.setPointSize(11);
        search_by_label->setFont(font);
        search_by_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, search_by_label);

        search_for_items_lineEdit = new QLineEdit(formLayoutWidget);
        search_for_items_lineEdit->setObjectName("search_for_items_lineEdit");
        search_for_items_lineEdit->setMaximumSize(QSize(421, 31));
        search_for_items_lineEdit->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, search_for_items_lineEdit);

        formLayoutWidget_2 = new QWidget(add_items_into_inventory_widget);
        formLayoutWidget_2->setObjectName("formLayoutWidget_2");
        formLayoutWidget_2->setGeometry(QRect(0, 60, 681, 51));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout_2->setLabelAlignment(Qt::AlignCenter);
        formLayout_2->setFormAlignment(Qt::AlignCenter);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        Name_of_item_label = new QLabel(formLayoutWidget_2);
        Name_of_item_label->setObjectName("Name_of_item_label");
        Name_of_item_label->setFont(font);
        Name_of_item_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, Name_of_item_label);

        name_of_item_lineEdit = new QLineEdit(formLayoutWidget_2);
        name_of_item_lineEdit->setObjectName("name_of_item_lineEdit");
        name_of_item_lineEdit->setMaximumSize(QSize(421, 31));
        name_of_item_lineEdit->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, name_of_item_lineEdit);

        horizontalLayoutWidget = new QWidget(add_items_into_inventory_widget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 130, 671, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        items_count_label = new QLabel(horizontalLayoutWidget);
        items_count_label->setObjectName("items_count_label");

        horizontalLayout_3->addWidget(items_count_label);

        items_count_spinBox = new QSpinBox(horizontalLayoutWidget);
        items_count_spinBox->setObjectName("items_count_spinBox");
        items_count_spinBox->setMaximumSize(QSize(51, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Open Sans")});
        items_count_spinBox->setFont(font1);
        items_count_spinBox->setAlignment(Qt::AlignCenter);
        items_count_spinBox->setMaximum(999);

        horizontalLayout_3->addWidget(items_count_spinBox);

        status_label = new QLabel(horizontalLayoutWidget);
        status_label->setObjectName("status_label");
        status_label->setFont(font);
        status_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(status_label);

        status_comboBox = new QComboBox(horizontalLayoutWidget);
        status_comboBox->setObjectName("status_comboBox");
        status_comboBox->setMinimumSize(QSize(150, 0));
        status_comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        horizontalLayout_3->addWidget(status_comboBox);

        date_added_label = new QLabel(horizontalLayoutWidget);
        date_added_label->setObjectName("date_added_label");
        date_added_label->setFont(font);
        date_added_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(date_added_label);

        date_added_lineEdit = new QLineEdit(horizontalLayoutWidget);
        date_added_lineEdit->setObjectName("date_added_lineEdit");
        date_added_lineEdit->setEnabled(false);
        date_added_lineEdit->setMaximumSize(QSize(421, 31));
        date_added_lineEdit->setFont(font);

        horizontalLayout_3->addWidget(date_added_lineEdit);

        horizontalLayoutWidget_2 = new QWidget(add_items_into_inventory_widget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(10, 220, 661, 80));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_4->setSpacing(15);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_4->setContentsMargins(8, 8, 8, 8);
        entered_by_label = new QLabel(horizontalLayoutWidget_2);
        entered_by_label->setObjectName("entered_by_label");
        entered_by_label->setFont(font);
        entered_by_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(entered_by_label);

        entered_by_lineEdit = new QLineEdit(horizontalLayoutWidget_2);
        entered_by_lineEdit->setObjectName("entered_by_lineEdit");
        entered_by_lineEdit->setEnabled(false);
        entered_by_lineEdit->setMaximumSize(QSize(338, 31));
        entered_by_lineEdit->setFont(font);

        horizontalLayout_4->addWidget(entered_by_lineEdit);

        category_label = new QLabel(horizontalLayoutWidget_2);
        category_label->setObjectName("category_label");
        category_label->setFont(font);
        category_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(category_label);

        category_comboBox = new QComboBox(horizontalLayoutWidget_2);
        category_comboBox->setObjectName("category_comboBox");
        category_comboBox->setMinimumSize(QSize(140, 28));
        category_comboBox->setFont(font);

        horizontalLayout_4->addWidget(category_comboBox);

        gridLayoutWidget = new QWidget(add_items_into_inventory_widget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 310, 661, 51));
        gridLayout_4 = new QGridLayout(gridLayoutWidget);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        add_item_pushButton = new QPushButton(gridLayoutWidget);
        add_item_pushButton->setObjectName("add_item_pushButton");
        add_item_pushButton->setMaximumSize(QSize(90, 27));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Open Sans")});
        font2.setPointSize(11);
        font2.setItalic(true);
        add_item_pushButton->setFont(font2);

        gridLayout_4->addWidget(add_item_pushButton, 0, 0, 1, 1);

        exit_pushButton = new QPushButton(gridLayoutWidget);
        exit_pushButton->setObjectName("exit_pushButton");
        exit_pushButton->setMaximumSize(QSize(90, 27));
        exit_pushButton->setFont(font2);

        gridLayout_4->addWidget(exit_pushButton, 0, 3, 1, 1);

        edit_pushButton = new QPushButton(gridLayoutWidget);
        edit_pushButton->setObjectName("edit_pushButton");
        edit_pushButton->setMaximumSize(QSize(90, 27));
        edit_pushButton->setFont(font2);

        gridLayout_4->addWidget(edit_pushButton, 0, 1, 1, 1);


        retranslateUi(add_items_into_inventory_widget);

        QMetaObject::connectSlotsByName(add_items_into_inventory_widget);
    } // setupUi

    void retranslateUi(QWidget *add_items_into_inventory_widget)
    {
        add_items_into_inventory_widget->setWindowTitle(QCoreApplication::translate("add_items_into_inventory_widget", "Add items into the inventory", nullptr));
        search_by_label->setText(QCoreApplication::translate("add_items_into_inventory_widget", "Search:", nullptr));
        Name_of_item_label->setText(QCoreApplication::translate("add_items_into_inventory_widget", "Name:", nullptr));
        items_count_label->setText(QCoreApplication::translate("add_items_into_inventory_widget", "Items Count", nullptr));
        status_label->setText(QCoreApplication::translate("add_items_into_inventory_widget", "Status:", nullptr));
        date_added_label->setText(QCoreApplication::translate("add_items_into_inventory_widget", "Date added:", nullptr));
        entered_by_label->setText(QCoreApplication::translate("add_items_into_inventory_widget", "Entered by:", nullptr));
        category_label->setText(QCoreApplication::translate("add_items_into_inventory_widget", "Category:", nullptr));
        category_comboBox->setCurrentText(QString());
        add_item_pushButton->setText(QCoreApplication::translate("add_items_into_inventory_widget", "Add", nullptr));
        exit_pushButton->setText(QCoreApplication::translate("add_items_into_inventory_widget", "Exit", nullptr));
        edit_pushButton->setText(QCoreApplication::translate("add_items_into_inventory_widget", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_items_into_inventory_widget: public Ui_add_items_into_inventory_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_ITEMS_IN_THE_INVENTORY_H
