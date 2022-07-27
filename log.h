#ifndef LOG_H
#define LOG_H
#include "logfile.h"
#include <QQueue>
#include <QWidget>

namespace Ui {
class Log;
}

class Log : public QWidget
{
    Q_OBJECT

public:
    explicit Log(QWidget *parent = nullptr);
    ~Log();
signals:
    void LogStart(); //启动线程信号
private:
    Ui::Log *ui;
    QVector<bool> check;
};

#endif // LOG_H
