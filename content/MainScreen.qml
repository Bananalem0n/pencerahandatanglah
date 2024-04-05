import QtQuick 2.15
import QtQuick.Controls 2.15
import pencerahandatanglah

Rectangle {
    id:canvas
    width: Constants.width
    height: Constants.height

    Row {
        id: row
        anchors.centerIn: parent
        width: parent
        height: parent

        Button {
            id: button1
        }

        Button {
            id: button2

        }
    }
}
