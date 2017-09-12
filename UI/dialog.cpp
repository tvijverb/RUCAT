#include "UI/dialog.h"
#include "UI/ui_dialog.h"

#include <QWinTaskbarButton>
#include <QWinTaskbarProgress>
#include <QObject>
#include <QShowEvent>
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    taskbarButton = new QWinTaskbarButton(this);
    //taskbarButton->setWindow(windowHandle());
    taskbarButton->setOverlayIcon(QIcon(":/loading.png"));
}

void Dialog::setTitle(const QString title)
{
    this->setWindowTitle(title);
}

void Dialog::showEvent(QShowEvent *e)
{
#ifdef Q_OS_WIN32
    taskbarButton->setWindow(windowHandle());
    taskbarProgress = taskbarButton->progress();
    taskbarProgress->setVisible(true);
    taskbarProgress->show();

    QObject::connect(ui->progressBar, &QProgressBar::valueChanged, taskbarProgress, &QWinTaskbarProgress::setValue);
    QObject::connect(this, &Dialog::dialogMax2Changed, taskbarProgress, &QWinTaskbarProgress::setMaximum);
#endif

    e->accept();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setZero()
{
    ui->progressBar->setValue(0);
}

void Dialog::setRange(int min,int max)
{
    ui->progressBar->setMinimum(min);
    ui->progressBar->setMaximum(max);
    emit dialogMax2Changed(max);
}

void Dialog::setMax(int max)
{
    ui->progressBar->setMaximum(max);
    emit dialogMax2Changed(max);
    //qDebug() << "progress_2 minmax:" << 0 << max;
    //qDebug() << "taskbarProgress max: " << taskbarProgress->maximum();
}

void Dialog::setValue(int value)
{
    ui->progressBar->setValue(value);
    //qDebug() << "progress valuechanged:" << value;
    //qDebug() << "taskbarProgress max: " << taskbarProgress->maximum();
}

void Dialog::closethis()
{
    close();
}

#include "moc_dialog.cpp"
