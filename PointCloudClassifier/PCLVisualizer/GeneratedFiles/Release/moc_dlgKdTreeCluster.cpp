/****************************************************************************
** Meta object code from reading C++ file 'dlgKdTreeCluster.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dlgKdTreeCluster.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgKdTreeCluster.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_dlgKdTreeCluster_t {
    QByteArrayData data[10];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dlgKdTreeCluster_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dlgKdTreeCluster_t qt_meta_stringdata_dlgKdTreeCluster = {
    {
QT_MOC_LITERAL(0, 0, 16), // "dlgKdTreeCluster"
QT_MOC_LITERAL(1, 17, 12), // "startConvert"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 12), // "toolClicked1"
QT_MOC_LITERAL(4, 44, 12), // "toolClicked2"
QT_MOC_LITERAL(5, 57, 10), // "rbClicked1"
QT_MOC_LITERAL(6, 68, 10), // "rbClicked2"
QT_MOC_LITERAL(7, 79, 13), // "checkClicked1"
QT_MOC_LITERAL(8, 93, 13), // "checkClicked2"
QT_MOC_LITERAL(9, 107, 13) // "convertButton"

    },
    "dlgKdTreeCluster\0startConvert\0\0"
    "toolClicked1\0toolClicked2\0rbClicked1\0"
    "rbClicked2\0checkClicked1\0checkClicked2\0"
    "convertButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dlgKdTreeCluster[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dlgKdTreeCluster::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        dlgKdTreeCluster *_t = static_cast<dlgKdTreeCluster *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startConvert(); break;
        case 1: _t->toolClicked1(); break;
        case 2: _t->toolClicked2(); break;
        case 3: _t->rbClicked1(); break;
        case 4: _t->rbClicked2(); break;
        case 5: _t->checkClicked1(); break;
        case 6: _t->checkClicked2(); break;
        case 7: _t->convertButton(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (dlgKdTreeCluster::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dlgKdTreeCluster::startConvert)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject dlgKdTreeCluster::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dlgKdTreeCluster.data,
      qt_meta_data_dlgKdTreeCluster,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *dlgKdTreeCluster::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dlgKdTreeCluster::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_dlgKdTreeCluster.stringdata0))
        return static_cast<void*>(const_cast< dlgKdTreeCluster*>(this));
    return QDialog::qt_metacast(_clname);
}

int dlgKdTreeCluster::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void dlgKdTreeCluster::startConvert()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
