#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <QObject>

class DisjointSet : public QObject
{
    Q_OBJECT
public:
    explicit DisjointSet(int m0,int n0,QObject *parent = nullptr);
    virtual ~DisjointSet();

    void init();
    void add(int x,int y);
    void merge(int x1,int y1,int x2,int y2);
    bool isConnect(int x1,int y1,int x2,int y2);

    //void print();


signals:

private:
    int father[1100];
    int m, n;

    int number(int x,int y) const;
    int findRoot(int x);

};

#endif // DISJOINTSET_H
