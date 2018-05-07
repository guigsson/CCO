/****************************************************************************
** Meta object code from reading C++ file 'testellipsisproximityalgorithm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcc/test/testellipsisproximityalgorithm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testellipsisproximityalgorithm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestEllipsisProximityAlgorithm_t {
    QByteArrayData data[10];
    char stringdata0[270];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestEllipsisProximityAlgorithm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestEllipsisProximityAlgorithm_t qt_meta_stringdata_TestEllipsisProximityAlgorithm = {
    {
QT_MOC_LITERAL(0, 0, 30), // "TestEllipsisProximityAlgorithm"
QT_MOC_LITERAL(1, 31, 25), // "TestInBetweenCircleCenter"
QT_MOC_LITERAL(2, 57, 0), // ""
QT_MOC_LITERAL(3, 58, 24), // "TestInBetweenCircleOuter"
QT_MOC_LITERAL(4, 83, 31), // "TestInBetweenCircleNotCollinear"
QT_MOC_LITERAL(5, 115, 31), // "TestInBetweenCircleNotInBetween"
QT_MOC_LITERAL(6, 147, 27), // "TestInBetweenEllipsisCenter"
QT_MOC_LITERAL(7, 175, 26), // "TestInBetweenEllipsisOuter"
QT_MOC_LITERAL(8, 202, 33), // "TestInBetweenEllipsisNotColli..."
QT_MOC_LITERAL(9, 236, 33) // "TestInBetweenEllipsisNotInBet..."

    },
    "TestEllipsisProximityAlgorithm\0"
    "TestInBetweenCircleCenter\0\0"
    "TestInBetweenCircleOuter\0"
    "TestInBetweenCircleNotCollinear\0"
    "TestInBetweenCircleNotInBetween\0"
    "TestInBetweenEllipsisCenter\0"
    "TestInBetweenEllipsisOuter\0"
    "TestInBetweenEllipsisNotCollinear\0"
    "TestInBetweenEllipsisNotInBetween"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestEllipsisProximityAlgorithm[] = {

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

void TestEllipsisProximityAlgorithm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestEllipsisProximityAlgorithm *_t = static_cast<TestEllipsisProximityAlgorithm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TestInBetweenCircleCenter(); break;
        case 1: _t->TestInBetweenCircleOuter(); break;
        case 2: _t->TestInBetweenCircleNotCollinear(); break;
        case 3: _t->TestInBetweenCircleNotInBetween(); break;
        case 4: _t->TestInBetweenEllipsisCenter(); break;
        case 5: _t->TestInBetweenEllipsisOuter(); break;
        case 6: _t->TestInBetweenEllipsisNotCollinear(); break;
        case 7: _t->TestInBetweenEllipsisNotInBetween(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject TestEllipsisProximityAlgorithm::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TestEllipsisProximityAlgorithm.data,
      qt_meta_data_TestEllipsisProximityAlgorithm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TestEllipsisProximityAlgorithm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestEllipsisProximityAlgorithm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestEllipsisProximityAlgorithm.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TestEllipsisProximityAlgorithm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
