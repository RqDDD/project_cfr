#include "projet_cfr/services/CameraViewModel.h"

#include "projet_cfr/services/CameraService.h"

#include <QByteArray>
#include <QHash>
#include <QSet>
#include <QVariantMap>

namespace projet_cfr::services {

CameraViewModel::CameraViewModel(CameraService *service, QObject *parent)
    : QAbstractListModel(parent), m_service(service) {
    if (m_service) {
        connect(m_service, &CameraService::availabilityChanged, this, &CameraViewModel::availableChanged);
        connect(m_service, &CameraService::videoInputsChanged, this, &CameraViewModel::refresh);
    }
    refresh();
}

int CameraViewModel::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) {
        return 0;
    }
    return m_sources.size();
}

QVariant CameraViewModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() < 0 || index.row() >= m_sources.size()) {
        return {};
    }

    const SourceEntry &entry = m_sources.at(index.row());
    switch (role) {
    case NameRole:
        return entry.device.description();
    case IdRole:
        return entry.device.id();
    case SelectedRole:
        return entry.selected;
    case DeviceRole:
        return QVariant::fromValue(entry.device);
    default:
        return {};
    }
}

QHash<int, QByteArray> CameraViewModel::roleNames() const {
    return {
        {NameRole, "name"},
        {IdRole, "id"},
        {SelectedRole, "selected"},
        {DeviceRole, "device"},
    };
}

bool CameraViewModel::available() const {
    if (!m_service) {
        return false;
    }
    return m_service->isAvailable();
}

int CameraViewModel::selectedCount() const {
    int count = 0;
    for (const SourceEntry &entry : m_sources) {
        if (entry.selected) {
            ++count;
        }
    }
    return count;
}

QVariantList CameraViewModel::selectedSources() const {
    QVariantList list;
    for (const SourceEntry &entry : m_sources) {
        if (!entry.selected) {
            continue;
        }

        QVariantMap source;
        source.insert("name", entry.device.description());
        source.insert("id", entry.device.id());
        source.insert("device", QVariant::fromValue(entry.device));
        list.push_back(source);
    }
    return list;
}

void CameraViewModel::toggleSelected(int row) {
    if (row < 0 || row >= m_sources.size()) {
        return;
    }
    setSelected(row, !m_sources[row].selected);
}

void CameraViewModel::setSelected(int row, bool selected) {
    if (row < 0 || row >= m_sources.size()) {
        return;
    }
    if (m_sources[row].selected == selected) {
        return;
    }

    m_sources[row].selected = selected;
    const QModelIndex modelIndex = index(row);
    emit dataChanged(modelIndex, modelIndex, {SelectedRole});
    emit selectedCountChanged();
    emit selectedSourcesChanged();
}

void CameraViewModel::refresh() {
    if (!m_service) {
        if (m_sources.isEmpty()) {
            return;
        }
        beginResetModel();
        m_sources.clear();
        endResetModel();
        emit selectedCountChanged();
        emit selectedSourcesChanged();
        emit availableChanged();
        return;
    }

    QSet<QByteArray> previouslySelectedIds;
    for (const SourceEntry &entry : m_sources) {
        if (entry.selected) {
            previouslySelectedIds.insert(entry.device.id());
        }
    }

    const QList<QCameraDevice> inputs = m_service->videoInputs();

    beginResetModel();
    m_sources.clear();
    m_sources.reserve(inputs.size());
    for (const QCameraDevice &device : inputs) {
        SourceEntry entry;
        entry.device = device;
        entry.selected = previouslySelectedIds.contains(device.id());
        m_sources.push_back(entry);
    }
    endResetModel();

    emit selectedCountChanged();
    emit selectedSourcesChanged();
    emit availableChanged();
}

}
