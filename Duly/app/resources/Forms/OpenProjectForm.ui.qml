import QtQuick 2.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2

Page {
    property alias fileDialog: fileDialog
    property alias chooseButton: pathButton
    property alias cancelButton: cancelButton
    property alias openButton: openButton
    property alias projectPath: projectPath
    property alias viewData: viewData

    FileDialog {
        id: fileDialog
        title: "Please choose a project"
        folder: shortcuts.home
        selectMultiple: false
        nameFilters: ["Duly project (*.dulyproject)"]
    }
    TabBar {
        width: parent.width
        TabButton {
            text: qsTr("Open a project")
        }
    }
    ColumnLayout {
        width: parent.width - 40
        anchors.rightMargin: 20
        anchors.leftMargin: 20
        anchors.centerIn: parent
        RowLayout {
            anchors.left: parent.left
            anchors.right: parent.right
            Label {
                id: pathLabel
                text: qsTr("Open : ")
                anchors.left: parent.left
            }
            TextField {
                id: projectPath
                anchors.leftMargin: 20
                anchors.rightMargin: 50
                anchors.left: pathLabel.right
                anchors.right: pathButton.left
                placeholderText: qsTr("Choose a project")
                text: fileDialog.fileUrl
                readOnly: true
            }
            Button {
                id: pathButton
                anchors.right: parent.right
                text: qsTr("Choose")
            }
        }
        RowLayout {
            anchors.left: parent.left
            anchors.right: parent.right
            Rectangle {
                width: parent.width
                height: viewData.count * 18
                color: "#80FFFFFF"
                radius: 10
                ListView {
                    id: list
                    anchors.fill: parent
                    anchors.topMargin: 10
                    anchors.leftMargin: 15
                    model: ListModel {
                        id:viewData
                    }
                    delegate: Text {
                            text: field + ": " + value
                        }
                }
            }
        }
    }

    footer: ToolBar {
        Material.background: Material.color(Material.Grey, Material.Shade800)
        ToolButton {
            id: cancelButton
            anchors.left: parent.left
            leftPadding: 20
            rightPadding: 20
            text: qsTr("Cancel")
        }
        ToolButton {
            id: openButton
            anchors.right: parent.right
            leftPadding: 20
            rightPadding: 20
            text: qsTr("Open")
        }
    }
}
