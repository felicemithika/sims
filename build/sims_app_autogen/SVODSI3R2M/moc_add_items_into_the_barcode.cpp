/****************************************************************************
** Meta object code from reading C++ file 'add_items_into_the_barcode.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../cpp/add_items_into_the_barcode.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'add_items_into_the_barcode.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14add_items_FormE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN14add_items_FormE = QtMocHelpers::stringData(
    "add_items_Form",
    "items_added",
    "",
    "category_list_changed",
    "surgical_instrument_list_changed",
    "success_message",
    "message",
    "warning_message",
    "error_message",
    "load_surgical_instruments",
    "category",
    "add_requested_item",
    "instrument_count",
    "surgical_instrument",
    "comments",
    "set_batch_code",
    "batch_code",
    "category_list",
    "surgical_instrument_list"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN14add_items_FormE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       2,   95, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    3 /* Public */,
       3,    0,   69,    2, 0x06,    4 /* Public */,
       4,    0,   70,    2, 0x06,    5 /* Public */,
       5,    1,   71,    2, 0x06,    6 /* Public */,
       7,    1,   74,    2, 0x06,    8 /* Public */,
       8,    1,   77,    2, 0x06,   10 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,   80,    2, 0x02,   12 /* Public */,
      11,    4,   83,    2, 0x02,   14 /* Public */,
      15,    1,   92,    2, 0x02,   19 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,   10,   12,   13,   14,
    QMetaType::Void, QMetaType::QString,   16,

 // properties: name, type, flags, notifyId, revision
      17, QMetaType::QStringList, 0x00015001, uint(1), 0,
      18, QMetaType::QStringList, 0x00015001, uint(2), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject add_items_Form::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN14add_items_FormE.offsetsAndSizes,
    qt_meta_data_ZN14add_items_FormE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN14add_items_FormE_t,
        // property 'category_list'
        QtPrivate::TypeAndForceComplete<QStringList, std::true_type>,
        // property 'surgical_instrument_list'
        QtPrivate::TypeAndForceComplete<QStringList, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<add_items_Form, std::true_type>,
        // method 'items_added'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'category_list_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'surgical_instrument_list_changed'
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
        // method 'load_surgical_instruments'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'add_requested_item'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'set_batch_code'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void add_items_Form::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<add_items_Form *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->items_added(); break;
        case 1: _t->category_list_changed(); break;
        case 2: _t->surgical_instrument_list_changed(); break;
        case 3: _t->success_message((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->warning_message((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->error_message((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->load_surgical_instruments((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->add_requested_item((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 8: _t->set_batch_code((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (add_items_Form::*)();
            if (_q_method_type _q_method = &add_items_Form::items_added; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (add_items_Form::*)();
            if (_q_method_type _q_method = &add_items_Form::category_list_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (add_items_Form::*)();
            if (_q_method_type _q_method = &add_items_Form::surgical_instrument_list_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (add_items_Form::*)(const QString & );
            if (_q_method_type _q_method = &add_items_Form::success_message; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (add_items_Form::*)(const QString & );
            if (_q_method_type _q_method = &add_items_Form::warning_message; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (add_items_Form::*)(const QString & );
            if (_q_method_type _q_method = &add_items_Form::error_message; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QStringList*>(_v) = _t->category_list(); break;
        case 1: *reinterpret_cast< QStringList*>(_v) = _t->surgical_instrument_list(); break;
        default: break;
        }
    }
}

const QMetaObject *add_items_Form::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *add_items_Form::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN14add_items_FormE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int add_items_Form::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
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
void add_items_Form::items_added()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void add_items_Form::category_list_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void add_items_Form::surgical_instrument_list_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void add_items_Form::success_message(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void add_items_Form::warning_message(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void add_items_Form::error_message(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
