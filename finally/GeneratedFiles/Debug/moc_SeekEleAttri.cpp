/****************************************************************************
** Meta object code from reading C++ file 'SeekEleAttri.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SeekEleAttri.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SeekEleAttri.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SeekEleAttri_t {
    QByteArrayData data[13];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SeekEleAttri_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SeekEleAttri_t qt_meta_stringdata_SeekEleAttri = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SeekEleAttri"
QT_MOC_LITERAL(1, 13, 21), // "sendColorAndWidthData"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5), // "objID"
QT_MOC_LITERAL(4, 42, 9), // "fillColor"
QT_MOC_LITERAL(5, 52, 11), // "strokeColor"
QT_MOC_LITERAL(6, 64, 5), // "width"
QT_MOC_LITERAL(7, 70, 7), // "restore"
QT_MOC_LITERAL(8, 78, 9), // "showAttri"
QT_MOC_LITERAL(9, 88, 11), // "CGeoObject*"
QT_MOC_LITERAL(10, 100, 3), // "obj"
QT_MOC_LITERAL(11, 104, 13), // "continueClick"
QT_MOC_LITERAL(12, 118, 11) // "cancelClick"

    },
    "SeekEleAttri\0sendColorAndWidthData\0\0"
    "objID\0fillColor\0strokeColor\0width\0"
    "restore\0showAttri\0CGeoObject*\0obj\0"
    "continueClick\0cancelClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SeekEleAttri[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   39,    2, 0x06 /* Public */,
       7,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   51,    2, 0x08 /* Private */,
      11,    0,   56,    2, 0x08 /* Private */,
      12,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QColor, QMetaType::QColor, QMetaType::Float,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int,   10,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SeekEleAttri::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SeekEleAttri *_t = static_cast<SeekEleAttri *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendColorAndWidthData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 1: _t->restore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->showAttri((*reinterpret_cast< CGeoObject*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->continueClick(); break;
        case 4: _t->cancelClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SeekEleAttri::*_t)(int , QColor , QColor , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SeekEleAttri::sendColorAndWidthData)) {
                *result = 0;
            }
        }
        {
            typedef void (SeekEleAttri::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SeekEleAttri::restore)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject SeekEleAttri::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SeekEleAttri.data,
      qt_meta_data_SeekEleAttri,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SeekEleAttri::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SeekEleAttri::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SeekEleAttri.stringdata0))
        return static_cast<void*>(const_cast< SeekEleAttri*>(this));
    return QWidget::qt_metacast(_clname);
}

int SeekEleAttri::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void SeekEleAttri::sendColorAndWidthData(int _t1, QColor _t2, QColor _t3, float _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SeekEleAttri::restore(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
