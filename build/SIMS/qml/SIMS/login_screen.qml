import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    id: login_window

    width: 600
    height: 400
    visible:true

    title: "SIMS - Login"

    color: "#OF172A"

    ColumnLayout {
        anchors.centerIn: parent 

        width: 350
        spacing: 15

        Label {
            text: "SIMS"
            font.pixelSize: 36
            font.bold: true

            color: "white"
            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            text: "Surgical Instrument Management System"
            font.pixelSize: 16

            color: "#CBD5E1"

            Layout.alignment: Qt.AlignHCenter
            Layout.bottomMargin: 20
        }

        TextField {
            id: username_field
            Layout.fillWidth: true
            placeholderText: "Username"
            selectByMouse: true
            onAccepted: password_field.forceActiveFocus()
        }

        TextField {
            id: password_field
            Layout.fillWidth: true
            placeholderText: "Password"
            selectByMouse: true
            onAccepted: login_button.clicked()
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: 10

            Button {
                id: login_button
                text: "Login"
                Layout.fillWidth: true

                onClicked: {
                    loginController.login (
                        username_field.text,
                        password_field.text
                    )
                }
            }

            Button {
                text: "Cancel"
                Layout.fillWidth: true

                onClicked: {
                    loginController.cancelLogin()
                }
            }
        }
        
        Label {
            id: errorLabel
            text: ""
            color: "#EF4444"
            visible: text !== ""
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignHCenter
        }

    }

    Connections {
        target: loginController

        function onLoginFailed(message) {
            errorLabel.text = message
            password_field.clear()
            username_field.forceActiveFocus()
        }
    }
}