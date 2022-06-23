import QtQuick 2.0

Rectangle{
    property int count:0
    width:800
    height:800
    color:"black"

    Rectangle{
        id:r1
        width:100
        height:100
        color:"red"
        visible: false
    }
    Rectangle{
        id:r2
        width:100
        height:100
        color:"yellow"
        visible: false
    }
    Rectangle{
        id:r3
        width:100
        height:100
        color:"green"
        visible: false
    }
    Rectangle{
        id:r4
        width:100
        height:100
        color:"pink"
        visible: false
    }

    MouseArea{
        anchors.fill:parent
        onClicked:
        {
            count++
            if(count==1){
                r1.x=mouseX
                r1.y=mouseY
                r1.visible=true
            }

            if(count==2){
                r2.x=mouseX
                r2.y=mouseY
                r2.visible=true
            }

            if(count==3){
                r3.x=mouseX
                r3.y=mouseY
                r3.visible=true
            }

            if(count==4){
                r4.x=mouseX
                r4.y=mouseY
                r4.visible=true
            }
        }
    }
}
