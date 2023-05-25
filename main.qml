import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import ClassButton 1.0
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Caculator")
    Column
    {
        width: parent.width
        height: parent.height
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
        Text {
            id: temp
//            text: qsTr("text")
            width: parent.width
            height: parent.height/17
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
            id: idButton
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
                    border.color: "#000000"
                }
            }
        }
        GridView {
            id: showButton
            width: parent.width
            height: parent.height*12/17
            cellWidth: width/4
            cellHeight: height/6
            delegate: idButton
            model: listButton
        }
    }

}
