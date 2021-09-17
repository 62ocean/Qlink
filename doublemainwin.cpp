#include "doublemainwin.h"
#include "ui_doublemainwin.h"
#include "help.h"
#include "pause.h"
#include "doublegameover.h"
#include <QPainter>
#include <QKeyEvent>

DoubleMainWin::DoubleMainWin(int wid0,int heigh0,int boxNum0,int secs0,int density0,int characterKind10,int characterKind20,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DoubleMainWin),
    wid(wid0),heigh(heigh0),boxNum(boxNum0),secs(secs0),density(density0),characterKind1(characterKind10),characterKind2(characterKind20)
{
    ui->setupUi(this);
    createMenus();

    resize(wid * mapPix, heigh * mapPix);

    map = new Map(heigh, wid, boxNum, 2, density, this);
    player1 = new Character(characterKind1, this);
    player2 = new Character(characterKind2, this);
    characterPosInit();

    if (!map->checkMap(player1) || !map->checkMap(player2)) gameOver();

    updateTimer = new QTimer(this);
    updateTimer->start(1000);
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(updateTime()));

    hintTimer = new QTimer(this);
    hintTimer->setSingleShot(true);
    connect(hintTimer,SIGNAL(timeout()),this,SLOT(hintStop()));

    connect(player1->lineTimer,SIGNAL(timeout()),this,SLOT(update()));
    connect(player1,SIGNAL(twoSelectedBox(int,int,int,int,Character*)),map,SLOT(twoBoxJudge(int,int,int,int,Character*)));
    connect(player2->lineTimer,SIGNAL(timeout()),this,SLOT(update()));
    connect(player2,SIGNAL(twoSelectedBox(int,int,int,int,Character*)),map,SLOT(twoBoxJudge(int,int,int,int,Character*)));
    connect(map,SIGNAL(gameOver()),this,SLOT(gameOver()));

}

DoubleMainWin::~DoubleMainWin()
{
    delete ui;
}

void DoubleMainWin::characterPosInit()
{
    srand((int)time(0));
    while (1) {
        int x = std::rand() % heigh + 1;
        int y = std::rand() % wid + 1;
        if (!map->isBox(x,y) && !map->isProp(x,y)) {
            player1->x = x;
            player1->y = y;
            break;
        }
    }
    while (1) {
        int x = std::rand() % heigh + 1;
        int y = std::rand() % wid + 1;
        if (!map->isBox(x,y) && !map->isProp(x,y) && x != player1->x && y != player1->y) {
            player2->x = x;
            player2->y = y;
            break;
        }
    }
}

void DoubleMainWin::createMenus()
{
    pauseAct = new QAction(tr("暂停"), this);
    connect(pauseAct, SIGNAL(triggered()), this, SLOT(pause()));
    helpAct = new QAction(tr("怎么玩？"), this);
    connect(helpAct, SIGNAL(triggered()), this, SLOT(help()));

    menuBar()->addAction(pauseAct);
    menuBar()->addAction(helpAct);
}
void DoubleMainWin::pause()
{
    Pause *pau = new Pause(this);
    updateTimer->stop();
    hintRemaining = hintTimer->remainingTime();
    hintTimer->stop();

    player1->comboRemaining = player1->comboTimer->remainingTime();
    player1->comboTimer->stop();
    player1->freezeRemaining = player1->freezeTimer->remainingTime();
    player1->freezeTimer->stop();
    player1->dizzyRemaining = player1->dizzyTimer->remainingTime();
    player1->dizzyTimer->stop();

    player2->comboRemaining = player2->comboTimer->remainingTime();
    player2->comboTimer->stop();
    player2->freezeRemaining = player2->freezeTimer->remainingTime();
    player2->freezeTimer->stop();
    player2->dizzyRemaining = player2->dizzyTimer->remainingTime();
    player2->dizzyTimer->stop();

    pau->exec();

    updateTimer->start();
    if (isHint) hintTimer->start(hintRemaining);

    if (player1->isCombo) player1->comboTimer->start(player1->comboRemaining);
    if (player1->isFreeze) player1->freezeTimer->start(player1->freezeRemaining);
    if (player1->isDizzy) player1->dizzyTimer->start(player1->dizzyRemaining);

    if (player2->isCombo) player2->comboTimer->start(player2->comboRemaining);
    if (player2->isFreeze) player2->freezeTimer->start(player2->freezeRemaining);
    if (player2->isDizzy) player2->dizzyTimer->start(player2->dizzyRemaining);
}
void DoubleMainWin::save()
{
    QFile file("../data.dat");
    bool isOk = file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    qDebug("open save\n");
    if (isOk) {
        qDebug("save isok\n");
        QDataStream stream(&file);
        stream << 2;
        stream << heigh << wid << boxNum << characterKind1 << characterKind2 << secs << density;
        stream << map << player1 << player2;
        stream << isHint << hintRemaining;
        file.close();
    }
}

void DoubleMainWin::help()
{
    Help *help = new Help;
    help->exec();
}
void DoubleMainWin::gameOver(int mode)
{
    updateTimer->stop();
    hintTimer->stop();

    DoubleGameover *doubleOver = new DoubleGameover(mode,player1->score,player2->score,characterKind1,characterKind2,this);
    doubleOver->exec();
}

void DoubleMainWin::updateTime()
{
    --secs;
    if (!secs) {
        updateTimer->stop();
        gameOver(1);
    }
    update();
}


void DoubleMainWin::propHandle(int kind, Character *player)
{
    map->deleteBoxProp(player->x,player->y);
    switch (kind) {
    case 1: addTime(); break;
    case 2: shuffle(); break;
    case 3: hint(); break;
    case 4:
        if (player == player1) freeze(player2);
        else if (player == player2) freeze(player1);
        break;
    case 5:
        if (player == player1) dizzy(player2);
        else if (player == player2) dizzy(player1);
        break;
    }
}
void DoubleMainWin::addTime()
{
    secs += 30;
}
void DoubleMainWin::shuffle()
{
    map->shuffle();
    characterPosInit();
    player1->xSelect = player1->ySelect = 0;
    player2->xSelect = player2->ySelect = 0;
    if (!map->checkMap(player1) || !map->checkMap(player2)) gameOver(); //判断地图是否有解

}
void DoubleMainWin::hint()
{
    isHint = true;
    hintTimer->start(10*1000);
}
void DoubleMainWin::hintStop()
{
    isHint = false;
}
void DoubleMainWin::freeze(Character *freezedPlayer)
{
    freezedPlayer->freezeTimer->start(3*1000);
    freezedPlayer->isFreeze = true;
}
void DoubleMainWin::dizzy(Character *dizzyPlayer)
{
    dizzyPlayer->dizzyTimer->start(10*1000);
    dizzyPlayer->isDizzy = true;
}



void DoubleMainWin::drawTimeAndScore(QPainter *painter) const
{
    QFont font;
    font.setFamily("Bahnschrift SemiBold Condensed");
    font.setBold(true);
    font.setPixelSize(2);
    painter->setFont(font);
    painter->setPen(Qt::black);
    painter->drawText(QPointF(wid,heigh+2),QString::number(secs));
    painter->drawText(QPointF(-0.5,heigh+2),QString::number(player1->score));
    painter->drawText(QPointF(wid/2-1.5,heigh+2),QString::number(player2->score));

    font.setPointSizeF(0.5);
    font.setFamily("consolas");
    font.setBold(false);
    painter->setFont(font);
    painter->drawText(QPointF(wid-4,heigh+2),QString("time"));


    switch (characterKind1) {
    case  1:
        painter->drawPixmap(QRectF(-2,heigh+0.5,1.5,1.5),QPixmap(":/res/role1.png"),QRectF(0,0,60,60));
        break;
    case  2:
        painter->drawPixmap(QRectF(-2,heigh+0.5,1.5,1.5),QPixmap(":/res/role2.png"),QRectF(0,0,31,31));
        break;
    case  3:
        painter->drawPixmap(QRectF(-2,heigh+0.5,1.5,1.5),QPixmap(":/res/role3.png"),QRectF(0,0,34,34));
        break;
    case  4:
        painter->drawPixmap(QRectF(-2,heigh+0.5,1.5,1.5),QPixmap(":/res/role4.png"),QRectF(0,0,36,36));
        break;
    }
    switch (characterKind2) {
    case  1:
        painter->drawPixmap(QRectF(wid/2-3,heigh+0.5,1.5,1.5),QPixmap(":/res/role1.png"),QRectF(0,0,60,60));
        break;
    case  2:
        painter->drawPixmap(QRectF(wid/2-3,heigh+0.5,1.5,1.5),QPixmap(":/res/role2.png"),QRectF(0,0,31,31));
        break;
    case  3:
        painter->drawPixmap(QRectF(wid/2-3,heigh+0.5,1.5,1.5),QPixmap(":/res/role3.png"),QRectF(0,0,34,34));
        break;
    case  4:
        painter->drawPixmap(QRectF(wid/2-3,heigh+0.5,1.5,1.5),QPixmap(":/res/role4.png"),QRectF(0,0,36,36));
        break;
    }


}
void DoubleMainWin::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);

    //设置背景图片
    painter.drawPixmap(0,0,width(),height(),QPixmap(":/res/play1.jpg"));

    //设置视口比例，防止地图变形
    int heightSide, widthSide;
    if (((double)(width())/(double)(height())) > ((double)(wid) / (double)(heigh))) {
        heightSide = height();
        widthSide = wid * heightSide / heigh;
    } else {
        widthSide = width();
        heightSide = heigh * widthSide / wid;
    }
    painter.setViewport((width()-widthSide)/2,(height()-heightSide)/2,widthSide,heightSide);

    double widSpace, heiSpace;
    heiSpace = heigh / std::min(heigh/3, wid/3);
    widSpace = wid / std::min(heigh/3, wid/3);
    painter.setWindow(-widSpace, -heiSpace, wid+2*widSpace, heigh+2*heiSpace);

    //*******************************************************************
    map->drawMap(&painter);

    drawTimeAndScore(&painter);

    //************道具****************
    if (isHint) {
        map->drawHint(&painter);
        painter.drawPixmap(QRectF(player1->y-0.5,player1->x-1.5,0.5,0.5),QPixmap(":/res/hint.png"),QRectF(0,0,500,500));
        painter.drawPixmap(QRectF(player2->y-0.5,player2->x-1.5,0.5,0.5),QPixmap(":/res/hint.png"),QRectF(0,0,500,500));
    }
    if (player1->isDizzy) painter.drawPixmap(QRectF(player1->y-1,player1->x-1.5,0.5,0.5),QPixmap(":/res/dizzy.png"),QRectF(0,0,500,500));
    if (player2->isDizzy) painter.drawPixmap(QRectF(player2->y-1,player2->x-1.5,0.5,0.5),QPixmap(":/res/dizzy.png"),QRectF(0,0,500,500));


    //***********与人物有关*************
    player1->drawSelectBox(&painter,QColor(128,255,255));
    if (player1->showLine) {
        map->drawDisppearingBox(&painter,player1);
        player1->drawLine(&painter,QColor(128,255,255));
    }
    player2->drawSelectBox(&painter,QColor(131,250,2));
    if (player2->showLine) {
        map->drawDisppearingBox(&painter,player2);
        player2->drawLine(&painter,QColor(131,250,2));
    }
    player1->drawCombo(&painter);
    player1->drawCharacter(&painter);
    player2->drawCombo(&painter);
    player2->drawCharacter(&painter);

    if (player1->isFreeze) painter.drawPixmap(QRectF(player1->y-1,player1->x-1,1,1),QPixmap(":/res/ice.png"),QRectF(0,0,353,353));
    if (player2->isFreeze) painter.drawPixmap(QRectF(player2->y-1,player2->x-1,1,1),QPixmap(":/res/ice.png"),QRectF(0,0,353,353));

}

void DoubleMainWin::moveJudge(int cntx, int cnty,Character *player)
{
    if ((!cnty) && (cntx == 1) && (player->x == heigh+1)) return;
    if ((!cnty) && (cntx == -1) && (player->x == 0)) return;
    if ((!cntx) && (cnty == 1) && (player->y == wid+1)) return;
    if ((!cntx) && (cnty == -1) && (player->y == 0)) return;
    //↑ 再走就会超出边界时，什么也不做
    if (player->showLine && (player->x == player->point1.x()) && (player->y == player->point1.y())) return;
    if (player->showLine && (player->x == player->point2.x()) && (player->y == player->point2.y())) return;
    //↑ 如果要走的地方是一个正在被消除的箱子，什么也不做
    if ((player == player1 && player->x + cntx == player2->x && player->y + cnty == player2->y)
        || (player == player2 && player->x + cntx == player1->x && player->y + cnty == player1->y))
        return;
    //↑如果要走的地方是另一个角色的位置，什么也不做

    if (map->isBox(player->x + cntx,player->y + cnty)) {
        player->selectBox(player->x + cntx,player->y + cnty);
        //↑ 如果要走的地方是一个箱子，选择这个箱子
        if (player == player1 && player2->xSelect == player->x + cntx && player2->ySelect == player->y + cnty)
            player2->xSelect = player2->ySelect = 0;
        if (player == player2 && player1->xSelect == player->x + cntx && player1->ySelect == player->y + cnty)
            player1->xSelect = player1->ySelect = 0;
        //↑如果角色选中的是另一个角色选中的箱子，则另一个角色取消选择
    }
    else {
        player->x += cntx;
        player->y += cnty;
        //↑ 要走的地方没有箱子，则走一步
        if (map->isProp(player->x,player->y)) propHandle(map->getPropNum(player->x,player->y),player);
        //↑ 如果角色所在位置有道具，则激发道具效果
    }
}
void DoubleMainWin::keyPressEvent(QKeyEvent *event)
{
    if (!player1->isFreeze) {
        if (player1->isDizzy) {
            if (event->key() == Qt::Key_S) moveJudge(-1, 0, player1);
            else if (event->key() == Qt::Key_W) moveJudge(1, 0, player1);
            else if (event->key() == Qt::Key_D) moveJudge(0, -1, player1);
            else if (event->key() == Qt::Key_A) moveJudge(0, 1, player1);
        } else {
            if (event->key() == Qt::Key_W) moveJudge(-1, 0, player1);
            else if (event->key() == Qt::Key_S) moveJudge(1, 0, player1);
            else if (event->key() == Qt::Key_A) moveJudge(0, -1, player1);
            else if (event->key() == Qt::Key_D) moveJudge(0, 1, player1);
        }
    }

    if (!player2->isFreeze) {
        if (player2->isDizzy) {
            if (event->key() == Qt::Key_Down) moveJudge(-1, 0, player2);
            else if (event->key() == Qt::Key_Up) moveJudge(1, 0, player2);
            else if (event->key() == Qt::Key_Right) moveJudge(0, -1, player2);
            else if (event->key() == Qt::Key_Left) moveJudge(0, 1, player2);
        } else {
            if (event->key() == Qt::Key_Up) moveJudge(-1, 0, player2);
            else if (event->key() == Qt::Key_Down) moveJudge(1, 0, player2);
            else if (event->key() == Qt::Key_Left) moveJudge(0, -1, player2);
            else if (event->key() == Qt::Key_Right) moveJudge(0, 1, player2);
        }
    }
    update();
}
