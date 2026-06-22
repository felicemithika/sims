/********************************************************************************
** Form generated from reading UI file 'view_all_created_batches.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_ALL_CREATED_BATCHES_H
#define UI_VIEW_ALL_CREATED_BATCHES_H

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

class Ui_view_created_batches
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *title_label;
    QLabel *clients_brief_explanation_label;
    QVBoxLayout *verticalLayout_2;
    QTableView *view_created_batches_tableView;
    QFormLayout *formLayout;
    QPushButton *view_pushButton;
    QPushButton *exit_pushButton;

    void setupUi(QWidget *view_created_batches)
    {
        if (view_created_batches->objectName().isEmpty())
            view_created_batches->setObjectName("view_created_batches");
        view_created_batches->resize(949, 641);
        view_created_batches->setStyleSheet(QString::fromUtf8("QWidget#view_created_batches {\n"
"	background-color: rgb(0, 0, 0);\n"
"\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(view_created_batches);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        title_label = new QLabel(view_created_batches);
        title_label->setObjectName("title_label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Open Sans")});
        font.setPointSize(14);
        font.setBold(true);
        title_label->setFont(font);
        title_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(title_label);

        clients_brief_explanation_label = new QLabel(view_created_batches);
        clients_brief_explanation_label->setObjectName("clients_brief_explanation_label");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Open Sans")});
        font1.setBold(false);
        font1.setItalic(true);
        clients_brief_explanation_label->setFont(font1);
        clients_brief_explanation_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(clients_brief_explanation_label);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        view_created_batches_tableView = new QTableView(view_created_batches);
        view_created_batches_tableView->setObjectName("view_created_batches_tableView");

        verticalLayout_2->addWidget(view_created_batches_tableView);


        verticalLayout_3->addLayout(verticalLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setSizeConstraint(QLayout::SetFixedSize);
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignCenter);
        formLayout->setHorizontalSpacing(80);
        formLayout->setVerticalSpacing(0);
        formLayout->setContentsMargins(0, 15, 80, 15);
        view_pushButton = new QPushButton(view_created_batches);
        view_pushButton->setObjectName("view_pushButton");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Open Sans")});
        font2.setPointSize(12);
        font2.setItalic(true);
        view_pushButton->setFont(font2);
        view_pushButton->setStyleSheet(QString::fromUtf8("QPushButton#view_pushButton {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        formLayout->setWidget(0, QFormLayout::LabelRole, view_pushButton);

        exit_pushButton = new QPushButton(view_created_batches);
        exit_pushButton->setObjectName("exit_pushButton");
        exit_pushButton->setFont(font2);
        exit_pushButton->setStyleSheet(QString::fromUtf8("QPushButton#exit_pushButton {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        formLayout->setWidget(0, QFormLayout::FieldRole, exit_pushButton);


        verticalLayout_3->addLayout(formLayout);


        retranslateUi(view_created_batches);

        QMetaObject::connectSlotsByName(view_created_batches);
    } // setupUi

    void retranslateUi(QWidget *view_created_batches)
    {
        view_created_batches->setWindowTitle(QCoreApplication::translate("view_created_batches", "View all the created batches", nullptr));
        title_label->setText(QCoreApplication::translate("view_created_batches", "View all batches created in the Barcode Creation widget", nullptr));
        clients_brief_explanation_label->setText(QCoreApplication::translate("view_created_batches", "(Double-click a batch code, or select one and press View, to see its items.)", nullptr));
        view_pushButton->setText(QCoreApplication::translate("view_created_batches", "View", nullptr));
        exit_pushButton->setText(QCoreApplication::translate("view_created_batches", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class view_created_batches: public Ui_view_created_batches {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_ALL_CREATED_BATCHES_H
