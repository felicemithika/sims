#ifndef LOGIN_SCREEN_H
#define LOGIN_SCREEN_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include "../build/ui_login-screen.h"

class loginScreen : public QWidget {
    Q_OBJECT

    public:
        explicit loginScreen(QWidget* parent = nullptr);
        ~loginScreen();
    
    private slots:
        void pressing_loginButton();
        void pressing_cancelButton();
    
    signals:
        void loginSuccessful();
        void loginCancelled();
    
    private:
        Ui::login_screen ui;
};

#endif