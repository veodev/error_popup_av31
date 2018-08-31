#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget * w = new Widget(QString(argv[1]));
    w->show();

    return a.exec();
}
