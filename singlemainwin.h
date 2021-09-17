#ifndef SINGLEMAINWIN_H
#define SINGLEMAINWIN_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QLabel>
#include "map.h"
#include "character.h"
#include "pause.h"
#include "openmenu.h"

namespace Ui {
class SingleMainWin;
}

class SingleMainWin : public QMainWindow
{
    Q_OBJECT
    friend Pause;
    friend OpenMenu;

public:
    explicit SingleMainWin(int,int,int,int,int,int,QWidget *parent = nullptr);
    virtual ~SingleMainWin();

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

signals:

private slots:
    void pause();
    void help();
    void updateTime();
    void gameOver(int mode = 0);
    void hintStop();
    void flashStop();
    void save();

private:
    Ui::SingleMainWin *ui;
    Map *map;
    Character *player;

    //************菜单************//
    void createMenus();
    QAction *pauseAct;
    QAction *helpAct;

    const int mapPix = 40; //决定窗口大小

    //*******得分系统*********//

    void drawTimeAndScore(QPainter *painter) const; //画出时间和分数

    //*********计时系统*********//
    QTimer *updateTimer;
    Pause *pau;


    //*********道具系统*********//
    void propHandle(int kind);
    void addTime();
    void shuffle();
    void hint();
    void flash();
    QTimer *hintTimer, *flashTimer;
    bool isHint = false;
    bool isFlash = false;
    int hintRemaining, flashRemaining;


    //玩家自定义的一些属性
    int heigh = 15, wid = 20;
    int boxNum = 7;
    int characterKind = 1;
    int secs = 120;
    int density = 3;

    void characterPosInit();
    void moveJudge(int x,int y,Character *player);

};
#endif // SINGLEMAINWIN_H
