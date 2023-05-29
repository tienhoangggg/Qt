#include "bt.h"

float Bt::cal()
{
    if(operation == EnumButton::button::BtAdd)
    {
        return value1 + value2;
    }
    if(operation == EnumButton::button::BtSub)
    {
        return value1 - value2;
    }
    if(operation == EnumButton::button::BtMul)
    {
        return value1 * value2;
    }
    if(operation == EnumButton::button::BtDiv)
    {
        return value1 / value2;
    }
    if(operation == EnumButton::button::BtNull)
    {
        return value1;
    }
    return 0;
}

QString Bt::output() const
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

void Bt::setOutput(const QString &out)
{
    if(_output != out)
    {
        _output = out;
        emit outputChanged();
    }
}

QString Bt::outputTop() const
{
    return _outputTop;
}

void Bt::setOutputTop(const QString &out)
{
    if(_outputTop != out)
    {
        _outputTop = out;
        emit outputTopChanged();
    }
}

Bt::Bt(QObject *parent) : QObject(parent){}

void Bt::pressButton(int bt)
{
    if(_outputTop.length() > 0 && _outputTop[_outputTop.length()-1] == '=')
    {
        _outputTop = "";
    }
    if(bt == EnumButton::button::Bt0 || bt == EnumButton::button::Bt1 || bt == EnumButton::button::Bt2 || bt == EnumButton::button::Bt3 || bt == EnumButton::button::Bt4 || bt == EnumButton::button::Bt5 || bt == EnumButton::button::Bt6 || bt == EnumButton::button::Bt7 || bt == EnumButton::button::Bt8 || bt == EnumButton::button::Bt9)
    {
        if(state_input == true && _output != "0")
        {
            _output += QString::number(EnumButton::toInt(EnumButton::button(bt)));
        }
        else
        {
            _output = QString::number(EnumButton::toInt(EnumButton::button(bt)));
            state_input = true;
            state_input_violate = true;
        }
    }
    if(bt == EnumButton::button::BtDot)
    {
        if(state_input == true)
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
            state_input = true;
            state_input_violate = true;
        }
    }
    if(bt == EnumButton::button::BtSign)
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
        if(state_arg == args::Arg1)
        {
//            if(value1S == "")
        }
        _outputTop = "negate("+_output+")";
    }
    if(bt == EnumButton::button::BtBack)
    {
        if(state_input == false)
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
    if(bt == EnumButton::button::BtPercent)
    {
        if(operation == EnumButton::button::BtMul || operation == EnumButton::button::BtDiv)
        {
            _output = QString::number(_output.toFloat() / 100);
        }
        else
        {
            _output = QString::number(_output.toFloat() * value1 / 100);
        }
        state_input = false;
    }
    if (bt == EnumButton::button::BtSqrt)
    {
        _outputTop += " V("+_output+")";
        _output = QString::number(sqrt(_output.toFloat()));
        state_input = false;
    }
    if (bt == EnumButton::button::BtSquare)
    {
        if(state_arg == args::Arg1)
        {
            _outputTop = " sqr("+_output+")";
        }
        else
        {
            _outputTop += " sqr("+_output+")";
        }
        _output = QString::number(_output.toFloat() * _output.toFloat());
        state_input = false;
    }
    if(bt == EnumButton::button::BtOneDivX)
    {
        _outputTop += " 1/("+_output+")";
        _output = QString::number(1 / _output.toFloat());
        state_input = false;
    }
    if(bt == EnumButton::button::BtCE)
    {
        _output = "0";
        state_input = true;
        if(state_arg == args::Arg1)
        {
            _outputTop = QString::number(value1) + EnumButton::toQString(operation);
        }
    }
    if(bt == EnumButton::button::BtC)
    {
        _output = "0";
        _outputTop = "";
        value1 = 0;
        operation = EnumButton::button::BtNull;
        state_arg = args::Arg1;
        state_input = true;
    }
    if(bt ==  EnumButton::button::BtAdd || bt == EnumButton::button::BtSub || bt == EnumButton::button::BtMul || bt == EnumButton::button::BtDiv)
    {
        if(state_arg == args::Arg1)
        {
            value1 = _output.toFloat();
            state_arg = args::Arg2;
            if(_outputTop.length() == 0 || _outputTop[_outputTop.length()-1] == '=')
            {
                _outputTop = QString::number(value1);
            }
        }
        else
        {
            value2 = _output.toFloat();
            value1 = cal();//
            _output = QString::number(value1);
            _outputTop = _output;
        }
        operation = EnumButton::button(bt);
        state_input = false;
        _outputTop += EnumButton::toQString(operation);
    }
    if(bt == EnumButton::button::BtEqual)
    {
        if(state_arg == args::Arg1)
        {
            value1 = _output.toFloat();
            if(_outputTop.length() == 0)
            {
                _outputTop += QString::number(value1);
            }
            if(operation != EnumButton::button::BtNull)
            {
                _outputTop += EnumButton::toQString(operation) + QString::number(value2);
            }
        }
        else {
            value2 = _output.toFloat();
            QChar temp = _outputTop[_outputTop.length()-1];
            if(temp == '+' || temp == '-' || temp == '*' || temp == '/')
            {
                _outputTop += QString::number(value2);
            }
        }
        _outputTop += " =";
        value1 = cal();
        _output = QString::number(value1);
        state_arg = args::Arg1;
        state_input = false;
    }

    emit outputChanged();
    emit outputTopChanged();
}

