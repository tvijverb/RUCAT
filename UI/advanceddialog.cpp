#include "advanceddialog.h"
#include "ui_advanceddialog.h"

advanceddialog::advanceddialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::advanceddialog)
{
    ui->setupUi(this);
}

void advanceddialog::setSlidersRange(int s1min,int s1max,int s2min,int s2max,int s3min,int s3max)
{
    ui->horizontalSlider->setRange(s1min,s1max);
    ui->horizontalSlider_2->setRange(s2min,s2max);
    ui->horizontalSlider_3->setRange(s3min,s3max);
    ui->spinBox->setRange(s1min,s1max);
    ui->spinBox_2->setRange(s2min,s2max);
    ui->spinBox_3->setRange(s3min,s3max);
}

void advanceddialog::setSlidersvalue(int s1,int s2,int s3)
{
    ui->horizontalSlider->setValue(s1);
    ui->horizontalSlider_2->setValue(s2);
    ui->horizontalSlider_3->setValue(s3);
    ui->spinBox->setValue(s1);
    ui->spinBox_2->setValue(s2);
    ui->spinBox_3->setValue(s3);
}

std::vector<int> advanceddialog::getSlidersvalue()
{
    std::vector<int> sliderv;
    sliderv.push_back(ui->horizontalSlider->value());
    sliderv.push_back(ui->horizontalSlider_2->value());
    sliderv.push_back(ui->horizontalSlider_3->value());
    return sliderv;
}


advanceddialog::~advanceddialog()
{
    delete ui;
}

void advanceddialog::on_horizontalSlider_2_sliderMoved(int position)
{

}


#include "moc_advanceddialog.cpp";

