/****************************************************************************
** Meta object code from reading C++ file 'singlemainwin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../singlemainwin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'singlemainwin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SingleMainWin_t {
    QByteArrayData data[10];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SingleMainWin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SingleMainWin_t qt_meta_stringdata_SingleMainWin = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SingleMainWin"
QT_MOC_LITERAL(1, 14, 5), // "pause"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "help"
QT_MOC_LITERAL(4, 26, 10), // "updateTime"
QT_MOC_LITERAL(5, 37, 8), // "gameOver"
QT_MOC_LITERAL(6, 46, 4), // "mode"
QT_MOC_LITERAL(7, 51, 8), // "hintStop"
QT_MOC_LITERAL(8, 60, 9), // "flashStop"
QT_MOC_LITERAL(9, 70, 4) // "save"

    },
    "SingleMainWin\0pause\0\0help\0updateTime\0"
    "gameOver\0mode\0hintStop\0flashStop\0save"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SingleMainWin[] = {

 // content:
       8,       // revision
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
       5,    1,   57,    2, 0x08 /* Private */,
       5,    0,   60,    2, 0x28 /* Private | MethodCloned */,
       7,    0,   61,    2, 0x08 /* Private */,
       8,    0,   62,    2, 0x08 /* Private */,
       9,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SingleMainWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SingleMainWin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pause(); break;
        case 1: _t->help(); break;
        case 2: _t->updateTime(); break;
        case 3: _t->gameOver((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->gameOver(); break;
        case 5: _t->hintStop(); break;
        case 6: _t->flashStop(); break;
        case 7: _t->save(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SingleMainWin::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_SingleMainWin.data,
    qt_meta_data_SingleMainWin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SingleMainWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SingleMainWin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SingleMainWin.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SingleMainWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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