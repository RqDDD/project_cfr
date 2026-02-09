#pragma once

#include <QAbstractListModel>
#include <QString>
#include <QVector>

namespace projet_cfr::services {

class BpmnEditorModel : public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY(QString xml READ xml NOTIFY xmlChanged)

public:
    enum Roles {
        ElementIdRole = Qt::UserRole + 1,
        TypeRole,
        XRole,
        YRole,
        WidthRole,
        HeightRole,
        LabelRole,
    };
    Q_ENUM(Roles)

    explicit BpmnEditorModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QHash<int, QByteArray> roleNames() const override;

    QString xml() const;

    Q_INVOKABLE int addElement(const QString &type, qreal x, qreal y);
    Q_INVOKABLE void moveElement(int row, qreal x, qreal y);
    Q_INVOKABLE void setLabel(int row, const QString &label);
    Q_INVOKABLE void removeElement(int row);
    Q_INVOKABLE void clear();

signals:
    void xmlChanged();

private:
    struct Element {
        QString id;
        QString type;
        qreal x{0};
        qreal y{0};
        qreal width{120};
        qreal height{70};
        QString label;
    };

    QString nextElementId(const QString &type);
    QString toBpmnType(const QString &type) const;
    QString toBpmnTag(const QString &type) const;
    QString toBpmnXml() const;
    void emitElementChanged(int row, const QVector<int> &roles);

    QVector<Element> m_elements;
    int m_startCounter{1};
    int m_taskCounter{1};
    int m_gatewayCounter{1};
    int m_endCounter{1};
};

} // namespace projet_cfr::services
