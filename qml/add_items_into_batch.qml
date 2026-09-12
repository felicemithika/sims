import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Item {
    id: add_batch_items

    anchors.fill: parent 

     Connections {
        target: add_items_into_the_barcode

        function onSuccess_message(message) {
            message_dialog.message_title = "Success"
            message_dialog.message_text = message
            message_dialog.message_type = "success"

            message_dialog.open()
        }

        function onWarning_message(message) {

            message_dialog.message_title = "Attention"
            message_dialog.message_text = message
            message_dialog.message_type = "warning"

            message_dialog.open()
        }

        function onError_message(message) {

            message_dialog.message_title = "Error"
            message_dialog.message_text = message
            message_dialog.message_type = "error"

            message_dialog.open()
        }
    }

    Dialog {
        id: message_dialog

        anchors.centerIn: Overlay.overlay

        width:420
        height: header.height + contentItem.implicitHeight + footer.height

        modal: true
        focus: true

        property string message_title: ""
        property string message_text: ""
        property string message_type: "info"

        background: Rectangle {
            color: "#172033"
            radius: 14
            border.color: "#E2E8F0"
            border.width: 1
        }

        header: Rectangle {
            width: parent.width
            height: 65
            color: "#172033"
            radius: 14

            Label {
                anchors.left: parent.left
                anchors.leftMargin: 22
                anchors.verticalCenter: parent.verticalCenter

                text: message_dialog.message_title

                font.pixelSize: 15
                font.bold: true

                color: "white"
            }
        }

        contentItem: Item {
            width: parent.width
            implicitHeight: message_text_label.implicitHeight + 35

            Label {
                id: message_text_label

                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom

                anchors.leftMargin: 22
                anchors.rightMargin: 22
                anchors.topMargin: 15
                anchors.bottomMargin: 20

                text: message_dialog.message_text

                wrapMode: Text.WordWrap

                color: "white"

                font.pixelSize: 15

                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignTop
            }
        }
        
        footer: DialogButtonBox {
            width: parent.width

            padding: 15

            alignment: Qt.AlignRight

            background: Rectangle {
                color: "#172033"

                radius: 14
            }

            Button {
                text: "OK"

                DialogButtonBox.buttonRole: DialogButtonBox.AcceptRole

                onClicked: {
                    message_dialog.close()
                }
            }
        }
    }

    ColumnLayout {
        anchors.fill: parent 
        spacing: 15

        GridLayout {
            Layout.fillWidth: true

            columns: 2
            columnSpacing: 20
            rowSpacing: 12

            Label {
                text: "Category"
                font.bold: true
                color: "#334155"
            }

            ComboBox {
                id: category_combo_box
                Layout.fillWidth: true
                Layout.preferredHeight: 30

                model: add_items_into_the_barcode.category_list
                onCurrentTextChanged: {
                    add_items_into_the_barcode.load_surgical_instruments(currentText)
                }

                background: Rectangle {
                    color: "#F1F5F9"
                    border.color: "#CBD5E1"
                    border.width: 1
                    radius: 5
                }

                contentItem: Text {
                    text: category_combo_box.displayText

                    color: "#0F172A"
                    font.pixelSize: 14

                    verticalAlignment: Text.AlignVCenter
                    leftPadding: 12
                }
            }
            Label {
                text: "Instrument count"
                font.bold: true
                color: "#334155"
            }

            SpinBox {
                id: instrument_count_spin_box

                Layout.preferredWidth: 60
                Layout.preferredHeight: 30

                from: 1
                to: 50
                value: 1

                background: Rectangle {
                    color: "#F1F5F9"
                    border.color: "#CBD5E1"
                    border.width: 1
                    radius: 5
                }

                contentItem: TextInput {
                    text: instrument_count_spin_box.textFromValue(
                        instrument_count_spin_box.value,
                        instrument_count_spin_box.locale
                    )

                        color: "#0F172A"

                        font.pixelSize: 14

                        horizontalAlignment: TextInput.AlignHCenter
                        verticalAlignment: TextInput.AlignVCenter
                }
            }

            Label {
                text: "Surgical Instrument"
                font.bold: true
                color:"#334155" 
            }

            ComboBox {
                id: surgical_instruments_combo_box

                Layout.fillWidth: true
                Layout.preferredHeight: 30

                model: add_items_into_the_barcode.surgical_instrument_list

                background: Rectangle {
                    color: "#F1F5F9"
                    border.color: "#CBD5E1"
                    border.width: 1
                    radius: 5
                }

                contentItem: Text {
                    text: surgical_instruments_combo_box.displayText

                    color: "#0F172A"
                    font.pixelSize: 14

                    verticalAlignment: Text.AlignVCenter
                    leftPadding: 12
                }
            }
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: 10

            Label {
                text: "Comments:"
                font.pixelSize: 14
                font.bold: true
                color: "#334155"
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true

            color: "white"

            border.color: "#CBD5E1"
            border.width: 1
            radius: 6

            TextArea {
                id: comments_text_area
                Layout.fillWidth: true
                Layout.fillHeight: true

                placeholderText: "---Enter comments here (Optional)---"
                placeholderTextColor: "#94A3B8"
                
                color: "#334155" 

                wrapMode: TextArea.Wrap
            }
        }

        RowLayout {
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignCenter 

            Button {
                text: "Add"

                onClicked: {
                    add_items_into_the_barcode.add_requested_item(
                        category_combo_box.currentText,
                        instrument_count_spin_box.value,
                        surgical_instruments_combo_box.currentText,
                        comments_text_area.text
                    )
                }
            }
        }
    }
}