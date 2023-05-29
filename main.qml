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
    Column {
        width: parent.width - historyAndMemory.width
        height: parent.height
        id: columnList
        Text {
            id: outputTop
            width: parent.width
            height: parent.height/17
            text: BtFunc.outputTop
            font.pixelSize: height
            horizontalAlignment: Text.AlignRight
        }
        Text {
            id: output
            width: parent.width
            height: parent.height*3/17
            text: BtFunc.output
            font.pixelSize: height
            horizontalAlignment: Text.AlignRight
        }
        Row
        {
            width: parent.width
            height: parent.height/17
            id: rowButtonFunc
            ListModel{
                id: modelButtonFunc
                Component.onCompleted: {
                    modelButtonFunc.append({id:Bt.BtMC, show:qsTr("MC")})
                    modelButtonFunc.append({id:Bt.BtMR, show:qsTr("MR")})
                    modelButtonFunc.append({id:Bt.BtMPlus, show:qsTr("M+")})
                    modelButtonFunc.append({id:Bt.BtMMinus, show:qsTr("M-")})
                    modelButtonFunc.append({id:Bt.BtMS, show:qsTr("MS")})
                    modelButtonFunc.append({id:Bt.BtMMore, show:qsTr("M~")})
                }
            }
            Component
            {
                id: componentButtonFunc
                Button{
                    hoverEnabled: true
                    width: rootWindow.width < BtFunc.widthWindow? parent.width/6 : parent.width/5
                    height: parent.height
                    onClicked: {
                        BtFunc.pressButton(model.id)
                    }
                    text: model.show
                    background: Rectangle{
                        id: bg
                        anchors.fill: parent
                        color: parent.hovered? parent.pressed? "#00505b":"#00a0ab":"#ffffff"
                    }
                }
            }
            Repeater{
                id: buttonFunc
                width: parent.width
                height: parent.height
                model: modelButtonFunc
                delegate: componentButtonFunc
            }
        }
        ListModel {
            Component.onCompleted: {
                listButton.append({id: Bt.BtPercent, show:qsTr("%")})
                listButton.append({id: Bt.BtCE, show:qsTr("CE")})
                listButton.append({id: Bt.BtC, show:qsTr("C")})
                listButton.append({id: Bt.BtBack, show:qsTr("x")})
                listButton.append({id: Bt.BtOneDivX, show:qsTr("1/x")})
                listButton.append({id: Bt.BtSquare, show:qsTr("x^2")})
                listButton.append({id: Bt.BtSqrt, show:qsTr("2Vx")})
                listButton.append({id: Bt.BtDiv, show:qsTr("/")})
                listButton.append({id: Bt.Bt7, show:qsTr("7")})
                listButton.append({id: Bt.Bt8, show:qsTr("8")})
                listButton.append({id: Bt.Bt9, show:qsTr("9")})
                listButton.append({id: Bt.BtMul, show:qsTr("*")})
                listButton.append({id: Bt.Bt4, show:qsTr("4")})
                listButton.append({id: Bt.Bt5, show:qsTr("5")})
                listButton.append({id: Bt.Bt6, show:qsTr("6")})
                listButton.append({id: Bt.BtSub, show:qsTr("-")})
                listButton.append({id: Bt.Bt1, show:qsTr("1")})
                listButton.append({id: Bt.Bt2, show:qsTr("2")})
                listButton.append({id: Bt.Bt3, show:qsTr("3")})
                listButton.append({id: Bt.BtAdd, show:qsTr("+")})
                listButton.append({id: Bt.BtSign, show:qsTr("+/-")})
                listButton.append({id: Bt.Bt0, show:qsTr("0")})
                listButton.append({id: Bt.BtDot, show:qsTr(".")})
                listButton.append({id: Bt.BtEqual, show:qsTr("=")})
            }
            id: listButton
        }
        Component {
            id: componentButton
            Button {
                hoverEnabled: true
                width: showButton.cellWidth
                height: showButton.cellHeight
                onClicked: {
                    BtFunc.pressButton(model.id)
                }
                text: model.show
                background: Rectangle{
                    id: bg
                    anchors.fill: parent
                    color: parent.hovered? parent.pressed? "#8b008b":"#ff69b4":"#ffc0cb"
                    border.color: "#ffffff"
                }
            }
        }
        GridView {
            id: showButton
            width: parent.width
            height: parent.height*12/17
            cellWidth: width/4
            cellHeight: height/6
            delegate: componentButton
            model: listButton
        }
    }
    Exp{
        id: historyAndMemory
    }
}
