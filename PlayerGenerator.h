#ifndef PLAYERGENERATOR_H
#define PLAYERGENERATOR_H

#include <QObject>

#include <qqml.h>

class PlayerGenerator : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int getReturnTypeId READ getReturnTypeId WRITE setReturnTypeId NOTIFY getReturnTypeIdChanged)
    Q_PROPERTY(bool isActivated READ getActivated WRITE setActivated NOTIFY isActivatedChanged)
    Q_PROPERTY(float CoordinateId READ getCoordinateId WRITE setCoordinateId NOTIFY CoordinateIdChanged)

    QML_ELEMENT
    QML_ADDED_IN_MINOR_VERSION(1)

public:
    explicit PlayerGenerator();
    PlayerGenerator(QObject* parent);
    PlayerGenerator(const PlayerGenerator &);
    virtual ~PlayerGenerator();

signals:
    void getReturnTypeIdChanged(int value);
    void isActivatedChanged(bool active);
    void CoordinateIdChanged(float value);

public:
    Q_INVOKABLE float setCoordinateId(float value=0);
    Q_INVOKABLE float getCoordinateId(float value=0);
    Q_INVOKABLE float CoordinateId(float value=0);
    Q_INVOKABLE bool getActivated(bool active=false);
    Q_INVOKABLE bool setActivated(bool active=false);
    Q_INVOKABLE bool isActivated(bool active=false);
    Q_INVOKABLE int setReturnTypeId(int value=0);
    Q_INVOKABLE int getReturnTypeId(int value=0);
};

Q_DECLARE_METATYPE(PlayerGenerator)
QML_DECLARE_TYPE(PlayerGenerator)

#endif // PLAYERGENERATOR_H
