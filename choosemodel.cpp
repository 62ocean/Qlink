#include "choosemodel.h"
#include "ui_choosemodel.h"

ChooseModel::ChooseModel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseModel)
{
    ui->setupUi(this);
    setFixedSize(this->width(),this->height());

    connect(ui->singleButton,SIGNAL(clicked()),this,SLOT(singleModle()));
    connect(ui->doubleButton,SIGNAL(clicked()),this,SLOT(doubleModle()));
    connect(ui->returnButton,SIGNAL(clicked()),this,SLOT(close()));
}

ChooseModel::~ChooseModel()
{
    delete ui;
}

void ChooseModel::singleModle()
{
    done(1);
}
void ChooseModel::doubleModle()
{
    done(2);
}
