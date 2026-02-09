#include "projet_cfr/services/BpmnEditorModel.h"

#include <QBuffer>
#include <QByteArray>
#include <QHash>
#include <QVariant>
#include <QXmlStreamWriter>

namespace projet_cfr::services {

BpmnEditorModel::BpmnEditorModel(QObject *parent)
    : QAbstractListModel(parent) {}

int BpmnEditorModel::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) {
        return 0;
    }
    return m_elements.size();
}

QVariant BpmnEditorModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() < 0 || index.row() >= m_elements.size()) {
        return {};
    }

    const Element &element = m_elements.at(index.row());
    switch (role) {
    case ElementIdRole:
        return element.id;
    case TypeRole:
        return element.type;
    case XRole:
        return element.x;
    case YRole:
        return element.y;
    case WidthRole:
        return element.width;
    case HeightRole:
        return element.height;
    case LabelRole:
        return element.label;
    default:
        return {};
    }
}

bool BpmnEditorModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (!index.isValid() || index.row() < 0 || index.row() >= m_elements.size()) {
        return false;
    }

    Element &element = m_elements[index.row()];
    switch (role) {
    case XRole:
        element.x = value.toReal();
        emitElementChanged(index.row(), {XRole});
        emit xmlChanged();
        return true;
    case YRole:
        element.y = value.toReal();
        emitElementChanged(index.row(), {YRole});
        emit xmlChanged();
        return true;
    case LabelRole:
        element.label = value.toString();
        emitElementChanged(index.row(), {LabelRole});
        emit xmlChanged();
        return true;
    default:
        return false;
    }
}

Qt::ItemFlags BpmnEditorModel::flags(const QModelIndex &index) const {
    if (!index.isValid()) {
        return Qt::NoItemFlags;
    }
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

QHash<int, QByteArray> BpmnEditorModel::roleNames() const {
    return {
        {ElementIdRole, "elementId"},
        {TypeRole, "type"},
        {XRole, "posX"},
        {YRole, "posY"},
        {WidthRole, "boxWidth"},
        {HeightRole, "boxHeight"},
        {LabelRole, "label"},
    };
}

QString BpmnEditorModel::xml() const {
    return toBpmnXml();
}

int BpmnEditorModel::addElement(const QString &type, qreal x, qreal y) {
    Element element;
    element.type = toBpmnType(type);
    element.id = nextElementId(element.type);
    element.x = x;
    element.y = y;

    if (element.type == "startEvent" || element.type == "endEvent") {
        element.width = 56;
        element.height = 56;
    } else if (element.type == "exclusiveGateway") {
        element.width = 72;
        element.height = 72;
    } else {
        element.width = 140;
        element.height = 84;
    }

    beginInsertRows(QModelIndex(), m_elements.size(), m_elements.size());
    m_elements.push_back(element);
    endInsertRows();

    emit xmlChanged();
    return m_elements.size() - 1;
}

void BpmnEditorModel::moveElement(int row, qreal x, qreal y) {
    if (row < 0 || row >= m_elements.size()) {
        return;
    }

    Element &element = m_elements[row];
    if (element.x == x && element.y == y) {
        return;
    }

    element.x = x;
    element.y = y;
    emitElementChanged(row, {XRole, YRole});
    emit xmlChanged();
}

void BpmnEditorModel::setLabel(int row, const QString &label) {
    if (row < 0 || row >= m_elements.size()) {
        return;
    }

    if (m_elements[row].label == label) {
        return;
    }

    m_elements[row].label = label;
    emitElementChanged(row, {LabelRole});
    emit xmlChanged();
}

void BpmnEditorModel::removeElement(int row) {
    if (row < 0 || row >= m_elements.size()) {
        return;
    }

    beginRemoveRows(QModelIndex(), row, row);
    m_elements.removeAt(row);
    endRemoveRows();
    emit xmlChanged();
}

void BpmnEditorModel::clear() {
    if (m_elements.isEmpty()) {
        return;
    }

    beginResetModel();
    m_elements.clear();
    endResetModel();
    emit xmlChanged();
}

QString BpmnEditorModel::nextElementId(const QString &type) {
    if (type == "startEvent") {
        return QString("StartEvent_%1").arg(m_startCounter++);
    }
    if (type == "exclusiveGateway") {
        return QString("Gateway_%1").arg(m_gatewayCounter++);
    }
    if (type == "endEvent") {
        return QString("EndEvent_%1").arg(m_endCounter++);
    }
    return QString("Task_%1").arg(m_taskCounter++);
}

QString BpmnEditorModel::toBpmnType(const QString &type) const {
    if (type == "start" || type == "startEvent") {
        return "startEvent";
    }
    if (type == "gateway" || type == "exclusiveGateway") {
        return "exclusiveGateway";
    }
    if (type == "end" || type == "endEvent") {
        return "endEvent";
    }
    return "task";
}

QString BpmnEditorModel::toBpmnTag(const QString &type) const {
    if (type == "startEvent") {
        return "bpmn:startEvent";
    }
    if (type == "exclusiveGateway") {
        return "bpmn:exclusiveGateway";
    }
    if (type == "endEvent") {
        return "bpmn:endEvent";
    }
    return "bpmn:task";
}

QString BpmnEditorModel::toBpmnXml() const {
    QByteArray bufferData;
    QBuffer buffer(&bufferData);
    buffer.open(QIODevice::WriteOnly);

    QXmlStreamWriter writer(&buffer);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();

    writer.writeStartElement("bpmn:definitions");
    writer.writeAttribute("xmlns:bpmn", "http://www.omg.org/spec/BPMN/20100524/MODEL");
    writer.writeAttribute("xmlns:bpmndi", "http://www.omg.org/spec/BPMN/20100524/DI");
    writer.writeAttribute("xmlns:dc", "http://www.omg.org/spec/DD/20100524/DC");
    writer.writeAttribute("xmlns:di", "http://www.omg.org/spec/DD/20100524/DI");
    writer.writeAttribute("id", "Definitions_1");
    writer.writeAttribute("targetNamespace", "https://projet_cfr.local/bpmn");

    writer.writeStartElement("bpmn:process");
    writer.writeAttribute("id", "Process_1");
    writer.writeAttribute("isExecutable", "false");

    for (const Element &element : m_elements) {
        writer.writeStartElement(toBpmnTag(element.type));
        writer.writeAttribute("id", element.id);
        if (!element.label.isEmpty()) {
            writer.writeAttribute("name", element.label);
        }
        writer.writeEndElement();
    }

    writer.writeEndElement();

    writer.writeStartElement("bpmndi:BPMNDiagram");
    writer.writeAttribute("id", "BPMNDiagram_1");
    writer.writeStartElement("bpmndi:BPMNPlane");
    writer.writeAttribute("id", "BPMNPlane_1");
    writer.writeAttribute("bpmnElement", "Process_1");

    for (const Element &element : m_elements) {
        writer.writeStartElement("bpmndi:BPMNShape");
        writer.writeAttribute("id", element.id + "_di");
        writer.writeAttribute("bpmnElement", element.id);

        writer.writeEmptyElement("dc:Bounds");
        writer.writeAttribute("x", QString::number(element.x, 'f', 2));
        writer.writeAttribute("y", QString::number(element.y, 'f', 2));
        writer.writeAttribute("width", QString::number(element.width, 'f', 2));
        writer.writeAttribute("height", QString::number(element.height, 'f', 2));

        writer.writeEndElement();
    }

    writer.writeEndElement();
    writer.writeEndElement();
    writer.writeEndElement();
    writer.writeEndDocument();

    buffer.close();
    return QString::fromUtf8(bufferData);
}

void BpmnEditorModel::emitElementChanged(int row, const QVector<int> &roles) {
    const QModelIndex modelIndex = index(row);
    emit dataChanged(modelIndex, modelIndex, roles);
}

} // namespace projet_cfr::services
