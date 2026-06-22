#include "login_screen.h"
#include "user_session.h"
#include "main_window.h"
#include "DBManager.h"

loginScreen::loginScreen(QWidget* parent) : QWidget(parent) {
    this->setObjectName("login_screen");
    ui.setupUi(this);
    this->setFixedSize(601, 359);

    ui.username->setFocus();

    //Set password to show dots for privacy
    ui.password->setEchoMode(QLineEdit::Password);

    //Connect buttons to functions
    connect(ui.login_Button, &QPushButton::clicked, this, &loginScreen::pressing_loginButton);
    connect(ui.cancelButton, &QPushButton::clicked, this, &loginScreen::pressing_cancelButton);

    //Connect enter key press to move cursor from usename to password
    connect(ui.username, &QLineEdit::returnPressed, [this]() {
        ui.password->setFocus();
    });

    connect(ui.password, &QLineEdit::returnPressed, [this]() {
        ui.login_Button->setFocus();
    });
}

loginScreen::~loginScreen() {
}

void loginScreen::pressing_loginButton(){
    QString username = ui.username->text().trimmed();
    QString password = ui.password->text().trimmed();

    //validate input
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login Failed", 
            "Please enter both username and password.");
        return;
    }

    QSqlQuery query(database_manager::instance().get_database());
    query.prepare("SELECT * FROM sims_logins WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        QMessageBox::information(this, "Login Successful", QString("Welcome, %1!").arg(username));
        UserSession::getInstance().setCurrentUser(username);

        ui.username->clear();
        ui.password->clear();

        emit loginSuccessful();
        this->close();


    } else {
        QMessageBox::warning(this, "Login Failed!!", "Check your username and password and try again.");

        ui.password->clear();
        ui.username->setFocus();
    }
}

void loginScreen::pressing_cancelButton() {
    ui.username->clear();
    ui.password->clear();

    QMessageBox::information(this, "Cancelled", "Exiting the application");

    emit loginCancelled();
    this->close();

}