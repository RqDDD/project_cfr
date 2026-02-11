import QtQuick 2.15
import QtMultimedia

Rectangle {
    id: cameraPane
    required property var cameraVM

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
            model: cameraPane.cameraVM
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
                    onClicked: cameraPane.cameraVM.toggleSelected(index)
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
            columns: cameraPane.cameraVM.selectedCount <= 1 ? 1 : (cameraPane.cameraVM.selectedCount <= 4 ? 2 : 3)

            Repeater {
                model: cameraPane.cameraVM.selectedSources

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
            visible: cameraPane.cameraVM.selectedCount === 0
            text: cameraPane.cameraVM.available ? "Selectionne une ou plusieurs sources" : "Aucune camera detectee"
            color: "#cbd5e1"
            font.pixelSize: 19
        }
    }
}
