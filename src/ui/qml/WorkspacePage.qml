import QtQuick 2.15

Rectangle {
    id: workspace
    required property var cameraViewModel
    required property var bpmnEditorModel
    required property int minPaneWidth

    color: "#0f172a"

    property bool cameraVisible: true
    property bool bpmnVisible: true
    property string maximizedPane: ""

    property int activeTabIndex: 0
    property bool viewsMenuOpen: false

    property bool dualMode: cameraVisible && bpmnVisible && maximizedPane === ""
    property bool cameraShown: cameraVisible && maximizedPane !== "bpmn"
    property bool bpmnShown: bpmnVisible && maximizedPane !== "camera"

    function clampSplitter() {
        const minX = workspace.minPaneWidth - splitter.width / 2;
        const maxX = contentArea.width - workspace.minPaneWidth - splitter.width / 2;
        if (maxX < minX) {
            splitter.x = contentArea.width / 2 - splitter.width / 2;
            return;
        }
        if (splitter.x < minX) {
            splitter.x = minX;
        }
        if (splitter.x > maxX) {
            splitter.x = maxX;
        }
    }

    function setPaneVisible(paneId, visible) {
        if (paneId === "camera") {
            cameraVisible = visible;
            if (!visible && maximizedPane === "camera") {
                maximizedPane = "";
            }
        } else {
            bpmnVisible = visible;
            if (!visible && maximizedPane === "bpmn") {
                maximizedPane = "";
            }
        }
    }

    function reducePane(paneId) {
        maximizedPane = "";
        if (paneId === "camera") {
            splitter.x = workspace.minPaneWidth - splitter.width / 2;
        } else {
            splitter.x = contentArea.width - workspace.minPaneWidth - splitter.width / 2;
        }
        clampSplitter();
    }

    function toggleMaximizePane(paneId) {
        maximizedPane = maximizedPane === paneId ? "" : paneId;
    }

    Rectangle {
        id: tabBar
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        height: 44
        color: "#111827"
        border.color: "#334155"
        border.width: 1

        Row {
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            anchors.leftMargin: 8
            spacing: 8

            Repeater {
                model: [
                    { label: "Espace", viewTab: true },
                    { label: "Onglet 2", viewTab: false },
                    { label: "Onglet 3", viewTab: false },
                    { label: "Vues", viewTab: false, menu: true }
                ]

                delegate: Rectangle {
                    width: modelData.menu ? 84 : 96
                    height: 30
                    radius: 6
                    color: modelData.menu
                        ? (workspace.viewsMenuOpen ? "#2563eb" : "#1f2937")
                        : (workspace.activeTabIndex === index ? "#2563eb" : "#1f2937")
                    border.color: modelData.menu
                        ? (workspace.viewsMenuOpen ? "#93c5fd" : "#475569")
                        : (workspace.activeTabIndex === index ? "#93c5fd" : "#475569")
                    border.width: 1

                    Text {
                        anchors.centerIn: parent
                        text: modelData.menu ? "Vues v" : modelData.label
                        color: "#f8fafc"
                        font.pixelSize: 13
                        font.bold: true
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            if (modelData.menu) {
                                workspace.viewsMenuOpen = !workspace.viewsMenuOpen;
                                return;
                            }
                            workspace.viewsMenuOpen = false;
                            workspace.activeTabIndex = index;
                        }
                    }
                }
            }
        }
    }

    Rectangle {
        id: viewsMenu
        visible: workspace.viewsMenuOpen
        width: 220
        height: 92
        color: "#0b1224"
        border.color: "#475569"
        border.width: 1
        radius: 6
        anchors.top: tabBar.bottom
        anchors.left: parent.left
        anchors.leftMargin: 316
        z: 20

        Column {
            anchors.fill: parent
            anchors.margins: 8
            spacing: 8

            Rectangle {
                width: parent.width
                height: 34
                radius: 4
                color: "#1f2937"
                border.color: "#475569"
                border.width: 1

                Text {
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.leftMargin: 8
                    text: (workspace.cameraVisible ? "[x] " : "[ ] ") + "Vue Camera"
                    color: "#e2e8f0"
                    font.pixelSize: 13
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: workspace.setPaneVisible("camera", !workspace.cameraVisible)
                }
            }

            Rectangle {
                width: parent.width
                height: 34
                radius: 4
                color: "#1f2937"
                border.color: "#475569"
                border.width: 1

                Text {
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.leftMargin: 8
                    text: (workspace.bpmnVisible ? "[x] " : "[ ] ") + "Vue BPMN"
                    color: "#e2e8f0"
                    font.pixelSize: 13
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: workspace.setPaneVisible("bpmn", !workspace.bpmnVisible)
                }
            }
        }
    }

    Item {
        anchors.fill: parent
        z: 10
        visible: workspace.viewsMenuOpen

        MouseArea {
            anchors.fill: parent
            onClicked: workspace.viewsMenuOpen = false
        }
    }

    Rectangle {
        id: contentArea
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: tabBar.bottom
        anchors.bottom: parent.bottom
        color: "#0f172a"

        onWidthChanged: clampSplitter()

        Component.onCompleted: {
            splitter.x = width / 2 - splitter.width / 2;
            clampSplitter();
        }

        Rectangle {
            id: cameraHost
            visible: workspace.cameraShown
            x: 0
            y: 0
            width: workspace.dualMode ? splitter.x + splitter.width / 2 : (workspace.cameraShown ? parent.width : 0)
            height: parent.height
            color: "#111827"

            Rectangle {
                id: cameraHeader
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                height: 36
                color: "#0b1224"
                border.color: "#334155"
                border.width: 1

                Text {
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.leftMargin: 10
                    text: "Camera"
                    color: "#e2e8f0"
                    font.pixelSize: 13
                    font.bold: true
                }

                Row {
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.rightMargin: 8
                    spacing: 6

                    Rectangle {
                        width: 24
                        height: 22
                        radius: 4
                        color: "#1f2937"
                        border.color: "#475569"
                        border.width: 1

                        Text {
                            anchors.centerIn: parent
                            text: "-"
                            color: "#e2e8f0"
                            font.bold: true
                        }

                        MouseArea {
                            anchors.fill: parent
                            onClicked: workspace.reducePane("camera")
                        }
                    }

                    Rectangle {
                        width: 24
                        height: 22
                        radius: 4
                        color: workspace.maximizedPane === "camera" ? "#2563eb" : "#1f2937"
                        border.color: workspace.maximizedPane === "camera" ? "#93c5fd" : "#475569"
                        border.width: 1

                        Text {
                            anchors.centerIn: parent
                            text: "[ ]"
                            color: "#e2e8f0"
                            font.pixelSize: 10
                            font.bold: true
                        }

                        MouseArea {
                            anchors.fill: parent
                            onClicked: workspace.toggleMaximizePane("camera")
                        }
                    }

                    Rectangle {
                        width: 24
                        height: 22
                        radius: 4
                        color: "#7f1d1d"
                        border.color: "#ef4444"
                        border.width: 1

                        Text {
                            anchors.centerIn: parent
                            text: "x"
                            color: "#fee2e2"
                            font.bold: true
                        }

                        MouseArea {
                            anchors.fill: parent
                            onClicked: workspace.setPaneVisible("camera", false)
                        }
                    }
                }
            }

            CameraPane {
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: cameraHeader.bottom
                anchors.bottom: parent.bottom
                cameraVM: workspace.cameraViewModel
            }
        }

        Rectangle {
            id: bpmnHost
            visible: workspace.bpmnShown
            x: workspace.dualMode ? splitter.x + splitter.width : 0
            y: 0
            width: workspace.dualMode ? parent.width - x : (workspace.bpmnShown ? parent.width : 0)
            height: parent.height
            color: "#0f172a"

            Rectangle {
                id: bpmnHeader
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                height: 36
                color: "#111827"
                border.color: "#334155"
                border.width: 1

                Text {
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.leftMargin: 10
                    text: "BPMN"
                    color: "#e2e8f0"
                    font.pixelSize: 13
                    font.bold: true
                }

                Row {
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.rightMargin: 8
                    spacing: 6

                    Rectangle {
                        width: 24
                        height: 22
                        radius: 4
                        color: "#1f2937"
                        border.color: "#475569"
                        border.width: 1

                        Text {
                            anchors.centerIn: parent
                            text: "-"
                            color: "#e2e8f0"
                            font.bold: true
                        }

                        MouseArea {
                            anchors.fill: parent
                            onClicked: workspace.reducePane("bpmn")
                        }
                    }

                    Rectangle {
                        width: 24
                        height: 22
                        radius: 4
                        color: workspace.maximizedPane === "bpmn" ? "#2563eb" : "#1f2937"
                        border.color: workspace.maximizedPane === "bpmn" ? "#93c5fd" : "#475569"
                        border.width: 1

                        Text {
                            anchors.centerIn: parent
                            text: "[ ]"
                            color: "#e2e8f0"
                            font.pixelSize: 10
                            font.bold: true
                        }

                        MouseArea {
                            anchors.fill: parent
                            onClicked: workspace.toggleMaximizePane("bpmn")
                        }
                    }

                    Rectangle {
                        width: 24
                        height: 22
                        radius: 4
                        color: "#7f1d1d"
                        border.color: "#ef4444"
                        border.width: 1

                        Text {
                            anchors.centerIn: parent
                            text: "x"
                            color: "#fee2e2"
                            font.bold: true
                        }

                        MouseArea {
                            anchors.fill: parent
                            onClicked: workspace.setPaneVisible("bpmn", false)
                        }
                    }
                }
            }

            BpmnPane {
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: bpmnHeader.bottom
                anchors.bottom: parent.bottom
                bpmnModel: workspace.bpmnEditorModel
            }
        }

        Rectangle {
            id: splitter
            visible: workspace.dualMode
            z: 5
            y: 0
            width: 8
            height: parent.height
            color: "#334155"

            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.SplitHCursor
                drag.target: splitter
                drag.axis: Drag.XAxis
                drag.minimumX: workspace.minPaneWidth - splitter.width / 2
                drag.maximumX: contentArea.width - workspace.minPaneWidth - splitter.width / 2
            }
        }

        Text {
            anchors.centerIn: parent
            visible: !workspace.cameraVisible && !workspace.bpmnVisible && workspace.activeTabIndex === 0
            text: "Aucune vue active. Ouvre le menu Vues pour cocher une fenetre."
            color: "#cbd5e1"
            font.pixelSize: 16
        }

        Rectangle {
            anchors.fill: parent
            color: "#0b1224"
            visible: workspace.activeTabIndex !== 0

            Text {
                anchors.centerIn: parent
                text: workspace.activeTabIndex === 1 ? "Onglet 2 (vide)" : "Onglet 3 (vide)"
                color: "#cbd5e1"
                font.pixelSize: 18
            }
        }
    }
}
