/********************************************************************************
** Form generated from reading UI file 'add_items_into_the_barcode.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_ITEMS_INTO_THE_BARCODE_H
#define UI_ADD_ITEMS_INTO_THE_BARCODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_add_items_Form
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *category_label;
    QComboBox *category_comboBox;
    QLabel *instrument_count_label;
    QSpinBox *instrument_count_spinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *surgical_instrument_label;
    QComboBox *surgical_instrument_comboBox;
    QVBoxLayout *verticalLayout;
    QLabel *comments_label;
    QPlainTextEdit *comments_plainTextEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *add_instrument_pushButton;
    QPushButton *exit_pushButton;

    void setupUi(QWidget *add_items_Form)
    {
        if (add_items_Form->objectName().isEmpty())
            add_items_Form->setObjectName("add_items_Form");
        add_items_Form->setWindowModality(Qt::WindowModality::ApplicationModal);
        add_items_Form->resize(728, 421);
        add_items_Form->setMinimumSize(QSize(728, 421));
        add_items_Form->setMaximumSize(QSize(928, 421));
        add_items_Form->setStyleSheet(QString::fromUtf8("QWidget#add_items_Form {\n"
"	background-color: rgb(0, 0, 0);\n"
"}\n"
""));
        verticalLayout_2 = new QVBoxLayout(add_items_Form);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(90, 10, 90, 10);
        category_label = new QLabel(add_items_Form);
        category_label->setObjectName("category_label");
        category_label->setMinimumSize(QSize(91, 31));
        category_label->setMaximumSize(QSize(91, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Open Sans")});
        font.setPointSize(11);
        font.setBold(false);
        category_label->setFont(font);
        category_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(category_label);

        category_comboBox = new QComboBox(add_items_Form);
        category_comboBox->setObjectName("category_comboBox");
        category_comboBox->setMaximumSize(QSize(201, 31));

        horizontalLayout->addWidget(category_comboBox);

        instrument_count_label = new QLabel(add_items_Form);
        instrument_count_label->setObjectName("instrument_count_label");
        instrument_count_label->setMaximumSize(QSize(131, 31));
        instrument_count_label->setFont(font);
        instrument_count_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(instrument_count_label);

        instrument_count_spinBox = new QSpinBox(add_items_Form);
        instrument_count_spinBox->setObjectName("instrument_count_spinBox");
        instrument_count_spinBox->setMinimumSize(QSize(61, 31));
        instrument_count_spinBox->setMaximumSize(QSize(61, 31));

        horizontalLayout->addWidget(instrument_count_spinBox);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(60, 10, 60, 10);
        surgical_instrument_label = new QLabel(add_items_Form);
        surgical_instrument_label->setObjectName("surgical_instrument_label");
        surgical_instrument_label->setMaximumSize(QSize(141, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Open Sans")});
        font1.setPointSize(11);
        surgical_instrument_label->setFont(font1);
        surgical_instrument_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(surgical_instrument_label);

        surgical_instrument_comboBox = new QComboBox(add_items_Form);
        surgical_instrument_comboBox->setObjectName("surgical_instrument_comboBox");
        surgical_instrument_comboBox->setMaximumSize(QSize(521, 31));

        horizontalLayout_2->addWidget(surgical_instrument_comboBox);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(80, -1, -1, -1);
        comments_label = new QLabel(add_items_Form);
        comments_label->setObjectName("comments_label");
        comments_label->setMaximumSize(QSize(91, 31));
        comments_label->setFont(font1);
        comments_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(comments_label);

        comments_plainTextEdit = new QPlainTextEdit(add_items_Form);
        comments_plainTextEdit->setObjectName("comments_plainTextEdit");
        comments_plainTextEdit->setMaximumSize(QSize(521, 101));
        comments_plainTextEdit->setFont(font1);
        comments_plainTextEdit->setFrameShape(QFrame::Shape::WinPanel);
        comments_plainTextEdit->setFrameShadow(QFrame::Shadow::Raised);
        comments_plainTextEdit->setLineWidth(12);

        verticalLayout->addWidget(comments_plainTextEdit);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(-1, 20, -1, 20);
        add_instrument_pushButton = new QPushButton(add_items_Form);
        add_instrument_pushButton->setObjectName("add_instrument_pushButton");
        add_instrument_pushButton->setMinimumSize(QSize(91, 31));
        add_instrument_pushButton->setMaximumSize(QSize(91, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Open Sans")});
        font2.setPointSize(11);
        font2.setItalic(true);
        add_instrument_pushButton->setFont(font2);

        horizontalLayout_3->addWidget(add_instrument_pushButton);

        exit_pushButton = new QPushButton(add_items_Form);
        exit_pushButton->setObjectName("exit_pushButton");
        exit_pushButton->setMaximumSize(QSize(91, 31));
        exit_pushButton->setFont(font2);

        horizontalLayout_3->addWidget(exit_pushButton);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(add_items_Form);

        QMetaObject::connectSlotsByName(add_items_Form);
    } // setupUi

    void retranslateUi(QWidget *add_items_Form)
    {
        add_items_Form->setWindowTitle(QCoreApplication::translate("add_items_Form", "Add Items", nullptr));
        category_label->setText(QCoreApplication::translate("add_items_Form", "Category:", nullptr));
        instrument_count_label->setText(QCoreApplication::translate("add_items_Form", "Instrument Count:", nullptr));
        surgical_instrument_label->setText(QCoreApplication::translate("add_items_Form", "Surgical Instrument:", nullptr));
        comments_label->setText(QCoreApplication::translate("add_items_Form", "Comments:", nullptr));
        add_instrument_pushButton->setText(QCoreApplication::translate("add_items_Form", "Add", nullptr));
        exit_pushButton->setText(QCoreApplication::translate("add_items_Form", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_items_Form: public Ui_add_items_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_ITEMS_INTO_THE_BARCODE_H
