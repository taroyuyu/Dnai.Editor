import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Dialogs 1.3

import DNAI 1.0
import Dnai.Controls 1.0
import DNAI.Views 1.0


import "../Style"
import "../Components"
import "../Panels"
import "../Properties"

Rectangle {
    color: "#16000000"
    property FileDialog openModal: null
    property Modal newModal: null

    Column {
        anchors.centerIn: parent
        spacing: 15
        LinkButton {
            cursorShape: Qt.PointingHandCursor
            text: qsTr("Create new project")
            onPressed: {
                if (newModal !== null)
                    newProjectPopup.open()
            }
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Text {
            text: qsTr("or")
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
        }
        LinkButton {
            cursorShape: Qt.PointingHandCursor
            text: qsTr("Open a project")
            onPressed: {
                if (openModal !== null)
                    openProjectId.open()
            }
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
