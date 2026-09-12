/****************************************************************************
** Meta object code from reading C++ file 'pick_a_set_widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../cpp/pick_a_set_widget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pick_a_set_widget.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN17pick_a_set_widgetE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN17pick_a_set_widgetE = QtMocHelpers::stringData(
    "pick_a_set_widget",
    "session_user_changed",
    "",
    "date_time_created_changed",
    "success_message",
    "message",
    "warning_message",
    "error_message",
    "getSurgeryTypes",
    "select_batch",
    "QVariantMap",
    "surgery_type",
    "get_batch_items",
    "batch_code",
    "commit_transaction",
    "rollback_transaction",
    "auto_fill",
    "save_patient_details",
    "type_of_surgery",
    "patients_name",
    "patients_phone_no",
    "patients_other_phone_no",
    "next_of_kins_name",
    "next_of_kins_phone_no",
    "next_of_kins_other_phone_no",
    "theatre",
    "issued_to",
    "issued_by",
    "date_and_time_picked",
    "session_user",
    "date_time_created"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN17pick_a_set_widgetE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       2,  132, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x06,    3 /* Public */,
       3,    0,   87,    2, 0x06,    4 /* Public */,
       4,    1,   88,    2, 0x06,    5 /* Public */,
       6,    1,   91,    2, 0x06,    7 /* Public */,
       7,    1,   94,    2, 0x06,    9 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   97,    2, 0x02,   11 /* Public */,
       9,    1,   98,    2, 0x02,   12 /* Public */,
      12,    1,  101,    2, 0x02,   14 /* Public */,
      14,    0,  104,    2, 0x02,   16 /* Public */,
      15,    0,  105,    2, 0x02,   17 /* Public */,
      16,    0,  106,    2, 0x02,   18 /* Public */,
      17,   12,  107,    2, 0x02,   19 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,

 // methods: parameters
    QMetaType::QStringList,
    0x80000000 | 10, QMetaType::QString,   11,
    0x80000000 | 10, QMetaType::QString,   13,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    0x80000000 | 10, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   13,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,

 // properties: name, type, flags, notifyId, revision
      29, QMetaType::QString, 0x00015001, uint(0), 0,
      30, QMetaType::QString, 0x00015001, uint(1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject pick_a_set_widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN17pick_a_set_widgetE.offsetsAndSizes,
    qt_meta_data_ZN17pick_a_set_widgetE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN17pick_a_set_widgetE_t,
        // property 'session_user'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'date_time_created'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<pick_a_set_widget, std::true_type>,
        // method 'session_user_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'date_time_created_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'success_message'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'warning_message'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'error_message'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'getSurgeryTypes'
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'select_batch'
        QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'get_batch_items'
        QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'commit_transaction'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'rollback_transaction'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'auto_fill'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'save_patient_details'
        QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void pick_a_set_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<pick_a_set_widget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->session_user_changed(); break;
        case 1: _t->date_time_created_changed(); break;
        case 2: _t->success_message((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->warning_message((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->error_message((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: { QStringList _r = _t->getSurgeryTypes();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 6: { QVariantMap _r = _t->select_batch((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 7: { QVariantMap _r = _t->get_batch_items((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->commit_transaction();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->rollback_transaction();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->auto_fill(); break;
        case 11: { QVariantMap _r = _t->save_patient_details((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[12])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (pick_a_set_widget::*)();
            if (_q_method_type _q_method = &pick_a_set_widget::session_user_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (pick_a_set_widget::*)();
            if (_q_method_type _q_method = &pick_a_set_widget::date_time_created_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (pick_a_set_widget::*)(const QString & );
            if (_q_method_type _q_method = &pick_a_set_widget::success_message; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (pick_a_set_widget::*)(const QString & );
            if (_q_method_type _q_method = &pick_a_set_widget::warning_message; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (pick_a_set_widget::*)(const QString & );
            if (_q_method_type _q_method = &pick_a_set_widget::error_message; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->session_user(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->date_time_created(); break;
        default: break;
        }
    }
}

const QMetaObject *pick_a_set_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pick_a_set_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN17pick_a_set_widgetE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int pick_a_set_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void pick_a_set_widget::session_user_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void pick_a_set_widget::date_time_created_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void pick_a_set_widget::success_message(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void pick_a_set_widget::warning_message(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void pick_a_set_widget::error_message(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
