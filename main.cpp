#include "widget.h"
#include "log.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Log log;
    log.show();
    return a.exec();
}
