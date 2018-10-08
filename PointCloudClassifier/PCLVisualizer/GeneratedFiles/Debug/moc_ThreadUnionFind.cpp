/****************************************************************************
** Meta object code from reading C++ file 'ThreadUnionFind.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ThreadUnionFind.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ThreadUnionFind.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ThreadUnionFind_t {
    QByteArrayData data[6];
    char stringdata0[47];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThreadUnionFind_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThreadUnionFind_t qt_meta_stringdata_ThreadUnionFind = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ThreadUnionFind"
QT_MOC_LITERAL(1, 16, 8), // "finishUF"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "int&"
QT_MOC_LITERAL(4, 31, 9), // "changeBar"
QT_MOC_LITERAL(5, 41, 5) // "value"

    },
    "ThreadUnionFind\0finishUF\0\0int&\0changeBar\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadUnionFind[] = {

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
       1,    2,   24,    2, 0x06 /* Public */,
       4,    1,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void ThreadUnionFind::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ThreadUnionFind *_t = static_cast<ThreadUnionFind *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finishUF((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->changeBar((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ThreadUnionFind::*_t)(int & , int & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadUnionFind::finishUF)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ThreadUnionFind::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadUnionFind::changeBar)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ThreadUnionFind::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ThreadUnionFind.data,
      qt_meta_data_ThreadUnionFind,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ThreadUnionFind::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadUnionFind::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadUnionFind.stringdata0))
        return static_cast<void*>(const_cast< ThreadUnionFind*>(this));
    return QObject::qt_metacast(_clname);
}

int ThreadUnionFind::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ThreadUnionFind::finishUF(int & _t1, int & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThreadUnionFind::changeBar(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
