#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
//#include <QWinTaskbarButton>
//#include <QWinTaskbarProgress>
#include <QObject>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

	public slots:
    void setZero();
    void setMax(int);
    void setValue(int);
    void setRange(int,int);
    void closethis();

private:
    Ui::Dialog *ui;

    void showEvent(QShowEvent *e);

    //QWinTaskbarButton *taskbarButton = nullptr;
    //QWinTaskbarProgress *taskbarProgress = nullptr;

signals:
    void dialogMax2Changed(int);
};

#endif // DIALOG_H
