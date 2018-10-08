/****************************************************************************
** Meta object code from reading C++ file 'ThreadDelegate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ThreadDelegate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ThreadDelegate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ThreadDelegate_t {
    QByteArrayData data[11];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThreadDelegate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThreadDelegate_t qt_meta_stringdata_ThreadDelegate = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ThreadDelegate"
QT_MOC_LITERAL(1, 15, 13), // "signalRunTask"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 16), // "LY::XYZRGBCloud&"
QT_MOC_LITERAL(4, 47, 5), // "cloud"
QT_MOC_LITERAL(5, 53, 20), // "std::vector<QString>"
QT_MOC_LITERAL(6, 74, 7), // "vecPara"
QT_MOC_LITERAL(7, 82, 14), // "signalBarValue"
QT_MOC_LITERAL(8, 97, 15), // "LY::THREAD_TYPE"
QT_MOC_LITERAL(9, 113, 17), // "signalResultCloud"
QT_MOC_LITERAL(10, 131, 16) // "LY::XYZRGBCloud*"

    },
    "ThreadDelegate\0signalRunTask\0\0"
    "LY::XYZRGBCloud&\0cloud\0std::vector<QString>\0"
    "vecPara\0signalBarValue\0LY::THREAD_TYPE\0"
    "signalResultCloud\0LY::XYZRGBCloud*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadDelegate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       7,    2,   34,    2, 0x06 /* Public */,
       9,    2,   39,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10,    2,    4,

       0        // eod
};

void ThreadDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ThreadDelegate *_t = static_cast<ThreadDelegate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalRunTask((*reinterpret_cast< LY::XYZRGBCloud(*)>(_a[1])),(*reinterpret_cast< std::vector<QString>(*)>(_a[2]))); break;
        case 1: _t->signalBarValue((*reinterpret_cast< LY::THREAD_TYPE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->signalResultCloud((*reinterpret_cast< LY::THREAD_TYPE(*)>(_a[1])),(*reinterpret_cast< LY::XYZRGBCloud*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ThreadDelegate::*_t)(LY::XYZRGBCloud & , std::vector<QString> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadDelegate::signalRunTask)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ThreadDelegate::*_t)(LY::THREAD_TYPE , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadDelegate::signalBarValue)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ThreadDelegate::*_t)(LY::THREAD_TYPE , LY::XYZRGBCloud * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadDelegate::signalResultCloud)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ThreadDelegate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ThreadDelegate.data,
      qt_meta_data_ThreadDelegate,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ThreadDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadDelegate.stringdata0))
        return static_cast<void*>(const_cast< ThreadDelegate*>(this));
    return QObject::qt_metacast(_clname);
}

int ThreadDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ThreadDelegate::signalRunTask(LY::XYZRGBCloud & _t1, std::vector<QString> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThreadDelegate::signalBarValue(LY::THREAD_TYPE _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ThreadDelegate::signalResultCloud(LY::THREAD_TYPE _t1, LY::XYZRGBCloud * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
