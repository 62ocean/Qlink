#include "singlemainwin.h"
#include "ui_singlemainwin.h"
#include "help.h"
#include "map.h"
#include "pause.h"
#include "singlegameover.h"
#include <QPainter>
#include <algorithm>
#include <ctime>
#include <QDebug>


SingleMainWin::SingleMainWin(int wid0,int heigh0,int boxNum0,int secs0,int density0,int characterKind0,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SingleMainWin),
    wid(wid0),heigh(heigh0),boxNum(boxNum0),secs(secs0),density(density0),characterKind(characterKind0)
{
    ui->setupUi(this);
    createMenus();

    resize(wid * mapPix, heigh * mapPix);

    map = new Map(heigh, wid, boxNum, 1, density, this); //数值要改！！！
    player = new Character(characterKind, this);
    characterPosInit();


    if (!map->checkMap(player)) gameOver();

    updateTimer = new QTimer(this);
    updateTimer->start(1000);
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(updateTime()));

    hintTimer = new QTimer(this);
    hintTimer->setSingleShot(true);
    connect(hintTimer,SIGNAL(timeout()),this,SLOT(hintStop()));
    flashTimer = new QTimer(this);
    flashTimer->setSingleShot(true);
    connect(flashTimer,SIGNAL(timeout()),this,SLOT(flashStop()));

    connect(player->lineTimer,SIGNAL(timeout()),this,SLOT(update()));
    connect(player,SIGNAL(twoSelectedBox(int,int,int,int,Character*)),map,SLOT(twoBoxJudge(int,int,int,int,Character*)));
    connect(map,SIGNAL(gameOver()),this,SLOT(gameOver()));

}

SingleMainWin::~SingleMainWin()
{
    delete ui;
}

void SingleMainWin::characterPosInit()
{
    srand((int)time(0));
    while (1) {
        int x = std::rand() % heigh + 1;
        int y = std::rand() % wid + 1;
        if (!map->isBox(x,y) && !map->isProp(x,y)) {
            player->x = x;
            player->y = y;
            break;
        }
    }
}

void SingleMainWin::createMenus()
{
    pauseAct = new QAction(tr("暂停"), this);
    connect(pauseAct, SIGNAL(triggered()), this, SLOT(pause()));
    helpAct = new QAction(tr("怎么玩？"), this);
    connect(helpAct, SIGNAL(triggered()), this, SLOT(help()));

    menuBar()->addAction(pauseAct);
    menuBar()->addAction(helpAct);
}
void SingleMainWin::pause()
{
    pau = new Pause(this);
    hintRemaining = hintTimer->remainingTime();
    flashRemaining = flashTimer->remainingTime();
    player->comboRemaining = player->comboTimer->remainingTime();
    updateTimer->stop();
    hintTimer->stop();
    flashTimer->stop();
    player->comboTimer->stop();

    pau->exec();
    //pau不close的话无法继续执行，如果在exec的时候delete它是不是会出错？

    updateTimer->start();
    if (isHint) hintTimer->start(hintRemaining);
    if (isFlash) flashTimer->start(flashRemaining);
    if (player->comboRemaining > 0) player->comboTimer->start(player->comboRemaining);

}
void SingleMainWin::save()
{
    QFile file("../data.dat");
    bool isOk = file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    qDebug("open save\n");
    if (isOk) {
        qDebug("save isok\n");
        QDataStream stream(&file);
        stream << 1;
        stream << heigh << wid << boxNum << characterKind << secs << density;
        stream << map << player;
        stream << isHint << hintRemaining << isFlash << flashRemaining;
        file.close();
    }
}

void SingleMainWin::help()
{
    Help *help = new Help;
    help->exec();
}

void SingleMainWin::gameOver(int mode)
{
    updateTimer->stop();
    hintTimer->stop();

    SingleGameover *singleOver = new SingleGameover(mode,player->score,this);
    singleOver->exec();
}

void SingleMainWin::updateTime()
{
    --secs;
    if (!secs) {
        updateTimer->stop();
        gameOver(1);
    }
    update();
}



void SingleMainWin::propHandle(int kind)
{
    map->deleteBoxProp(player->x,player->y);
    switch (kind) {
    case 1: addTime(); break;
    case 2: shuffle(); break;
    case 3: hint(); break;
    case 4: flash(); break;
    }
}
void SingleMainWin::addTime()
{
    secs += 30;
}
void SingleMainWin::shuffle()
{
    map->shuffle();
    characterPosInit();
    player->xSelect = player->ySelect = 0;
    if (!map->checkMap(player)) gameOver(); //判断地图是否有解

}
void SingleMainWin::hint()
{
    isHint = true;
    hintTimer->start(10*1000);
}
void SingleMainWin::flash()
{
    isFlash = true;
    flashTimer->start(5*1000);
}
void SingleMainWin::hintStop()
{
    isHint = false;
}
void SingleMainWin::flashStop()
{
    isFlash = false;
}




void SingleMainWin::drawTimeAndScore(QPainter *painter) const
{
    /*painter->save();
    int widSpace, heiSpace;
    heiSpace = heigh / std::min(heigh/3, wid/3);
    widSpace = wid / std::min(heigh/3, wid/3);
    painter->setWindow(-widSpace*2, -heiSpace*2, (wid+2*widSpace)*2, (heigh+2*heiSpace)*2);*/

    QFont font;
    font.setFamily("Bahnschrift SemiBold Condensed");
    font.setBold(true);
    font.setPixelSize(2);
    painter->setFont(font);
    painter->setPen(Qt::black);
    painter->drawText(QPointF(wid,heigh+2),QString::number(secs));
    painter->drawText(QPointF(-2.5,heigh+2),QString::number(player->score));

    font.setPointSizeF(0.5);
    font.setFamily("consolas");
    font.setBold(false);
    painter->setFont(font);
    painter->drawText(QPointF(wid-4,heigh+2),QString("time"));
    painter->drawText(QPointF(0.5,heigh+2),QString("score"));

}
void SingleMainWin::paintEvent(QPaintEvent *event)
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

    map->drawMap(&painter); //地图（箱子与道具）
    //************道具****************
    if (isHint) {
        map->drawHint(&painter);
        painter.drawPixmap(QRectF(player->y-0.5,player->x-1.5,0.5,0.5),QPixmap(":/res/hint.png"),QRectF(0,0,500,500));
    }
    if (isFlash) painter.drawPixmap(QRectF(player->y-1,player->x-1.5,0.5,0.5),QPixmap(":/res/flash.png"),QRectF(0,0,500,500));

    //***********分数与时间**************
    drawTimeAndScore(&painter);

    //***********与人物有关*************
    player->drawSelectBox(&painter,QColor(128,255,255));
    if (player->showLine) {
        map->drawDisppearingBox(&painter,player);
        player->drawLine(&painter,QColor(128,255,255));
    }
    player->drawCombo(&painter);
    player->drawCharacter(&painter);
}

void SingleMainWin::moveJudge(int cntx, int cnty,Character *player)
{
    if ((!cnty) && (cntx == 1) && (player->x == heigh+1)) return;
    if ((!cnty) && (cntx == -1) && (player->x == 0)) return;
    if ((!cntx) && (cnty == 1) && (player->y == wid+1)) return;
    if ((!cntx) && (cnty == -1) && (player->y == 0)) return;
    //↑ 再走就会超出边界时，什么也不做
    if (player->showLine && (player->x == player->point1.x()) && (player->y == player->point1.y())) return;
    if (player->showLine && (player->x == player->point2.x()) && (player->y == player->point2.y())) return;
    //↑ 如果要走的地方是一个正在被消除的箱子，什么也不做
    if (map->isBox(player->x + cntx,player->y + cnty)) player->selectBox(player->x + cntx,player->y + cnty);
    //↑ 如果要走的地方是一个箱子，选择这个箱子
    else {
        player->x += cntx;
        player->y += cnty;
        //↑ 要走的地方没有箱子，则走一步
        if (map->isProp(player->x,player->y)) propHandle(map->getPropNum(player->x,player->y));
        //↑ 如果角色所在位置有道具，则激发道具效果
    }
}
void SingleMainWin::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_W:
        moveJudge(-1, 0, player);
        break;
    case Qt::Key_S:
        moveJudge(1, 0, player);
        break;
    case Qt::Key_A:
        moveJudge(0, -1, player);
        break;
    case Qt::Key_D:
        moveJudge(0, 1, player);
        break;
    }
    update();
}

void SingleMainWin::mousePressEvent(QMouseEvent *event)
{
    //if (isFlash) {
        int heightSide, widthSide;
        if (((double)(width())/(double)(height())) > ((double)(wid) / (double)(heigh))) {
            heightSide = height();
            widthSide = wid * heightSide / heigh;
        } else {
            widthSide = width();
            heightSide = heigh * widthSide / wid;
        }
        double x0 = (width() - widthSide) / 2;
        double y0 = (height() - heightSide) / 2;
        //qDebug("pos:%d %d\n",event->pos().x(),event->pos().y());
        //qDebug("%d %d\n",x0,y0);

        int widSpace, heiSpace;
        heiSpace = heigh / std::min(heigh/3, wid/3);
        widSpace = wid / std::min(heigh/3, wid/3);
        double xBox = (double)widthSide / (wid + widSpace*2);
        double yBox = (double)heightSide / (heigh + heiSpace*2);
        //qDebug("side:%d %d\n",widthSide, heightSide);
        //qDebug("space:%d %d\n",widSpace, heiSpace);
        //qDebug("xBox yBox:%.2lf %.2lf\n",xBox,yBox);

        x0 += widSpace*xBox;
        y0 += heiSpace*yBox;
        //qDebug("x0 y0:%.2lf %.2lf\n",x0,y0);

        int y = (event->pos().x() - x0) / xBox + 1;
        int x = (event->pos().y() - y0) / yBox + 1;

        x = qBound(0, x, heigh+1);
        y = qBound(0, y, wid+1);

        //qDebug("%d %d\n",x,y);

        int xMove,yMove;
        if (map->canArrive(player,x,y,xMove,yMove)) {
            player->x = xMove;
            player->y = yMove;
            if (map->isBox(x,y)) player->selectBox(x,y);
            if (map->isProp(player->x,player->y)) propHandle(map->getPropNum(player->x,player->y));
            update();
        }
    //}
}




