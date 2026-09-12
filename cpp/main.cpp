#include "login_screen.h"
#include "main_window.h"
#include "DBManager.h"
#include "create_a_barcode.h"
#include "add_items_into_the_barcode.h"
#include "user_session.h"
#include "pick_a_set_widget.h"
#include "pre_theatre.h"
#include "post_theatre.h"
#include "pre_decontamination.h"
#include "post_decontamination.h"
#include "pre_packaging.h"
#include "post_packaging.h"
#include "end_autoclaving.h"
#include "post_store.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QObject>
#include <QUrl>
#include <QSqlDatabase>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    if (!database_manager::instance().open_database()) {
        return -1;
    }

    QSqlDatabase db = database_manager::instance().get_database();

    loginScreen login;
    //MainWindow* mainwindow = nullptr;
    create_a_barcode_widget barcode_widget;
    QQmlApplicationEngine engine;
    pick_a_set_widget patients_details;
    pre_theatre theatre_entry(db);
    post_theatre theatre_exit(db);
    pre_decontamination deconamination_entry(db);
    post_decontamination deconamination_exit(db);
    pre_packaging packaging_entry(db);
    post_packaging packaging_exit(db);
    end_autoclaving autoclave(db);
    post_store cycle_end(db);

    add_items_Form add_items_widget(
        "",
        &db
    );

    QObject::connect (
        &add_items_widget,
        &add_items_Form::items_added,
        &barcode_widget,
        &create_a_barcode_widget::setUp_selected_items_tableView
    );

    engine.rootContext()->setContextProperty(
        "loginController",
        &login
    );

    engine.load(QUrl(QStringLiteral(
        "qrc:/SIMS/qml/main.qml"
    )));

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }


    QObject::connect(
        &login,
        &loginScreen::loginSuccessful,
        [&]() {
            QQmlApplicationEngine* main_engine = new QQmlApplicationEngine();
            main_engine->rootContext()->setContextProperty(
                "create_a_barcode_widget",
                &barcode_widget
            );

            main_engine->rootContext()->setContextProperty(
                "add_items_into_the_barcode",
                &add_items_widget
            );

            main_engine->rootContext()->setContextProperty(
                "pick_a_set_widget",
                &patients_details
            );

            main_engine->rootContext()->setContextProperty(
                "pre_theatre",
                &theatre_entry
            );

            main_engine->rootContext()->setContextProperty(
                "post_theatre",
                &theatre_exit
            );

            main_engine->rootContext()->setContextProperty(
                "pre_decontamination",
                &deconamination_entry
            );

            main_engine->rootContext()->setContextProperty(
                "post_decontamination",
                &deconamination_exit
            );

            main_engine->rootContext()->setContextProperty(
                "pre_packaging",
                &packaging_entry
            );

            main_engine->rootContext()->setContextProperty(
                "post_packaging",
                &packaging_exit
            );

            main_engine->rootContext()->setContextProperty(
                "end_autoclaving",
                &autoclave
            );

            main_engine->rootContext()->setContextProperty(
                "post_store",
                &cycle_end
            );


            main_engine->load(QUrl(QStringLiteral("qrc:/SIMS/qml/main_window.qml")));

            if (main_engine->rootObjects().isEmpty()) {
                delete main_engine;
                return;
            }

            QObject* main_window = main_engine->rootObjects().first();

            QObject::connect(
                main_window,
                &QObject::destroyed,
                main_engine,
                &QObject::deleteLater
            );

            QObject* login_window = engine.rootObjects().first();

            if (login_window) {
                login_window->deleteLater();
            }
        }
    );

    QObject::connect(
        &login,
        &loginScreen::loginCancelled,
        &app,
        QApplication::quit
    );

    return app.exec();
}