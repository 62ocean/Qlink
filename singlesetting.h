#ifndef SINGLESETTING_H
#define SINGLESETTING_H

#include <QDialog>
#include <QButtonGroup>

namespace Ui {
class SingleSetting;
}

class SingleSetting : public QDialog
{
    Q_OBJECT

public:
    explicit SingleSetting(QWidget *parent = nullptr);
    ~SingleSetting();

private slots:
    void startGame();
    void cancel();

private:
    Ui::SingleSetting *ui;
    QButtonGroup *bgDensity, *bgCharacter;

};

#endif // SINGLESETTING_H
