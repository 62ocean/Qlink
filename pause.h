#ifndef PAUSE_H
#define PAUSE_H

#include <QDialog>

namespace Ui {
class Pause;
}

class Pause : public QDialog
{
    Q_OBJECT

public:
    explicit Pause(QWidget *parent = nullptr);
    ~Pause();
signals:
    void closeParent();

private slots:
    void load();
    void openmenu();
    void save();


private:
    Ui::Pause *ui;
};

#endif // PAUSE_H
