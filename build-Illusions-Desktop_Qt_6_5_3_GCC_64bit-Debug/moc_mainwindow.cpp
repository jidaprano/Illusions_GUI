/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Illusions/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "nextIllusionSlot",
    "",
    "prevIllusionSlot",
    "switchToOpticalMenu",
    "switchToAudioMenu",
    "switchToIdleScreen",
    "idleStackedSwitch",
    "switchToExhibitScreen",
    "changeAudioIllusion",
    "QWidget*",
    "widget",
    "changeOpticalIllusion",
    "restartAudio",
    "setProgressBarPosition",
    "val"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[11];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[20];
    char stringdata5[18];
    char stringdata6[19];
    char stringdata7[18];
    char stringdata8[22];
    char stringdata9[20];
    char stringdata10[9];
    char stringdata11[7];
    char stringdata12[22];
    char stringdata13[13];
    char stringdata14[23];
    char stringdata15[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 16),  // "nextIllusionSlot"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 16),  // "prevIllusionSlot"
        QT_MOC_LITERAL(46, 19),  // "switchToOpticalMenu"
        QT_MOC_LITERAL(66, 17),  // "switchToAudioMenu"
        QT_MOC_LITERAL(84, 18),  // "switchToIdleScreen"
        QT_MOC_LITERAL(103, 17),  // "idleStackedSwitch"
        QT_MOC_LITERAL(121, 21),  // "switchToExhibitScreen"
        QT_MOC_LITERAL(143, 19),  // "changeAudioIllusion"
        QT_MOC_LITERAL(163, 8),  // "QWidget*"
        QT_MOC_LITERAL(172, 6),  // "widget"
        QT_MOC_LITERAL(179, 21),  // "changeOpticalIllusion"
        QT_MOC_LITERAL(201, 12),  // "restartAudio"
        QT_MOC_LITERAL(214, 22),  // "setProgressBarPosition"
        QT_MOC_LITERAL(237, 3)   // "val"
    },
    "MainWindow",
    "nextIllusionSlot",
    "",
    "prevIllusionSlot",
    "switchToOpticalMenu",
    "switchToAudioMenu",
    "switchToIdleScreen",
    "idleStackedSwitch",
    "switchToExhibitScreen",
    "changeAudioIllusion",
    "QWidget*",
    "widget",
    "changeOpticalIllusion",
    "restartAudio",
    "setProgressBarPosition",
    "val"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    0,   81,    2, 0x08,    2 /* Private */,
       4,    0,   82,    2, 0x08,    3 /* Private */,
       5,    0,   83,    2, 0x08,    4 /* Private */,
       6,    0,   84,    2, 0x08,    5 /* Private */,
       7,    0,   85,    2, 0x08,    6 /* Private */,
       8,    0,   86,    2, 0x08,    7 /* Private */,
       9,    1,   87,    2, 0x08,    8 /* Private */,
      12,    1,   90,    2, 0x08,   10 /* Private */,
      13,    0,   93,    2, 0x08,   12 /* Private */,
      14,    1,   94,    2, 0x08,   13 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   15,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'nextIllusionSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'prevIllusionSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switchToOpticalMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switchToAudioMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switchToIdleScreen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'idleStackedSwitch'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switchToExhibitScreen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeAudioIllusion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        // method 'changeOpticalIllusion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        // method 'restartAudio'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setProgressBarPosition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->nextIllusionSlot(); break;
        case 1: _t->prevIllusionSlot(); break;
        case 2: _t->switchToOpticalMenu(); break;
        case 3: _t->switchToAudioMenu(); break;
        case 4: _t->switchToIdleScreen(); break;
        case 5: _t->idleStackedSwitch(); break;
        case 6: _t->switchToExhibitScreen(); break;
        case 7: _t->changeAudioIllusion((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        case 8: _t->changeOpticalIllusion((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        case 9: _t->restartAudio(); break;
        case 10: _t->setProgressBarPosition((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
