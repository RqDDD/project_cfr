import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: root
    visible: true
    width: 960
    height: 540
    title: "projet_cfr"
    color: "#0b1020"
    property int minPaneWidth: 220

    WorkspacePage {
        anchors.fill: parent
        minPaneWidth: root.minPaneWidth
        cameraViewModel: cameraVM
        bpmnEditorModel: bpmnModel
    }
}
