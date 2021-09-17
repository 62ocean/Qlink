#include "openmenu.h"
#include "ui_openmenu.h"
#include "choosemodel.h"
#include "singlemainwin.h"
#include "doublemainwin.h"
#include "singlesetting.h"
#include "doublesetting.h"
#include "help.h"

OpenMenu::OpenMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::OpenMenu)
{
    ui->setupUi(this);
    setFixedSize(this->width(),this->height());
    ui->label->hide();

    connect(ui->startButton,SIGNAL(clicked()),this,SLOT(startGame()));
    connect(ui->loadButton,SIGNAL(clicked()),this,SLOT(loadGame()));
    connect(ui->helpButton,SIGNAL(clicked()),this,SLOT(gameHelp()));
    connect(ui->exitButton,SIGNAL(clicked()),this,SLOT(close()));

}

OpenMenu::~OpenMenu()
{
    delete ui;
}

void OpenMenu::startGame()
{
    ChooseModel *model = new ChooseModel;
    model->setAttribute(Qt::WA_DeleteOnClose);
    int res = model->exec();
    if (res == 1) {
        SingleSetting *singleMod = new SingleSetting;
        singleMod->setAttribute(Qt::WA_DeleteOnClose);
        singleMod->show();
        this->close();
    } else if (res == 2){
        DoubleSetting *doubleMod = new DoubleSetting;
        doubleMod->setAttribute(Qt::WA_DeleteOnClose);
        doubleMod->show();
        this->close();
    }
}

void OpenMenu::loadGame()
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
        //this->parent()->deleteLater();
        //delete this->parent(); //为什么加这一句load就不好用了？
    } else {
        ui->label->setText("没有可供载入的存档哦！");
    }
}

void OpenMenu::gameHelp()
{
    Help *help = new Help;
    //help->setAttribute(Qt::WA_DeleteOnClose);
    help->exec();
}

