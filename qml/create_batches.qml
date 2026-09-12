import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: create_batch

    width: parent ? parent.width : 0

    implicitHeight: create_batch_content.implicitHeight

    Component.onCompleted: {
        create_a_barcode_widget.auto_fill_items()
    }

    Connections {
        target: create_batch

        function onExit_requested() {
            widget_loader.source = ""
        }
    }

    Connections {
        target: create_a_barcode_widget

        function onSelected_items_updated(items) {
            batch_items.clear()

            for (var i=0; i < items.length; i++) {
                batch_items.append({
                    instrument: items[i].instrument,
                    count: items[i].count,
                    category: items[i].category
                })
            }
        }

        function onBatch_created(batch_code) {

            console.log(
                "Batch successfully created:",
                batch_code
            )

            // add further navigation
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
        id: create_batch_content

        width: parent.width

        spacing: 15

        // Batch information
        GridLayout {
            Layout.fillWidth: true

            columns: 2
            columnSpacing: 20
            rowSpacing: 12

            Label {
                text: "Batch Code"
                font.bold: true
                color: "#334155"
            }

            TextField {
                id: batch_code_field

                Layout.fillWidth: true

                text: create_a_barcode_widget.batch_code

                readOnly: true
                selectByMouse: true

                color: "#475569"

                horizontalAlignment: Text.AlignHCenter

                background: Rectangle {
                    color: "#F1F5F9"
                    border.color: "#CBD5E1"
                    border.width: 1
                    radius: 5
                }
            }

            Label {
                text: "Type of Surgery"
                font.bold: true
                color: "#334155"
            }

            TextField {
                id: surgery_type_field

                Layout.fillWidth: true

                placeholderText: "---Use medically approved terminology---"
                placeholderTextColor: "#94A3B8"

                selectByMouse: true

                color: "#0F172A"

                horizontalAlignment: Text.AlignHCenter

                background: Rectangle {
                    color: "white"
                    border.color: surgery_type_field.activeFocus
                                  ? "#3B82F6"
                                  : "#CBD5E1"
                    border.width: 1
                    radius: 5
                }
            }

            Label {
                text: "Created By"
                font.bold: true
                color: "#334155"
            }

            TextField {
                id: created_by_field

                Layout.fillWidth: true

                text: create_a_barcode_widget.session_user

                readOnly: true
                selectByMouse: true

                color: "#475569"

                horizontalAlignment: Text.AlignHCenter

                background: Rectangle {
                    color: "#F1F5F9"
                    border.color: "#CBD5E1"
                    border.width: 1
                    radius: 5
                }
            }

            Label {
                text: "Date Created"
                font.bold: true
                color: "#334155"
            }

            TextField {
                id: date_created_field

                Layout.fillWidth: true

                text: create_a_barcode_widget.date_created

                readOnly: true

                color: "#475569"

                horizontalAlignment: Text.AlignHCenter

                background: Rectangle {
                    color: "#F1F5F9"
                    border.color: "#CBD5E1"
                    border.width: 1
                    radius: 5
                }
            }

            Label {
                text: "Time Created"
                font.bold: true
                color: "#334155"
            }

            TextField {
                id: time_created_field

                Layout.fillWidth: true

                text: create_a_barcode_widget.time_created

                readOnly: true

                color: "#475569"

                horizontalAlignment: Text.AlignHCenter

                background: Rectangle {
                    color: "#F1F5F9"
                    border.color: "#CBD5E1"
                    border.width: 1
                    radius: 5
                }
            }
        }

        // Add items section
        RowLayout {
            Layout.fillWidth: true
            spacing: 10

            Label {
                text: "Items in Batch"
                font.pixelSize: 17
                font.bold: true
                color: "#0F172A"
            }

            Item {
                Layout.fillWidth: true
            }

            Button {
                text: "+ Add Items"

                onClicked: {
                    add_items_into_the_barcode.set_batch_code (create_a_barcode_widget.batch_code)
                    create_a_barcode_widget.start_items_transaction()
                    //create_a_barcode_widget.setUp_selected_items_tableView()
                    add_items_popup.open()
                }
            }
        }

        // Items table
        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 300

            color: "white"

            border.color: "#CBD5E1"
            border.width: 1
            radius: 6

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 1
                spacing: 0

                // Table header
                Rectangle {
                    Layout.fillWidth: true
                    height: 42

                    color: "#E2E8F0"

                    RowLayout {
                        anchors.fill: parent

                        Label {
                            Layout.preferredWidth: 0.35 * parent.width
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

                // Table contents
                ListView {
                    id: items_list

                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    clip: true

                    model: ListModel {
                        id: batch_items
                    }

                    delegate: Rectangle {
                        width: items_list.width
                        height: 40

                        color: index % 2 === 0
                               ? "white"
                               : "#F8FAFC"

                        RowLayout {
                            anchors.fill: parent

                            Label {
                                Layout.preferredWidth: 0.35 * parent.width
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

                        visible: batch_items.count === 0

                        text: "No instruments have been added to this batch."
                        color: "#94A3B8"
                    }
                }
            }
        }

        // Bottom buttons
        RowLayout {
            Layout.fillWidth: true

            spacing: 10

            Item {
                Layout.fillWidth: true
            }

            Button {
                text: "Exit"

                onClicked: {
                    create_a_barcode_widget.rollback_items_transaction()
                    create_batch.exit_requested()
                }
            }

            Button {
                text: "Create"

                highlighted: true

                onClicked: {
                    create_a_barcode_widget.create_batch(surgery_type_field.text)
                    create_batch.exit_requested()
                }
            }
        }
    }

    // Add-items popup
    Popup {
        id: add_items_popup

        anchors.centerIn: Overlay.overlay

        width: 650
        height: 500

        modal: true
        focus: true

        closePolicy: Popup.NoAutoClose

        background: Rectangle {
            color: "white"
            radius: 10

            border.color: "#CBD5E1"
            border.width: 1
        }

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 20

            spacing: 15

            Label {
                text: "Add Items to Batch"
                font.pixelSize: 20
                font.bold: true
                color: "#0F172A"
            }

            Label {
                text: "Batch: " + create_a_barcode_widget.batch_code
                color: "#64748B"
            }

            Rectangle {
                Layout.fillWidth: true
                height: 1
                color: "#E2E8F0"
            }

            Loader {
                id: add_items_loader

                Layout.fillWidth: true
                Layout.fillHeight: true

                source: "add_items_into_batch.qml"
            }

            RowLayout {
                Layout.fillWidth: true

                Item {
                    Layout.fillWidth: true
                }

                Button {
                    text: "Done"

                    onClicked: {
                        add_items_popup.close()
                    }
                }
            }
        }
    }

    signal exit_requested()
}
