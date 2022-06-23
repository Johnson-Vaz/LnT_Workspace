import QtQuick 2.0

Item {
    width: 400;
    height: 500;
    Column{
        anchors.fill: parent
        Rectangle{
            id:r1;width:100;height:100;color:"orange"
            radius:focus ?50:25
            focus:true
            KeyNavigation.right:r2
        }
        Rectangle{
            id:r2;width:100;height:100;color:"pink"
            radius:focus ?50:25
            KeyNavigation.left:r1
        }
    }
}
