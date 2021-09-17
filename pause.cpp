#include "pause.h"
#include "ui_pause.h"
#include "singlemainwin.h"
#include "doublemainwin.h"
#include "openmenu.h"
#include <QDataStream>
#include <QFile>
#include <QString>
#include <QDebug>

Pause::Pause(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pause)
{
    ui->setupUi(this);
    setFixedSize(this->width(),this->height());

    connect(ui->continueButton,SIGNAL(clicked()),this,SLOT(close()));

    connect(ui->saveButton,SIGNAL(clicked()),this->parent(),SLOT(save()));
    connect(ui->saveButton,SIGNAL(clicked()),this,SLOT(save()));

    connect(ui->loadButton,SIGNAL(clicked()),this,SLOT(load()));
    connect(this,SIGNAL(closeParent()),this->parent(),SLOT(close()));

    connect(ui->openmenuButton,SIGNAL(clicked()),this,SLOT(openmenu()));
    connect(ui->openmenuButton,SIGNAL(clicked()),this->parent(),SLOT(close()));

}

Pause::~Pause()
{
    delete ui;
}

void Pause::save()
{
    ui->label->setText("保存成功！");
}

void Pause::load()
{
    QFile file("../data.dat");
    bool isOk = file.open(QIODevice::ReadOnly);
    qDebug("open load\n");
    if (isOk) {
        qDebug("load isok\n");
        QDataStream stream(&file);

        int mode;
        stream >> mode;

        if (mode == 1) {
            int heigh,wid,boxNum,characterKind,secs,density;
            stream >> heigh >> wid >> boxNum >> characterKind >> secs >> density;
            SingleMainWin *game = new SingleMainWin(wid,heigh,boxNum,secs,density,characterKind);
            game->setAttribute(Qt::WA_DeleteOnClose);
            stream >> game->map >> game->player;
            stream >> game->isHint >> game->hintRemaining >> game->isFlash >> game->flashRemaining;
            if (game->isHint) game->hintTimer->start(game->hintRemaining);
            if (game->isFlash) game->flashTimer->start(game->flashRemaining);
            game->show();
            this->close();
        } else if (mode == 2) {
            int heigh,wid,boxNum,characterKind1,characterKind2,secs,density;
            stream >> heigh >> wid >> boxNum >> characterKind1 >> characterKind2 >> secs >> density;
            DoubleMainWin *game = new DoubleMainWin(wid,heigh,boxNum,secs,density,characterKind1,characterKind2);
            game->setAttribute(Qt::WA_DeleteOnClose);
            stream >> game->map >> game->player1 >> game->player2;
            stream >> game->isHint >> game->hintRemaining;
            if (game->isHint) game->hintTimer->start(game->hintRemaining);
            game->show();
            this->close();
        }
        file.close();
        emit closeParent();
        //this->parent()->deleteLater();
        //delete this->parent(); //为什么加这一句load就不好用了？
    } else {
        ui->label->setText("没有可供载入的存档哦！");
    }
}
void Pause::openmenu()
{
    OpenMenu *openmenu = new OpenMenu;
    openmenu->setAttribute(Qt::WA_DeleteOnClose);
    openmenu->show();
    this->close();
}
