#pragma once

#include <QAbstractListModel>
#include <QCameraDevice>
#include <QVariantList>

namespace projet_cfr::services {

class CameraService;

class CameraViewModel : public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY(bool available READ available NOTIFY availableChanged)
    Q_PROPERTY(int selectedCount READ selectedCount NOTIFY selectedCountChanged)
    Q_PROPERTY(QVariantList selectedSources READ selectedSources NOTIFY selectedSourcesChanged)

public:
    enum Roles {
        NameRole = Qt::UserRole + 1,
        IdRole,
        SelectedRole,
        DeviceRole,
    };
    Q_ENUM(Roles)

    explicit CameraViewModel(CameraService *service, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    bool available() const;
    int selectedCount() const;
    QVariantList selectedSources() const;

    Q_INVOKABLE void toggleSelected(int row);
    Q_INVOKABLE void setSelected(int row, bool selected);
    Q_INVOKABLE void refresh();

signals:
    void availableChanged();
    void selectedCountChanged();
    void selectedSourcesChanged();

private:
    struct SourceEntry {
        QCameraDevice device;
        bool selected{false};
    };

    CameraService *m_service{nullptr};
    QList<SourceEntry> m_sources;
};

}
