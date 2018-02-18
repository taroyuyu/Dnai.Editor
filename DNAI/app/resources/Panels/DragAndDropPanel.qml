import QtQuick 2.0
import QtQuick.Controls 2.2

import "../Components"

ExpendablePanel {
    id: tr
//    property alias gridview: _gridView
    title: "DragAndDrop"
    ScrollView
    {
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        NodeModelViewer {
            anchors.fill: parent
        }
    }
}