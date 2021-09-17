#ifndef CHOOSEMODEL_H
#define CHOOSEMODEL_H

#include <QDialog>

namespace Ui {
class ChooseModel;
}

class ChooseModel : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseModel(QWidget *parent = nullptr);
    ~ChooseModel();

private slots:
    void singleModle();
    void doubleModle();

private:
    Ui::ChooseModel *ui;
};

#endif // CHOOSEMODEL_H
