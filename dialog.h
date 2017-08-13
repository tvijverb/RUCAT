#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void setZero();
    void setMax(int);
    void setMax2(int);
    void setValue(int);
    void setValue2(int);
    void closethis();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
