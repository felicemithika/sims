#ifndef CREATE_A_BARCODE_H
#define CREATE_A_BARCODE_H

#include "../build/ui_create_a_barcode.h"
#include "add_items_into_the_barcode.h"
#include "pick_a_set_widget.h"
#include <QWidget>
#include <QDateTime>
#include <QTimer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QProcess>
#include <QVariantList>


class create_a_barcode_widget : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString batch_code READ batch_code NOTIFY batch_code_changed)
    Q_PROPERTY(QString date_created READ date_created NOTIFY date_created_changed)
    Q_PROPERTY(QString time_created READ time_created NOTIFY time_created_changed)
    Q_PROPERTY(QString session_user READ session_user NOTIFY session_user_changed)
   // Q_PROPERTY(QObject* add_items_widget READ add_items_widget NOTIFY add_items_widget_changed)

    public:
        explicit create_a_barcode_widget(QObject* parent = nullptr);

        QString batch_code() const;
        QString date_created() const;
        QString time_created() const;
        QString session_user() const;
        //QObject* add_items_widget() const;

        Q_INVOKABLE void auto_fill_items();
        //start a db transaction
        Q_INVOKABLE void start_items_transaction();
        //roll back a db transaction
        Q_INVOKABLE void rollback_items_transaction();
        //allow qml to refresh the table
        Q_INVOKABLE void setUp_selected_items_tableView();
        //submit the batch into the db
        Q_INVOKABLE void create_batch(const QString &surgery_type);
    
    signals:
        void batch_code_changed();
        void date_created_changed();
        void time_created_changed();
        void session_user_changed();
        //void add_items_widget_changed();
        void selected_items_updated(const QVariantList &items);

        void success_message(const QString &message);
        void warning_message(const QString &message);
        void error_message(const QString &message);

        void batch_created(const QString &batch_code);

    private slots:
        void on_barcode_generated(int exit_code, QProcess::ExitStatus exit_status);

    private:
        QString m_batch_code;
        QString m_date_created;
        QString m_time_created;
        QString m_session_user;

        QTimer* timer;

        QSqlDatabase db;

        //add_items_Form* m_add_items_widget = nullptr;

        bool transaction_started = false;

        QProcess* python_process = nullptr;

        bool create_in_progress = false;

        QString pending_batch_code;
        QString pending_barcode_filename;

        //QMessageBox::StandardButton reply;
        bool generate_barcode(const QString& data, const QString& filename);
};

#endif