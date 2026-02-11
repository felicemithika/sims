#ifndef USER_SESSION_H
#define USER_SESSION_H

#include <QString>

class UserSession {
    private:
        UserSession() {}

        QString currentuser;
    
    public:
        UserSession(const UserSession&) = delete;
        UserSession& operator=(const UserSession&) = delete;

        static UserSession& getInstance() {
            static UserSession instance;
            return instance;
        }

        void setCurrentUser(const QString &username) { 
            currentuser = username; 
        }

        QString getCurrentUser() const {
            return currentuser;
        }

        bool isLoggedIn() const {
            return !currentuser.isEmpty();
        }
};

#endif