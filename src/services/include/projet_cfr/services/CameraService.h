#pragma once

#include <QCameraDevice>
#include <QList>
#include <QMediaDevices>
#include <QObject>

namespace projet_cfr::services {

class CameraService : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool available READ isAvailable NOTIFY availabilityChanged)

public:
    explicit CameraService(QObject *parent = nullptr);

    bool isAvailable() const;
    QList<QCameraDevice> videoInputs() const;

signals:
    void availabilityChanged();
    void videoInputsChanged();

private:
    void refreshAvailability();

    QMediaDevices m_mediaDevices;
    bool m_available{false};
};

}
