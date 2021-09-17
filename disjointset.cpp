#include "disjointset.h"

DisjointSet::DisjointSet(int m0,int n0,QObject *parent)
    : QObject(parent), m(m0), n(n0)
{
    init();
}
DisjointSet::~DisjointSet()
{qDebug("aaa\n");}

void DisjointSet::init()
{
    for (int i = 0; i <= number(m+1,n+1); ++i)
        father[i] = -1;
}
int DisjointSet::number(int x, int y) const
{
    assert(x * (n + 2) + y < 1100);
    return x * (n + 2) + y;
}

void DisjointSet::add(int x,int y)
{
    father[number(x,y)] = number(x,y);
    //qDebug("%d ",number(x,y));
}

int DisjointSet::findRoot(int x)
{
    if (father[x] == -1) return -1;
    if (x == father[x]) return x;
    return father[x] = findRoot(father[x]);
}

void DisjointSet::merge(int x1,int y1,int x2,int y2)
{
    int root1 = findRoot(number(x1,y1));
    int root2 = findRoot(number(x2,y2));
    //qDebug("(%d %d):%d  (%d %d):%d",x1,y1,root1,x2,y2,root2);
    if (root1 == root2) return;
    else father[root1] = root2;
}

bool DisjointSet::isConnect(int x1,int y1,int x2,int y2)
{
    if (findRoot(number(x1,y1)) == findRoot(number(x2,y2))) return true;
    else return false;
}
/*void DisjointSet::print()
{
    for (int i=0; i<=m; ++i) {
        for (int j=0; j<=n; ++j) qDebug("%d ",findRoot(number(i,j)));
        qDebug("\n");
    }
}*/

