/****************************************************************************
** Meta object code from reading C++ file 'myclass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../myclass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myclass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyClass_t {
    QByteArrayData data[24];
    char stringdata0[275];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyClass_t qt_meta_stringdata_MyClass = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MyClass"
QT_MOC_LITERAL(1, 8, 16), // "updateMyGLSignal"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "mode"
QT_MOC_LITERAL(4, 31, 11), // "const char*"
QT_MOC_LITERAL(5, 43, 8), // "filename"
QT_MOC_LITERAL(6, 52, 7), // "layerID"
QT_MOC_LITERAL(7, 60, 26), // "updateMyGLPostgresqlSignal"
QT_MOC_LITERAL(8, 87, 6), // "dbname"
QT_MOC_LITERAL(9, 94, 4), // "host"
QT_MOC_LITERAL(10, 99, 4), // "user"
QT_MOC_LITERAL(11, 104, 8), // "password"
QT_MOC_LITERAL(12, 113, 5), // "table"
QT_MOC_LITERAL(13, 119, 24), // "updateMyTreeWidgetSignal"
QT_MOC_LITERAL(14, 144, 8), // "CGeoMap*"
QT_MOC_LITERAL(15, 153, 3), // "map"
QT_MOC_LITERAL(16, 157, 10), // "updateData"
QT_MOC_LITERAL(17, 168, 19), // "updateLayerIDSignal"
QT_MOC_LITERAL(18, 188, 11), // "readGeoJson"
QT_MOC_LITERAL(19, 200, 9), // "readShape"
QT_MOC_LITERAL(20, 210, 13), // "saveShapefile"
QT_MOC_LITERAL(21, 224, 15), // "getDatabaseData"
QT_MOC_LITERAL(22, 240, 16), // "updateTreeGLSlot"
QT_MOC_LITERAL(23, 257, 17) // "updateLayerIDSlot"

    },
    "MyClass\0updateMyGLSignal\0\0mode\0"
    "const char*\0filename\0layerID\0"
    "updateMyGLPostgresqlSignal\0dbname\0"
    "host\0user\0password\0table\0"
    "updateMyTreeWidgetSignal\0CGeoMap*\0map\0"
    "updateData\0updateLayerIDSignal\0"
    "readGeoJson\0readShape\0saveShapefile\0"
    "getDatabaseData\0updateTreeGLSlot\0"
    "updateLayerIDSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyClass[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   69,    2, 0x06 /* Public */,
       7,    7,   76,    2, 0x06 /* Public */,
      13,    1,   91,    2, 0x06 /* Public */,
      16,    2,   94,    2, 0x06 /* Public */,
      17,    2,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,  104,    2, 0x08 /* Private */,
      19,    0,  105,    2, 0x08 /* Private */,
      20,    0,  106,    2, 0x08 /* Private */,
      21,    0,  107,    2, 0x08 /* Private */,
      22,    2,  108,    2, 0x08 /* Private */,
      23,    2,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    6,    8,    9,   10,   11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 14,    3,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 14,    3,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    6,

       0        // eod
};

void MyClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyClass *_t = static_cast<MyClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateMyGLSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->updateMyGLPostgresqlSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7]))); break;
        case 2: _t->updateMyTreeWidgetSignal((*reinterpret_cast< CGeoMap*(*)>(_a[1]))); break;
        case 3: _t->updateData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< CGeoMap*(*)>(_a[2]))); break;
        case 4: _t->updateLayerIDSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->readGeoJson(); break;
        case 6: _t->readShape(); break;
        case 7: _t->saveShapefile(); break;
        case 8: _t->getDatabaseData(); break;
        case 9: _t->updateTreeGLSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< CGeoMap*(*)>(_a[2]))); break;
        case 10: _t->updateLayerIDSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyClass::*_t)(int , const char * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyClass::updateMyGLSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (MyClass::*_t)(int , int , QString , QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyClass::updateMyGLPostgresqlSignal)) {
                *result = 1;
            }
        }
        {
            typedef void (MyClass::*_t)(CGeoMap * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyClass::updateMyTreeWidgetSignal)) {
                *result = 2;
            }
        }
        {
            typedef void (MyClass::*_t)(int , CGeoMap * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyClass::updateData)) {
                *result = 3;
            }
        }
        {
            typedef void (MyClass::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyClass::updateLayerIDSignal)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject MyClass::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MyClass.data,
      qt_meta_data_MyClass,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyClass::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyClass.stringdata0))
        return static_cast<void*>(const_cast< MyClass*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MyClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MyClass::updateMyGLSignal(int _t1, const char * _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyClass::updateMyGLPostgresqlSignal(int _t1, int _t2, QString _t3, QString _t4, QString _t5, QString _t6, QString _t7)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyClass::updateMyTreeWidgetSignal(CGeoMap * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyClass::updateData(int _t1, CGeoMap * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyClass::updateLayerIDSignal(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
