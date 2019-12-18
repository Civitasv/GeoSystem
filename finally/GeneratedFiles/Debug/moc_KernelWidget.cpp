/****************************************************************************
** Meta object code from reading C++ file 'KernelWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../KernelWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KernelWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KernelWidget_t {
    QByteArrayData data[8];
    char stringdata0[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KernelWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KernelWidget_t qt_meta_stringdata_KernelWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "KernelWidget"
QT_MOC_LITERAL(1, 13, 10), // "KDEAnalyze"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "bandWidth"
QT_MOC_LITERAL(4, 35, 7), // "float**"
QT_MOC_LITERAL(5, 43, 3), // "loc"
QT_MOC_LITERAL(6, 47, 6), // "maxLoc"
QT_MOC_LITERAL(7, 54, 6) // "minLoc"

    },
    "KernelWidget\0KDEAnalyze\0\0bandWidth\0"
    "float**\0loc\0maxLoc\0minLoc"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KernelWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Float, 0x80000000 | 4, QMetaType::Float, QMetaType::Float,    3,    5,    6,    7,

       0        // eod
};

void KernelWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KernelWidget *_t = static_cast<KernelWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->KDEAnalyze((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float**(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        default: ;
        }
    }
}

const QMetaObject KernelWidget::staticMetaObject = {
    { &QOpenGLWidget::staticMetaObject, qt_meta_stringdata_KernelWidget.data,
      qt_meta_data_KernelWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KernelWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KernelWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KernelWidget.stringdata0))
        return static_cast<void*>(const_cast< KernelWidget*>(this));
    if (!strcmp(_clname, "QOpenGLFunctions_4_5_Core"))
        return static_cast< QOpenGLFunctions_4_5_Core*>(const_cast< KernelWidget*>(this));
    return QOpenGLWidget::qt_metacast(_clname);
}

int KernelWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
