#ifndef LOGIN_SCREEN_H
#define LOGIN_SCREEN_H

#include <QObject>
#include <QString>

class loginScreen : public QObject {
    Q_OBJECT

    public:
        explicit loginScreen(QObject* parent = nullptr);

        Q_INVOKABLE void login(const QString& username, const QString& password);
        Q_INVOKABLE void cancelLogin();
    
    signals:
        void loginSuccessful();
        void loginCancelled();
        void loginFailed(const QString& message);

};

#endif