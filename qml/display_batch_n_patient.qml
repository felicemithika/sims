import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: display_batch_n_patient

    property var controller

    width: parent ? parent.width : 0

    implicitHeight: display_batch_n_patient_content.implicitHeight

    Component.onCompleted: { 
        controller.start_barcode_scanning()
        scan_overlay.visible = true
    }

    Rectangle {
        id: scan_overlay

        anchors.fill: parent

        color: '#000c0b0b'

        z: 100

        MouseArea {
            anchors.fill: parent
            preventStealing: true
        }

        Rectangle {
            anchors.centerIn: parent

            width: 300
            height: 300

            color: "#172033"

            radius: 14

            border.color: "#E2E8F0"
            border.width: 1

            Label {
                anchors.fill: parent

                anchors.margins: 20

                text: "Please scan the batch barcode to continue..."

                color: "#E2E8F0"

                font.pixelSize: 15

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter

                wrapMode: Text.WordWrap
            }
        }
    }

    Connections {
        target: display_batch_n_patient

        function onExit_requested() {
            controller.stop_barcode_scanning()
            widget_loader.source = ""
        }
    }

    signal exit_requested()

    Connections {
        target: controller

        function onItems_loaded(items) {
            patient_items.clear()

            for (var i=0; i < items.length; i++) {
                patient_items.append({
                    instrument: items[i].instrument,
                    count: items[i].count,
                    category: items[i].category
                })
            }
        }

        function onBarcode_accepted() {
            scan_overlay.visible = false
            controller.stop_barcode_scanning()
        }

        function onBarcode_rejected(message) {

            message_dialog.message_title = "Attention"
            message_dialog.message_text = message
            message_dialog.message_type = "warning"

            message_dialog.open()
        }

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
        id: reject_dialog

        anchors.centerIn: Overlay.overlay

        width: 450

        modal: true
        focus: true

        closePolicy: Popup.NoAutoClose

        title: "Reject Batch"

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

            Label {
                anchors.left: parent.left
                anchors.leftMargin: 22
                anchors.verticalCenter: parent.verticalCenter

                text: "Reject the Batch"

                font.pixelSize: 15
                font.bold: true

                color: "white"
            }
        }

        contentItem: ColumnLayout {
            spacing: 10

            Label {
                Layout.fillWidth: true

                text: "Please provide a reason for rejecting this batch:"

                color: "white"

                font.pixelSize: 14

                wrapMode: Text.WordWrap
            }

            TextArea {
                id: rejection_comment

                Layout.fillWidth: true
                Layout.preferredHeight: 300

                placeholderText: "Enter a rejection comment. Make it precise..."

                color: "#0F172A"
                placeholderTextColor: "#94A3B8"

                wrapMode: TextArea.Wrap

                background: Rectangle {
                    color: "white"

                    radius: 6

                    border.color: rejection_comment.activeFocus
                                ? "#3B82F6"
                                : "#CBD5E1"

                    border.width: 1
                }
            }
        }

        footer: DialogButtonBox {
            width: parent.width

            padding: 15

            alignment: Qt.AlignRight

            background: Rectangle {
                color: "#172033"

                radius: 14

                Rectangle {
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.right: parent.right
                    height: parent.radius
                    color: parent.color
                }
            }

            Button {
                text: "Cancel"

                DialogButtonBox.buttonRole: DialogButtonBox.RejectRole

                onClicked: {
                    rejection_comment.clear()
                    reject_dialog.close()
                }
            }

            Button {
                text: "Confirm"

                DialogButtonBox.buttonRole: DialogButtonBox.AcceptRole

                onClicked: {
                    if (rejection_comment.text.trim() === "") {

                        message_dialog.message_title = "Attention"
                        message_dialog.message_text = "A rejection comment is required."
                        message_dialog.message_type = "warning"

                        message_dialog.open()

                        return
                    }

                    controller.reject_batch(
                        nurse_name_field.text.trim(),
                        rejection_comment.text.trim()
                    )

                    display_batch_n_patient.exit_requested()
                }
            }
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
        id: display_batch_n_patient_content

        width: parent.width

        spacing: 30

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 10

            Label {
                text: "Batch Code:"
                font.bold: true
                color: "#334155"
            }

            Label {
                text: controller.batch_code
                color: "#334155"
            }

            Item {
                Layout.preferredWidth: 100
            }

            Label {
                text: "Type of Surgery:"
                font.bold: true
                color: "#334155"
            }

            Label {
                text: controller.type_of_surgery
                color: "#334155"
            }
        }

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 10

            Label {
                text: "Patient's Name:"
                font.bold: true
                color: "#334155"
            }

            Label {
                text: controller.patients_name
                color: "#334155"
            }

            Item {
                Layout.preferredWidth: 100
            }

            Label {
                text: "Nurse's Name:"
                font.bold: true
                color: "#334155"
            }

            Item {
                id: nurse_name_container

                Layout.fillWidth: true
                height: nurse_name_field.height

                TextField {
                    id: nurse_name_field

                    anchors.fill: parent 

                    placeholderText: "---Nurse's name---"
                    placeholderTextColor: "#94A3B8"
                    horizontalAlignment: Text.AlignHCenter

                    color: "#0F172A"

                    background: Rectangle {
                        color: "white"

                        border.color: nurse_name_field.activeFocus
                                    ? "#3B82F6"
                                    : "#CBD5E1"

                        border.width: 1
                        radius: 5
                    }
                }
            }
        }

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 10

            Label {
                text: "Last Scan Date & Time:"
                font.bold: true
                color: "#334155"
            }

            Label {
                text: controller.last_scan_date_n_time
                color: "#334155"
            }

            Item {
                Layout.preferredWidth: 50
            }

            Label {
                text: "Current Scan Date & Time:"
                font.bold: true
                color: "#334155"
            }

            Label {
                text: controller.current_scan_date_n_time
                color: "#334155"
            }
        }

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 10

            Label {
                text: "Scanned By:"
                font.bold: true
                color: "#334155"
            }

            Label {
                text: controller.session_user
                color: "#334155"
            }
        }

        RowLayout {
            spacing: 10

            Label {
                text: "Expected Items:"
                font.pixelSize: 17
                font.bold: true
                color: "#334155"
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 300
            Layout.topMargin: -25

            color: "white"

            border.color: "#CBD5E1"
            border.width: 1

            radius: 6

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 1

                spacing: 0

                Rectangle {
                    Layout.fillWidth: true

                    height: 42

                    color: "#E2E8F0"

                    RowLayout {
                        anchors.fill: parent

                        Label {
                            Layout.preferredWidth: 0.45 * parent.width

                            text: "Surgical Instrument"

                            font.bold: true

                            leftPadding: 15

                            color: "#334155"
                        }

                        Label {
                            Layout.preferredWidth: 0.25 * parent.width

                            text: "Instrument Count"

                            font.bold: true

                            color: "#334155"
                        }

                        Label {
                            Layout.fillWidth: true

                            text: "Category"

                            font.bold: true

                            color: "#334155"
                        }
                    }
                }

                ListView {
                    id: patient_items_list

                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    clip: true

                    model: ListModel {
                        id: patient_items
                    }


                    delegate: Rectangle {
                        width: patient_items_list.width

                        height: 40

                        color: index % 2 === 0
                               ? "white"
                               : "#F8FAFC"


                        RowLayout {
                            anchors.fill: parent

                            Label {
                                Layout.preferredWidth: 0.45 * parent.width

                                text: model.instrument

                                leftPadding: 15

                                color: "#475569"
                            }

                            Label {
                                Layout.preferredWidth: 0.25 * parent.width

                                text: model.count

                                color: "#475569"
                            }

                            Label {
                                Layout.fillWidth: true

                                text: model.category

                                color: "#475569"
                            }
                        }
                    }


                    Label {
                        anchors.centerIn: parent

                        visible: patient_items.count === 0

                        text: "No instruments have been added."

                        color: "#94A3B8"
                    }
                }
            }
        }

        RowLayout {
            Layout.fillWidth: true

            spacing: 30

            Item {
                Layout.fillWidth: true
            }

            Button {
                text: "Reject"

                onClicked: {
                    rejection_comment.clear()
                    reject_dialog.open()
                }
            }

            Button {
                text: "Confirm"

                highlighted: true

                onClicked: {
                    if (nurse_name_field.text.trim() === "") {

                        message_dialog.message_title = "Attention"
                        message_dialog.message_text = "Please enter the nurse's name."
                        message_dialog.message_type = "warning"

                        message_dialog.open()

                        return
                    }

                    controller.confirm_batch(
                        nurse_name_field.text.trim(),
                        controller.session_user,
                        controller.current_scan_date_n_time
                    )

                    display_batch_n_patient.exit_requested()
                }
            }
        }
    }
}