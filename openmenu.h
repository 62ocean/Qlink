#ifndef OPENMENU_H
#define OPENMENU_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class OpenMenu; }
QT_END_NAMESPACE

class OpenMenu : public QDialog
{
    Q_OBJECT

public:
    OpenMenu(QWidget *parent = nullptr);
    ~OpenMenu();

private slots:
    void startGame();
    void gameHelp();
    void loadGame();

private:
    Ui::OpenMenu *ui;
};
#endif // OPENMENU_H
