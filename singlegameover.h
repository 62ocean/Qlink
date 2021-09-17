#ifndef SINGLEGAMEOVER_H
#define SINGLEGAMEOVER_H

#include <QDialog>

namespace Ui {
class SingleGameover;
}

class SingleGameover : public QDialog
{
    Q_OBJECT

public:
    explicit SingleGameover(int mode,int score,QWidget *parent = nullptr);
    ~SingleGameover();

private slots:
    void openmenu();

private:
    Ui::SingleGameover *ui;
};

#endif // SINGLEGAMEOVER_H
