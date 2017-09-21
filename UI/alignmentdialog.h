#ifndef ALIGNMENTDIALOG_H
#define ALIGNMENTDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QLabel>
#include <QSlider>

namespace Ui {
class AlignmentDialog;
}

class AlignmentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AlignmentDialog(QWidget *parent = 0);
    ~AlignmentDialog();

private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_buttonBox_accepted();

private:
    Ui::AlignmentDialog *ui;
    QLabel *labelPeakShift = new QLabel(this);
    QLabel *labelPeakShiftSlider = new QLabel(this);
    QSlider *sliderPeakShift = new QSlider(this);
};

#endif // ALIGNMENTDIALOG_H
