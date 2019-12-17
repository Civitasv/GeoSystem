/****************************************************************************
** Meta object code from reading C++ file 'MyTreeWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MyTreeWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyTreeWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyTreeWidget_t {
    QByteArrayData data[32];
    char stringdata0[333];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyTreeWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyTreeWidget_t qt_meta_stringdata_MyTreeWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MyTreeWidget"
QT_MOC_LITERAL(1, 13, 18), // "updateTreeGLSignal"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 4), // "mode"
QT_MOC_LITERAL(4, 38, 8), // "CGeoMap*"
QT_MOC_LITERAL(5, 47, 3), // "map"
QT_MOC_LITERAL(6, 51, 7), // "layerID"
QT_MOC_LITERAL(7, 59, 4), // "size"
QT_MOC_LITERAL(8, 64, 19), // "updateLayerIDSignal"
QT_MOC_LITERAL(9, 84, 19), // "updateColorAndWidth"
QT_MOC_LITERAL(10, 104, 1), // "r"
QT_MOC_LITERAL(11, 106, 1), // "g"
QT_MOC_LITERAL(12, 108, 1), // "b"
QT_MOC_LITERAL(13, 110, 5), // "width"
QT_MOC_LITERAL(14, 116, 21), // "sendColorAndWidthData"
QT_MOC_LITERAL(15, 138, 5), // "index"
QT_MOC_LITERAL(16, 144, 9), // "fillColor"
QT_MOC_LITERAL(17, 154, 11), // "strokeColor"
QT_MOC_LITERAL(18, 166, 9), // "showAttri"
QT_MOC_LITERAL(19, 176, 10), // "CGeoLayer*"
QT_MOC_LITERAL(20, 187, 5), // "layer"
QT_MOC_LITERAL(21, 193, 10), // "IndexGrids"
QT_MOC_LITERAL(22, 204, 22), // "updateMyTreeWidgetSlot"
QT_MOC_LITERAL(23, 227, 9), // "itemClick"
QT_MOC_LITERAL(24, 237, 6), // "viewIt"
QT_MOC_LITERAL(25, 244, 8), // "deleteIt"
QT_MOC_LITERAL(26, 253, 14), // "sltShowPopMenu"
QT_MOC_LITERAL(27, 268, 7), // "serProp"
QT_MOC_LITERAL(28, 276, 9), // "openAttri"
QT_MOC_LITERAL(29, 286, 16), // "getColorAndWidth"
QT_MOC_LITERAL(30, 303, 14), // "showIndexGrids"
QT_MOC_LITERAL(31, 318, 14) // "hideIndexGrids"

    },
    "MyTreeWidget\0updateTreeGLSignal\0\0mode\0"
    "CGeoMap*\0map\0layerID\0size\0updateLayerIDSignal\0"
    "updateColorAndWidth\0r\0g\0b\0width\0"
    "sendColorAndWidthData\0index\0fillColor\0"
    "strokeColor\0showAttri\0CGeoLayer*\0layer\0"
    "IndexGrids\0updateMyTreeWidgetSlot\0"
    "itemClick\0viewIt\0deleteIt\0sltShowPopMenu\0"
    "serProp\0openAttri\0getColorAndWidth\0"
    "showIndexGrids\0hideIndexGrids"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyTreeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   94,    2, 0x06 /* Public */,
       8,    2,  103,    2, 0x06 /* Public */,
       9,    4,  108,    2, 0x06 /* Public */,
      14,    4,  117,    2, 0x06 /* Public */,
      18,    1,  126,    2, 0x06 /* Public */,
      21,    0,  129,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      22,    1,  130,    2, 0x08 /* Private */,
      23,    0,  133,    2, 0x08 /* Private */,
      24,    0,  134,    2, 0x08 /* Private */,
      25,    0,  135,    2, 0x08 /* Private */,
      26,    1,  136,    2, 0x08 /* Private */,
      27,    0,  139,    2, 0x08 /* Private */,
      28,    0,  140,    2, 0x08 /* Private */,
      29,    3,  141,    2, 0x08 /* Private */,
      30,    0,  148,    2, 0x08 /* Private */,
      31,    0,  149,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, QMetaType::Int, QMetaType::Int,    3,    5,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    6,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Double,   10,   11,   12,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::QColor, QMetaType::QColor, QMetaType::Float,   15,   16,   17,   13,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor, QMetaType::QColor, QMetaType::Float,   16,   17,   13,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyTreeWidget *_t = static_cast<MyTreeWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateTreeGLSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< CGeoMap*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->updateLayerIDSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->updateColorAndWidth((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 3: _t->sendColorAndWidthData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 4: _t->showAttri((*reinterpret_cast< CGeoLayer*(*)>(_a[1]))); break;
        case 5: _t->IndexGrids(); break;
        case 6: _t->updateMyTreeWidgetSlot((*reinterpret_cast< CGeoMap*(*)>(_a[1]))); break;
        case 7: _t->itemClick(); break;
        case 8: _t->viewIt(); break;
        case 9: _t->deleteIt(); break;
        case 10: _t->sltShowPopMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 11: _t->serProp(); break;
        case 12: _t->openAttri(); break;
        case 13: _t->getColorAndWidth((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 14: _t->showIndexGrids(); break;
        case 15: _t->hideIndexGrids(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyTreeWidget::*_t)(int , CGeoMap * , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::updateTreeGLSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::updateLayerIDSignal)) {
                *result = 1;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(float , float , float , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::updateColorAndWidth)) {
                *result = 2;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(int , QColor , QColor , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sendColorAndWidthData)) {
                *result = 3;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(CGeoLayer * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::showAttri)) {
                *result = 4;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::IndexGrids)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject MyTreeWidget::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_MyTreeWidget.data,
      qt_meta_data_MyTreeWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyTreeWidget.stringdata0))
        return static_cast<void*>(const_cast< MyTreeWidget*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int MyTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MyTreeWidget::updateTreeGLSignal(int _t1, CGeoMap * _t2, int _t3, int _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyTreeWidget::updateLayerIDSignal(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyTreeWidget::updateColorAndWidth(float _t1, float _t2, float _t3, double _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyTreeWidget::sendColorAndWidthData(int _t1, QColor _t2, QColor _t3, float _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyTreeWidget::showAttri(CGeoLayer * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyTreeWidget::IndexGrids()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
