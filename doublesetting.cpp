#include "doublesetting.h"
#include "ui_doublesetting.h"
#include "openmenu.h"
#include "doublemainwin.h"

#include <QButtonGroup>

DoubleSetting::DoubleSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoubleSetting)
{
    ui->setupUi(this);
    setFixedSize(this->width(),this->height());
    bgDensity = new QButtonGroup(this);
    bgCharacter1 = new QButtonGroup(this);
    bgCharacter2 = new QButtonGroup(this);

    bgDensity->addButton(ui->button1,3);
    bgDensity->addButton(ui->button2,2);
    bgDensity->addButton(ui->button3,1);

    bgCharacter1->addButton(ui->role1Button,1);
    bgCharacter1->addButton(ui->role2Button,2);
    bgCharacter1->addButton(ui->role3Button,3);
    bgCharacter1->addButton(ui->role4Button,4);
    bgCharacter2->addButton(ui->role1Button_2,1);
    bgCharacter2->addButton(ui->role2Button_2,2);
    bgCharacter2->addButton(ui->role3Button_2,3);
    bgCharacter2->addButton(ui->role4Button_2,4);

    connect(ui->okButton,SIGNAL(clicked()),this,SLOT(startGame()));
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(cancel()));
}

DoubleSetting::~DoubleSetting()
{
    delete ui;
}

void DoubleSetting::startGame()
{
    int heigh = ui->heightBox->value();
    int wid = ui->widthBox->value();
    int boxNum = ui->boxNumBox->value();
    int secs = ui->timeBox->value();

    int density = bgDensity->checkedId();
    int characterKind1 = bgCharacter1->checkedId();
    int characterKind2 = bgCharacter2->checkedId();

    if (characterKind1 == characterKind2) {
        ui->hintLabel->setText("两位玩家不能选择相同的角色哦！");
    } else {
        DoubleMainWin *doubleGame = new DoubleMainWin(wid,heigh,boxNum,secs,density,characterKind1,characterKind2);
        doubleGame->setAttribute(Qt::WA_DeleteOnClose);
        doubleGame->show();
        this->close();
    }
}

void DoubleSetting::cancel()
{
    OpenMenu *openMenu = new OpenMenu;
    openMenu->setAttribute(Qt::WA_DeleteOnClose);
    openMenu->show();
    this->close();
}
