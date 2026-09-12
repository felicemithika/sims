#include "login_screen.h"
#include "user_session.h"
#include "main_window.h"
#include "DBManager.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

loginScreen::loginScreen(QObject* parent) : QObject(parent) {}

//loginScreen::~loginScreen() {}

void loginScreen::login(const QString& username, const QString& password){
    QString clean_username = username.trimmed();
    QString clean_password = password.trimmed();

    //validate input
    if (clean_username.isEmpty() || clean_password.isEmpty()) {
        emit loginFailed (
            "Please enter both username and password."
        );
        return;
    }

    QSqlQuery query(database_manager::instance().get_database());
    query.prepare("SELECT * FROM sims_logins WHERE username = :username AND password = :password");
    query.bindValue(":username", clean_username);
    query.bindValue(":password", clean_password);

    if (query.exec() && query.next()) {
        //QMessageBox::information(this, "Login Successful", QString("Welcome, %1!").arg(clean_username));
        UserSession::getInstance().setCurrentUser(clean_username);


        emit loginSuccessful();


    } else {
       emit loginFailed (
        "Check your username and password and try again."
       );
    }
}

void loginScreen::cancelLogin() {
   // ui.username->clear();
   // ui.password->clear();

   // QMessageBox::information(this, "Cancelled", "Exiting the application");

    emit loginCancelled();

}