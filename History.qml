import QtQuick 2.0
import QtQuick.Controls 2.12
import ClassButton 1.0

Column {
    Text {
        id: announcement
        width: parent.width
        height: parent.height
        text: qsTr("There's no history yet")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignLeft
        visible: historyModel.count == 0? true : false
    }
    Connections{
        target: bt
        ignoreUnknownSignals: true
        onHistoryChanged:{
            historyModel.insert(0,{output: bt.output, value1: bt.showValue1, value2: bt.showValue2, operation: bt.showOperation})
        }
    }
    ListModel {
        id: historyModel
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
                        text: model.value1 + " " + (model.operation === ""?"":model.operation + " "+ model.value2 + " ") + "="
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
                bt.getHistory(model.value1, model.operation, model.value2, model.output)
            }
        }

    }
    GridView {
        id: historyList
        width: parent.width
        height: parent.height - eraseHistory.height
        cellWidth: width
        cellHeight: 70
        delegate: historyComponent
        model: historyModel
    }
    Button{
        id: eraseHistory
        hoverEnabled: true
        onClicked: {
            historyModel.clear()
        }
        height: 50
        anchors.right: parent.right
        text: "Erase"
        background: Rectangle{
            anchors.fill: parent
            color: parent.hovered? parent.pressed? "#8b008b":"#ff69b4":"#ffc0cb"
            border.color: "#ffffff"
        }
    }
}
