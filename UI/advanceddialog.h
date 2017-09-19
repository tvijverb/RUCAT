#ifndef ADVANCEDDIALOG_H
#define ADVANCEDDIALOG_H

#include <QDialog>

namespace Ui {
class advanceddialog;
}

class advanceddialog : public QDialog
{
    Q_OBJECT

public:
    explicit advanceddialog(QWidget *parent = 0);
    void setSlidersRange(int,int,int,int,int,int);
    void setSlidersvalue(int,int,int);
    std::vector<int> getSlidersvalue();
    ~advanceddialog();

private slots:
    void on_horizontalSlider_2_valueChanged(int value);

    void on_horizontalSlider_3_valueChanged(int value);

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::advanceddialog *ui;
};

#endif // ADVANCEDDIALOG_H
