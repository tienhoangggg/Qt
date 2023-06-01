#include "enumbutton.h"


EnumButton::EnumButton(QObject *parent): QObject(parent)
{

}

int EnumButton::toInt(button a)
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
    return 0;
}

QString EnumButton::toQString(button a)
{
    if(a == EnumButton::button::BtAdd)
        return "+";
    if(a == EnumButton::button::BtSub)
        return "-";
    if(a == EnumButton::button::BtMul)
        return "*";
    if(a == EnumButton::button::BtDiv)
        return "/";
    if(a == EnumButton::button::BtEqual)
        return "=";
    if(a == EnumButton::button::BtDot)
        return ".";
    if(a == EnumButton::button::Bt0)
        return "0";
    if(a == EnumButton::button::Bt1)
        return "1";
    if(a == EnumButton::button::Bt2)
        return "2";
    if(a == EnumButton::button::Bt3)
        return "3";
    if(a == EnumButton::button::Bt4)
        return "4";
    if(a == EnumButton::button::Bt5)
        return "5";
    if(a == EnumButton::button::Bt6)
        return "6";
    if(a == EnumButton::button::Bt7)
        return "7";
    if(a == EnumButton::button::Bt8)
        return "8";
    if(a == EnumButton::button::Bt9)
        return "9";
    if(a == EnumButton::button::BtSquare)
        return "sqr(";
    if(a == EnumButton::button::BtSqrt)
        return "sqrt(";
    if(a == EnumButton::button::BtOneDivX)
        return "1/x";
    if(a == EnumButton::button::BtSign)
        return "negate(";
    return "";
}

bool EnumButton::isOperation(button bt)
{
    if(bt ==  EnumButton::button::BtAdd || bt == EnumButton::button::BtSub || bt == EnumButton::button::BtMul || bt == EnumButton::button::BtDiv)
    {
        return true;
    }
    return false;
}

bool EnumButton::isNumric(button bt)
{
    if(bt == EnumButton::button::Bt0 || bt == EnumButton::button::Bt1 || bt == EnumButton::button::Bt2 || bt == EnumButton::button::Bt3 || bt == EnumButton::button::Bt4 || bt == EnumButton::button::Bt5 || bt == EnumButton::button::Bt6 || bt == EnumButton::button::Bt7 || bt == EnumButton::button::Bt8 || bt == EnumButton::button::Bt9)
    {
        return true;
    }
    return false;
}

float EnumButton::calculate2value()
{
    if(operation == EnumButton::button::BtAdd)
    {
        return EtoF(value1) + EtoF(value2);
    }
    if(operation == EnumButton::button::BtSub)
    {
        return EtoF(value1) - EtoF(value2);
    }
    if(operation == EnumButton::button::BtMul)
    {
        return EtoF(value1) * EtoF(value2);
    }
    if(operation == EnumButton::button::BtDiv)
    {
        return EtoF(value1) / EtoF(value2);
    }
    if(operation == EnumButton::button::BtNull)
    {
        return EtoF(value1);
    }
    return 0;
}

float EnumButton::EtoF(QList<EnumButton::button> val)
{
    QStack<EnumButton::button> stack;
    int index = 0;
    while(EnumButton::isNumric(val[index]) == false)
    {
        stack.push(val[index]);
        index++;
    }
    float res = EtoS(val.mid(index)).toFloat();
    EnumButton::button bt;
    while(stack.empty() == false)
    {
        bt = stack.pop();
        if(bt == EnumButton::button::BtSign)
        {
            res = -res;
        }
        if(bt == EnumButton::button::BtSqrt)
        {
            res = sqrt(res);
        }
        if(bt == EnumButton::button::BtSquare)
        {
            res = res * res;
        }
        if(bt == EnumButton::button::BtOneDivX)
        {
            res = 1/res;
        }
    }
    return res;
}

QString EnumButton::EtoS(QList<EnumButton::button> val)
{
    QString res = "";
    QStack<EnumButton::button> stack;
    for(int i = val.length()-1; i >= 0; i--)
    {
        if(val[i] == EnumButton::button::BtSquare || val[i] == EnumButton::button::BtSqrt || val[i] == EnumButton::button::BtOneDivX || val[i] == EnumButton::button::BtSign)
        {
            res = EnumButton::toQString(val[i])+res+")";
        }
        else
        {
            res = EnumButton::toQString(val[i])+res;
        }
    }
    return res;
}

QList<EnumButton::button> EnumButton::StoE(QString val)
{
    QList<EnumButton::button> res;
    int index = 0;
    while(index < val.length())
    {
        if( val.mid(index, 1) == "+")
        {
            res.append(EnumButton::button::BtAdd);
            index ++;
            continue;
        }
        if( val.mid(index, 1) == "-")
        {
            res.append(EnumButton::button::BtSub);
            index ++;
            continue;
        }
        if( val.mid(index, 1) == "*")
        {
            res.append(EnumButton::button::BtMul);
            index ++;
            continue;
        }
        if( val.mid(index, 1) == "/")
        {
            res.append(EnumButton::button::BtDiv);
            index ++;
            continue;
        }
        if( val.mid(index, 1) == "=")
        {
            res.append(EnumButton::button::BtEqual);
            index ++;
            continue;
        }
        if( val.mid(index, 1) == ".")
        {
            res.append(EnumButton::button::BtDot);
            index ++;
            continue;
        }
        if( val.mid(index, 1) == "0")
        {
            res.append(EnumButton::button::Bt0);
            index ++;
            continue;
        }
        if( val.mid(index, 1) == "1")
        {
            res.append(EnumButton::button::Bt1);
            index ++;
            continue;
        }
        if( val.mid(index, 1) == "2")
        {
            res.append(EnumButton::button::Bt2);
            index ++;
            continue;
        }
        if( val.mid(index, 1) == "3")
        {
            res.append(EnumButton::button::Bt3);
            index ++;
            continue;
        }
        if( val.mid(index, 1) == "4")
        {
            res.append(EnumButton::button::Bt4);
            index ++;
            continue;
        }
        if( val.mid(index, 1) == "5")
        {
            res.append(EnumButton::button::Bt5);
            index ++;
            continue;
        }
        if( val.mid(index, 1) == "6")
        {
            res.append(EnumButton::button::Bt6);
            index ++;
            continue;
        }
        if( val.mid(index, 1) == "7")
        {
            res.append(EnumButton::button::Bt7);
            index ++;
            continue;
        }
        if( val.mid(index, 1) == "8")
        {
            res.append(EnumButton::button::Bt8);
            index ++;
            continue;
        }
        if( val.mid(index, 1) == "9")
        {
            res.append(EnumButton::button::Bt9);
            index ++;
            continue;
        }
        if( val.mid(index, 5) == "sqrt(")
        {
            res.append(EnumButton::button::BtSqrt);
            index += 5;
            continue;
        }
        if( val.mid(index, 4) == "sqr(")
        {
            res.append(EnumButton::button::BtSquare);
            index += 4;
            continue;
        }
        if( val.mid(index, 5) == "negate(")
        {
            res.append(EnumButton::button::BtSign);
            index += 5;
            continue;
        }
        if( val.mid(index, 3) == "1/(")
        {
            res.append(EnumButton::button::BtOneDivX);
            index += 3;
            continue;
        }
        index++;
    }
    if(res.back() == EnumButton::button::BtDot)
    {
        res.pop_back();
    }
    return res;
}

QString EnumButton::output()
{
    QString temp = _output;
    int index = temp.indexOf('.');
    if(index == -1)
    {
        index = temp.length();
    }
    index -= 3;
    int sign = temp[0] == '-'? 1 : 0;
    while(index > sign)
    {
        temp.insert(index,',');
        index -= 3;
    }
    return temp;
}

QString EnumButton::outputTop()
{
    return _outputTop;
}

QString EnumButton::showValue1()
{
    return EtoS(value1);
}

QString EnumButton::showValue2()
{
    return EtoS(value2);
}

QString EnumButton::showOperation()
{
    return toQString(operation);
}

void EnumButton::pressButton(int bt)
{
    if(EnumButton::isNumric(button(bt)))
    {
        if(state_cur == state::afterOperation)
        {
            _output = "";
            state_cur = state::arg2;
        }
        if(state_cur == state::afterBtEqual)
        {
            _output = "";
            state_cur = state::arg1;
        }
        if(_output == "0")
        {
            _output = "";
        }
        if(state_cur == state::arg1 || state_cur == state::arg2)
        {
            _output += QString::number(EnumButton::toInt(EnumButton::button(bt)));
        }
        else
        {
            _output = QString::number(EnumButton::toInt(EnumButton::button(bt)));
            if(state_cur == state::afterArg1)
            {
                value1.clear();
                state_cur = state::arg1;
            }
            if(state_cur == state::afterArg2)
            {
                value2.clear();
                state_cur = state::arg2;
            }
        }
    }
    if(bt == button::BtDot)
    {
        if(state_cur == state::arg1 || state_cur == state::arg2)
        {
            if(_output.contains("."))
            {
                return;
            }
            _output += ".";
        }
        else
        {
            _output = "0.";
            if(state_cur == state::afterArg1 || state_cur == state::afterBtEqual)
            {
                value1.clear();
                state_cur = state::arg1;
            }
            if(state_cur == state::afterArg2 || state_cur == state::afterOperation)
            {
                value2.clear();
                state_cur = state::arg2;
            }
        }
    }
    if(bt == button::BtSign)
    {
        if(_output == "0")
        {
            return;
        }
        if(_output[0] == '-')
        {
            _output.remove(0,1);
        }
        else
        {
            _output.push_front('-');
        }
        if(state_cur == state::arg1 || state_cur == state::afterArg1)
        {
            value1.insert(0,EnumButton::button::BtSign);
        }
        if(state_cur == state::arg2 || state_cur == state::afterArg2)
        {
            value2.insert(0,EnumButton::button::BtSign);
        }
    }
    if(bt == button::BtBack)
    {
        if(state_cur == state::afterArg1 || state_cur == state::afterArg2)
        {
            return;
        }
        int sign = 1;
        if(_output[0] == '-')
        {
            sign = 2;
        }
        if(_output.length() == sign)
        {
            _output = "0";
        }
        else
        {
            _output.remove(_output.length()-1,1);
        }
    }
    if(bt == button::BtPercent)
    {
        if(operation == EnumButton::button::BtNull || value1.empty())
        {
            _output = "0";
            _outputTop = "0";
            emit outputChanged();
            emit outputTopChanged();
            return;
        }
        if(state_cur == state::afterBtEqual)
        {
            value1 = StoE(_output);
        }
        if(operation == EnumButton::button::BtMul || operation == EnumButton::button::BtDiv)
        {
            _output = QString::number(_output.toFloat() / 100);
        }
        else
        {
            _output = QString::number(_output.toFloat() * EtoF(value1) / 100);
        }
        state_cur = state::afterArg2;
        value2 = StoE(_output);
    }
    if(bt == button::BtSquare || bt == button::BtSqrt || bt == button::BtOneDivX)
    {
        if(state_cur == state::afterBtEqual)
        {
            value1 = StoE(_output);
            state_cur = state::arg1;
        }
        if(state_cur == state::arg1 || state_cur == state::afterArg1)
        {
            if(value1.empty())
            {
                value1 = StoE(_output);
            }
            value1.insert(0,button(bt));
            _output = QString::number(EtoF(value1));
            state_cur = state::afterArg1;
        }
        if(state_cur == state::arg2 || state_cur == state::afterArg2)
        {
            if(value2.empty())
            {
                value2 = StoE(_output);
            }
            value2.insert(0,button(bt));
            _output = QString::number(EtoF(value2));
            state_cur = state::afterArg2;
        }
    }
    if(bt == button::BtCE)
    {
        _output = "0";
        if(state_cur == state::afterArg1)
        {
            value1.clear();
            state_cur = state::arg1;
        }
        if(state_cur == state::afterArg2)
        {
            value2.clear();
            state_cur = state::arg2;
        }
        if(state_cur == state::afterBtEqual)
        {
            state_cur = state::arg1;
        }
    }
    if(bt == button::BtC)
    {
        _output = "0";
        _outputTop = "";
        value1.clear();
        value2.clear();
        operation = EnumButton::button::BtNull;
        state_cur = state::arg1;
    }
    if(EnumButton::isOperation(EnumButton::button(bt)))
    {
        if(state_cur == state::arg1 || state_cur == state::afterBtEqual)
        {
            value1 = StoE(_output);
        }
        if(state_cur == state::arg2 || state_cur == state::afterArg2)
        {
            if(state_cur == state::arg2)
            {
                value2 = StoE(_output);
            }
            _output = QString::number(calculate2value());
            emit historyChanged();
            value1 = StoE(_output);
        }
        operation = EnumButton::button(bt);
        state_cur = state::afterOperation;
    }
    if(bt == button::BtEqual)
    {
        if(state_cur == state::arg1)
        {
            value1 = StoE(_output);
        }
        if(state_cur == state::arg2)
        {
            value2 = StoE(_output);
        }
        if(state_cur == state::afterBtEqual)
        {
            value1 = StoE(_output);
        }
        _output = QString::number(calculate2value());
        emit historyChanged();
        state_cur = state::afterBtEqual;
    }
    if(bt == button::BtMS)
    {
        state_cur = state::afterBtEqual;
        emit mSfunc();
        return;
    }
    if(bt == button::BtMC)
    {
        state_cur = state::afterBtEqual;
        emit mCfunc();
        return;
    }
    if(bt == button::BtMR)
    {
        emit mRfunc();
        return;
    }
    if(bt == button::BtMPlus)
    {
        state_cur = state::afterBtEqual;
        emit mPfunc();
        return;
    }
    if(bt == button::BtMMinus)
    {
        state_cur = state::afterBtEqual;
        emit mMfunc();
        return;
    }
    updateOutputTop();
    emit outputChanged();
    emit outputTopChanged();
}

void EnumButton::getHistory(QString val1, QString opera, QString val2, QString out)
{
    value1 = StoE(val1);
    value2 = StoE(val2);
    operation = StoE(opera)[0];
    _output = out;
    state_cur = state::afterArg2;
    updateOutputTop();
    emit outputChanged();
    emit outputTopChanged();
}

void EnumButton::getMemory(QString val)
{
    _output = val;
    if(state_cur == state::arg1 || state_cur == state::afterBtEqual)
    {
        state_cur = state::afterArg1;
        value1 = StoE(_output);
    }
    if(state_cur == state::afterOperation || state_cur == state::arg2)
    {
        state_cur = state::afterArg2;
        value2 = StoE(_output);
    }
    emit outputChanged();
}

void EnumButton::updateOutputTop()
{
    if(state_cur == state::arg1)
    {
        _outputTop = "";
    }
    if(state_cur == state::afterArg1)
    {
        _outputTop = EtoS(value1);
    }
    if(state_cur == state::afterOperation || state_cur == state::arg2)
    {
        _outputTop = EtoS(value1)+toQString(operation);
    }
    if(state_cur == state::afterArg2)
    {
        _outputTop = EtoS(value1)+toQString(operation) + EtoS(value2);
    }
    if(state_cur == state::afterBtEqual)
    {
        _outputTop = EtoS(value1)+toQString(operation) + EtoS(value2) + "=";
    }
}
