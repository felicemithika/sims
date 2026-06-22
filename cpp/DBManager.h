#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>

class database_manager {
    public:
        static database_manager& instance();

        bool open_database();
        QSqlDatabase get_database();

    private:
        database_manager();
        ~database_manager();

        QSqlDatabase db;

        // Prevent copying
        database_manager(const database_manager&) = delete;
        database_manager& operator=(const database_manager&) =delete;
};

#endif