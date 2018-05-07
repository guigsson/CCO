/****************************************************************************
** Meta object code from reading C++ file 'testneighborhood.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcc/test/testneighborhood.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testneighborhood.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestNeighborhood_t {
    QByteArrayData data[10];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestNeighborhood_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestNeighborhood_t qt_meta_stringdata_TestNeighborhood = {
    {
QT_MOC_LITERAL(0, 0, 16), // "TestNeighborhood"
QT_MOC_LITERAL(1, 17, 15), // "TestGetUserById"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 14), // "TestGetPOIById"
QT_MOC_LITERAL(4, 49, 15), // "TestGetVicinity"
QT_MOC_LITERAL(5, 65, 26), // "TestGetVicinityNoNeighbors"
QT_MOC_LITERAL(6, 92, 23), // "TestGetSameTypeVicinity"
QT_MOC_LITERAL(7, 116, 42), // "TestGetSameTypeVicinityNoSame..."
QT_MOC_LITERAL(8, 159, 34), // "TestGetSameTypeVicinityNoNeig..."
QT_MOC_LITERAL(9, 194, 17) // "TestGetTrajectory"

    },
    "TestNeighborhood\0TestGetUserById\0\0"
    "TestGetPOIById\0TestGetVicinity\0"
    "TestGetVicinityNoNeighbors\0"
    "TestGetSameTypeVicinity\0"
    "TestGetSameTypeVicinityNoSameTypeNeighbors\0"
    "TestGetSameTypeVicinityNoNeighbors\0"
    "TestGetTrajectory"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestNeighborhood[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
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

void TestNeighborhood::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestNeighborhood *_t = static_cast<TestNeighborhood *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TestGetUserById(); break;
        case 1: _t->TestGetPOIById(); break;
        case 2: _t->TestGetVicinity(); break;
        case 3: _t->TestGetVicinityNoNeighbors(); break;
        case 4: _t->TestGetSameTypeVicinity(); break;
        case 5: _t->TestGetSameTypeVicinityNoSameTypeNeighbors(); break;
        case 6: _t->TestGetSameTypeVicinityNoNeighbors(); break;
        case 7: _t->TestGetTrajectory(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject TestNeighborhood::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TestNeighborhood.data,
      qt_meta_data_TestNeighborhood,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TestNeighborhood::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestNeighborhood::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestNeighborhood.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TestNeighborhood::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
