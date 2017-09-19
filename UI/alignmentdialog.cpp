#include "alignmentdialog.h"
#include "ui_alignmentdialog.h"

AlignmentDialog::AlignmentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlignmentDialog)
{
    ui->setupUi(this);

    labelPeakShift->setText("Uses peaks assigned by user input. Please run peak picking first before using this option.");
    labelPeakShiftSlider->setText("Peak Shift window size: ");

    sliderPeakShift->setRange(1,50);
    sliderPeakShift->setValue(10);
    sliderPeakShift->setOrientation(Qt::Orientation::Horizontal);

    ui->verticalLayout->addWidget(labelPeakShift,1,0);
    ui->verticalLayout->addWidget(labelPeakShiftSlider,2);
    ui->verticalLayout->addWidget(sliderPeakShift,2);

    ui->verticalLayout->removeWidget(ui->buttonBox);
    ui->verticalLayout->addWidget(ui->buttonBox,3);

}

AlignmentDialog::~AlignmentDialog()
{
    delete ui;
}

void AlignmentDialog::on_comboBox_currentIndexChanged(const QString &arg1)
{
    qDebug() << arg1;
    if(arg1 == "IcoShift")
    {
        sliderPeakShift->hide();
        labelPeakShift->hide();
        labelPeakShiftSlider->hide();
    }
    else if(arg1 == "Fuzzy Warping")
    {
        sliderPeakShift->hide();
        labelPeakShift->hide();
        labelPeakShiftSlider->hide();
    }
    else if(arg1 == "Simple PeakShift")
    {
        sliderPeakShift->show();
        labelPeakShift->show();
        labelPeakShiftSlider->show();
    }
    else
    {

    }
}
