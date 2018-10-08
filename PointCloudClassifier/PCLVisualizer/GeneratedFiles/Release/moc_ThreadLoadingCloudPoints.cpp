/****************************************************************************
** Meta object code from reading C++ file 'ThreadLoadingCloudPoints.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ThreadLoadingCloudPoints.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ThreadLoadingCloudPoints.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ThreadLoadingCloudPoints_t {
    QByteArrayData data[7];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThreadLoadingCloudPoints_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThreadLoadingCloudPoints_t qt_meta_stringdata_ThreadLoadingCloudPoints = {
    {
QT_MOC_LITERAL(0, 0, 24), // "ThreadLoadingCloudPoints"
QT_MOC_LITERAL(1, 25, 11), // "msgBarValue"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 8), // "finished"
QT_MOC_LITERAL(4, 47, 15), // "LY::THREAD_TYPE"
QT_MOC_LITERAL(5, 63, 11), // "submitCloud"
QT_MOC_LITERAL(6, 75, 15) // "LY::XYZRGBCloud"

    },
    "ThreadLoadingCloudPoints\0msgBarValue\0"
    "\0finished\0LY::THREAD_TYPE\0submitCloud\0"
    "LY::XYZRGBCloud"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadLoadingCloudPoints[] = {

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
       1,    1,   29,    2, 0x06 /* Public */,
       3,    2,   32,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 6,    2,

       0        // eod
};

void ThreadLoadingCloudPoints::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ThreadLoadingCloudPoints *_t = static_cast<ThreadLoadingCloudPoints *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->msgBarValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->finished((*reinterpret_cast< LY::THREAD_TYPE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->submitCloud((*reinterpret_cast< LY::XYZRGBCloud(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ThreadLoadingCloudPoints::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadLoadingCloudPoints::msgBarValue)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ThreadLoadingCloudPoints::*_t)(LY::THREAD_TYPE , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadLoadingCloudPoints::finished)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ThreadLoadingCloudPoints::*_t)(LY::XYZRGBCloud );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadLoadingCloudPoints::submitCloud)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ThreadLoadingCloudPoints::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThreadLoadingCloudPoints.data,
      qt_meta_data_ThreadLoadingCloudPoints,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ThreadLoadingCloudPoints::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadLoadingCloudPoints::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadLoadingCloudPoints.stringdata0))
        return static_cast<void*>(const_cast< ThreadLoadingCloudPoints*>(this));
    return QThread::qt_metacast(_clname);
}

int ThreadLoadingCloudPoints::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void ThreadLoadingCloudPoints::msgBarValue(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThreadLoadingCloudPoints::finished(LY::THREAD_TYPE _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ThreadLoadingCloudPoints::submitCloud(LY::XYZRGBCloud _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
