#ifndef PLAYERGENERATOR_H
#define PLAYERGENERATOR_H

#include <qqml.h>
#include <QObject>
#include <QAbstractTableModel>

class PlayerGenerator : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(int getReturnTypeId READ getReturnTypeId WRITE setReturnTypeId NOTIFY getReturnTypeIdChanged)
    Q_PROPERTY(bool isActivated READ getActivated WRITE setActivated NOTIFY isActivatedChanged)
    Q_PROPERTY(float CoordinateId READ getCoordinateId WRITE setCoordinateId NOTIFY CoordinateIdChanged)
    QML_ELEMENT
    QML_ADDED_IN_MINOR_VERSION(1)
public:
    PlayerGenerator();
    ~PlayerGenerator();

signals:
    void getReturnTypeIdChanged(int value);
    void isActivatedChanged(bool active);
    void CoordinateIdChanged(float value);

public:
    Q_INVOKABLE float setCoordinateId(float value=0) {
        return value;
    }

    Q_INVOKABLE float getCoordinateId(float value=0) {
        return value;
    }

    Q_INVOKABLE float CoordinateId(float value=0) {
        return value;
    }

    Q_INVOKABLE bool getActivated(bool active=false) {
        return active;
    }

    Q_INVOKABLE bool setActivated(bool active=false) {
        return active;
    }

    Q_INVOKABLE bool isActivated(bool active=false) {
        return active;
    }

    Q_INVOKABLE int setReturnTypeId(int value=0) {
        return value;
    }

    Q_INVOKABLE int getReturnTypeId(int value=0) {
        emit getReturnTypeIdChanged(value);
        return value;
    }

    int rowCount(const QModelIndex &parent) const override {
        return 200;
    }
    int columnCount(const QModelIndex &parent) const override {
        return 200;
    }
    QVariant data(const QModelIndex &index, int role) const override {
        switch (role) {
        case Qt::DisplayRole:
            return QString("%1, %2").arg(index.column()).arg(index.row());
        default:
            break;
        }

        return QVariant();
    }

private:
    unsigned int typeId;
    volatile double speed;
    unsigned int ammo;
    volatile bool is_active;
    volatile float coord;
};

#endif // PLAYERGENERATOR_H
