/****************************************************************************
** Meta object code from reading C++ file 'testframe.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../testframe.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testframe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
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
struct qt_meta_stringdata_CLASSTestFrameENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSTestFrameENDCLASS = QtMocHelpers::stringData(
    "TestFrame",
    "on_nextQuestionButton_clicked",
    "",
    "loadAvailableTests",
    "on_startTestButton_clicked",
    "loadTestQuestions",
    "showQuestion",
    "index",
    "on_finishTestButton_clicked",
    "getUserIdByUsername",
    "username",
    "updateUserExperience",
    "userId",
    "pointsEarned"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTestFrameENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    1,   66,    2, 0x08,    5 /* Private */,
       8,    0,   69,    2, 0x08,    7 /* Private */,
       9,    1,   70,    2, 0x08,    8 /* Private */,
      11,    2,   73,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Int, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,

       0        // eod
};

Q_CONSTINIT const QMetaObject TestFrame::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_meta_stringdata_CLASSTestFrameENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTestFrameENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTestFrameENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TestFrame, std::true_type>,
        // method 'on_nextQuestionButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadAvailableTests'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_startTestButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadTestQuestions'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showQuestion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_finishTestButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getUserIdByUsername'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'updateUserExperience'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void TestFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestFrame *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_nextQuestionButton_clicked(); break;
        case 1: _t->loadAvailableTests(); break;
        case 2: _t->on_startTestButton_clicked(); break;
        case 3: _t->loadTestQuestions(); break;
        case 4: _t->showQuestion((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->on_finishTestButton_clicked(); break;
        case 6: { int _r = _t->getUserIdByUsername((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->updateUserExperience((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject *TestFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTestFrameENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int TestFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
