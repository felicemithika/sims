import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    id: main_window

    width: 1200
    height: 750
    visible: true
    visibility: Window.Maximized

    title: "Surgical Instrument Management System"

    // Main Background
    Rectangle {
        anchors.fill: parent 
        color: "#F1F5F9"
    }

    //Top toolbar
    Rectangle {
        id: top_bar

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        height: 55

        color: "#172033"

        RowLayout {
            anchors.fill: parent
            anchors.leftMargin: 15
            anchors.rightMargin: 15
            spacing: 10

            Label {
                text: "SIMS"
                color: "white"
                font.pixelSize: 20
                font.bold: true
            }

            ToolButton {
                text: "File"
                contentItem: Text {
                    text: parent.text
                    color: "white"
                    verticalAlignment: Text.AlignVCenter
                }
            }

            ToolButton {
                text: "Reports"
                contentItem: Text {
                    text: parent.text
                    color: "white"
                    verticalAlignment: Text.AlignVCenter
                }
            }

            ToolButton {
                text: "Generate Report"
                contentItem: Text {
                    text: parent.text
                    color: "white"
                    verticalAlignment: Text.AlignVCenter
                }
            }

            ToolButton {
                text: "Settings"
                contentItem: Text {
                    text: parent.text
                    color: "white"
                    verticalAlignment: Text.AlignVCenter
                }
            }

            Item {
                Layout.fillWidth: true
            }

            Label {
                text: "Surgical Instrument Management System"
                color: "#CBD5E1"
                font.pixelSize: 13
            }
        }
    }

    //Main Area
    RowLayout {
        id: main_area

        anchors.top: top_bar.bottom
        anchors.bottom: bottom_bar.top
        anchors.left: parent.left
        anchors.right: parent.right

        spacing: 0

        // The left navigation side
        Rectangle {
            id: navigation_panel

            Layout.preferredWidth: main_window.width * 0.20
            Layout.fillHeight: true

            color: "#1E293B"

            ColumnLayout {
                anchors.fill: parent
                spacing: 0

                //logo area
                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 130

                    color: "#172033"

                    Column {
                        anchors.centerIn: parent
                        spacing: 8

                        Rectangle {
                            width: 55
                            height: 55

                            radius: 10

                            color: "#334155"

                            Label {
                                anchors.centerIn: parent

                                text: "S"
                                color: "white"

                                font.pixelSize: 28
                                font.bold: true
                            }
                        }

                        Label {
                            anchors.horizontalCenter: parent.horizontalCenter

                            text: "SIMS"

                            color: "white"
                            font.pixelSize: 18
                            font.bold: true
                        }
                    }
                }
                //navigation buttons
                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 1

                    color: "#334155"
                }

                //store
                Button {
                    id: store_button

                    Layout.fillWidth: true
                    Layout.preferredHeight: 55

                    text: "Store"

                    flat: true

                    onClicked: {
                        store_options.visible = true
                        theatre_options.visible = false
                        decontamination_options.visible = false
                        packaging_options.visible = false

                    section_title.text = "Store"
                    }

                    contentItem: Text {
                        text: parent.text
                        color: "white"
                        font.pixelSize: 15

                        leftPadding: 25
                        rightPadding: 10

                        wrapMode: Text.WordWrap
                        maximumLineCount: 2

                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignLeft

                        elide: Text.ElideNone
                    }

                    background: Rectangle {
                        color: parent.down
                               ? "#475569"
                               : parent.hovered
                                 ? "#334155"
                                 : "transparent"
                    }
                }
                //store submenu
                ColumnLayout {
                    id: store_options

                    Layout.fillWidth: true

                    visible: false

                    spacing: 0

                    Button {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 45

                        text: "Create a Batch"

                        flat: true

                        onClicked: {
                            widget_title.text = "Create a Batch"
                            widget_loader.source = "create_batches.qml"
                        }

                        contentItem: Text {
                            text: parent.text

                            color: "#CBD5E1"

                            font.pixelSize: 13

                            leftPadding: 45

                            verticalAlignment: Text.AlignVCenter
                        }

                        background: Rectangle {
                            color: parent.hovered
                                   ? "#334155"
                                   : "transparent"
                        }
                    }

                    Button {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 45

                        text: "Enter Patient Details"

                        flat: true

                        onClicked: {
                            widget_title.text = "Enter Patient Details"
                            widget_loader.source = "patient_details.qml"
                        }

                        contentItem: Text {
                            text: parent.text

                            color: "#CBD5E1"

                            font.pixelSize: 13

                            leftPadding: 45

                            verticalAlignment: Text.AlignVCenter
                        }

                        background: Rectangle {
                            color: parent.hovered
                                   ? "#334155"
                                   : "transparent"
                        }
                    }

                    Button {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 45

                        text: "Post-Store"

                        flat: true

                        onClicked: {
                            widget_title.text = "Post-Store"
                            widget_loader.setSource("display_batch_n_patient.qml", {
                                "controller": post_store
                            })
                        }

                        contentItem: Text {
                            text: parent.text

                            color: "#CBD5E1"

                            font.pixelSize: 13

                            leftPadding: 45

                            verticalAlignment: Text.AlignVCenter
                        }

                        background: Rectangle {
                            color: parent.hovered
                                   ? "#334155"
                                   : "transparent"
                        }
                    }
                }

                //theatre
                Button {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 55

                    text: "Theatre"

                    flat: true

                    onClicked: {
                        store_options.visible = false
                        theatre_options.visible = true
                        decontamination_options.visible = false
                        packaging_options.visible = false

                    section_title.text = "Theatre"
                    }

                    contentItem: Text {
                        text: parent.text
                        color: "white"
                        font.pixelSize: 15

                        leftPadding: 25
                        rightPadding: 10

                        wrapMode: Text.WordWrap
                        maximumLineCount: 2

                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignLeft

                        elide: Text.ElideNone
                    }

                    background: Rectangle {
                        color: parent.hovered
                               ? "#334155"
                               : "transparent"
                    }
                }

                ColumnLayout {
                    id: theatre_options

                    Layout.fillWidth: true

                    visible: false

                    spacing: 0

                    Button {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 45

                        text: "Pre-Theatre"

                        flat: true

                        onClicked: {
                            widget_title.text = "Pre-Theatre"
                            widget_loader.setSource("display_batch_n_patient.qml", {
                                "controller": pre_theatre
                            })
                        }

                        contentItem: Text {
                            text: parent.text

                            color: "#CBD5E1"

                            font.pixelSize: 13

                            leftPadding: 45

                            verticalAlignment: Text.AlignVCenter
                        }
                    }

                    Button {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 45

                        text: "Post-Theatre"

                        flat: true

                        onClicked: {
                            widget_title.text = "Post-Theatre"
                            widget_loader.setSource("display_batch_n_patient.qml", {
                                "controller": post_theatre
                            })
                        }

                        contentItem: Text {
                            text: parent.text

                            color: "#CBD5E1"

                            font.pixelSize: 13

                            leftPadding: 45

                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                }

                // decontamination
                Button {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 55

                    text: "Decontamination"

                    flat: true

                    onClicked: {
                        store_options.visible = false
                        theatre_options.visible = false
                        decontamination_options.visible = true
                        packaging_options.visible = false

                    section_title.text = "Decontamination"
                    }

                    contentItem: Text {
                        text: parent.text
                        color: "white"
                        font.pixelSize: 15

                        leftPadding: 25
                        rightPadding: 10

                        wrapMode: Text.WordWrap
                        maximumLineCount: 2

                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignLeft

                        elide: Text.ElideNone
                    }

                    background: Rectangle {
                        color: parent.hovered
                               ? "#334155"
                               : "transparent"
                    }
                }

                ColumnLayout {
                    id: decontamination_options

                    Layout.fillWidth: true

                    visible: false

                    spacing: 0

                    Button {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 45

                        text: "Pre-Decontamination"

                        flat: true

                        onClicked: {
                            widget_title.text = "Pre-Decontaminate"
                            widget_loader.setSource("display_batch_n_patient.qml", {
                                "controller": pre_decontamination
                            })
                        }

                        contentItem: Text {
                            text: parent.text

                            color: "#CBD5E1"

                            font.pixelSize: 13

                            leftPadding: 45

                            verticalAlignment: Text.AlignVCenter
                        }
                    }

                    Button {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 45

                        text: "Post-Decontamination"

                        flat: true

                        onClicked: {
                            widget_title.text = "Post-ThDecontaminateeatre"
                            widget_loader.setSource("display_batch_n_patient.qml", {
                                "controller": post_decontamination
                            })
                        }

                        contentItem: Text {
                            text: parent.text

                            color: "#CBD5E1"

                            font.pixelSize: 13

                            leftPadding: 45

                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                }

                //packaging and autoclave
                Button {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 55

                    text: "Packaging & Autoclave"

                    flat: true

                    onClicked: {
                        store_options.visible = false
                        theatre_options.visible = false
                        decontamination_options.visible = false
                        packaging_options.visible = true

                    section_title.text = "Packaging & Autoclave"
                    }
                    contentItem: Text {
                        text: parent.text
                        color: "white"
                        font.pixelSize: 15

                        leftPadding: 25
                        rightPadding: 10

                        wrapMode: Text.WordWrap
                        maximumLineCount: 2

                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignLeft

                        elide: Text.ElideNone
                    }

                    background: Rectangle {
                        color: parent.hovered
                               ? "#334155"
                               : "transparent"
                    }
                }
                ColumnLayout {
                    id: packaging_options

                    Layout.fillWidth: true

                    visible: false

                    spacing: 0

                    Button {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 45

                        text: "Pre-Packaging"

                        flat: true

                        onClicked: {
                            widget_title.text = "Pre-Packaging"
                            widget_loader.setSource("display_batch_n_patient.qml", {
                                "controller": pre_packaging
                            })
                        }
                        contentItem: Text {
                            text: parent.text

                            color: "#CBD5E1"

                            font.pixelSize: 13

                            leftPadding: 45

                            verticalAlignment: Text.AlignVCenter
                        }
                    }

                    Button {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 45

                        text: "Post-Packaging"

                        flat: true

                        onClicked: {
                            widget_title.text = "Post-Packaging"
                            widget_loader.setSource("display_batch_n_patient.qml", {
                                "controller": post_packaging
                            })
                        }

                        contentItem: Text {
                            text: parent.text

                            color: "#CBD5E1"

                            font.pixelSize: 13

                            leftPadding: 45

                            verticalAlignment: Text.AlignVCenter
                        }
                    }

                    Button {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 45

                        text: "End-Autoclaving"

                        flat: true

                        onClicked: {
                            widget_title.text = "End-Autoclaving"
                            widget_loader.setSource("display_batch_n_patient.qml", {
                                "controller": end_autoclaving
                            })
                        }

                        contentItem: Text {
                            text: parent.text

                            color: "#CBD5E1"

                            font.pixelSize: 13

                            leftPadding: 45

                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                }

                Item {
                    Layout.fillHeight: true
                }

            }
        }
    

    // right content area
        Rectangle {
                id: content_area

                Layout.fillWidth: true
                Layout.fillHeight: true

                color: "#E2E8F0"

                //background logo

                Label {
                    anchors.centerIn: parent

                    text: "SIMS"

                    color: "#CBD5E1"

                    opacity: 0.25

                    font.pixelSize: 180
                    font.bold: true

                    z: 0
                }

                //section title
                Label {
                    id: section_title

                    anchors.top: parent.top
                    anchors.left: parent.left

                    anchors.topMargin: 20
                    anchors.leftMargin: 30

                    text: "Welcome"

                    color: "#0F172A"

                    font.pixelSize: 24
                    font.bold: true

                    z: 2
                }

                //floating widget
                Rectangle {
                    id: widget_container

                    anchors.centerIn: parent

                    width: parent.width * 0.85
                    height: parent.height * 0.83

                    radius: 12

                    color: "white"

                    border.color: "#CBD5E1"
                    border.width: 1

                    z: 1

                    Rectangle {
                        anchors.fill: parent

                        anchors.margins: -5

                        color: "transparent"

                        border.color: "#94A3B8"
                        border.width: 1

                        opacity: 0.2

                        radius: 15

                        z: -1
                    }

                    ColumnLayout {
                        anchors.fill: parent

                        anchors.margins: 20

                        spacing: 15


                        // Widget title

                        Label {
                            id: widget_title

                            text: "Select an option"

                            color: "#0F172A"

                            font.pixelSize: 20
                            font.bold: true
                        }


                        Rectangle {
                            Layout.fillWidth: true

                            height: 1

                            color: "#E2E8F0"
                        }

                        ScrollView {
                            id: widget_scroll

                            Layout.fillWidth: true
                            Layout.fillHeight: true

                            clip: true

                            ScrollBar.vertical.policy: ScrollBar.AsNeeded
                            ScrollBar.horizontal.policy: ScrollBar.AsNeeded

                            Loader {
                                id: widget_loader

                                width: widget_scroll.availableWidth

                                asynchronous: true

                                source: ""
                            }
                        }
                    }
                }
            }
    }
    

    //Bottom status bar
    Rectangle {
        id: bottom_bar

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        height: 30

        color: "#0F172A"

        RowLayout {
            anchors.fill: parent

            anchors.leftMargin: 15
            anchors.rightMargin: 15

            Label {
                text: "SIMS"

                color: "#CBD5E1"

                font.pixelSize: 12
            }

            Label {
                text: "Ready"

                color: "#94A3B8"

                font.pixelSize: 12
            }

            Item {
                Layout.fillWidth: true
            }

            Label {
                text: "System Status: Online"

                color: "#94A3B8"

                font.pixelSize: 12
            }
        }
    }

}