#ifndef DOUBLESETTING_H
#define DOUBLESETTING_H

#include <QDialog>
#include <QButtonGroup>

namespace Ui {
class DoubleSetting;
}

class DoubleSetting : public QDialog
{
    Q_OBJECT

public:
    explicit DoubleSetting(QWidget *parent = nullptr);
    ~DoubleSetting();

private slots:
    void startGame();
    void cancel();

private:
    Ui::DoubleSetting *ui;
    QButtonGroup *bgDensity, *bgCharacter1, *bgCharacter2;
    QButtonGroup *bg1,*bg2,*bg3,*bg4;
};

#endif // DOUBLESETTING_H
