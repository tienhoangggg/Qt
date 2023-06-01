#ifndef ENUMBUTTON_H
#define ENUMBUTTON_H

#include <QObject>
#include <QDebug>
#include <QStack>
#include <cmath>
class EnumButton : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString output READ output NOTIFY outputChanged)
    Q_PROPERTY(QString outputTop READ outputTop NOTIFY outputTopChanged)
    Q_PROPERTY(int widthWindow READ widthWindow NOTIFY widthWindowChanged)
    Q_PROPERTY(QString showValue1 READ showValue1 NOTIFY showValue1Changed)
    Q_PROPERTY(QString showValue2 READ showValue2 NOTIFY showValue2Changed)
    Q_PROPERTY(QString showOperation READ showOperation NOTIFY showOperationChanged)
public:
    explicit EnumButton(QObject *parent = nullptr);
    enum button {Bt0, Bt1, Bt2, Bt3, Bt4, Bt5, Bt6, Bt7, Bt8, Bt9, BtDot, BtSign, BtPercent, BtCE, BtC, BtBack, BtDiv, BtMul, BtSub, BtAdd, BtNull, BtEqual, BtSqrt, BtSquare, BtOneDivX, BtMC, BtMR, BtMPlus, BtMMinus, BtMS, BtMMore};
    Q_ENUM(button);

    int widthWindow()const{return _widthWindow;}
    QString output();
    QString outputTop();
    QString showValue1();
    QString showValue2();
    QString showOperation();
    float calculate2value();
    float EtoF(QList<EnumButton::button> val);
    QString EtoS(QList<EnumButton::button> val);
    QList<EnumButton::button> StoE(QString val);
    int toInt(button a);
    bool isOperation(button a);
    bool isNumric(button a);
    button toEnum(QChar a);
    QString toQString(button a);
    void updateOutputTop();
public slots:
    void pressButton(int bt);
    void getHistory(QString val1, QString opera, QString val2, QString out);
    void getMemory(QString val);

private:
    int _widthWindow = 600;
    QList<EnumButton::button> value1;
    QList<EnumButton::button> value2;
    QString _output = "0";
    QString _outputTop = "";
    enum state {arg1, afterArg1, afterOperation, arg2, afterArg2, afterBtEqual};
    EnumButton::button operation = EnumButton::button::BtNull;
    state state_cur = state::arg1;
signals:
    void widthWindowChanged();
    void outputChanged();
    void outputTopChanged();
    void historyChanged();
    void showValue1Changed();
    void showValue2Changed();
    void showOperationChanged();
    void mCfunc();
    void mRfunc();
    void mPfunc();
    void mMfunc();
    void mSfunc();
};

#endif // ENUMBUTTON_H
