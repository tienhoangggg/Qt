import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import ClassButton 1.0
Window {
    visible: true
    width: 500
    height: 600
    id: rootWindow
    title: qsTr("Caculator")
    Bt{
        id: bt
    }
    CalculatorMain {
        width: rootWindow.width - historyAndMemory.width
        height: parent.height
        id: columnList
    }
    Rectangle{
        id: historyAndMemory
        width: visible? 300 : 0
        height: parent.height
        color: "#ffd0db"
        visible: rootWindow.width > bt.widthWindow? true : false
        anchors.left: columnList.right
        Column{
            anchors.fill: parent
            Row {
                id: buttonShow
                width: parent.width
                height: parent.height/17
                Button {
                    hoverEnabled: true
                    width: parent.width*2/7
                    height: parent.height
                    onClicked: {
                        memoryList.visible = false
                        historyList.visible = true
                    }
                    text: qsTr("History")
                    background: Rectangle{
                        anchors.fill: parent
                        color: parent.hovered? parent.pressed? "#8b008b":"#ff69b4":"#ffc0cb"
                        border.color: "#ffffff"
                    }
                }
                Button {
                    hoverEnabled: true
                    width: parent.width*2/7
                    height: parent.height
                    onClicked: {
                        memoryList.visible = true
                        historyList.visible = false
                    }
                    text: qsTr("Memory")
                    background: Rectangle{
                        anchors.fill: parent
                        color: parent.hovered? parent.pressed? "#8b008b":"#ff69b4":"#ffc0cb"
                        border.color: "#ffffff"
                    }
                }
            }
            History{
                id: historyList
                height: parent.height - buttonShow.height
                width: parent.width
                visible: parent.visible
            }
            Memory{
                id: memoryList
                height: parent.height - buttonShow.height
                width: parent.width
                visible: parent.visible
            }
        }
    }
}
