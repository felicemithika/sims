#ifndef ADD_ITEMS_INTO_THE_BARCODE_H
#define ADD_ITEMS_INTO_THE_BARCODE_H

#include "../build/ui_add_items_into_the_barcode.h"
#include "../build/ui_create_a_barcode.h"
//#include "create_a_barcode.h"
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>

class add_items_Form : public QObject {
    Q_OBJECT

    Q_PROPERTY(QStringList category_list READ category_list NOTIFY category_list_changed)
    Q_PROPERTY(QStringList surgical_instrument_list READ surgical_instrument_list NOTIFY surgical_instrument_list_changed)

    public:
        explicit add_items_Form(const QString &batch_code, QSqlDatabase* parentdb = nullptr, QObject* parent = nullptr);
        QStringList category_list() const;
        QStringList surgical_instrument_list() const;
        Q_INVOKABLE void load_surgical_instruments( const QString &category);
        Q_INVOKABLE void add_requested_item(const QString &category, int instrument_count, const QString &surgical_instrument, const QString &comments);
        Q_INVOKABLE void set_batch_code(const QString &batch_code);

    signals:
        void items_added();
        void category_list_changed();
        void surgical_instrument_list_changed();

        void success_message(const QString &message);
        void warning_message(const QString &message);
        void error_message(const QString &message);
    
    private:
        QSqlDatabase db;
        QString currentBatchCode;
        QStringList m_category_list;
        QStringList m_surgical_instrument_list;

       // void add_items_into_surgical_instrument_combobox(const QString &category);
};

#endif