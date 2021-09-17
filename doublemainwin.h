#ifndef DOUBLEMAINWIN_H
#define DOUBLEMAINWIN_H

#include <QMainWindow>
#include "map.h"
#include "character.h"
#include "pause.h"
#include "openmenu.h"

namespace Ui {
class DoubleMainWin;
}

class DoubleMainWin : public QMainWindow
{
    Q_OBJECT
    friend Pause;
    friend OpenMenu;

public:
    explicit DoubleMainWin(int,int,int,int,int,int,int,QWidget *parent = nullptr);
    ~DoubleMainWin();

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void pause();
    void help();
    void updateTime();
    void gameOver(int mode = 0);
    void hintStop();
    void save();

private:
    Ui::DoubleMainWin *ui;
    Map *map;
    Character *player1, *player2;

    //************菜单************//
    void createMenus();
    QAction *pauseAct;
    QAction *helpAct;

    const int mapPix = 40; //决定窗口大小

    //*******得分系统*********//
    void drawTimeAndScore(QPainter *painter) const; //画出时间和分数

    //*********计时系统*********//
    QTimer *updateTimer;

    //*********道具系统*********//
    void propHandle(int kind, Character *player);
    void addTime();
    void shuffle();
    void hint();
    void freeze(Character *freezedPlayer);
    void dizzy(Character *dizzyPlayer);
    QTimer *hintTimer;
    bool isHint = false;
    int hintRemaining;

    //**********玩家自定义的一些参数*********//
    int heigh = 15, wid = 20;
    int boxNum = 7;
    int characterKind1 = 1, characterKind2 = 2;
    int secs = 120;
    int density = 3;

    void characterPosInit();
    void moveJudge(int x,int y,Character *player);

};

#endif // DOUBLEMAINWIN_H
