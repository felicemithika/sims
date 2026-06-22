/********************************************************************************
** Form generated from reading UI file 'welcome-screen.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_2D_SCREEN_H
#define UI_WELCOME_2D_SCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_welcome_screen
{
public:
    QLabel *name;
    QLabel *logo;
    QProgressBar *progressBar;
    QLabel *main_background;

    void setupUi(QWidget *welcome_screen)
    {
        if (welcome_screen->objectName().isEmpty())
            welcome_screen->setObjectName("welcome_screen");
        welcome_screen->resize(728, 393);
        welcome_screen->setMinimumSize(QSize(728, 393));
        welcome_screen->setMaximumSize(QSize(764, 393));
        welcome_screen->setStyleSheet(QString::fromUtf8("QWidget#welcome_screen {\n"
"	background-image: url(:/1/images/surgery-1822458_640.jpg);\n"
"	border-image: url(:/1/images/surgery-1822458_640.jpg);\n"
"}"));
        name = new QLabel(welcome_screen);
        name->setObjectName("name");
        name->setGeometry(QRect(0, -20, 771, 529));
        name->setMinimumSize(QSize(771, 529));
        name->setMaximumSize(QSize(771, 529));
        name->setStyleSheet(QString::fromUtf8("QLabel#name {\n"
"	border-image: url(:/2/images/surgical instrument management system.png);\n"
"}\n"
""));
        logo = new QLabel(welcome_screen);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(190, 30, 431, 271));
        logo->setMinimumSize(QSize(431, 271));
        logo->setMaximumSize(QSize(431, 271));
        logo->setStyleSheet(QString::fromUtf8("QLabel#logo {\n"
"	border-image: url(:/2/images/Aga-Khan-Logo-Crop.png);\n"
"}"));
        progressBar = new QProgressBar(welcome_screen);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(80, 310, 581, 23));
        progressBar->setMinimumSize(QSize(581, 23));
        progressBar->setMaximumSize(QSize(581, 23));
        QFont font;
        font.setFamilies({QString::fromUtf8("FontAwesome")});
        font.setPointSize(9);
        font.setBold(true);
        font.setItalic(true);
        font.setStrikeOut(false);
        progressBar->setFont(font);
        progressBar->setValue(24);
        main_background = new QLabel(welcome_screen);
        main_background->setObjectName("main_background");
        main_background->setGeometry(QRect(-9, -11, 741, 411));
        main_background->setStyleSheet(QString::fromUtf8("QWidget#main_background {\n"
"	border-image: url(:/1/images/surgery-1822458_640.jpg);\n"
"}"));
        main_background->raise();
        name->raise();
        logo->raise();
        progressBar->raise();

        retranslateUi(welcome_screen);

        QMetaObject::connectSlotsByName(welcome_screen);
    } // setupUi

    void retranslateUi(QWidget *welcome_screen)
    {
        welcome_screen->setWindowTitle(QCoreApplication::translate("welcome_screen", "SURGICAL INSTRUMENT MANAGEMENT SYSTEM", nullptr));
        name->setText(QString());
        logo->setText(QString());
        main_background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class welcome_screen: public Ui_welcome_screen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_2D_SCREEN_H
