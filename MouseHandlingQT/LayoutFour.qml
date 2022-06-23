import QtQuick 2.0

Item {
    width:800;height:800;
    Grid{
        rows:2;
        columns: 2;
        spacing:10;
        anchors.centerIn: parent

        Rectangle{
            id:r1;
            height:200
            width: 200
            focus: true
            color:focus ?"maroon":"green"
            radius:focus ? 50:25
            KeyNavigation.right:r2
            KeyNavigation.down:r3
        }
        Rectangle{
            id:r2;
            height:200
            width: 200
            focus: true
            color:focus ?"red":"pink"
            radius:focus ? 50:25
            KeyNavigation.down:r4
            KeyNavigation.left:r1
        }
        Rectangle{
            id:r3;
            height:200
            width: 200
            focus: true
            color:focus ?"blue":"purple"
            radius:focus ? 50:25
            KeyNavigation.right:r4
            KeyNavigation.up:r1
        }
        Rectangle{
            id:r4;
            height:200
            width: 200
            focus: true
            color:focus ?"yellow":"orange"
            radius:focus ? 50:25
            KeyNavigation.up:r2
            KeyNavigation.left:r3
        }
    }

}
