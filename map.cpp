#include "map.h"
#include "disjointset.h"
#include "character.h"
#include <ctime>
#include <algorithm>
#include <cmath>
#include <QDebug>
#include <QPointF>

Map::Map(int m0,int n0,int boxNum0,int mode0, int density0, QObject *parent) :
    QObject(parent),m(m0),n(n0),boxNum(boxNum0),mode(mode0),density(density0)
{
    set = new DisjointSet(m, n, this);
    mapInit();

    srand((int)time(0));

}
Map::~Map()
{
    delete [] color;
}

void Map::randomColor()
{
    color = new QColor[boxNum+1];
    for (int i = 1; i <= boxNum; ++i) {
        int green = (std::rand()) % 256;
        int red = (std::rand()) % 256;
        int blue = (std::rand()) % 256;
        color[i] = QColor(red, green, blue);
    }
}
void Map::mapInit()
{
    for (int i = 0; i <= m+1; ++i)
        for (int j = 0; j <= n+1; ++j) {
            map[i][j] = 0;
        }

    int propNum = m * n / 50 + 2;
    if (propNum % 2) ++propNum;  //保证道具数为偶数

    int spaceNum = boxNum * density;
    int *array = new int [spaceNum + boxNum*2];
    for (int i = 0; i < boxNum*2; i ++) array[i] = (i + 2) / 2;
    for (int i = boxNum*2; i < boxNum*2 + spaceNum; ++i) array[i] = 0;

    //填充map
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            map[i][j] = array[((i-1)*n+j-1) % (spaceNum + boxNum*2)];
        }
    //放入道具
    for (int i = 0; i < propNum; ++i) {
        if (mode == 1) map[i/m+1][i%m+1] = -(std::rand() % 4 + 1);
        else if (mode == 2) map[i/m+1][i%m+1] = -(std::rand() % 5 + 1);
    }
    if ((m*n) % 2) map[m][n] = 0; //保证方块都成对

    //打乱数组
    shuffle();


    delete []array;

    randomColor(); //随机颜色
}
void Map::setInit()
{
    set->init();
    for (int i = 0; i <= m+1; ++i)
        for (int j = 0; j <= n+1; ++j)
            if (!isBox(i,j)) {
                //qDebug("%d %d %d",map[i][j],i,j);
                set->add(i,j);
            }
    for (int i = 0; i <= m+1; ++i)
        for (int j = 0; j <= n+1; ++j) {
            if (isBox(i,j)) continue;
            if ((i > 0) && (!isBox(i-1,j))) set->merge(i,j,i-1,j);
            if ((i < m+1) && (!isBox(i+1,j))) set->merge(i,j,i+1,j);
            if ((j > 0) && (!isBox(i,j-1))) set->merge(i,j,i,j-1);
            if ((j < n+1) && (!isBox(i,j+1))) set->merge(i,j,i,j+1);
        }
}


bool Map::isBox(int x, int y) const
{
    if (map[x][y] > 0) return true;
    else return false;
}
bool Map::isProp(int x, int y) const
{
    if (map[x][y] < 0) return true;
    else return false;
}
int Map::getPropNum(int x, int y) const
{
    return -map[x][y];
}

void Map::shuffle()
{
    //打乱每一列
    for (int j = 1; j <= n; ++j)
        for (int i = 1; i <= m; ++i) std::swap(map[i][j],map[(rand()%i)+1][j]);
    //打乱每一行
    for (int i = 1; i <= m; ++i) std::random_shuffle(map[i]+1,map[i]+n+1);
    setInit();
}
void Map::deleteBoxProp(int x, int y)
{
    if (isBox(x,y)) {
        set->add(x,y);
        if ((x > 0) && (!isBox(x-1,y))) set->merge(x,y,x-1,y);
        if ((x < m+1) && (!isBox(x+1,y))) set->merge(x,y,x+1,y);
        if ((y > 0) && (!isBox(x,y-1))) set->merge(x,y,x,y-1);
        if ((y < n+1) && (!isBox(x,y+1))) set->merge(x,y,x,y+1);
    }
    map[x][y] = 0;
}

bool Map::canArrive(Character *player, int x, int y,int &xMove,int &yMove)
{
    if (!isBox(x,y)) {
        if (set->isConnect(player->x,player->y,x,y)) {
            xMove = x; yMove = y;
            return true;
        } else return false;
    } else {
        if ((x > 0) && (!isBox(x-1,y)) && (set->isConnect(player->x,player->y,x-1,y))) {
            xMove = x-1; yMove = y;
            return true;
        } else if ((x < m+1) && (!isBox(x+1,y)) && (set->isConnect(player->x,player->y,x+1,y))) {
            xMove = x+1; yMove = y;
            return true;
        } else if ((y > 0) && (!isBox(x,y-1)) && (set->isConnect(player->x,player->y,x,y-1))) {
            xMove = x; yMove = y-1;
            return true;
        } else if ((y < n+1) && (!isBox(x,y+1)) && (set->isConnect(player->x,player->y,x,y+1))) {
            xMove = x; yMove = y+1;
            return true;
        } else return false;
    }
}



bool Map::straightCheck(int x1, int y1, int x2, int y2) const
{
    if (x1 == x2) {
        int yMin = std::min(y1, y2);
        int yMax = std::max(y1, y2);
        for (int i = yMin+1; i < yMax; ++i)
            if (isBox(x1,i)) return false;
        return true;
    } else if (y1 == y2) {
        int xMin = std::min(x1, x2);
        int xMax = std::max(x1, x2);
        for (int i = xMin+1; i < xMax; ++i)
            if (isBox(i,y1)) return false;
        return true;
    } else return false;
}
bool Map::oneCornerCheck(int x1, int y1, int x2, int y2,bool changeCorner,Character *player)
{
    if ((!isBox(x2,y1)) && straightCheck(x1,y1,x2,y1) && straightCheck(x2,y1,x2,y2)) {
        if (changeCorner) {
            player->corner1.setX(x2);
            player->corner1.setY(y1);
        }
        return true;
    }
    if ((!isBox(x1,y2)) && straightCheck(x1,y1,x1,y2) && straightCheck(x1,y2,x2,y2)) {
        if (changeCorner) {
            player->corner1.setX(x1);
            player->corner1.setY(y2);
        }
        return true;
    }
    return false;
}
bool Map::twoCornerCheck(int x1, int y1, int x2, int y2,bool changeCorner,Character *player)
{
    for (int x0 = x1+1; (!isBox(x0,y1)) && x0 <= m+1; ++x0) {  //一旦遇到方块或超出边界，就退出循环
        if (straightCheck(x1,y1,x0,y1) && oneCornerCheck(x0,y1,x2,y2,changeCorner,player)) {
            if (changeCorner) {
                player->corner2.setX(x0);
                player->corner2.setY(y1);
            }
            return true;
        }
    }
    for (int x0 = x1-1; (!isBox(x0,y1)) && x0 >= 0; --x0) {
        if (straightCheck(x1,y1,x0,y1) && oneCornerCheck(x0,y1,x2,y2,changeCorner,player)) {
            if (changeCorner) {
                player->corner2.setX(x0);
                player->corner2.setY(y1);
            }
            return true;
        }
    }
    for (int y0 = y1+1; (!isBox(x1,y0)) && y0 <= n+1; ++y0) {
        if (straightCheck(x1,y1,x1,y0) && oneCornerCheck(x1,y0,x2,y2,changeCorner,player)) {
            if (changeCorner) {
                player->corner2.setX(x1);
                player->corner2.setY(y0);
            }
            return true;
        }
    }
    for (int y0 = y1-1; (!isBox(x1,y0)) && y0 >= 0; --y0) {
        if (straightCheck(x1,y1,x1,y0) && oneCornerCheck(x1,y0,x2,y2,changeCorner,player)) {
            if (changeCorner) {
                player->corner2.setX(x1);
                player->corner2.setY(y0);
            }
            return true;
        }
    }
    return false;
}
//x,y不是坐标，而是行数和列数！！！
bool Map::checkBox(int x1, int y1, int x2, int y2, bool changeCornerNum,Character *player)
{
    if (map[x1][y1] != map[x2][y2]) return false;

    if (x1 == x2 && y1 == y2) return false;
    else if ((x1 == x2 || y1 == y2) && straightCheck(x1,y1,x2,y2)) {
        if (changeCornerNum) player->cornerNum = 0;
        return true;
    }
    else if (oneCornerCheck(x1,y1,x2,y2,changeCornerNum,player)) {
        if (changeCornerNum) player->cornerNum = 1;
        return true;
    }
    else if (twoCornerCheck(x1,y1,x2,y2,changeCornerNum,player)) {
        if (changeCornerNum) player->cornerNum = 2;
        return true;
    }
    else return false;

}
void Map::twoBoxJudge(int x1,int y1,int x2,int y2,Character *player)
{
    if (checkBox(x1,y1,x2,y2,true,player)) {
        player->scoreCalculate(map[x1][y1]);

        deleteBoxProp(player->point1.x(),player->point1.y());
        deleteBoxProp(player->point2.x(),player->point2.y());
        player->showLine = true;
        player->lineTimer->start(200);

        if (!checkMap(player)) gameOver();

    }
}
bool Map::checkMap(Character *player)
{
    int xMove,yMove;
    for (int i1 = 1; i1 <= m; ++i1)
        for (int j1 = 1; j1 <= n; ++j1) {
            for (int i2 = 1; i2 <= m; ++i2)
                for (int j2 = 1; j2 <= n; ++j2) {
                    if ((i1-1)*n+j1 >= (i2-1)*n+j2) continue;
                    if (!isBox(i1,j1) || !isBox(i2,j2)) continue;
                    if (checkBox(i1,j1,i2,j2,false,player)
                        && canArrive(player,i1,j1,xMove,yMove) && canArrive(player,i2,j2,xMove,yMove)) {
                        hint1.setX(i1); hint1.setY(j1);
                        hint2.setX(i2); hint2.setY(j2);
                        return true;
                    }
                }
        }
    return false;
}



void Map::drawMap(QPainter *painter) const
{
    painter->setPen(Qt::NoPen);
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            if (map[i][j] == 0) continue;
            if (map[i][j] < 0) {
                switch (-map[i][j]) {
                case 1:
                    painter->drawPixmap(j-1,i-1,1,1,QPixmap(":/res/+1s.png"));
                    break;
                case 2:
                    painter->drawPixmap(j-1,i-1,1,1,QPixmap(":/res/shuffle.png"));
                    break;
                case 3:
                    painter->drawPixmap(j-1,i-1,1,1,QPixmap(":/res/hint.png"));
                    break;
                case 4:
                    if (mode == 1) painter->drawPixmap(j-1,i-1,1,1,QPixmap(":/res/flash.png"));
                    else if (mode == 2) painter->drawPixmap(j-1,i-1,1,1,QPixmap(":/res/freeze.png"));
                    break;
                case 5:
                    painter->drawPixmap(j-1,i-1,1,1,QPixmap(":/res/dizzy.png"));
                    break;
                }
            }
            if (map[i][j] > 0) {
                QLinearGradient boxGradient(i-1,j-1,i,j);
                boxGradient.setColorAt(0.0,Qt::white);
                boxGradient.setColorAt(0.8,color[map[i][j]]);
                boxGradient.setColorAt(1.0,Qt::lightGray);

                painter->setBrush(boxGradient);
                painter->drawRect(j-1,i-1,1,1);
            }

        }
}
void Map::drawDisppearingBox(QPainter *painter, Character *player) const
{
    painter->setPen(Qt::NoPen);
    QLinearGradient boxGradient(player->point1.x()-1,player->point1.y()-1,player->point1.x(),player->point1.y());
    boxGradient.setColorAt(0.0,Qt::white);
    boxGradient.setColorAt(0.8,color[player->lastBoxScore]);
    boxGradient.setColorAt(1.0,Qt::lightGray);
    painter->setBrush(boxGradient);
    painter->drawRect(player->point1.y()-1,player->point1.x()-1,1,1);

    boxGradient.setStart(player->point2.x()-1,player->point2.y()-1);
    boxGradient.setFinalStop(player->point2.x(),player->point2.y());
    painter->setBrush(boxGradient);
    painter->drawRect(player->point2.y()-1,player->point2.x()-1,1,1);
}
void Map::drawHint(QPainter *painter) const
{
    QLinearGradient boxGradient(hint1.x()-1,hint1.y()-1,hint1.x(),hint1.y());
    boxGradient.setColorAt(0.0,Qt::white);
    boxGradient.setColorAt(0.2,color[map[hint1.x()][hint1.y()]]);
    boxGradient.setColorAt(0.3,Qt::white);
    boxGradient.setColorAt(0.4,color[map[hint1.x()][hint1.y()]]);
    boxGradient.setColorAt(0.5,Qt::white);
    boxGradient.setColorAt(0.8,color[map[hint1.x()][hint1.y()]]);

    painter->setPen(Qt::NoPen);
    painter->setBrush(boxGradient);
    painter->drawRect(hint1.y()-1,hint1.x()-1,1,1);

    boxGradient.setStart(hint2.x()-1,hint2.y()-1);
    boxGradient.setFinalStop(hint2.x(),hint2.y());
    painter->setBrush(boxGradient);
    painter->drawRect(hint2.y()-1,hint2.x()-1,1,1);
}

QDataStream &operator<< (QDataStream &out, Map *map)
{
    for (int i = 1; i <= map->m; ++i)
        for (int j = 1; j <= map->n; ++j) out << map->map[i][j];
    for (int i = 1; i <= map->boxNum; ++i)
        out << map->color[i];
    out << map->hint1 << map->hint2;

    return out;
}
QDataStream &operator>> (QDataStream &in, Map *map)
{
    for (int i = 1; i <= map->m; ++i)
        for (int j = 1; j <= map->n; ++j) in >> map->map[i][j];
    for (int i = 1; i <= map->boxNum; ++i)
        in >> map->color[i];
    in >> map->hint1 >> map->hint2;
    map->setInit();

    return in;
}

