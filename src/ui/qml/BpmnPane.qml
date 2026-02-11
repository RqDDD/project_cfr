import QtQuick 2.15

Rectangle {
    id: bpmnPane
    required property var bpmnModel
    property string bpmnTool: "task"

    color: "#0f172a"

    Rectangle {
        id: bpmnToolbar
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        height: 48
        color: "#111827"
        border.color: "#334155"
        border.width: 1

        Row {
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            anchors.margins: 8
            spacing: 8

            Repeater {
                model: [
                    { key: "startEvent", label: "Start" },
                    { key: "task", label: "Task" },
                    { key: "exclusiveGateway", label: "Gateway" },
                    { key: "endEvent", label: "End" }
                ]

                delegate: Rectangle {
                    width: 78
                    height: 30
                    radius: 6
                    color: bpmnPane.bpmnTool === modelData.key ? "#2563eb" : "#1f2937"
                    border.color: bpmnPane.bpmnTool === modelData.key ? "#93c5fd" : "#475569"
                    border.width: 1

                    Text {
                        anchors.centerIn: parent
                        text: modelData.label
                        color: "#f8fafc"
                        font.pixelSize: 13
                        font.bold: true
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: bpmnPane.bpmnTool = modelData.key
                    }
                }
            }

            Rectangle {
                width: 72
                height: 30
                radius: 6
                color: "#7f1d1d"
                border.color: "#ef4444"
                border.width: 1

                Text {
                    anchors.centerIn: parent
                    text: "Clear"
                    color: "#fee2e2"
                    font.pixelSize: 13
                    font.bold: true
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: bpmnPane.bpmnModel.clear()
                }
            }
        }
    }

    Rectangle {
        id: bpmnCanvas
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: bpmnToolbar.bottom
        anchors.bottom: xmlPanel.top
        color: "#1e293b"
        border.color: "#334155"
        border.width: 1
        clip: true

        Text {
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.margins: 8
            text: "Click to place: " + bpmnPane.bpmnTool
            color: "#e2e8f0"
            font.pixelSize: 13
        }

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton
            onClicked: function(mouse) {
                const elementWidth = bpmnPane.bpmnTool === "task" ? 140 : (bpmnPane.bpmnTool === "exclusiveGateway" ? 72 : 56);
                const elementHeight = bpmnPane.bpmnTool === "task" ? 84 : (bpmnPane.bpmnTool === "exclusiveGateway" ? 72 : 56);
                const x = Math.max(0, mouse.x - elementWidth / 2);
                const y = Math.max(0, mouse.y - elementHeight / 2);
                bpmnPane.bpmnModel.addElement(bpmnPane.bpmnTool, x, y);
            }
        }

        Repeater {
            model: bpmnPane.bpmnModel

            delegate: Item {
                id: node
                x: posX
                y: posY
                width: boxWidth
                height: boxHeight

                Rectangle {
                    anchors.fill: parent
                    radius: type === "task" ? 10 : width / 2
                    color: type === "task" ? "#0b3b76" : (type === "exclusiveGateway" ? "#78350f" : "#1f2937")
                    border.color: type === "endEvent" ? "#f87171" : "#e2e8f0"
                    border.width: type === "endEvent" ? 4 : 2
                    rotation: type === "exclusiveGateway" ? 45 : 0
                }

                Text {
                    anchors.centerIn: parent
                    text: label.length > 0 ? label : type
                    color: "#ffffff"
                    font.pixelSize: 12
                    font.bold: true
                }

                MouseArea {
                    anchors.fill: parent
                    drag.target: node
                    drag.axis: Drag.XAndYAxis
                    onPositionChanged: bpmnPane.bpmnModel.moveElement(index, node.x, node.y)
                    acceptedButtons: Qt.LeftButton | Qt.RightButton
                    onClicked: function(mouse) {
                        if (mouse.button === Qt.RightButton) {
                            bpmnPane.bpmnModel.removeElement(index);
                        }
                    }
                }
            }
        }
    }

    Rectangle {
        id: xmlPanel
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        height: Math.max(160, parent.height * 0.28)
        color: "#020617"
        border.color: "#334155"
        border.width: 1

        Text {
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.margins: 8
            text: "BPMN XML Preview"
            color: "#e2e8f0"
            font.pixelSize: 13
            font.bold: true
        }

        Flickable {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.margins: 8
            anchors.topMargin: 28
            clip: true
            contentWidth: xmlText.paintedWidth
            contentHeight: xmlText.paintedHeight

            Text {
                id: xmlText
                width: parent.width
                text: bpmnPane.bpmnModel.xml
                color: "#cbd5e1"
                font.family: "monospace"
                font.pixelSize: 12
                wrapMode: Text.NoWrap
            }
        }
    }
}
