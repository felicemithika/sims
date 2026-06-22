/********************************************************************************
** Form generated from reading UI file 'select_the_surgery_widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECT_THE_SURGERY_WIDGET_H
#define UI_SELECT_THE_SURGERY_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_select_the_surgery_widget
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *info_label;
    QFormLayout *formLayout;
    QLabel *type_of_surgery_label;
    QComboBox *type_of_surgery_comboBox;
    QGridLayout *gridLayout;
    QPushButton *new_batch_pushButton;
    QPushButton *patients_details_pushButton;
    QPushButton *exit_pushButton;

    void setupUi(QWidget *select_the_surgery_widget)
    {
        if (select_the_surgery_widget->objectName().isEmpty())
            select_the_surgery_widget->setObjectName("select_the_surgery_widget");
        select_the_surgery_widget->resize(700, 259);
        verticalLayout = new QVBoxLayout(select_the_surgery_widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        info_label = new QLabel(select_the_surgery_widget);
        info_label->setObjectName("info_label");
        info_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(info_label);


        verticalLayout->addLayout(verticalLayout_3);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        formLayout->setFormAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        type_of_surgery_label = new QLabel(select_the_surgery_widget);
        type_of_surgery_label->setObjectName("type_of_surgery_label");
        type_of_surgery_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, type_of_surgery_label);

        type_of_surgery_comboBox = new QComboBox(select_the_surgery_widget);
        type_of_surgery_comboBox->setObjectName("type_of_surgery_comboBox");
        type_of_surgery_comboBox->setMinimumSize(QSize(450, 0));

        formLayout->setWidget(0, QFormLayout::FieldRole, type_of_surgery_comboBox);


        verticalLayout->addLayout(formLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(5, 10, 5, 10);
        new_batch_pushButton = new QPushButton(select_the_surgery_widget);
        new_batch_pushButton->setObjectName("new_batch_pushButton");
        new_batch_pushButton->setMaximumSize(QSize(128, 25));

        gridLayout->addWidget(new_batch_pushButton, 1, 0, 1, 1);

        patients_details_pushButton = new QPushButton(select_the_surgery_widget);
        patients_details_pushButton->setObjectName("patients_details_pushButton");
        patients_details_pushButton->setMaximumSize(QSize(143, 25));

        gridLayout->addWidget(patients_details_pushButton, 1, 1, 1, 1);

        exit_pushButton = new QPushButton(select_the_surgery_widget);
        exit_pushButton->setObjectName("exit_pushButton");
        exit_pushButton->setMaximumSize(QSize(80, 25));

        gridLayout->addWidget(exit_pushButton, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(select_the_surgery_widget);

        QMetaObject::connectSlotsByName(select_the_surgery_widget);
    } // setupUi

    void retranslateUi(QWidget *select_the_surgery_widget)
    {
        select_the_surgery_widget->setWindowTitle(QCoreApplication::translate("select_the_surgery_widget", "Select the surgery", nullptr));
        info_label->setText(QCoreApplication::translate("select_the_surgery_widget", "NB:Type to search for a surgical procedure\342\200\246", nullptr));
        type_of_surgery_label->setText(QCoreApplication::translate("select_the_surgery_widget", "Type of surgery:", nullptr));
        new_batch_pushButton->setText(QCoreApplication::translate("select_the_surgery_widget", "New batch", nullptr));
        patients_details_pushButton->setText(QCoreApplication::translate("select_the_surgery_widget", "patient's details", nullptr));
        exit_pushButton->setText(QCoreApplication::translate("select_the_surgery_widget", "exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class select_the_surgery_widget: public Ui_select_the_surgery_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_THE_SURGERY_WIDGET_H
