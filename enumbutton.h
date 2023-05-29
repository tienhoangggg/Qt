#ifndef ENUMBUTTON_H
#define ENUMBUTTON_H

#include <QObject>
#include <QDebug>
class EnumButton : public QObject
{
    Q_OBJECT
public:
    explicit EnumButton(QObject *parent = nullptr);
    enum button {Bt0, Bt1, Bt2, Bt3, Bt4, Bt5, Bt6, Bt7, Bt8, Bt9, BtDot, BtSign, BtPercent, BtCE, BtC, BtBack, BtDiv, BtMul, BtSub, BtAdd, BtEqual, BtSqrt, BtSquare, BtOneDivX, BtMC, BtMR, BtMPlus, BtMMinus, BtMS, BtMMore};
    Q_ENUM(button);
    int static toInt(button a);
    QString static toQString(button a);
private:
signals:
};

#endif // ENUMBUTTON_H
