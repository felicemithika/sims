#include "DBManager.h"
#include <QSqlError>
#include <QDebug>

database_manager::database_manager() {}

database_manager::~database_manager() {
    if (db.isOpen()) {
        db.close();
    }
}

database_manager& database_manager::instance() {
    static database_manager instance;
    return instance;
}

bool database_manager::open_database() {
    if (QSqlDatabase::contains("SIMS_DB_connection")) {
        db = QSqlDatabase::database("SIMS_DB_connection");
    } else {
        db = QSqlDatabase::addDatabase("QMARIADB", "SIMS_DB_connection");
        db.setHostName("localhost");
        db.setDatabaseName("sims_db");
        db.setUserName("root");
        db.setPassword("");
    }

    if (!db.open()) {
        qDebug() << "Database error:" <<db.lastError().text();
        return false;
    }
    qDebug() << "Database connected successfully";
    return true;
}

QSqlDatabase database_manager::get_database() {
    return db;
}