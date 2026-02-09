/****************************************************************************
** Meta object code from reading C++ file 'CameraViewModel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../src/services/include/projet_cfr/services/CameraViewModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CameraViewModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_projet_cfr__services__CameraViewModel_t {
    const uint offsetsAndSize[36];
    char stringdata0[234];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_projet_cfr__services__CameraViewModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_projet_cfr__services__CameraViewModel_t qt_meta_stringdata_projet_cfr__services__CameraViewModel = {
    {
QT_MOC_LITERAL(0, 37), // "projet_cfr::services::CameraV..."
QT_MOC_LITERAL(38, 16), // "availableChanged"
QT_MOC_LITERAL(55, 0), // ""
QT_MOC_LITERAL(56, 20), // "selectedCountChanged"
QT_MOC_LITERAL(77, 22), // "selectedSourcesChanged"
QT_MOC_LITERAL(100, 14), // "toggleSelected"
QT_MOC_LITERAL(115, 3), // "row"
QT_MOC_LITERAL(119, 11), // "setSelected"
QT_MOC_LITERAL(131, 8), // "selected"
QT_MOC_LITERAL(140, 7), // "refresh"
QT_MOC_LITERAL(148, 9), // "available"
QT_MOC_LITERAL(158, 13), // "selectedCount"
QT_MOC_LITERAL(172, 15), // "selectedSources"
QT_MOC_LITERAL(188, 5), // "Roles"
QT_MOC_LITERAL(194, 8), // "NameRole"
QT_MOC_LITERAL(203, 6), // "IdRole"
QT_MOC_LITERAL(210, 12), // "SelectedRole"
QT_MOC_LITERAL(223, 10) // "DeviceRole"

    },
    "projet_cfr::services::CameraViewModel\0"
    "availableChanged\0\0selectedCountChanged\0"
    "selectedSourcesChanged\0toggleSelected\0"
    "row\0setSelected\0selected\0refresh\0"
    "available\0selectedCount\0selectedSources\0"
    "Roles\0NameRole\0IdRole\0SelectedRole\0"
    "DeviceRole"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_projet_cfr__services__CameraViewModel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       3,   62, // properties
       1,   77, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    4 /* Public */,
       3,    0,   51,    2, 0x06,    5 /* Public */,
       4,    0,   52,    2, 0x06,    6 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   53,    2, 0x02,    7 /* Public */,
       7,    2,   56,    2, 0x02,    9 /* Public */,
       9,    0,   61,    2, 0x02,   12 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    6,    8,
    QMetaType::Void,

 // properties: name, type, flags
      10, QMetaType::Bool, 0x00015001, uint(0), 0,
      11, QMetaType::Int, 0x00015001, uint(1), 0,
      12, QMetaType::QVariantList, 0x00015001, uint(2), 0,

 // enums: name, alias, flags, count, data
      13,   13, 0x0,    4,   82,

 // enum data: key, value
      14, uint(projet_cfr::services::CameraViewModel::NameRole),
      15, uint(projet_cfr::services::CameraViewModel::IdRole),
      16, uint(projet_cfr::services::CameraViewModel::SelectedRole),
      17, uint(projet_cfr::services::CameraViewModel::DeviceRole),

       0        // eod
};

void projet_cfr::services::CameraViewModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CameraViewModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->availableChanged(); break;
        case 1: _t->selectedCountChanged(); break;
        case 2: _t->selectedSourcesChanged(); break;
        case 3: _t->toggleSelected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->setSelected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 5: _t->refresh(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CameraViewModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CameraViewModel::availableChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CameraViewModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CameraViewModel::selectedCountChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CameraViewModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CameraViewModel::selectedSourcesChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CameraViewModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->available(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->selectedCount(); break;
        case 2: *reinterpret_cast< QVariantList*>(_v) = _t->selectedSources(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject projet_cfr::services::CameraViewModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_projet_cfr__services__CameraViewModel.offsetsAndSize,
    qt_meta_data_projet_cfr__services__CameraViewModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_projet_cfr__services__CameraViewModel_t
, QtPrivate::TypeAndForceComplete<bool, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>, QtPrivate::TypeAndForceComplete<CameraViewModel, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>

>,
    nullptr
} };


const QMetaObject *projet_cfr::services::CameraViewModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *projet_cfr::services::CameraViewModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_projet_cfr__services__CameraViewModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int projet_cfr::services::CameraViewModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void projet_cfr::services::CameraViewModel::availableChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void projet_cfr::services::CameraViewModel::selectedCountChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void projet_cfr::services::CameraViewModel::selectedSourcesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
