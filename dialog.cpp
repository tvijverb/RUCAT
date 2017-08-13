#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setZero()
{
    ui->progressBar->setValue(0);
    ui->progressBar_2->setValue(0);
}

void Dialog::setMax(int max)
{
    ui->progressBar->setMaximum(max);
}

void Dialog::setMax2(int max)
{
    ui->progressBar_2->setMaximum(max);
}

void Dialog::setValue(int value)
{
    ui->progressBar->setValue(value);
}

void Dialog::setValue2(int value)
{
    ui->progressBar_2->setValue(value);
}

void Dialog::closethis()
{
    close();
}
