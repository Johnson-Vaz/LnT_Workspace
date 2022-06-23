import QtQuick 2.0

Item {
    anchors.fill: parent
    ListView {
        anchors.fill: parent
        spacing: 5
        model: dModel
        delegate: Rectangle{height:100; width:_root.width;color: "light blue"
            Row{
                spacing: 5
                anchors.verticalCenter: parent.verticalCenter
                Text {
                    text: index+1
                    font.pixelSize: 18
                }
                Column{
                    spacing: 5
                    Text {
                        text: "Doctor: "+dModel.getData(index).doctorname
                        font.pixelSize: 18
//                        color: "Blue"
                    }
                    Text {
                        text: "Speciality: "+dModel.getData(index).speciality
                        font.pixelSize: 18
//                        color: "red"
                    }
                    Text {
                        text: "Qualification: "+dModel.getData(index).qualification
                        font.pixelSize: 18
//                        color: "Red"
                    }
                }
            }
        }
        focus: true
    }
}
