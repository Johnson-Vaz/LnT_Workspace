import QtQuick 2.0

Rectangle{
    property int count:0
    width:900
    height:900
    color:"white"
    Rectangle{
        id:r1
        width:100
        height:100
        color:"red"
        radius:width/2
    }
    Rectangle{
        id:r2
        //      x:100
        //      y:100
        width:100
        height:100
        color:rgba(1,2,3,4);
        border.color:"red" ;
        border.width:5
        anchors.left:r1.right
        anchors.top:r1.bottom
    }
    Rectangle {
        id:r3
        //      x:200
        //      y:200
        width:100
        height:100
        anchors.left:r2.right
        anchors.top:r2.bottom
        gradient: Gradient {
            GradientStop { position: 0.0; color: "red" }
            GradientStop { position: 0.5; color: "yellow" }
            GradientStop { position: 1.0; color: "green" }
            GradientStop { position: 0.0; color: "blue" }
            GradientStop { position: 0.5; color: "orange" }
        }
    }
    Rectangle{
        id:r4
        //      x:300
        //      y:300
        width:100
        height:100
        color:"blue"
        opacity:0.3
        anchors.left:r3.right
        anchors.top:r3.bottom
    }
    Rectangle{
        id:r5
        //      x:400
        //      y:400
        width:100
        height:100
        color:"green"
        visible: true
        anchors.left: r4.right
        anchors.top: r4.bottom
    }
    Rectangle{
        id:r6
        //      x:500
        //      y:500
        width:100
        height:100
        color:"purple"
        rotation: 850
        anchors.left: r5.right
        anchors.top: r5.bottom
    }
    Rectangle{
        id:r7
        //      x:600
        //      y:600
        width:100
        height:100
        color:"purple"
        scale:0.5
        anchors.left: r6.right
        anchors.top: r6.bottom
    }
    Image
    {
        id:img
        //        x:350
        //        y:50
        source: "../../../../Rockey.jpg"
        // anchors.centerIn: parent
        scale:0.5 ;
        anchors.right:parent.right

    }
}
