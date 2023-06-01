import QtQuick 2.12
import QtQuick.Controls 2.12
import ClassButton 1.0

Column {
    Text {
        id: outputTop
        width: parent.width
        height: parent.height/17
        text: bt.outputTop
        font.pixelSize: height
        horizontalAlignment: Text.AlignRight
    }
    Text {
        id: output
        width: parent.width
        height: parent.height*3/17
        text: bt.output
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
                width: rootWindow.width < bt.widthWindow? parent.width/6 : parent.width/5
                height: parent.height
                onClicked: {
                    bt.pressButton(model.id)
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
            listButton.append({id: Bt.BtPercent, show:qsTr("%"), color1: "#0b77b5", color2: "#16c8cf", color3: "#04f1fb"})
            listButton.append({id: Bt.BtCE, show:qsTr("CE"), color1: "#8b008b", color2: "#ff69b4", color3: "#ffc0cb"})
            listButton.append({id: Bt.BtC, show:qsTr("C"), color1: "#8b008b", color2: "#ff69b4", color3: "#ffc0cb"})
            listButton.append({id: Bt.BtBack, show:qsTr("x"), color1: "#8b008b", color2: "#ff69b4", color3: "#ffc0cb"})
            listButton.append({id: Bt.BtOneDivX, show:qsTr("1/x"), color1: "#0b77b5", color2: "#16c8cf", color3: "#04f1fb"})
            listButton.append({id: Bt.BtSquare, show:qsTr("x^2"), color1: "#0b77b5", color2: "#16c8cf", color3: "#04f1fb"})
            listButton.append({id: Bt.BtSqrt, show:qsTr("2Vx"), color1: "#0b77b5", color2: "#16c8cf", color3: "#04f1fb"})
            listButton.append({id: Bt.BtDiv, show:qsTr("/"), color1: "#006400", color2: "#008e32", color3: "#00b140"})
            listButton.append({id: Bt.Bt7, show:qsTr("7"), color1: "#8b008b", color2: "#ff69b4", color3: "#ffc0cb"})
            listButton.append({id: Bt.Bt8, show:qsTr("8"), color1: "#8b008b", color2: "#ff69b4", color3: "#ffc0cb"})
            listButton.append({id: Bt.Bt9, show:qsTr("9"), color1: "#8b008b", color2: "#ff69b4", color3: "#ffc0cb"})
            listButton.append({id: Bt.BtMul, show:qsTr("*"), color1: "#006400", color2: "#008e32", color3: "#00b140"})
            listButton.append({id: Bt.Bt4, show:qsTr("4"), color1: "#8b008b", color2: "#ff69b4", color3: "#ffc0cb"})
            listButton.append({id: Bt.Bt5, show:qsTr("5"), color1: "#8b008b", color2: "#ff69b4", color3: "#ffc0cb"})
            listButton.append({id: Bt.Bt6, show:qsTr("6"), color1: "#8b008b", color2: "#ff69b4", color3: "#ffc0cb"})
            listButton.append({id: Bt.BtSub, show:qsTr("-"), color1: "#006400", color2: "#008e32", color3: "#00b140"})
            listButton.append({id: Bt.Bt1, show:qsTr("1"), color1: "#8b008b", color2: "#ff69b4", color3: "#ffc0cb"})
            listButton.append({id: Bt.Bt2, show:qsTr("2"), color1: "#8b008b", color2: "#ff69b4", color3: "#ffc0cb"})
            listButton.append({id: Bt.Bt3, show:qsTr("3"), color1: "#8b008b", color2: "#ff69b4", color3: "#ffc0cb"})
            listButton.append({id: Bt.BtAdd, show:qsTr("+"), color1: "#006400", color2: "#008e32", color3: "#00b140"})
            listButton.append({id: Bt.BtSign, show:qsTr("+/-"), color1: "#8b008b", color2: "#ff69b4", color3: "#ffc0cb"})
            listButton.append({id: Bt.Bt0, show:qsTr("0"), color1: "#8b008b", color2: "#ff69b4", color3: "#ffc0cb"})
            listButton.append({id: Bt.BtDot, show:qsTr("."), color1: "#8b008b", color2: "#ff69b4", color3: "#ffc0cb"})
            listButton.append({id: Bt.BtEqual, show:qsTr("="), color1: "#af1fac", color2: "#d015cd", color3: "#f00eec"})
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
                bt.pressButton(model.id)
            }
            text: model.show
            background: Rectangle{
                id: bg
                anchors.fill: parent
                color: parent.hovered? parent.pressed?model.color1:model.color2:model.color3
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
