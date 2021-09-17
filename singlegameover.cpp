#include "singlegameover.h"
#include "ui_singlegameover.h"
#include "openmenu.h"

SingleGameover::SingleGameover(int mode,int score,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SingleGameover)
{
    ui->setupUi(this);
    if (mode == 1) ui->label->setText("时间到了");
    else ui->label->setText("没有可供消除的方块了");
    ui->scoreLabel->setText(QString::number(score));

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(openmenu()));
    connect(ui->pushButton,SIGNAL(clicked()),this->parent(),SLOT(close()));
}

SingleGameover::~SingleGameover()
{
    delete ui;
}

void SingleGameover::openmenu()
{
    OpenMenu *openMenu = new OpenMenu;
    openMenu->setAttribute(Qt::WA_DeleteOnClose);
    openMenu->show();
    this->close();
}
