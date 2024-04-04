/* This file is generated and only relevant for integrating the project into a Qt 6 and cmake based
C++ project. */

import QtQuick
import content
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import QMqttClient 1.0

Window {
    id: canvas
    width: 800
    height: 480
    title: "dudung"
    visible: true

    MqttClient {
        id:client
        hostname:"localhost"
        port: 1883
        username: "user"
        password: "user"

        Component.onCompleted: {
            connectToHost()
        }
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 10

        TextField {
            id: topicField
            placeholderText: "Topic"
            Layout.fillWidth: true
        }

        TextField {
            id: messageField
            placeholderText: "Message"
            Layout.fillWidth: true
        }

        Button {
            text: "Publish"
            Layout.fillWidth: true
            onClicked: {
                if (topicField.text !== "" && messageField.text !== "") {
                    client.publish(topicField.text, messageField.text)
                }
            }
        }
    }

}
