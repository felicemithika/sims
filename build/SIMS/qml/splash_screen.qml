import QtQuick
import QtQuick.Controls

Item {
    id: splash

    width: 600
    height: 400

    signal finished()

    Rectangle {
        anchors.fill: parent 
        color: "#0F172A"

        Column {
            anchors.centerIn: parent
            spacing: 12

            Text {
                anchors.horizontalCenter: parent.horizontalCenter

                text: "Surgical Instrument"
                color: "white"
                font.pixelSize: 32
                font.bold: true
            }

            Text {
                anchors.horizontalCenter: parent.horizontalCenter

                text: "Management System"
                color: "#CBD5E1"
                font.pixelSize: 22
            }

            Text {
                anchors.horizontalCenter: parent.horizontalCenter

                text: "Loading..."
                color: "#94A3B8"
                font.pixelSize: 14
            }

            BusyIndicator {
                anchors.horizontalCenter: parent.horizontalCenter
                running: true
            }
        }
    }

    Timer {
        interval: 3000
        running: true
        repeat: false

        onTriggered: {
            splash.finished()
        }
    }
}