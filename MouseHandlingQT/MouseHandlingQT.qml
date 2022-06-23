import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    visible: true
    width:440
    height:480
    title:qsTr("hello World")
    Rectangle{
        anchors.fill:parent
       // color:"blue"
       // color: ms.containsMouse ? "blue":"red"
         color: ms.pressed ? "blue":"red"
        Rectangle{
            id:r2
            width:100;
            height:100;
            color:"yellow"
            radius:50;
        }

        MouseArea{
            anchors.fill:parent
            id:ms
            hoverEnabled: true
            onEntered: {
                          console.log("mouse area entered")
           }
            onExited: {
                           console.log("mouse area exited")
            }
            width: 100; height:100;x:100;y:100;
            // clicked
            // pressed
            // released
            onClicked: {
                handleMouse(mouse);
            }
            onPressed: {
                console.log("press happened")
            }
            onReleased:  {
                console.log("release happened")
            }
        }
    }
    Connections{
        target:ms
    }

                function handleMouse(abcMouse){
                console.log("mouse event happened");
                console.log("X="+abcMouse.x)
                console.log("Y="+abcMouse.y)
                r2.x=abcMouse.x
                r2.y=abcMouse.y
            }

        }

