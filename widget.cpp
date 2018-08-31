#include "widget.h"
#include "ui_widget.h"

#include <QProcess>
#include <QFile>

const int writePointInterval = 500;

Widget::Widget(QString errorCode, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->infoLabel->setText(QString(tr("Application Avicon-31 crashed with code: ")) + errorCode);

    _timer = new QTimer(this);
    _timer->setInterval(writePointInterval);
    connect(_timer, SIGNAL(timeout()), this, SLOT(writePoint()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_released()
{
    _timer->start();
    ui->infoLabel->setText(QString(tr("Rebooting ")));
    QFile file("/etc/run");
    file.open(QIODevice::Truncate | QIODevice::Text | QIODevice::WriteOnly);
    file.write(QString("update").toLatin1());
    file.close();
    QProcess * process = new QProcess(this);
    process->startDetached("reboot");
}

void Widget::writePoint()
{
    ui->infoLabel->setText(ui->infoLabel->text() + QString("."));
}
