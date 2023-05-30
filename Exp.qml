import QtQuick 2.0
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import ClassButton 1.0
Rectangle{
    width: visible? 300 : 0
    height: parent.height
    color: "#ffd0db"
    visible: rootWindow.width > BtFunc.widthWindow? true : false
    anchors.left: columnList.right
    Column {
        height: parent.height
        width: parent.width
        visible: parent.visible
        Connections{
            target: BtFunc
            ignoreUnknownSignals: true
            onHistoryChanged:{
                if(historyModel.get(0).output === "")
                {
                    historyModel.clear();
                }
                historyModel.insert(0,{output: BtFunc.output, outputTop: BtFunc.outputTop})
            }
        }
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
        ListModel {
            id: historyModel
            Component.onCompleted: {
                historyModel.append({output: "", outputTop: "there's no history yet"})
            }
        }
        Component {
            id: historyComponent
            Button {
                width: historyList.cellWidth
                height: historyList.cellHeight
                hoverEnabled: true
                background: Rectangle{
                    color: parent.hovered? parent.pressed? "#8b008b":"#ff69b4":"#ffc0cb"
                    Column {
                        Text {
                            width: historyList.cellWidth
                            height: historyList.cellHeight * 2/5
                            text: model.outputTop
                            font.pixelSize: height*4/5
                            horizontalAlignment: Text.AlignRight
                        }
                        Text {
                            width: historyList.cellWidth
                            height: historyList.cellHeight * 3/5
                            text: model.output
                            font.pixelSize: height*4/5
                            horizontalAlignment: Text.AlignRight
                        }
                    }
                }
                onClicked: {
                    //
                }
            }

        }
        GridView {
            id: historyList
            width: parent.width
            height: parent.height
            cellWidth: width
            cellHeight: 70
            delegate: historyComponent
            model: historyModel
        }
        GridView {
            id: memoryList
            width: parent.width
            height: parent.height
        }
    }
}
