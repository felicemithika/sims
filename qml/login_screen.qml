import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: login_screen

    Rectangle {
        anchors.fill: parent 
        color: "#0F172A"
    }

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
            placeholderTextColor: "#94A3B8"

            color: "white"

            horizontalAlignment: Text.AlignHCenter

            selectByMouse: true

            onAccepted: {
                password_field.forceActiveFocus()
            }
        }

        TextField {
            id: password_field

            Layout.fillWidth: true

            placeholderText: "Password"
            placeholderTextColor: "#94A3B8"

            color: "white"

            horizontalAlignment: Text.AlignHCenter

            selectByMouse: true

            onAccepted: {
                login_button.clicked()
            }
        }

        RowLayout {
            Layout.alignment: Qt.AlignHCenter

            spacing: 15

            Button {
                id: login_button

                text: "Login"

                implicitWidth: 100
                implicitHeight: 40

                onClicked: {
                    loginController.login (
                        username_field.text,
                        password_field.text
                    )
                }
            }

            Button {
                id: cancel_button

                text: "Cancel"

                implicitWidth: 100
                implicitHeight: 40

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