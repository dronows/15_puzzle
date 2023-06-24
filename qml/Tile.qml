import QtQuick 2.0

Rectangle {
    id:root
    property string displayText: ""
    color: "lightgreen"
    border.color: "black"
    border.width: 1
    radius: 10
    Text{
        anchors.centerIn: root
        text: root.displayText
        font.bold: true
        font.pointSize: Math.min(root.width,root.height) / 3
    }
}