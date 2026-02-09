#include "projet_cfr/services/CameraService.h"

namespace projet_cfr::services {

CameraService::CameraService(QObject *parent)
    : QObject(parent) {
    refreshAvailability();

    connect(&m_mediaDevices, &QMediaDevices::videoInputsChanged, this, [this]() {
        refreshAvailability();
        emit videoInputsChanged();
    });
}

bool CameraService::isAvailable() const {
    return m_available;
}

QList<QCameraDevice> CameraService::videoInputs() const {
    return m_mediaDevices.videoInputs();
}

void CameraService::refreshAvailability() {
    const bool nextAvailable = !m_mediaDevices.videoInputs().isEmpty();
    if (nextAvailable == m_available) {
        return;
    }

    m_available = nextAvailable;
    emit availabilityChanged();
}

}
