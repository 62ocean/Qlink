#include "singlesetting.h"
#include "ui_singlesetting.h"
#include "singlemainwin.h"
#include "openmenu.h"
#include <QButtonGroup>

SingleSetting::SingleSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SingleSetting)
{
    ui->setupUi(this);
    setFixedSize(this->width(),this->height());
    bgDensity = new QButtonGroup(this);
    bgCharacter = new QButtonGroup(this);

    bgDensity->addButton(ui->button1,3);
    bgDensity->addButton(ui->button2,2);
    bgDensity->addButton(ui->button3,1);

    bgCharacter->addButton(ui->role1Button,1);
    bgCharacter->addButton(ui->role2Button,2);
    bgCharacter->addButton(ui->role3Button,3);
    bgCharacter->addButton(ui->role4Button,4);

    connect(ui->okButton,SIGNAL(clicked()),this,SLOT(startGame()));
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(cancel()));
}

SingleSetting::~SingleSetting()
{
    delete ui;
}

void SingleSetting::startGame()
{
    int heigh = ui->heightBox->value();
    int wid = ui->widthBox->value();
    int boxNum = ui->boxNumBox->value();
    int secs = ui->timeBox->value();

    int density = bgDensity->checkedId();
    int characterKind = bgCharacter->checkedId();

    SingleMainWin *singleGame = new SingleMainWin(wid,heigh,boxNum,secs,density,characterKind);
    singleGame->setAttribute(Qt::WA_DeleteOnClose);

    singleGame->show();
    this->close();
}

void SingleSetting::cancel()
{
    OpenMenu *openMenu = new OpenMenu;
    openMenu->setAttribute(Qt::WA_DeleteOnClose);
    openMenu->show();
    this->close();
}
