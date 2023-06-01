import QtQuick 2.12
import QtQuick.Controls 2.12
import ClassButton 1.0

Column{
    Text {
        id: announcement
        width: parent.width
        height: parent.height
        text: qsTr("There's nothing saved in memory")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignLeft
        visible: memoryModel.count == 0? true : false
    }
    Connections{
        target: bt
        ignoreUnknownSignals: true
        onMSfunc:{
            memoryModel.insert(0, {value:bt.output})
        }
        onMCfunc:{
            memoryModel.clear()
        }
        onMRfunc:{
            if(memoryModel.count > 0)
            {
                bt.getMemory( memoryModel.get(0).value)
            }
        }
        onMPfunc:{
            if(memoryModel.count == 0)
            {
                memoryModel.append({value:"0"})
            }
            memoryModel.get(0).value = (parseInt(memoryModel.get(0).value,10)+parseInt(bt.output, 10)).toString()
        }
        onMMfunc:{
            if(memoryModel.count == 0)
            {
                memoryModel.append({value:"0"})
            }
            memoryModel.get(0).value = (parseInt(memoryModel.get(0).value,10)-parseInt(bt.output, 10)).toString()
        }
    }
    ListModel{
        id: memoryModel
    }
    Component{
        id: memoryComponent
        Rectangle{
            width: memoryList.cellWidth
            height: memoryList.cellHeight
            color: mouseArea.containsMouse||mMinusBt.containsMouse||mPlusBt.containsMouse||mCBt.containsMouse?mouseArea.containsPress?"#ff69b4":"#ffc0cb":"#ffd0db"
            Text {
                width: parent.width
                height: parent.height
                font.pixelSize: height*3/7
                horizontalAlignment: Text.AlignRight
                text: model.value
            }
            MouseArea{
                id: mouseArea
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    bt.getMemory(model.value)
                }
            }
            Rectangle{
                id: mMinus
                visible: parent.color != "#ffd0db"
                width: memoryList.cellWidth/10
                height: memoryList.cellHeight*2/5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 2
                anchors.rightMargin: 10
                anchors.right: parent.right
                color: mMinusBt.containsMouse?mMinusBt.containsPress?"#8b008a":"#ff69b3":"#ffc0ca"
                border.color: "#ffffff"
                Text {
                    text: qsTr("M-")
                    horizontalAlignment: Text.AlignHCenter
                    anchors.fill: parent
                }
                MouseArea{
                    id: mMinusBt
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: {
                        model.value = (parseInt(model.value,10)-parseInt(bt.output, 10)).toString()
                    }
                }
            }
            Rectangle{
                id: mPlus
                visible: parent.color != "#ffd0db"
                width: memoryList.cellWidth/10
                height: memoryList.cellHeight*2/5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 2
                anchors.rightMargin: 2
                anchors.right: mMinus.left
                color: mPlusBt.containsMouse?mPlusBt.containsPress?"#8b008a":"#ff69b3":"#ffc0ca"
                border.color: "#ffffff"
                Text {
                    text: qsTr("M+")
                    horizontalAlignment: Text.AlignHCenter
                    anchors.fill: parent
                }
                MouseArea{
                    id: mPlusBt
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: {
                        model.value = (parseInt(model.value,10)+parseInt(bt.output, 10)).toString()
                    }
                }
            }
            Rectangle{
                id: mC
                visible: parent.color != "#ffd0db"
                width: memoryList.cellWidth/10
                height: memoryList.cellHeight*2/5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 2
                anchors.rightMargin: 2
                anchors.right: mPlus.left
                color: mCBt.containsMouse?mCBt.containsPress?"#8b008a":"#ff69b3":"#ffc0ca"
                border.color: "#ffffff"
                Text {
                    text: qsTr("MC")
                    horizontalAlignment: Text.AlignHCenter
                    anchors.fill: parent
                }
                MouseArea{
                    id: mCBt
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: {
                        memoryModel.remove(model.index)
                    }
                }
            }
        }
    }
    GridView{
        id: memoryList
        width: parent.width
        height: parent.height - eraseMemory.height
        cellWidth: width
        cellHeight: 70
        delegate: memoryComponent
        model: memoryModel
    }
    Button{
        id: eraseMemory
        hoverEnabled: true
        onClicked: {
            memoryModel.clear()
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
