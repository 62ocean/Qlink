#include "doublegameover.h"
#include "ui_doublegameover.h"
#include "openmenu.h"

DoubleGameover::DoubleGameover(int mode,int score1,int score2,int characterKind1,int characterKind2,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoubleGameover)
{
    ui->setupUi(this);
    if (mode == 1) ui->label->setText("时间到了");
    else ui->label->setText("有一方没有可供消除的方块了");
    ui->scoreLabel1->setText(QString::number(score1));
    ui->scoreLabel2->setText(QString::number(score2));
    if (score1 == score2) ui->winLabel->setText("平手！");
    switch (characterKind1) {
    case  1:
        ui->player1->setPixmap(QPixmap(":/res/role1.png"));
        if (score1 > score2) ui->winner->setPixmap(QPixmap(":/res/role1.png"));
        break;
    case  2:
        ui->player1->setPixmap(QPixmap(":/res/role2.png"));
        if (score1 > score2) ui->winner->setPixmap(QPixmap(":/res/role2.png"));
        break;
    case  3:
        ui->player1->setPixmap(QPixmap(":/res/role3.png"));
        if (score1 > score2) ui->winner->setPixmap(QPixmap(":/res/role3.png"));
        break;
    case  4:
        ui->player1->setPixmap(QPixmap(":/res/role4.png"));
        if (score1 > score2) ui->winner->setPixmap(QPixmap(":/res/role4.png"));
        break;
    }
    switch (characterKind2) {
    case  1:
        ui->player2->setPixmap(QPixmap(":/res/role1.png"));
        if (score1 < score2) ui->winner->setPixmap(QPixmap(":/res/role1.png"));
        break;
    case  2:
        ui->player2->setPixmap(QPixmap(":/res/role2.png"));
        if (score1 < score2) ui->winner->setPixmap(QPixmap(":/res/role2.png"));
        break;
    case  3:
        ui->player2->setPixmap(QPixmap(":/res/role3.png"));
        if (score1 < score2) ui->winner->setPixmap(QPixmap(":/res/role3.png"));
        break;
    case  4:
        ui->player2->setPixmap(QPixmap(":/res/role4.png"));
        if (score1 < score2) ui->winner->setPixmap(QPixmap(":/res/role4.png"));
        break;
    }
    ui->player1->setScaledContents(true);
    ui->player2->setScaledContents(true);
    ui->winner->setScaledContents(true);

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(openmenu()));
    connect(ui->pushButton,SIGNAL(clicked()),this->parent(),SLOT(close()));
}

DoubleGameover::~DoubleGameover()
{
    delete ui;
}

void DoubleGameover::openmenu()
{
    OpenMenu *openMenu = new OpenMenu;
    openMenu->setAttribute(Qt::WA_DeleteOnClose);
    openMenu->show();
    this->close();
}
