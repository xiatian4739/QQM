#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include <QQueue>
#include "log.h"
#include "logfile.h"
//QQueue <QString> Mesages;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
public:
    enum MsgType{Msg,UserEnter,UserExit}; //枚举： 普通信息，用户进入，用户离开
public:
    explicit Widget(QWidget *parent, QString name);
    Widget()=delete;
    ~Widget();

    void sendMsg(MsgType type); //广播upd信息
    QString getName();//获取名字
    QString getMsg();//获取聊天信息
    void userEnter(QString username,QString);//处理用户进入
    void userExit(QString username,QString time);//处理用户离开
    void ReceiveMessage();//接收UDP消息

    //重写关闭事件
    void closeEvent(QCloseEvent *event) override;
signals:
    void closeWidget();

private slots:
    //发送消息按钮
    void on_m_sendBtn_clicked();
    //退出按钮
    void on_m_exitBtn_clicked();
private:
    Ui::Widget *ui;
    quint16 m_port; //端口
    QString m_name; //名字
    QUdpSocket* m_udpSocket;//套接字
    QString m_logmsg; //保存信息

};
#endif // WIDGET_H
