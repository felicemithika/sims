// include the header files (*.h files)
#include "welcome-screen.h"
#include "login_screen.h"
#include "main_window.h"
#include "DBManager.h"

#include <QApplication>

// The main function
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    if (!database_manager::instance().open_database()) {
        return -1;
    }

    WelcomeScreen welcome;
    loginScreen login;

    MainWindow* mainwindow = nullptr;

    QObject::connect(&welcome, &WelcomeScreen::finished, [&]() {
        login.show();
    });

    QObject::connect(&login, &loginScreen::loginSuccessful, [&]() {
        mainwindow = new MainWindow();
        mainwindow->show();
        mainwindow->setAttribute(Qt::WA_DeleteOnClose);
    });

    QObject::connect(&login, &loginScreen::loginCancelled, [&]() {
        QApplication::quit();
    });
    
    welcome.show();

    return app.exec();
}
