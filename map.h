#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QPainter>
#include <QPoint>
#include <QTimer>
#include <QFile>
#include "disjointset.h"
#include "character.h"
#include "pause.h"
#include "openmenu.h"

class Character;

class Map : public QObject
{
    Q_OBJECT

public:
    explicit Map(int,int,int,int,int,QObject *parent = nullptr);
    virtual ~Map();

    //得到地图的一些信息（该位置是否为箱子/该位置是否为道具/该位置的道具号）
    bool isBox(int x,int y) const;
    bool isProp(int x,int y) const;
    int getPropNum(int x,int y) const;

    void shuffle(); //打乱地图
    void deleteBoxProp(int x,int y);  //删除该位置的箱子或道具

    bool canArrive(Character *player,int x,int y,int &xMove,int &yMove);
    //判断角色player是否能到达(x,y)
    bool checkMap(Character *player);
    //判断对于player来说，地图是否还有解

    //****************************************
    void drawMap(QPainter *painter) const;
    void drawDisppearingBox(QPainter *painter,Character *player) const;
    //画出角色player的disppearing box
    void drawHint(QPainter *painter) const;

    friend QDataStream &operator<< (QDataStream &out,Map *map);
    friend QDataStream &operator>> (QDataStream &in, Map *map);

signals:
    void gameOver();

private:
    int mode;
    int m, n;
    int boxNum, density = 3;
    int map[60][60];

    QColor *color;
    void randomColor();

    DisjointSet *set;    
    void setInit(); //重置并查集

    QPoint hint1, hint2;
    //提示。每次checkMap后更新。

    //初始化
    void mapInit();

    //判断能否两个箱子能否消除的函数
    bool straightCheck(int x1,int y1,int x2,int y2) const;
    bool oneCornerCheck(int x1,int y1,int x2,int y2,bool changeCorner,Character *player);
    bool twoCornerCheck(int x1,int y1,int x2,int y2,bool changeCorner,Character *player);
    bool checkBox(int x1,int y1,int x2,int y2,bool changeCornerNum,Character *player);

private slots:
    void twoBoxJudge(int x1,int y1,int x2,int y2,Character *player);
    //如两个箱子能消除，则进行消除操作。把得分返回给player。
};





#endif // MAP_H
