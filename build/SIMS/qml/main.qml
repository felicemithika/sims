import QtQuick
import QtQuick.Controls

ApplicationWindow {
    id: root 

    width: 600
    height: 400
    visible: true

    flags: Qt.FramelessWindowHint

    Loader {
        id: screen_loader
        anchors.fill: parent 
        source: "splash_screen.qml"

        onLoaded: {
            if (item && item.finished) {
                item.finished.connect(function() {
                    screen_loader.source = "login_screen.qml"
                }) 
            }
        }
    }

    Connections {
        target: loginController

        function onLoginSuccessful() {
            root.close()
        }
    }
}