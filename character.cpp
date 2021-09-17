#include "character.h"

Character::Character(int kind0,QObject *parent) :
    QObject(parent),kind(kind0)
{
    lineTimer = new QTimer(this);
    lineTimer->setSingleShot(true);
    connect(lineTimer,SIGNAL(timeout()),this,SLOT(notShowLine()));

    comboTimer = new QTimer(this);
    comboTimer->setSingleShot(true);
    connect(comboTimer,SIGNAL(timeout()),this,SLOT(closeCombo()));

    freezeTimer = new QTimer(this);
    freezeTimer->setSingleShot(true);
    connect(freezeTimer,SIGNAL(timeout()),this,SLOT(stopFreeze()));
    dizzyTimer = new QTimer(this);
    dizzyTimer->setSingleShot(true);
    connect(dizzyTimer,SIGNAL(timeout()),this,SLOT(stopDizzy()));
}



void Character::selectBox(int xBox, int yBox)
{
    if (!xSelect && !ySelect) {
        xSelect = xBox;
        ySelect = yBox;
    } else {
        point1.setX(xBox); point1.setY(yBox);
        point2.setX(xSelect); point2.setY(ySelect);

        emit twoSelectedBox(xBox, yBox, xSelect, ySelect, this);
        xSelect = ySelect = 0;
    }
}
void Character::scoreCalculate(int boxScore)
{
    if (isCombo && (lastBoxScore == boxScore)) {
        ++ timesNum;
        score += boxScore * timesNum;
        comboTimer->start(4000);
    } else {
        isCombo = true;
        timesNum = 1;

        score += boxScore;
        comboTimer->start(4000);
    }
    lastBoxScore = boxScore;
}

void Character::notShowLine()
{
    showLine = false;

}
void Character::closeCombo()
{
    isCombo = false;
    timesNum = 1;
}
void Character::stopFreeze()
{
    isFreeze = false;
}
void Character::stopDizzy()
{
    isDizzy = false;
}

void Character::drawCharacter(QPainter *painter) const
{
    painter->setPen(Qt::NoPen);
    switch (kind) {
    case 1:
        painter->drawPixmap(y-1,x-1,1,1,QPixmap(":/res/role1.png"));
        break;
    case 2:
        painter->drawPixmap(y-1,x-1,1,1,QPixmap(":/res/role2.png"));
        break;
    case 3:
        painter->drawPixmap(y-1,x-1,1,1,QPixmap(":/res/role3.png"));
        break;
    case 4:
        painter->drawPixmap(y-1,x-1,1,1,QPixmap(":/res/role4.png"));
        break;
    }
}
void Character::drawSelectBox(QPainter *painter, QColor color) const
{
    if (xSelect && ySelect) {
        painter->setPen(QPen(color, 0.1, Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin));
        painter->setBrush(Qt::NoBrush);
        painter->drawRect(ySelect-1,xSelect-1,1,1);
    }
}
void Character::drawLine(QPainter *painter, QColor color) const
{

    painter->setPen(QPen(color, 0.3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->setBrush(Qt::NoBrush);

    //如果实现一个新的功能要改动变量，不要改原来的变量，新建一个变量修改。
    //因为你不知道原来的那个变量除了这个功能外还用在了什么地方！！！
    QPointF point1s(point1.y(),point1.x());
    QPointF point2s(point2.y(),point2.x());
    QPointF corner1s(corner1.y(),corner1.x());
    QPointF corner2s(corner2.y(),corner2.x());
    point1s -= QPointF(0.5,0.5);
    point2s -= QPointF(0.5,0.5);
    corner1s -= QPointF(0.5,0.5);
    corner2s -= QPointF(0.5,0.5);

    if (cornerNum == 0) {
        painter->drawLine(point1s,point2s);
    } else if (cornerNum == 1) {
        painter->drawLine(point1s,corner1s);
        painter->drawLine(corner1s,point2s);
    } else if (cornerNum == 2) {
        if ((corner1s.x() != point1s.x()) && (corner1s.y() != point1s.y())) {
            painter->drawLine(point2s,corner1s);
            painter->drawLine(corner1s,corner2s);
            painter->drawLine(corner2s,point1s);
        } else {
            painter->drawLine(point1s,corner1s);
            painter->drawLine(corner1s,corner2s);
            painter->drawLine(corner2s,point2s);
        }
    }
}
void Character::drawCombo(QPainter *painter) const
{
    if (isCombo) {
        QFont font;
        font.setFamily("consolas");
        font.setBold(false);
        font.setPointSizeF(0.5);
        painter->setPen(Qt::black);
        QString str("+");
        str.append(QString::number(lastBoxScore));
        str.append(QString("×"));
        str.append(QString::number(timesNum));
        painter->setFont(font);
        painter->drawText(QPointF(y,x),str);
    }
}

QDataStream &operator<< (QDataStream &out, Character *player)
{
    out << player->x << player->y;
    out << player->score;
    out << player->xSelect << player->ySelect;

    out << player->isCombo << player->comboRemaining;
    out << player->lastBoxScore << player->timesNum;

    out << player->isFreeze << player->freezeRemaining;
    out << player->isDizzy << player->dizzyRemaining;
    return out;
}
QDataStream &operator>> (QDataStream &in, Character *player)
{
    in >> player->x >> player->y;
    in >> player->score;
    in >> player->xSelect >> player->ySelect;

    in >> player->isCombo >> player->comboRemaining;
    in >> player->lastBoxScore >> player->timesNum;
    if (player->isCombo) player->comboTimer->start(player->comboRemaining);

    in >> player->isFreeze >> player->freezeRemaining;
    in >> player->isDizzy >> player->dizzyRemaining;
    if (player->isFreeze) player->freezeTimer->start(player->freezeRemaining);
    if (player->isDizzy) player->dizzyTimer->start(player->dizzyRemaining);
    return in;
}





