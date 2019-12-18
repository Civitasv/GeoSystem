/****************************************************************************
** Meta object code from reading C++ file 'LayerColoursSet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LayerColoursSet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LayerColoursSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LayerColoursSet_t {
    QByteArrayData data[11];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LayerColoursSet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LayerColoursSet_t qt_meta_stringdata_LayerColoursSet = {
    {
QT_MOC_LITERAL(0, 0, 15), // "LayerColoursSet"
QT_MOC_LITERAL(1, 16, 14), // "setLayerClours"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 7), // "layerID"
QT_MOC_LITERAL(4, 40, 9), // "attribute"
QT_MOC_LITERAL(5, 50, 12), // "setAttribute"
QT_MOC_LITERAL(6, 63, 9), // "layerNAME"
QT_MOC_LITERAL(7, 73, 14), // "QList<QString>"
QT_MOC_LITERAL(8, 88, 8), // "propsKey"
QT_MOC_LITERAL(9, 97, 13), // "continueClick"
QT_MOC_LITERAL(10, 111, 11) // "cancelClick"

    },
    "LayerColoursSet\0setLayerClours\0\0layerID\0"
    "attribute\0setAttribute\0layerNAME\0"
    "QList<QString>\0propsKey\0continueClick\0"
    "cancelClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LayerColoursSet[] = {

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
       1,    2,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    3,   39,    2, 0x08 /* Private */,
       9,    0,   46,    2, 0x08 /* Private */,
      10,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 7,    3,    6,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LayerColoursSet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LayerColoursSet *_t = static_cast<LayerColoursSet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setLayerClours((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->setAttribute((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QList<QString>(*)>(_a[3]))); break;
        case 2: _t->continueClick(); break;
        case 3: _t->cancelClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LayerColoursSet::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerColoursSet::setLayerClours)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject LayerColoursSet::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LayerColoursSet.data,
      qt_meta_data_LayerColoursSet,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LayerColoursSet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LayerColoursSet::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LayerColoursSet.stringdata0))
        return static_cast<void*>(const_cast< LayerColoursSet*>(this));
    return QWidget::qt_metacast(_clname);
}

int LayerColoursSet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void LayerColoursSet::setLayerClours(int _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
