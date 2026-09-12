#ifndef PRE_PACKAGING_H
#define PRE_PACKAGING_H

#include "DBManager.h"
#include "user_session.h"

#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QVariantMap>
#include <QVariantList>
#include <QSocketNotifier>

class pre_packaging : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString batch_code READ batch_code NOTIFY batch_code_changed)
    Q_PROPERTY(QString type_of_surgery READ type_of_surgery NOTIFY type_of_surgery_changed)
    Q_PROPERTY(QString patients_name READ patients_name NOTIFY patients_name_changed)
    Q_PROPERTY(QString last_scan_date_n_time READ last_scan_date_n_time NOTIFY last_scan_date_n_time_changed)
    Q_PROPERTY(QString session_user READ session_user NOTIFY session_user_changed)
    Q_PROPERTY(QString current_scan_date_n_time READ current_scan_date_n_time NOTIFY current_scan_date_n_time_changed)

    public:
        explicit pre_packaging(QSqlDatabase database, QObject *parent = nullptr);

        QString batch_code() const;
        QString type_of_surgery() const;
        QString patients_name() const;
        QString last_scan_date_n_time() const;
        QString current_scan_date_n_time() const;
        QString session_user() const;

        Q_INVOKABLE void process_barcode(const QString &barcode);
        Q_INVOKABLE void auto_fill();
        Q_INVOKABLE void confirm_batch(const QString &nurse_name, const QString &scanned_by, const QString &current_scan_date_n_time);
        Q_INVOKABLE void reject_batch(const QString &nurse_name, const QString &comment);
        Q_INVOKABLE void start_barcode_scanning();
        Q_INVOKABLE void stop_barcode_scanning();

    signals:
        void batch_code_changed();
        void type_of_surgery_changed();
        void patients_name_changed();
        void last_scan_date_n_time_changed();
        void session_user_changed();
        void current_scan_date_n_time_changed();

        void items_loaded(const QVariantList &items);

        void barcode_accepted();
        void barcode_rejected(const QString &message);

        void success_message(const QString &message);
        void warning_message(const QString &message);
        void error_message(const QString &message);

    private slots:
        void read_terminal_input();

    private:
        QSqlDatabase db;

        QString m_batch_code;
        QString m_type_of_surgery;
        QString m_patients_name;
        QString m_last_scan_date_n_time;
        QString m_session_user;
        QString m_current_scan_date_n_time;

        QSocketNotifier *stdin_notifier;

        bool fetch_batch(const QString &barcode);
        QVariantList fetch_batch_items(const QString &batch_code);
    };


#endif