/****************************************************************************
** Meta object code from reading C++ file 'ThreadPCD2TXT.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ThreadPCD2TXT.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ThreadPCD2TXT.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ThreadPCD2TXT_t {
    QByteArrayData data[5];
    char stringdata0[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThreadPCD2TXT_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThreadPCD2TXT_t qt_meta_stringdata_ThreadPCD2TXT = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ThreadPCD2TXT"
QT_MOC_LITERAL(1, 14, 9), // "changeBar"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "value"
QT_MOC_LITERAL(4, 31, 13) // "finishConvert"

    },
    "ThreadPCD2TXT\0changeBar\0\0value\0"
    "finishConvert"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadPCD2TXT[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       4,    0,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void ThreadPCD2TXT::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ThreadPCD2TXT *_t = static_cast<ThreadPCD2TXT *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeBar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->finishConvert(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ThreadPCD2TXT::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadPCD2TXT::changeBar)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ThreadPCD2TXT::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadPCD2TXT::finishConvert)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ThreadPCD2TXT::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ThreadPCD2TXT.data,
      qt_meta_data_ThreadPCD2TXT,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ThreadPCD2TXT::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadPCD2TXT::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadPCD2TXT.stringdata0))
        return static_cast<void*>(const_cast< ThreadPCD2TXT*>(this));
    return QObject::qt_metacast(_clname);
}

int ThreadPCD2TXT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ThreadPCD2TXT::changeBar(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThreadPCD2TXT::finishConvert()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
