import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: patient_details

    width: parent ? parent.width : 0

    implicitHeight: patient_details_content.implicitHeight

    Component.onCompleted: {

        var surgeries = pick_a_set_widget.getSurgeryTypes()

        all_surgery_types_model.clear()
        surgery_types_model.clear()

        for (var i = 0; i < surgeries.length; i++) {

            all_surgery_types_model.append({
                surgery: surgeries[i]
            })
        }
    }

    function refresh_patient_items() {
        var result = pick_a_set_widget.get_batch_items(batch_code_field.text)

        if (!result.success) {
            console.log("Failed to refresh patient items:", result.message)
            return
        }

        patient_items.clear()

        for (var i=0; i<result.items.length; i++) {
            patient_items.append({
                instrument: result.items[i].instrument,
                count: result.items[i].count,
                category: result.items[i].category
            })
        }
    }

    Connections {
        target: add_items_into_the_barcode

        function onItems_added() {
            refresh_patient_items()
        }
    }

    Connections {
        target: patient_details

        function onExit_requested() {
            widget_loader.source = ""
        }
    }

    Connections {
        target: pick_a_set_widget

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

                    if (message_dialog.message_type === "success") {
                        patient_details.exit_requested()
                    }
                }
            }
        }
    }

    ListModel {
        id: surgery_types_model
    }

    ListModel {
        id: all_surgery_types_model
    }

    function filter_surgeries(search_text) {

        surgery_types_model.clear()

        var search = search_text.trim().toLowerCase()

        if (search === "") {
            surgery_suggestions_popup.close()
            return
        }

        for (
            var i = 0;
            i < all_surgery_types_model.count;
            i++
        ) {
            var surgery =
                all_surgery_types_model.get(i).surgery

            if (
                surgery
                    .toLowerCase()
                    .indexOf(search) !== -1
            ) {
                surgery_types_model.append({
                    surgery: surgery
                })
            }
        }

        if (surgery_types_model.count > 0) {
            surgery_suggestions_popup.open()
        } else {
            surgery_suggestions_popup.close()
        }
    }

    ColumnLayout {
        id: patient_details_content

        width: parent.width

        spacing: 15

        RowLayout {
            Layout.fillWidth: true
            spacing: 10

            Label {
                text: "Type of Surgery"
                font.bold: true
                color: "#334155"
            }

            Item {
                id: surgery_search_container

                Layout.fillWidth: true
                height: surgery_search_field.height

                TextField {
                    id: surgery_search_field

                    anchors.fill: parent

                    placeholderText: "Type of surgery..."
                    horizontalAlignment: Text.AlignLeft

                    color: "#0F172A"

                    background: Rectangle {
                        color: "white"

                        border.color: surgery_search_field.activeFocus
                                    ? "#3B82F6"
                                    : "#CBD5E1"

                        border.width: 1
                        radius: 5
                    }

                    onTextChanged: {
                        filter_surgeries(text)
                    }

                    onActiveFocusChanged: {
                        if (activeFocus && text.length > 0) {
                            filter_surgeries(text)
                        }
                    }

                    Keys.onEscapePressed: {
                        surgery_suggestions_popup.close()
                    }
                }
            }

            Button {
                text: "OK"

                Layout.preferredWidth: 80

                onClicked: {
                    var selected_surgery = surgery_search_field.text.trim()

                    if (selected_surgery === "") {
                        message_dialog.message_title = "Attention"
                        message_dialog.message_text = "Please select a surgery type before proceeding."
                        message_dialog.message_type = "warning"

                        message_dialog.open()
                        return
                    }

                    var result = pick_a_set_widget.select_batch(selected_surgery)

                    if (!result.success) {
                       console.log("Failed to select a batch: ", result.message)
                       return
                    }

                    batch_code_field.text = result.batch_code 

                    patient_items.clear()

                    var items = result.items

                    for (var i=0; i<items.length; i++) {
                        patient_items.append({
                            instrument: items[i].instrument,
                            count: items[i].count,
                            category: items[i].category
                        })
                    }

                    add_items_into_the_barcode.set_batch_code(result.batch_code)

                    pick_a_set_widget.auto_fill()

                }
            }
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: 10

            Label {
                text: "Batch Code"
                font.bold: true
                color: "#334155"

                Layout.preferredWidth: 110
            }

            TextField {
                id: batch_code_field

                Layout.fillWidth: true

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

        GridLayout {
            Layout.fillWidth: true

            columns: 3

            columnSpacing: 10
            rowSpacing: 8

            Label {
                text: "Patient's Name"
                font.bold: true
                color: "#334155"
            }

            Label {
                text: "Patient's Phone No"
                font.bold: true
                color: "#334155"
            }

            Label {
                text: "Patient's Alternative No"
                font.bold: true
                color: "#334155"
            }


            TextField {
                id: patient_name_field

                Layout.fillWidth: true

                placeholderText: "---Patient's name required---"
                placeholderTextColor: "#94A3B8"
                horizontalAlignment: Text.AlignHCenter

                color: "#0F172A"

                background: Rectangle {
                    color: "white"

                    border.color: patient_name_field.activeFocus
                                  ? "#3B82F6"
                                  : "#CBD5E1"

                    border.width: 1
                    radius: 5
                }
            }


            TextField {
                id: patient_phone_field

                Layout.fillWidth: true

                placeholderText: "---Phone number required---"
                placeholderTextColor: "#94A3B8"
                horizontalAlignment: Text.AlignHCenter

                color: "#0F172A"

                background: Rectangle {
                    color: "white"

                    border.color: patient_phone_field.activeFocus
                                  ? "#3B82F6"
                                  : "#CBD5E1"

                    border.width: 1
                    radius: 5
                }
            }


            TextField {
                id: patient_alternative_field

                Layout.fillWidth: true

                placeholderText: "---Alternative number optional---"
                placeholderTextColor: "#94A3B8"
                horizontalAlignment: Text.AlignHCenter

                color: "#0F172A"

                background: Rectangle {
                    color: "white"

                    border.color: patient_alternative_field.activeFocus
                                  ? "#3B82F6"
                                  : "#CBD5E1"

                    border.width: 1
                    radius: 5
                }
            }
        }

        GridLayout {
            Layout.fillWidth: true

            columns: 3

            columnSpacing: 10
            rowSpacing: 8

            Label {
                text: "Next of Kin's Name"
                font.bold: true
                color: "#334155"
            }

            Label {
                text: "Next of Kin's Phone No"
                font.bold: true
                color: "#334155"
            }

            Label {
                text: "Next of Kin's Alternative No"
                font.bold: true
                color: "#334155"
            }


            TextField {
                id: next_of_kin_name_field

                Layout.fillWidth: true

                placeholderText: "---Next of kin's name required---"
                placeholderTextColor: "#94A3B8"
                horizontalAlignment: Text.AlignHCenter

                color: "#0F172A"

                background: Rectangle {
                    color: "white"

                    border.color: next_of_kin_name_field.activeFocus
                                  ? "#3B82F6"
                                  : "#CBD5E1"

                    border.width: 1
                    radius: 5
                }
            }


            TextField {
                id: next_of_kin_phone_field

                Layout.fillWidth: true

                placeholderText: "---Phone number required---"
                placeholderTextColor: "#94A3B8"
                horizontalAlignment: Text.AlignHCenter

                color: "#0F172A"

                background: Rectangle {
                    color: "white"

                    border.color: next_of_kin_phone_field.activeFocus
                                  ? "#3B82F6"
                                  : "#CBD5E1"

                    border.width: 1
                    radius: 5
                }
            }


            TextField {
                id: next_of_kin_alternative_field

                Layout.fillWidth: true

                placeholderText: "---Alternative number optional---"
                placeholderTextColor: "#94A3B8"
                horizontalAlignment: Text.AlignHCenter

                color: "#0F172A"

                background: Rectangle {
                    color: "white"

                    border.color: next_of_kin_alternative_field.activeFocus
                                  ? "#3B82F6"
                                  : "#CBD5E1"

                    border.width: 1
                    radius: 5
                }
            }
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: 10

            Label {
                text: "Theatre"
                font.bold: true
                color: "#334155"

                Layout.preferredWidth: 60
            }

            ComboBox {
                id: theatre_combo

                Layout.fillWidth: true
                Layout.preferredHeight: 30

                model: [
                    "Theatre 1",
                    "Theatre 2",
                    "Theatre 3",
                    "Theatre 4"
                ]

                contentItem: Text {
                    text: theatre_combo.displayText

                    color: "white"

                    verticalAlignment: Text.AlignVCenter
                    leftPadding: 10
                }

                background: Rectangle {
                    color: "#172033"

                    border.width: 1
                    radius: 5
                }

                popup: Popup {
                    y: theatre_combo.height
                    width: theatre_combo.width

                    padding: 0

                    background: Rectangle {
                        color: "#172033"
                        border.color: "#172033"

                        radius: 5
                    }

                    contentItem: ListView {
                        clip: true

                        implicitHeight: contentHeight

                        model: theatre_combo.delegateModel

                        currentIndex: theatre_combo.highlightedIndex

                        delegate: ItemDelegate {
                            width: theatre_combo.width

                            height: 40

                            text: modelData

                            highlighted: theatre_combo.highlightedIndex === index

                            contentItem: Text {
                                text: modelData

                                color: "#0F172A"

                                verticalAlignment: Text.AlignVCenter

                                leftPadding: 10
                            }

                            background: Rectangle {
                                color: highlighted
                                    ? "#CBD5E1"
                                    : "#E2E8F0"
                            }
                        }
                    }
                }

                editable: false
            }

            Label {
                text: "Issued To"
                font.bold: true
                color: "#334155"
            }

            TextField {
                id: issued_to_field

                Layout.fillWidth: true

                placeholderText: "---Issued to required---"
                placeholderTextColor: "#94A3B8"
                horizontalAlignment: Text.AlignHCenter

                color: "#0F172A"

                background: Rectangle {
                    color: "white"

                    border.color: issued_to_field.activeFocus
                                  ? "#3B82F6"
                                  : "#CBD5E1"

                    border.width: 1
                    radius: 5
                }
            }
        }

        GridLayout {
            Layout.fillWidth: true

            columns: 2

            columnSpacing: 20

            Label {
                text: "Issued By"
                font.bold: true
                color: "#334155"
            }

            Label {
                text: "Date and Time Picked"
                font.bold: true
                color: "#334155"
            }


            TextField {
                id: issued_by_field

                Layout.fillWidth: true

                text: pick_a_set_widget.session_user

                readOnly: true

                color: "#475569"

                background: Rectangle {
                    color: "#F1F5F9"

                    border.color: "#CBD5E1"
                    border.width: 1
                    radius: 5
                }
            }

            TextField {
                id: date_and_time_picked_field

                Layout.fillWidth: true

                text: pick_a_set_widget.date_time_created

                readOnly: true

                color: "#475569"

                background: Rectangle {
                    color: "#F1F5F9"

                    border.color: "#CBD5E1"
                    border.width: 1
                    radius: 5
                }
            }
        }

        RowLayout {
            Layout.fillWidth: true

            Label {
                text: "Items Issued"
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
                    if (batch_code_field.text.trim() === "") {
                        console.log("No batch has been selected")
                        return
                    }

                    add_items_into_the_barcode.set_batch_code(batch_code_field.text)

                    add_items_popup.open()
                }
            }
        }

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

            spacing: 10

            Item {
                Layout.fillWidth: true
            }

            Button {
                text: "Exit"

                onClicked: {
                    var rolled_back = pick_a_set_widget.rollback_transaction()

                    if (!rolled_back) {
                        console.log("Failed to rollback transaction")
                        return
                    }

                    console.log("Transaction rolled back")

                    patient_details.exit_requested()
                }
            }

            Button {
                text: "Done"

                highlighted: true

                onClicked: {
                    var missing_fields = []

                    if (batch_code_field.text.trim() === "") {
                        missing_fields.push("batch_code")
                    }

                    if (patient_name_field.text.trim() === "") {
                        missing_fields.push("Patient's name")
                    }

                    if (patient_phone_field.text.trim() === "") {
                        missing_fields.push("Patient's phone no")
                    }

                    if (next_of_kin_name_field.text.trim() === "") {
                        missing_fields.push("Next of kin name")
                    }

                    if (next_of_kin_phone_field.text.trim() === "") {
                        missing_fields.push("Next of kin phone no")
                    }

                    if (issued_to_field.text.trim() === "") {
                        missing_fields.push("Issued To")
                    }

                    if (batch_code_field.text.trim() === "") {
                        missing_fields.push("Batch Code")
                    }

                    if (surgery_search_field.text.trim() === "") {
                        missing_fields.push("Type of Surgery")
                    }

                    if (missing_fields.length > 0) {

                        message_dialog.message_title = "Attention"

                        message_dialog.message_text = "Please fill in the following required fields:\n\n" + missing_fields.join("\n")

                        message_dialog.message_type = "warning"

                        message_dialog.open()


                        return
                    }

                    var result = pick_a_set_widget.save_patient_details(

                        batch_code_field.text.trim(),

                        surgery_search_field.text.trim(),

                        patient_name_field.text.trim(),

                        patient_phone_field.text.trim(),

                        patient_alternative_field.text.trim(),

                        next_of_kin_name_field.text.trim(),

                        next_of_kin_phone_field.text.trim(),

                        next_of_kin_alternative_field.text.trim(),

                        theatre_combo.currentText,

                        issued_to_field.text.trim(),

                        issued_by_field.text.trim(),

                        date_and_time_picked_field.text.trim()
                    )


                    if (!result.success) {
                        return
                    }
                }
            }
        }
    }

    Popup {
        id: surgery_suggestions_popup

        parent: surgery_search_container

        x: 0

        y: surgery_search_container.height

        width: surgery_search_container.width

        height: Math.min(
            surgery_suggestions_list.contentHeight,
            200
        )

        padding: 0

        z: 9999

        closePolicy:
            Popup.CloseOnEscape |
            Popup.CloseOnPressOutside

        background: Rectangle {
            color: "#172033"

            border.color: "#172033"
            border.width: 1

            radius: 10
        }

        contentItem: ListView {
            id: surgery_suggestions_list

            anchors.fill: parent

            clip: true

            model: surgery_types_model

            delegate: ItemDelegate {
                width: surgery_suggestions_list.width

                height: 40

                text: model.surgery

                onClicked: {
                    surgery_search_field.text = model.surgery

                    surgery_suggestions_popup.close()
                }
            }
        }
    }

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
                text: "Batch: " + batch_code_field.text
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