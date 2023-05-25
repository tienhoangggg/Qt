#include "enumbutton.h"


EnumButton::EnumButton(QObject *parent): QObject(parent)
{

}

int EnumButton::toInt(EnumButton::button a)
{
    if(a == EnumButton::button::Bt0)
        return 0;
    if(a == EnumButton::button::Bt1)
        return 1;
    if(a == EnumButton::button::Bt2)
        return 2;
    if(a == EnumButton::button::Bt3)
        return 3;
    if(a == EnumButton::button::Bt4)
        return 4;
    if(a == EnumButton::button::Bt5)
        return 5;
    if(a == EnumButton::button::Bt6)
        return 6;
    if(a == EnumButton::button::Bt7)
        return 7;
    if(a == EnumButton::button::Bt8)
        return 8;
    if(a == EnumButton::button::Bt9)
        return 9;
    return -1;
}

QString EnumButton::toQString(EnumButton::button a)
{
    if(a == EnumButton::button::BtAdd)
        return "+";
    if(a == EnumButton::button::BtSub)
        return "-";
    if(a == EnumButton::button::BtMul)
        return "*";
    if(a == EnumButton::button::BtDiv)
        return "/";
    return "";
}

