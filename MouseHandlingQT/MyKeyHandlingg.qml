import QtQuick 2.0

Rectangle {
    width: 400;
    height: 480;

    Image
    {
        id:img
        x:100
        y:100
        source: "../../../../rockey.jpg"
       // anchors.centerIn: parent
        scale:0.5;
    }
   // Keys.onPressed:console.log("event key is pressed")

    Keys.onLeftPressed:img.rotation = (img.rotation -10)%360
//    {
//        console.log("left is slapped complete now")

//    }
    Keys.onRightPressed: img.rotation=(img.rotation +10)%360
//    {
//        console.log("left is slapped complete now")

//    }
    Keys.onUpPressed:img.y=img.y-20
//    {
//        console.log("left is slapped complete now")

//    }
    Keys.onDownPressed:img.y=img.y+20
//    {
//        console.log("left is slapped complete now")

//    }

    focus: true

}



