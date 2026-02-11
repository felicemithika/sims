/********************************************************************************
** Form generated from reading UI file 'login-screen.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_2D_SCREEN_H
#define UI_LOGIN_2D_SCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login_screen
{
public:
    QGridLayout *gridLayout;
    QFormLayout *button_formLayout;
    QPushButton *login_Button;
    QPushButton *cancelButton;
    QVBoxLayout *usernameandpaswword_title_verticalLayout;
    QLabel *usernameandpassword_title_label;
    QVBoxLayout *title_verticalLayout;
    QLabel *title;
    QGridLayout *usenameandpasword_input_gridLayout;
    QLabel *username_label;
    QLabel *password_label;
    QLineEdit *username;
    QLineEdit *password;

    void setupUi(QWidget *login_screen)
    {
        if (login_screen->objectName().isEmpty())
            login_screen->setObjectName("login_screen");
        login_screen->setWindowModality(Qt::ApplicationModal);
        login_screen->setEnabled(true);
        login_screen->resize(784, 457);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(login_screen->sizePolicy().hasHeightForWidth());
        login_screen->setSizePolicy(sizePolicy);
        login_screen->setMinimumSize(QSize(784, 457));
        login_screen->setMaximumSize(QSize(784, 457));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sans Serif")});
        login_screen->setFont(font);
        login_screen->setWindowOpacity(0.000000000000000);
        gridLayout = new QGridLayout(login_screen);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        button_formLayout = new QFormLayout();
        button_formLayout->setObjectName("button_formLayout");
        button_formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        button_formLayout->setLabelAlignment(Qt::AlignCenter);
        button_formLayout->setFormAlignment(Qt::AlignCenter);
        button_formLayout->setVerticalSpacing(5);
        button_formLayout->setContentsMargins(5, 5, 5, 5);
        login_Button = new QPushButton(login_screen);
        login_Button->setObjectName("login_Button");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sans Serif")});
        font1.setItalic(true);
        login_Button->setFont(font1);

        button_formLayout->setWidget(0, QFormLayout::LabelRole, login_Button);

        cancelButton = new QPushButton(login_screen);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setFont(font1);

        button_formLayout->setWidget(0, QFormLayout::FieldRole, cancelButton);


        gridLayout->addLayout(button_formLayout, 3, 0, 1, 1);

        usernameandpaswword_title_verticalLayout = new QVBoxLayout();
        usernameandpaswword_title_verticalLayout->setSpacing(5);
        usernameandpaswword_title_verticalLayout->setObjectName("usernameandpaswword_title_verticalLayout");
        usernameandpassword_title_label = new QLabel(login_screen);
        usernameandpassword_title_label->setObjectName("usernameandpassword_title_label");
        usernameandpassword_title_label->setFont(font1);
        usernameandpassword_title_label->setAlignment(Qt::AlignCenter);

        usernameandpaswword_title_verticalLayout->addWidget(usernameandpassword_title_label);


        gridLayout->addLayout(usernameandpaswword_title_verticalLayout, 1, 0, 1, 1);

        title_verticalLayout = new QVBoxLayout();
        title_verticalLayout->setObjectName("title_verticalLayout");
        title = new QLabel(login_screen);
        title->setObjectName("title");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Sans Serif")});
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        title->setFont(font2);
        title->setAlignment(Qt::AlignCenter);

        title_verticalLayout->addWidget(title);


        gridLayout->addLayout(title_verticalLayout, 0, 0, 1, 1);

        usenameandpasword_input_gridLayout = new QGridLayout();
        usenameandpasword_input_gridLayout->setObjectName("usenameandpasword_input_gridLayout");
        username_label = new QLabel(login_screen);
        username_label->setObjectName("username_label");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Sans Serif")});
        font3.setPointSize(11);
        font3.setItalic(true);
        username_label->setFont(font3);

        usenameandpasword_input_gridLayout->addWidget(username_label, 0, 0, 1, 1);

        password_label = new QLabel(login_screen);
        password_label->setObjectName("password_label");
        password_label->setFont(font3);

        usenameandpasword_input_gridLayout->addWidget(password_label, 2, 0, 1, 1);

        username = new QLineEdit(login_screen);
        username->setObjectName("username");
        username->setMinimumSize(QSize(500, 30));
        username->setMaximumSize(QSize(500, 30));
        username->setFont(font);
        username->setAlignment(Qt::AlignCenter);

        usenameandpasword_input_gridLayout->addWidget(username, 1, 0, 1, 1);

        password = new QLineEdit(login_screen);
        password->setObjectName("password");
        password->setMinimumSize(QSize(500, 30));
        password->setMaximumSize(QSize(500, 30));
        password->setFont(font);
        password->setAlignment(Qt::AlignCenter);

        usenameandpasword_input_gridLayout->addWidget(password, 3, 0, 1, 1);


        gridLayout->addLayout(usenameandpasword_input_gridLayout, 2, 0, 1, 1);


        retranslateUi(login_screen);

        QMetaObject::connectSlotsByName(login_screen);
    } // setupUi

    void retranslateUi(QWidget *login_screen)
    {
        login_screen->setWindowTitle(QCoreApplication::translate("login_screen", "Login screen", nullptr));
        login_Button->setText(QCoreApplication::translate("login_screen", "Login", nullptr));
        cancelButton->setText(QCoreApplication::translate("login_screen", "Cancel", nullptr));
        usernameandpassword_title_label->setText(QCoreApplication::translate("login_screen", "Enter your username and password.", nullptr));
        title->setText(QCoreApplication::translate("login_screen", "LOGIN WINDOW.", nullptr));
        username_label->setText(QCoreApplication::translate("login_screen", "Username:", nullptr));
        password_label->setText(QCoreApplication::translate("login_screen", "Password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login_screen: public Ui_login_screen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_2D_SCREEN_H
