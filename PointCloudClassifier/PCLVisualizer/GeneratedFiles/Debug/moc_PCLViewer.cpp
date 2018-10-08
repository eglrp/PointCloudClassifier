/****************************************************************************
** Meta object code from reading C++ file 'PCLViewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PCLViewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PCLViewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PCLViewer_t {
    QByteArrayData data[15];
    char stringdata0[245];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PCLViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PCLViewer_t qt_meta_stringdata_PCLViewer = {
    {
QT_MOC_LITERAL(0, 0, 9), // "PCLViewer"
QT_MOC_LITERAL(1, 10, 14), // "actionOpenFile"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 14), // "showPointCloud"
QT_MOC_LITERAL(4, 41, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(5, 58, 23), // "actionPassThroughFilter"
QT_MOC_LITERAL(6, 82, 18), // "actionIntensityFix"
QT_MOC_LITERAL(7, 101, 19), // "actionKdTreeCluster"
QT_MOC_LITERAL(8, 121, 18), // "actionBinarySignal"
QT_MOC_LITERAL(9, 140, 15), // "actionGrayImage"
QT_MOC_LITERAL(10, 156, 11), // "actionAbout"
QT_MOC_LITERAL(11, 168, 13), // "actionLAS2TXT"
QT_MOC_LITERAL(12, 182, 18), // "actionTXT2PCDASCII"
QT_MOC_LITERAL(13, 201, 24), // "actionPCDBINARY2PCDASCII"
QT_MOC_LITERAL(14, 226, 18) // "actionPCDASCII2TXT"

    },
    "PCLViewer\0actionOpenFile\0\0showPointCloud\0"
    "QTreeWidgetItem*\0actionPassThroughFilter\0"
    "actionIntensityFix\0actionKdTreeCluster\0"
    "actionBinarySignal\0actionGrayImage\0"
    "actionAbout\0actionLAS2TXT\0actionTXT2PCDASCII\0"
    "actionPCDBINARY2PCDASCII\0actionPCDASCII2TXT"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PCLViewer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    2,   75,    2, 0x0a /* Public */,
       5,    0,   80,    2, 0x0a /* Public */,
       6,    0,   81,    2, 0x0a /* Public */,
       7,    0,   82,    2, 0x0a /* Public */,
       8,    0,   83,    2, 0x0a /* Public */,
       9,    0,   84,    2, 0x0a /* Public */,
      10,    0,   85,    2, 0x0a /* Public */,
      11,    0,   86,    2, 0x0a /* Public */,
      12,    0,   87,    2, 0x0a /* Public */,
      13,    0,   88,    2, 0x0a /* Public */,
      14,    0,   89,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PCLViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PCLViewer *_t = static_cast<PCLViewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->actionOpenFile(); break;
        case 1: _t->showPointCloud((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->actionPassThroughFilter(); break;
        case 3: _t->actionIntensityFix(); break;
        case 4: _t->actionKdTreeCluster(); break;
        case 5: _t->actionBinarySignal(); break;
        case 6: _t->actionGrayImage(); break;
        case 7: _t->actionAbout(); break;
        case 8: _t->actionLAS2TXT(); break;
        case 9: _t->actionTXT2PCDASCII(); break;
        case 10: _t->actionPCDBINARY2PCDASCII(); break;
        case 11: _t->actionPCDASCII2TXT(); break;
        default: ;
        }
    }
}

const QMetaObject PCLViewer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PCLViewer.data,
      qt_meta_data_PCLViewer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PCLViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PCLViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PCLViewer.stringdata0))
        return static_cast<void*>(const_cast< PCLViewer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int PCLViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
