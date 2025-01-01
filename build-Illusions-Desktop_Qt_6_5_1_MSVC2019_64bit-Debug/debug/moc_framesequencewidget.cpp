/****************************************************************************
** Meta object code from reading C++ file 'framesequencewidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Illusions/framesequencewidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'framesequencewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
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
struct qt_meta_stringdata_CLASSFrameSequenceWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSFrameSequenceWidgetENDCLASS = QtMocHelpers::stringData(
    "FrameSequenceWidget",
    "firstSequenceStarted",
    "",
    "firstSequenceFinished",
    "scrubSequence",
    "value",
    "playSequence",
    "pauseSequence",
    "restartSequence",
    "i",
    "resetIsFirstPlay"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSFrameSequenceWidgetENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[20];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[14];
    char stringdata5[6];
    char stringdata6[13];
    char stringdata7[14];
    char stringdata8[16];
    char stringdata9[2];
    char stringdata10[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSFrameSequenceWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSFrameSequenceWidgetENDCLASS_t qt_meta_stringdata_CLASSFrameSequenceWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 19),  // "FrameSequenceWidget"
        QT_MOC_LITERAL(20, 20),  // "firstSequenceStarted"
        QT_MOC_LITERAL(41, 0),  // ""
        QT_MOC_LITERAL(42, 21),  // "firstSequenceFinished"
        QT_MOC_LITERAL(64, 13),  // "scrubSequence"
        QT_MOC_LITERAL(78, 5),  // "value"
        QT_MOC_LITERAL(84, 12),  // "playSequence"
        QT_MOC_LITERAL(97, 13),  // "pauseSequence"
        QT_MOC_LITERAL(111, 15),  // "restartSequence"
        QT_MOC_LITERAL(127, 1),  // "i"
        QT_MOC_LITERAL(129, 16)   // "resetIsFirstPlay"
    },
    "FrameSequenceWidget",
    "firstSequenceStarted",
    "",
    "firstSequenceFinished",
    "scrubSequence",
    "value",
    "playSequence",
    "pauseSequence",
    "restartSequence",
    "i",
    "resetIsFirstPlay"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFrameSequenceWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,
       3,    0,   57,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   58,    2, 0x0a,    3 /* Public */,
       6,    0,   61,    2, 0x0a,    5 /* Public */,
       7,    0,   62,    2, 0x0a,    6 /* Public */,
       8,    1,   63,    2, 0x0a,    7 /* Public */,
      10,    1,   66,    2, 0x0a,    9 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

Q_CONSTINIT const QMetaObject FrameSequenceWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSFrameSequenceWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSFrameSequenceWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSFrameSequenceWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<FrameSequenceWidget, std::true_type>,
        // method 'firstSequenceStarted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'firstSequenceFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'scrubSequence'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'playSequence'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pauseSequence'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'restartSequence'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'resetIsFirstPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void FrameSequenceWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrameSequenceWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->firstSequenceStarted(); break;
        case 1: _t->firstSequenceFinished(); break;
        case 2: _t->scrubSequence((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->playSequence(); break;
        case 4: _t->pauseSequence(); break;
        case 5: _t->restartSequence((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->resetIsFirstPlay((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FrameSequenceWidget::*)();
            if (_t _q_method = &FrameSequenceWidget::firstSequenceStarted; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FrameSequenceWidget::*)();
            if (_t _q_method = &FrameSequenceWidget::firstSequenceFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *FrameSequenceWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrameSequenceWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSFrameSequenceWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FrameSequenceWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void FrameSequenceWidget::firstSequenceStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FrameSequenceWidget::firstSequenceFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
