#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QString errorCode, QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_released();
    void writePoint();

private:
    Ui::Widget *ui;

    QTimer * _timer;
};

#endif // WIDGET_H
