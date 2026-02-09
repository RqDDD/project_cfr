/****************************************************************************
** Meta object code from reading C++ file 'BpmnEditorModel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../src/services/include/projet_cfr/services/BpmnEditorModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BpmnEditorModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_projet_cfr__services__BpmnEditorModel_t {
    const uint offsetsAndSize[44];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_projet_cfr__services__BpmnEditorModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_projet_cfr__services__BpmnEditorModel_t qt_meta_stringdata_projet_cfr__services__BpmnEditorModel = {
    {
QT_MOC_LITERAL(0, 37), // "projet_cfr::services::BpmnEdi..."
QT_MOC_LITERAL(38, 10), // "xmlChanged"
QT_MOC_LITERAL(49, 0), // ""
QT_MOC_LITERAL(50, 10), // "addElement"
QT_MOC_LITERAL(61, 4), // "type"
QT_MOC_LITERAL(66, 1), // "x"
QT_MOC_LITERAL(68, 1), // "y"
QT_MOC_LITERAL(70, 11), // "moveElement"
QT_MOC_LITERAL(82, 3), // "row"
QT_MOC_LITERAL(86, 8), // "setLabel"
QT_MOC_LITERAL(95, 5), // "label"
QT_MOC_LITERAL(101, 13), // "removeElement"
QT_MOC_LITERAL(115, 5), // "clear"
QT_MOC_LITERAL(121, 3), // "xml"
QT_MOC_LITERAL(125, 5), // "Roles"
QT_MOC_LITERAL(131, 13), // "ElementIdRole"
QT_MOC_LITERAL(145, 8), // "TypeRole"
QT_MOC_LITERAL(154, 5), // "XRole"
QT_MOC_LITERAL(160, 5), // "YRole"
QT_MOC_LITERAL(166, 9), // "WidthRole"
QT_MOC_LITERAL(176, 10), // "HeightRole"
QT_MOC_LITERAL(187, 9) // "LabelRole"

    },
    "projet_cfr::services::BpmnEditorModel\0"
    "xmlChanged\0\0addElement\0type\0x\0y\0"
    "moveElement\0row\0setLabel\0label\0"
    "removeElement\0clear\0xml\0Roles\0"
    "ElementIdRole\0TypeRole\0XRole\0YRole\0"
    "WidthRole\0HeightRole\0LabelRole"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_projet_cfr__services__BpmnEditorModel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       1,   74, // properties
       1,   79, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    2 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       3,    3,   51,    2, 0x02,    3 /* Public */,
       7,    3,   58,    2, 0x02,    7 /* Public */,
       9,    2,   65,    2, 0x02,   11 /* Public */,
      11,    1,   70,    2, 0x02,   14 /* Public */,
      12,    0,   73,    2, 0x02,   16 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Int, QMetaType::QString, QMetaType::QReal, QMetaType::QReal,    4,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::QReal, QMetaType::QReal,    8,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    8,   10,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

 // properties: name, type, flags
      13, QMetaType::QString, 0x00015001, uint(0), 0,

 // enums: name, alias, flags, count, data
      14,   14, 0x0,    7,   84,

 // enum data: key, value
      15, uint(projet_cfr::services::BpmnEditorModel::ElementIdRole),
      16, uint(projet_cfr::services::BpmnEditorModel::TypeRole),
      17, uint(projet_cfr::services::BpmnEditorModel::XRole),
      18, uint(projet_cfr::services::BpmnEditorModel::YRole),
      19, uint(projet_cfr::services::BpmnEditorModel::WidthRole),
      20, uint(projet_cfr::services::BpmnEditorModel::HeightRole),
      21, uint(projet_cfr::services::BpmnEditorModel::LabelRole),

       0        // eod
};

void projet_cfr::services::BpmnEditorModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BpmnEditorModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->xmlChanged(); break;
        case 1: { int _r = _t->addElement((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->moveElement((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3]))); break;
        case 3: _t->setLabel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->removeElement((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->clear(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BpmnEditorModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BpmnEditorModel::xmlChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<BpmnEditorModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->xml(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject projet_cfr::services::BpmnEditorModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_projet_cfr__services__BpmnEditorModel.offsetsAndSize,
    qt_meta_data_projet_cfr__services__BpmnEditorModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_projet_cfr__services__BpmnEditorModel_t
, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<BpmnEditorModel, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>

, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<qreal, std::false_type>, QtPrivate::TypeAndForceComplete<qreal, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<qreal, std::false_type>, QtPrivate::TypeAndForceComplete<qreal, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>

>,
    nullptr
} };


const QMetaObject *projet_cfr::services::BpmnEditorModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *projet_cfr::services::BpmnEditorModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_projet_cfr__services__BpmnEditorModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int projet_cfr::services::BpmnEditorModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void projet_cfr::services::BpmnEditorModel::xmlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
