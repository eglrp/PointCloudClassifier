/****************************************************************************
** Meta object code from reading C++ file 'dlgTxt2PCD.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dlgTxt2PCD.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgTxt2PCD.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_dlgTxt2PCD_t {
    QByteArrayData data[6];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dlgTxt2PCD_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dlgTxt2PCD_t qt_meta_stringdata_dlgTxt2PCD = {
    {
QT_MOC_LITERAL(0, 0, 10), // "dlgTxt2PCD"
QT_MOC_LITERAL(1, 11, 12), // "startConvert"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "toolClicked1"
QT_MOC_LITERAL(4, 38, 12), // "toolClicked2"
QT_MOC_LITERAL(5, 51, 13) // "convertButton"

    },
    "dlgTxt2PCD\0startConvert\0\0toolClicked1\0"
    "toolClicked2\0convertButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dlgTxt2PCD[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dlgTxt2PCD::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        dlgTxt2PCD *_t = static_cast<dlgTxt2PCD *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startConvert(); break;
        case 1: _t->toolClicked1(); break;
        case 2: _t->toolClicked2(); break;
        case 3: _t->convertButton(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (dlgTxt2PCD::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dlgTxt2PCD::startConvert)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject dlgTxt2PCD::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dlgTxt2PCD.data,
      qt_meta_data_dlgTxt2PCD,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *dlgTxt2PCD::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dlgTxt2PCD::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_dlgTxt2PCD.stringdata0))
        return static_cast<void*>(const_cast< dlgTxt2PCD*>(this));
    return QDialog::qt_metacast(_clname);
}

int dlgTxt2PCD::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void dlgTxt2PCD::startConvert()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
