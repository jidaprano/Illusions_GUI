/****************************************************************************
** Meta object code from reading C++ file 'videowidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Illusions/videowidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videowidget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSVideoWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSVideoWidgetENDCLASS = QtMocHelpers::stringData(
    "VideoWidget",
    "firstVideoStarted",
    "",
    "firstVideoFinished",
    "changePosition",
    "play",
    "i",
    "pause",
    "onPlaybackStateChanged",
    "QMediaPlayer::PlaybackState",
    "status",
    "resetIsFirstPlay"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSVideoWidgetENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[12];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[15];
    char stringdata5[5];
    char stringdata6[2];
    char stringdata7[6];
    char stringdata8[23];
    char stringdata9[28];
    char stringdata10[7];
    char stringdata11[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSVideoWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSVideoWidgetENDCLASS_t qt_meta_stringdata_CLASSVideoWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "VideoWidget"
        QT_MOC_LITERAL(12, 17),  // "firstVideoStarted"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 18),  // "firstVideoFinished"
        QT_MOC_LITERAL(50, 14),  // "changePosition"
        QT_MOC_LITERAL(65, 4),  // "play"
        QT_MOC_LITERAL(70, 1),  // "i"
        QT_MOC_LITERAL(72, 5),  // "pause"
        QT_MOC_LITERAL(78, 22),  // "onPlaybackStateChanged"
        QT_MOC_LITERAL(101, 27),  // "QMediaPlayer::PlaybackState"
        QT_MOC_LITERAL(129, 6),  // "status"
        QT_MOC_LITERAL(136, 16)   // "resetIsFirstPlay"
    },
    "VideoWidget",
    "firstVideoStarted",
    "",
    "firstVideoFinished",
    "changePosition",
    "play",
    "i",
    "pause",
    "onPlaybackStateChanged",
    "QMediaPlayer::PlaybackState",
    "status",
    "resetIsFirstPlay"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSVideoWidgetENDCLASS[] = {

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
       5,    1,   61,    2, 0x0a,    5 /* Public */,
       7,    1,   64,    2, 0x0a,    7 /* Public */,
       8,    1,   67,    2, 0x0a,    9 /* Public */,
      11,    1,   70,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject VideoWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSVideoWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSVideoWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSVideoWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<VideoWidget, std::true_type>,
        // method 'firstVideoStarted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'firstVideoFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changePosition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'play'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'pause'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onPlaybackStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMediaPlayer::PlaybackState, std::false_type>,
        // method 'resetIsFirstPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void VideoWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VideoWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->firstVideoStarted(); break;
        case 1: _t->firstVideoFinished(); break;
        case 2: _t->changePosition((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->play((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->pause((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->onPlaybackStateChanged((*reinterpret_cast< std::add_pointer_t<QMediaPlayer::PlaybackState>>(_a[1]))); break;
        case 6: _t->resetIsFirstPlay((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VideoWidget::*)();
            if (_t _q_method = &VideoWidget::firstVideoStarted; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VideoWidget::*)();
            if (_t _q_method = &VideoWidget::firstVideoFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *VideoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSVideoWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int VideoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void VideoWidget::firstVideoStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VideoWidget::firstVideoFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
