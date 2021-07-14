#include <QObject>
#include <QGuiApplication>

#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "PlayerGenerator.h"
#include "main.moc"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    PlayerGenerator* playerGenerator = nullptr;

    auto convObj = static_cast<QObject *>( playerGenerator );
    QQmlEngine* qmlEngine = new QQmlEngine( convObj );
    qmlEngine->importModule("Generator.io");
    qmlEngine->setObjectName("rootPlayerItem");
    qmlProtectModule("Generator.io", 1);
    qmlRegisterType<PlayerGenerator>("Generator.io", 1,0, "RootPlayerItem");

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);
    //qvariant_cast<QVariant>(qobject_cast<QVariant>(
    engine.rootContext()->setContextProperty(
                "rootPlayerItem", playerGenerator);

    return app.exec();
}
