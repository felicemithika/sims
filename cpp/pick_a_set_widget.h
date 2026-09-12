#ifndef PICK_A_SET_WIDGET_H
#define PICK_A_SET_WIDGET_H

#include "../build/ui_pick_a_set_widget.h"
#include "DBManager.h"
#include "user_session.h"
#include "add_items_into_the_barcode.h"
#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QDateTime>
#include <QVariantMap>
#include <QVariantList>


class pick_a_set_widget : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString session_user READ session_user NOTIFY session_user_changed)
    Q_PROPERTY(QString date_time_created READ date_time_created NOTIFY date_time_created_changed)

    signals:
        void session_user_changed();
        void date_time_created_changed();

        void success_message(const QString &message);
        void warning_message(const QString &message);
        void error_message(const QString &message);

    private slots:
        //void on_done_pushButton_clicked();
        //void on_plus_pushButton_clicked();
        //void on_exit_pushButton_clicked();

    public:
       // enum open_source {
       //     from_create_a_barcode_widget,
      //      from_select_the_surgery_widget
       // };
        
        explicit pick_a_set_widget(QObject* parent=nullptr);

        Q_INVOKABLE QStringList getSurgeryTypes();
        Q_INVOKABLE QVariantMap select_batch(const QString &surgery_type);
        Q_INVOKABLE QVariantMap get_batch_items(const QString &batch_code);
        Q_INVOKABLE bool commit_transaction();
        Q_INVOKABLE bool rollback_transaction();
        Q_INVOKABLE void auto_fill();
        Q_INVOKABLE QVariantMap save_patient_details(
            const QString &batch_code,
            const QString &type_of_surgery,
            const QString &patients_name,
            const QString &patients_phone_no,
            const QString &patients_other_phone_no,
            const QString &next_of_kins_name,
            const QString &next_of_kins_phone_no,
            const QString &next_of_kins_other_phone_no,
            const QString &theatre,
            const QString &issued_to,
            const QString &issued_by,
            const QString &date_and_time_picked
        );

        QString date_time_created() const;
        QString session_user() const;

    private:
        //open_source m_source;
        //QString m_value;

        QString m_session_user;
        QString m_date_time_created;

        QSqlDatabase db;
        bool transaction_started = false;

        //void load_data();
       // void setUp_selected_items_tableView();
};

#endif