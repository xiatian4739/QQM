#include "logfile.h"
#include <QQueue>
#include <QTime>
#include <QDebug>

QQueue <QString> Mesages; //全局队列
LogFile::LogFile(QObject *parent) : QObject(parent)
{
    m_filePath = "./log/log_"+QDateTime::currentDateTime().toString("yyyy-MM-dd")+".txt";
    file.setFileName(m_filePath);
}


void LogFile::doWork()
{
    //队列中没有数据时关闭文件，有是打开文件。这样的效率不高

    //循环处理消息
    while (1) {
        if(!Mesages.isEmpty())
        {
            //有消息，打开文件写入
            file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
            //qDebug()<<"测试"<<Mesages.back();
            this->msg = Mesages.dequeue();
            //将消息写入文件
            //写入文件需要字符串为QByteArray格式
            file.write(this->msg.toUtf8());
            file.write("\n");
        }
        //没有消息，关闭文件
        file.close();
    }

}
