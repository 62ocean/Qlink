#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QPainter>
#include "map.h"

class Character : public QObject
{
    Q_OBJECT
public:
    explicit Character(int, QObject *parent = nullptr);
    //~Character();

    int x = 0, y = 0; //位置
    int score = 0; //得分
    QTimer *comboTimer;
    int comboRemaining;
    int lastBoxScore;  //上一个消除的箱子的数字
    int xSelect = 0, ySelect = 0; //角色已经选择好的箱子
    bool isCombo = false;

    //用于画折线的参数
    QPoint corner1, corner2;
    QPoint point1, point2;
    int cornerNum;

    //显示折线的参数
    bool showLine = false;
    QTimer *lineTimer; //这些计时器到时间了都要update()一下主窗口

    void selectBox(int xBox,int yBox); //选择对应的箱子

    void scoreCalculate(int boxScore); //箱子消除时计算得分

    //*********多人模式下的道具**********//
    QTimer *freezeTimer, *dizzyTimer;
    bool isFreeze = false, isDizzy = false;
    int freezeRemaining, dizzyRemaining;

    //**********************画图函数*************************
    void drawCharacter(QPainter *painter) const;
    void drawSelectBox(QPainter *painter, QColor color) const;
    void drawLine(QPainter *painter, QColor color) const;
    void drawCombo(QPainter *painter) const;

    friend QDataStream &operator<< (QDataStream &out, Character *player);
    friend QDataStream &operator>> (QDataStream &in, Character *player);


signals:
    void twoSelectedBox(int x1,int y1,int x2,int y2,Character *player);

private:
    int kind = 1; //角色种类

    //计算连击数所需要的参数
    int timesNum = 1;


private slots:
     void notShowLine();  //lineTimer到时间时调用
     void closeCombo();  //comboTimer到时间时调用
     void stopFreeze(); //freezeTimer到时间时调用
     void stopDizzy(); //dizzyTimer到时间时调用

};

#endif // CHARACTER_H
