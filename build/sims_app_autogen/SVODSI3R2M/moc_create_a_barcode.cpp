/****************************************************************************
** Meta object code from reading C++ file 'create_a_barcode.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../cpp/create_a_barcode.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'create_a_barcode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN23create_a_barcode_widgetE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN23create_a_barcode_widgetE = QtMocHelpers::stringData(
    "create_a_barcode_widget",
    "batch_code_changed",
    "",
    "date_created_changed",
    "time_created_changed",
    "session_user_changed",
    "selected_items_updated",
    "QVariantList",
    "items",
    "success_message",
    "message",
    "warning_message",
    "error_message",
    "batch_created",
    "batch_code",
    "on_barcode_generated",
    "exit_code",
    "QProcess::ExitStatus",
    "exit_status",
    "auto_fill_items",
    "start_items_transaction",
    "rollback_items_transaction",
    "setUp_selected_items_tableView",
    "create_batch",
    "surgery_type",
    "date_created",
    "time_created",
    "session_user"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN23create_a_barcode_widgetE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       4,  135, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x06,    5 /* Public */,
       3,    0,  105,    2, 0x06,    6 /* Public */,
       4,    0,  106,    2, 0x06,    7 /* Public */,
       5,    0,  107,    2, 0x06,    8 /* Public */,
       6,    1,  108,    2, 0x06,    9 /* Public */,
       9,    1,  111,    2, 0x06,   11 /* Public */,
      11,    1,  114,    2, 0x06,   13 /* Public */,
      12,    1,  117,    2, 0x06,   15 /* Public */,
      13,    1,  120,    2, 0x06,   17 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      15,    2,  123,    2, 0x08,   19 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      19,    0,  128,    2, 0x02,   22 /* Public */,
      20,    0,  129,    2, 0x02,   23 /* Public */,
      21,    0,  130,    2, 0x02,   24 /* Public */,
      22,    0,  131,    2, 0x02,   25 /* Public */,
      23,    1,  132,    2, 0x02,   26 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   14,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 17,   16,   18,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   24,

 // properties: name, type, flags, notifyId, revision
      14, QMetaType::QString, 0x00015001, uint(0), 0,
      25, QMetaType::QString, 0x00015001, uint(1), 0,
      26, QMetaType::QString, 0x00015001, uint(2), 0,
      27, QMetaType::QString, 0x00015001, uint(3), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject create_a_barcode_widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN23create_a_barcode_widgetE.offsetsAndSizes,
    qt_meta_data_ZN23create_a_barcode_widgetE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN23create_a_barcode_widgetE_t,
        // property 'batch_code'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'date_created'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'time_created'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'session_user'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<create_a_barcode_widget, std::true_type>,
        // method 'batch_code_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'date_created_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'time_created_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'session_user_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'selected_items_updated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantList &, std::false_type>,
        // method 'success_message'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'warning_message'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'error_message'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'batch_created'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_barcode_generated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QProcess::ExitStatus, std::false_type>,
        // method 'auto_fill_items'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'start_items_transaction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rollback_items_transaction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setUp_selected_items_tableView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'create_batch'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void create_a_barcode_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<create_a_barcode_widget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->batch_code_changed(); break;
        case 1: _t->date_created_changed(); break;
        case 2: _t->time_created_changed(); break;
        case 3: _t->session_user_changed(); break;
        case 4: _t->selected_items_updated((*reinterpret_cast< std::add_pointer_t<QVariantList>>(_a[1]))); break;
        case 5: _t->success_message((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->warning_message((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->error_message((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->batch_created((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->on_barcode_generated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QProcess::ExitStatus>>(_a[2]))); break;
        case 10: _t->auto_fill_items(); break;
        case 11: _t->start_items_transaction(); break;
        case 12: _t->rollback_items_transaction(); break;
        case 13: _t->setUp_selected_items_tableView(); break;
        case 14: _t->create_batch((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (create_a_barcode_widget::*)();
            if (_q_method_type _q_method = &create_a_barcode_widget::batch_code_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (create_a_barcode_widget::*)();
            if (_q_method_type _q_method = &create_a_barcode_widget::date_created_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (create_a_barcode_widget::*)();
            if (_q_method_type _q_method = &create_a_barcode_widget::time_created_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (create_a_barcode_widget::*)();
            if (_q_method_type _q_method = &create_a_barcode_widget::session_user_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (create_a_barcode_widget::*)(const QVariantList & );
            if (_q_method_type _q_method = &create_a_barcode_widget::selected_items_updated; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (create_a_barcode_widget::*)(const QString & );
            if (_q_method_type _q_method = &create_a_barcode_widget::success_message; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _q_method_type = void (create_a_barcode_widget::*)(const QString & );
            if (_q_method_type _q_method = &create_a_barcode_widget::warning_message; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _q_method_type = void (create_a_barcode_widget::*)(const QString & );
            if (_q_method_type _q_method = &create_a_barcode_widget::error_message; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _q_method_type = void (create_a_barcode_widget::*)(const QString & );
            if (_q_method_type _q_method = &create_a_barcode_widget::batch_created; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->batch_code(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->date_created(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->time_created(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->session_user(); break;
        default: break;
        }
    }
}

const QMetaObject *create_a_barcode_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *create_a_barcode_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN23create_a_barcode_widgetE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int create_a_barcode_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void create_a_barcode_widget::batch_code_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void create_a_barcode_widget::date_created_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void create_a_barcode_widget::time_created_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void create_a_barcode_widget::session_user_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void create_a_barcode_widget::selected_items_updated(const QVariantList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void create_a_barcode_widget::success_message(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void create_a_barcode_widget::warning_message(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void create_a_barcode_widget::error_message(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void create_a_barcode_widget::batch_created(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
