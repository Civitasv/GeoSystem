/****************************************************************************
** Meta object code from reading C++ file 'MyGLWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MyGLWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyGLWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyGLWidget_t {
    QByteArrayData data[22];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyGLWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyGLWidget_t qt_meta_stringdata_MyGLWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MyGLWidget"
QT_MOC_LITERAL(1, 11, 14), // "updateMyGLSlot"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 4), // "mode"
QT_MOC_LITERAL(4, 32, 11), // "const char*"
QT_MOC_LITERAL(5, 44, 8), // "filename"
QT_MOC_LITERAL(6, 53, 7), // "layerID"
QT_MOC_LITERAL(7, 61, 24), // "updateMyGLPostgresqlSlot"
QT_MOC_LITERAL(8, 86, 4), // "port"
QT_MOC_LITERAL(9, 91, 6), // "dbname"
QT_MOC_LITERAL(10, 98, 4), // "host"
QT_MOC_LITERAL(11, 103, 4), // "user"
QT_MOC_LITERAL(12, 108, 8), // "password"
QT_MOC_LITERAL(13, 117, 5), // "table"
QT_MOC_LITERAL(14, 123, 10), // "updateData"
QT_MOC_LITERAL(15, 134, 8), // "CGeoMap*"
QT_MOC_LITERAL(16, 143, 3), // "map"
QT_MOC_LITERAL(17, 147, 13), // "updateLayerID"
QT_MOC_LITERAL(18, 161, 7), // "LayerID"
QT_MOC_LITERAL(19, 169, 21), // "getColorAndWidthData2"
QT_MOC_LITERAL(20, 191, 5), // "color"
QT_MOC_LITERAL(21, 197, 5) // "width"

    },
    "MyGLWidget\0updateMyGLSlot\0\0mode\0"
    "const char*\0filename\0layerID\0"
    "updateMyGLPostgresqlSlot\0port\0dbname\0"
    "host\0user\0password\0table\0updateData\0"
    "CGeoMap*\0map\0updateLayerID\0LayerID\0"
    "getColorAndWidthData2\0color\0width"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGLWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x0a /* Public */,
       7,    8,   46,    2, 0x0a /* Public */,
      14,    2,   63,    2, 0x0a /* Public */,
      17,    2,   68,    2, 0x0a /* Public */,
      19,    3,   73,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    6,    8,    9,   10,   11,   12,   13,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 15,    3,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::QColor, QMetaType::Float,    6,   20,   21,

       0        // eod
};

void MyGLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyGLWidget *_t = static_cast<MyGLWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateMyGLSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->updateMyGLPostgresqlSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8]))); break;
        case 2: _t->updateData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< CGeoMap*(*)>(_a[2]))); break;
        case 3: _t->updateLayerID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->getColorAndWidthData2((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject MyGLWidget::staticMetaObject = {
    { &QOpenGLWidget::staticMetaObject, qt_meta_stringdata_MyGLWidget.data,
      qt_meta_data_MyGLWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyGLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyGLWidget.stringdata0))
        return static_cast<void*>(const_cast< MyGLWidget*>(this));
    if (!strcmp(_clname, "QOpenGLFunctions_4_5_Core"))
        return static_cast< QOpenGLFunctions_4_5_Core*>(const_cast< MyGLWidget*>(this));
    return QOpenGLWidget::qt_metacast(_clname);
}

int MyGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
