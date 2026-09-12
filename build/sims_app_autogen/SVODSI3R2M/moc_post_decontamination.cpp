/****************************************************************************
** Meta object code from reading C++ file 'post_decontamination.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../cpp/post_decontamination.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'post_decontamination.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN20post_decontaminationE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN20post_decontaminationE = QtMocHelpers::stringData(
    "post_decontamination",
    "batch_code_changed",
    "",
    "type_of_surgery_changed",
    "patients_name_changed",
    "last_scan_date_n_time_changed",
    "session_user_changed",
    "current_scan_date_n_time_changed",
    "items_loaded",
    "QVariantList",
    "items",
    "barcode_accepted",
    "barcode_rejected",
    "message",
    "success_message",
    "warning_message",
    "error_message",
    "read_terminal_input",
    "process_barcode",
    "barcode",
    "auto_fill",
    "confirm_batch",
    "nurse_name",
    "scanned_by",
    "current_scan_date_n_time",
    "reject_batch",
    "comment",
    "start_barcode_scanning",
    "stop_barcode_scanning",
    "batch_code",
    "type_of_surgery",
    "patients_name",
    "last_scan_date_n_time",
    "session_user"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN20post_decontaminationE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       6,  169, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  128,    2, 0x06,    7 /* Public */,
       3,    0,  129,    2, 0x06,    8 /* Public */,
       4,    0,  130,    2, 0x06,    9 /* Public */,
       5,    0,  131,    2, 0x06,   10 /* Public */,
       6,    0,  132,    2, 0x06,   11 /* Public */,
       7,    0,  133,    2, 0x06,   12 /* Public */,
       8,    1,  134,    2, 0x06,   13 /* Public */,
      11,    0,  137,    2, 0x06,   15 /* Public */,
      12,    1,  138,    2, 0x06,   16 /* Public */,
      14,    1,  141,    2, 0x06,   18 /* Public */,
      15,    1,  144,    2, 0x06,   20 /* Public */,
      16,    1,  147,    2, 0x06,   22 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      17,    0,  150,    2, 0x08,   24 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      18,    1,  151,    2, 0x02,   25 /* Public */,
      20,    0,  154,    2, 0x02,   27 /* Public */,
      21,    3,  155,    2, 0x02,   28 /* Public */,
      25,    2,  162,    2, 0x02,   32 /* Public */,
      27,    0,  167,    2, 0x02,   35 /* Public */,
      28,    0,  168,    2, 0x02,   36 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   13,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   22,   23,   24,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   22,   26,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags, notifyId, revision
      29, QMetaType::QString, 0x00015001, uint(0), 0,
      30, QMetaType::QString, 0x00015001, uint(1), 0,
      31, QMetaType::QString, 0x00015001, uint(2), 0,
      32, QMetaType::QString, 0x00015001, uint(3), 0,
      33, QMetaType::QString, 0x00015001, uint(4), 0,
      24, QMetaType::QString, 0x00015001, uint(5), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject post_decontamination::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN20post_decontaminationE.offsetsAndSizes,
    qt_meta_data_ZN20post_decontaminationE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN20post_decontaminationE_t,
        // property 'batch_code'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'type_of_surgery'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'patients_name'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'last_scan_date_n_time'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'session_user'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'current_scan_date_n_time'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<post_decontamination, std::true_type>,
        // method 'batch_code_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'type_of_surgery_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'patients_name_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'last_scan_date_n_time_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'session_user_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'current_scan_date_n_time_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'items_loaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantList &, std::false_type>,
        // method 'barcode_accepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'barcode_rejected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'success_message'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'warning_message'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'error_message'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'read_terminal_input'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'process_barcode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'auto_fill'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'confirm_batch'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'reject_batch'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'start_barcode_scanning'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stop_barcode_scanning'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void post_decontamination::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<post_decontamination *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->batch_code_changed(); break;
        case 1: _t->type_of_surgery_changed(); break;
        case 2: _t->patients_name_changed(); break;
        case 3: _t->last_scan_date_n_time_changed(); break;
        case 4: _t->session_user_changed(); break;
        case 5: _t->current_scan_date_n_time_changed(); break;
        case 6: _t->items_loaded((*reinterpret_cast< std::add_pointer_t<QVariantList>>(_a[1]))); break;
        case 7: _t->barcode_accepted(); break;
        case 8: _t->barcode_rejected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->success_message((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->warning_message((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->error_message((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->read_terminal_input(); break;
        case 13: _t->process_barcode((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->auto_fill(); break;
        case 15: _t->confirm_batch((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 16: _t->reject_batch((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 17: _t->start_barcode_scanning(); break;
        case 18: _t->stop_barcode_scanning(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (post_decontamination::*)();
            if (_q_method_type _q_method = &post_decontamination::batch_code_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (post_decontamination::*)();
            if (_q_method_type _q_method = &post_decontamination::type_of_surgery_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (post_decontamination::*)();
            if (_q_method_type _q_method = &post_decontamination::patients_name_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (post_decontamination::*)();
            if (_q_method_type _q_method = &post_decontamination::last_scan_date_n_time_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (post_decontamination::*)();
            if (_q_method_type _q_method = &post_decontamination::session_user_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (post_decontamination::*)();
            if (_q_method_type _q_method = &post_decontamination::current_scan_date_n_time_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _q_method_type = void (post_decontamination::*)(const QVariantList & );
            if (_q_method_type _q_method = &post_decontamination::items_loaded; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _q_method_type = void (post_decontamination::*)();
            if (_q_method_type _q_method = &post_decontamination::barcode_accepted; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _q_method_type = void (post_decontamination::*)(const QString & );
            if (_q_method_type _q_method = &post_decontamination::barcode_rejected; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _q_method_type = void (post_decontamination::*)(const QString & );
            if (_q_method_type _q_method = &post_decontamination::success_message; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _q_method_type = void (post_decontamination::*)(const QString & );
            if (_q_method_type _q_method = &post_decontamination::warning_message; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _q_method_type = void (post_decontamination::*)(const QString & );
            if (_q_method_type _q_method = &post_decontamination::error_message; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->batch_code(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->type_of_surgery(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->patients_name(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->last_scan_date_n_time(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->session_user(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->current_scan_date_n_time(); break;
        default: break;
        }
    }
}

const QMetaObject *post_decontamination::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *post_decontamination::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN20post_decontaminationE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int post_decontamination::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void post_decontamination::batch_code_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void post_decontamination::type_of_surgery_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void post_decontamination::patients_name_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void post_decontamination::last_scan_date_n_time_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void post_decontamination::session_user_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void post_decontamination::current_scan_date_n_time_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void post_decontamination::items_loaded(const QVariantList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void post_decontamination::barcode_accepted()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void post_decontamination::barcode_rejected(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void post_decontamination::success_message(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void post_decontamination::warning_message(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void post_decontamination::error_message(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_WARNING_POP
