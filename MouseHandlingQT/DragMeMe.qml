import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id:root
    visible: true
    width:440
    height:480
    title:qsTr("hello World")
    Rectangle{
        anchors.fill:parent
        color:"blue"

        Rectangle{
            id:r2
            width:100;
            height:100;
            color:"yellow"
            radius:50;
            //anchors.centerIn: parent
            //anchors.left:parent.left
            //anchors.bottom: parent.bottom
        }
         MouseArea{
            anchors.fill:parent
            id:ms
            drag.target: r2
            drag.minimumX: 0
            drag.maximumX: 300
            }

        }
}

