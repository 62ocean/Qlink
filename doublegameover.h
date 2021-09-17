#ifndef DOUBLEGAMEOVER_H
#define DOUBLEGAMEOVER_H

#include <QDialog>

namespace Ui {
class DoubleGameover;
}

class DoubleGameover : public QDialog
{
    Q_OBJECT

public:
    explicit DoubleGameover(int mode,int score1,int score2,int characterKind1,int characterKind2,QWidget *parent = nullptr);
    ~DoubleGameover();

private slots:
    void openmenu();

private:
    Ui::DoubleGameover *ui;
};

#endif // DOUBLEGAMEOVER_H
