import QtQuick 2.0

Rectangle{
    id:root
    width:800
    height:800
    color:"black"

    Rectangle{
        id:r1
        width:root.width/2
        height:200
        color:"blue"
        Text {
            text: "ON"
            font.pixelSize: 25
            color:"white"
            anchors.centerIn: parent
        }
    }
    Rectangle{
        id:r2
        width:root.width/2
        height:200
        color:"pink"
        anchors.left:r1.right
        Text {
           text:"OFF"
           font.pixelSize: 25
           color:"white"
           anchors.centerIn: parent
        }
    }
    Rectangle{
        id:r3
        width:root.width/2
        height:200
        color:"red"
        Text {
           text:"SWITCH"
           font.pixelSize: 25
           color:"white"
           anchors.centerIn: parent
        }
    }
    MouseArea{
        anchors.fill:parent
        id:ms
        drag.target: r3
        drag.axis: Drag.XAxis
        drag.minimumX: 0
        drag.maximumX: root.width/2
    }
}
