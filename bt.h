#ifndef BT_H
#define BT_H

#include <QObject>
#include <QDebug>
#include "enumbutton.h"
#include <cmath>
class Bt : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString output READ output WRITE setOutput NOTIFY outputChanged)
    Q_PROPERTY(QString outputTop READ outputTop WRITE setOutputTop NOTIFY outputTopChanged)
public:
    explicit Bt(QObject *parent = nullptr);
    QString output()const;
    void setOutput(QString const &out);
    QString outputTop()const;
    void setOutputTop(QString const &out);
    float cal();
public slots:
    void pressButton(int bt);
private:
    float value1 = 0;
    float value2 = 0;
    QString _output = "0";
    QString _outputTop = "";
    enum args {Arg1, Arg2};
    EnumButton::button operation = EnumButton::button::BtAdd;
    args state_arg = args::Arg1;
    bool state_input = true;
signals:
    void outputChanged();
    void outputTopChanged();
};

#endif // BT_H
