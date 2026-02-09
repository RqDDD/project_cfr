import QtQuick 2.15
import QtQuick.Window 2.15
import QtMultimedia

Window {
    id: root
    visible: true
    width: 960
    height: 540
    title: "projet_cfr"
    color: "#0b1020"
    property int minPaneWidth: 220
    property string bpmnTool: "task"

    Rectangle {
        id: splitView
        anchors.fill: parent
        color: "#0f172a"

        onWidthChanged: {
            const minX = root.minPaneWidth - splitter.width / 2;
            const maxX = width - root.minPaneWidth - splitter.width / 2;
            if (splitter.x < minX) {
                splitter.x = minX;
            }
            if (splitter.x > maxX) {
                splitter.x = maxX;
            }
        }

        Component.onCompleted: {
            splitter.x = width / 2 - splitter.width / 2;
        }

        Rectangle {
            id: leftPane
            x: 0
            y: 0
            width: splitter.x + splitter.width / 2
            height: parent.height
            color: "#111827"

            Rectangle {
                id: sourcePanel
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                height: 150
                color: "#0b1224"
                border.color: "#334155"
                border.width: 1

                Text {
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.margins: 10
                    text: "Sources video"
                    color: "#e2e8f0"
                    font.pixelSize: 16
                    font.bold: true
                }

                ListView {
                    id: sourceList
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.margins: 8
                    anchors.topMargin: 34
                    model: cameraVM
                    spacing: 6
                    clip: true

                    delegate: Rectangle {
                        width: sourceList.width
                        height: 34
                        radius: 6
                        color: selected ? "#1d4ed8" : "#1f2937"
                        border.color: selected ? "#93c5fd" : "#475569"
                        border.width: 1

                        Row {
                            anchors.fill: parent
                            anchors.margins: 8
                            spacing: 10

                            Rectangle {
                                width: 16
                                height: 16
                                radius: 3
                                border.color: "#e2e8f0"
                                border.width: 1
                                color: selected ? "#e2e8f0" : "transparent"
                            }

                            Text {
                                verticalAlignment: Text.AlignVCenter
                                text: name
                                color: "#f8fafc"
                                font.pixelSize: 14
                                elide: Text.ElideRight
                                width: sourceList.width - 60
                            }
                        }

                        MouseArea {
                            anchors.fill: parent
                            onClicked: cameraVM.toggleSelected(index)
                        }
                    }
                }
            }

            Rectangle {
                id: videoPanel
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: sourcePanel.bottom
                anchors.bottom: parent.bottom
                color: "#111827"

                Grid {
                    id: feedsGrid
                    anchors.fill: parent
                    anchors.margins: 10
                    spacing: 10
                    columns: cameraVM.selectedCount <= 1 ? 1 : (cameraVM.selectedCount <= 4 ? 2 : 3)

                    Repeater {
                        model: cameraVM.selectedSources

                        delegate: Rectangle {
                            width: Math.max(220, (feedsGrid.width - (feedsGrid.columns - 1) * feedsGrid.spacing) / feedsGrid.columns)
                            height: width * 0.56
                            radius: 8
                            color: "#020617"
                            border.color: "#334155"
                            border.width: 1
                            clip: true

                            Camera {
                                id: tileCamera
                                cameraDevice: modelData.device
                                active: true

                                function applyLowResolutionFormat() {
                                    const formats = cameraDevice.videoFormats;
                                    if (!formats || formats.length === 0) {
                                        return;
                                    }

                                    const targetW = 640;
                                    const targetH = 360;
                                    let best = null;
                                    let bestScore = 1e12;
                                    for (let i = 0; i < formats.length; ++i) {
                                        const fmt = formats[i];
                                        const w = fmt.resolution.width;
                                        const h = fmt.resolution.height;
                                        const score = Math.abs(w - targetW) + Math.abs(h - targetH);
                                        if (score < bestScore) {
                                            best = fmt;
                                            bestScore = score;
                                        }
                                    }

                                    if (best) {
                                        cameraFormat = best;
                                    }
                                }

                                Component.onCompleted: applyLowResolutionFormat()
                                onCameraDeviceChanged: applyLowResolutionFormat()
                            }

                            CaptureSession {
                                camera: tileCamera
                                videoOutput: tileVideoOutput
                            }

                            VideoOutput {
                                id: tileVideoOutput
                                anchors.fill: parent
                                fillMode: VideoOutput.PreserveAspectCrop
                            }

                            Rectangle {
                                anchors.left: parent.left
                                anchors.right: parent.right
                                anchors.top: parent.top
                                height: 30
                                color: "#66000000"

                                Text {
                                    anchors.left: parent.left
                                    anchors.verticalCenter: parent.verticalCenter
                                    anchors.margins: 8
                                    text: modelData.name + "  -  Clement Forever :D"
                                    color: "white"
                                    font.pixelSize: 13
                                    font.bold: true
                                }
                            }
                        }
                    }
                }

                Text {
                    anchors.centerIn: parent
                    visible: cameraVM.selectedCount === 0
                    text: cameraVM.available ? "Selectionne une ou plusieurs sources" : "Aucune camera detectee"
                    color: "#cbd5e1"
                    font.pixelSize: 19
                }
            }
        }

        Rectangle {
            id: rightPane
            x: splitter.x + splitter.width
            y: 0
            width: parent.width - x
            height: parent.height
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
                            color: root.bpmnTool === modelData.key ? "#2563eb" : "#1f2937"
                            border.color: root.bpmnTool === modelData.key ? "#93c5fd" : "#475569"
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
                                onClicked: root.bpmnTool = modelData.key
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
                            onClicked: bpmnModel.clear()
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
                    text: "Click to place: " + root.bpmnTool
                    color: "#e2e8f0"
                    font.pixelSize: 13
                }

                MouseArea {
                    anchors.fill: parent
                    acceptedButtons: Qt.LeftButton
                    onClicked: function(mouse) {
                        const elementWidth = root.bpmnTool === "task" ? 140 : (root.bpmnTool === "exclusiveGateway" ? 72 : 56);
                        const elementHeight = root.bpmnTool === "task" ? 84 : (root.bpmnTool === "exclusiveGateway" ? 72 : 56);
                        const x = Math.max(0, mouse.x - elementWidth / 2);
                        const y = Math.max(0, mouse.y - elementHeight / 2);
                        bpmnModel.addElement(root.bpmnTool, x, y);
                    }
                }

                Repeater {
                    model: bpmnModel

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
                            onPositionChanged: bpmnModel.moveElement(index, node.x, node.y)
                            acceptedButtons: Qt.LeftButton | Qt.RightButton
                            onClicked: function(mouse) {
                                if (mouse.button === Qt.RightButton) {
                                    bpmnModel.removeElement(index);
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
                        text: bpmnModel.xml
                        color: "#cbd5e1"
                        font.family: "monospace"
                        font.pixelSize: 12
                        wrapMode: Text.NoWrap
                    }
                }
            }
        }

        Rectangle {
            id: splitter
            y: 0
            width: 8
            height: parent.height
            color: "#334155"

            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.SplitHCursor
                drag.target: splitter
                drag.axis: Drag.XAxis
                drag.minimumX: root.minPaneWidth - splitter.width / 2
                drag.maximumX: splitView.width - root.minPaneWidth - splitter.width / 2
            }
        }
    }
}
