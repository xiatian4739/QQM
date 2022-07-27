#ifndef LOGFILE_H
#define LOGFILE_H
#include <QFile>
#include <QObject>
#include <QQueue>
//extern QQueue <QString> Mesages; //全局队列

class LogFile : public QObject
{
    Q_OBJECT
public:
    explicit LogFile(QObject *parent = nullptr);

    //工作类，将每一个消息写入到文本中
    void doWork();
signals:

private:
    QString m_filePath;
    QFile file;
    QString msg;
};

#endif // LOGFILE_H
