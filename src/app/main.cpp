#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QUrl>

#include "projet_cfr/services/BpmnEditorModel.h"
#include "projet_cfr/services/CameraService.h"
#include "projet_cfr/services/CameraViewModel.h"


// gtgt

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    projet_cfr::services::CameraService cameraService;
    projet_cfr::services::CameraViewModel cameraVM(&cameraService);
    projet_cfr::services::BpmnEditorModel bpmnModel;

    engine.rootContext()->setContextProperty("cameraVM", &cameraVM);
    engine.rootContext()->setContextProperty("bpmnModel", &bpmnModel);

    engine.load(QUrl(QStringLiteral("qrc:/MyApp/Main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
