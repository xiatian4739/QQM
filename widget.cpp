#include "widget.h"
#include "ui_widget.h"
#include <QDataStream>
#include <QMessageBox>
#include <QTime>
#include <QComboBox>
#include <QColorDialog>

extern QQueue <QString> Mesages; //全局队列

Widget::Widget(QWidget *parent,QString name)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_name = name;

    m_port = 8909;
    m_udpSocket = new QUdpSocket(this);
    m_udpSocket->bind(m_port,QUdpSocket::ShareAddress| QUdpSocket::ReuseAddressHint);

    //套接字，有消息进行读
    connect(m_udpSocket,&QUdpSocket::readyRead,this,&Widget::ReceiveMessage);
    //新用户进入
    sendMsg(MsgType::UserEnter);

    //设置字体
    connect(ui->fontComboBox,&QFontComboBox::currentFontChanged,this,[=](const QFont & font)
    {
       ui->MsgEdit->setCurrentFont(font);
       ui->MsgEdit->setFocus();
    });

    //设置字体大小
    void (QComboBox::* sizebtn)(const QString &text) =&QComboBox::currentTextChanged;
    connect(ui->sizeBox,sizebtn,[=](const QString &text){
        ui->MsgEdit->setFontPointSize(text.toDouble());
        ui->MsgEdit->setFocus();
    });

    //加粗
    connect(ui->Boldtool,&QToolButton::clicked,this,[=](bool checked){
       if(checked)
       {
           ui->MsgEdit->setFontWeight(QFont::Bold);
       }else {
           ui->MsgEdit->setFontWeight(QFont::Normal);
       }
    });

    //设置下划线
    connect(ui->Slanttool,&QToolButton::clicked,this,[=](bool checked){
       ui->MsgEdit->setFontItalic(checked);
       ui->MsgEdit->setFocus();
    });

    //设置颜色
    connect(ui->Colortool,&QToolButton::clicked,[=](){
       QColor color = QColorDialog::getColor(color,this);
       ui->MsgEdit->setTextColor(color);
    });

    //清空聊天记录
    connect(ui->Cleantool,&QToolButton::clicked,[=](){
       ui->textBrowser->clear();
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::sendMsg(MsgType type)
{
    QByteArray array;
    QDataStream stream(&array,QIODevice::WriteOnly);
    stream<<type<<this->getName();

    switch (type) {
        case MsgType::Msg:
            if(ui->MsgEdit->toPlainText() == "")
            {
                QMessageBox::warning(this,"警告","内容不能为空");
                return;
            }
            stream<<this->getMsg();
        break;
        case MsgType::UserExit:
            break;
        case MsgType::UserEnter:
            break;
    }
    m_udpSocket->writeDatagram(array.data(),array.size(),QHostAddress::Broadcast,m_port);
}

QString Widget::getName()
{
    return m_name;
}

QString Widget::getMsg()
{
    QString msg = ui->MsgEdit->toHtml();//toHtml 带字体样式
    m_logmsg = ui->MsgEdit->toPlainText();
    ui->MsgEdit->clear();
    ui->MsgEdit->setFocus();
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    Mesages.enqueue(QString(getName()+"于"+time+"说: "+m_logmsg));
    return msg;
}

void Widget::userEnter(QString username,QString time)
{

    bool isEmpty = ui->tableWidget->findItems(username,Qt::MatchExactly).isEmpty();
    if(isEmpty)
    {
        QTableWidgetItem * user= new QTableWidgetItem(username);
        ui->tableWidget->insertRow(0);
        ui->tableWidget->setItem(0,0,user);
        ui->textBrowser->setTextColor(Qt::gray);
        ui->textBrowser->append(username+"用户已上线 "+time);
        ui->userlabel->setText(QString("在线人数:%1").arg(ui->tableWidget->rowCount()));
        Mesages.enqueue(QString(username+"用户已上线 "+time));
        //新用户进入
        sendMsg(MsgType::UserEnter);

    }
}

void Widget::userExit(QString username, QString time)
{

    bool isEmpty = ui->tableWidget->findItems(username,Qt::MatchExactly).isEmpty();
    if(!isEmpty)
    {
        //寻找行
        int row = ui->tableWidget->findItems(username,Qt::MatchExactly).first()->row();
        //移除该行
        ui->tableWidget->removeRow(row);
        //发送用户下线消息
        ui->textBrowser->setTextColor(Qt::gray);
        ui->textBrowser->append(username+"用户于 "+time+" 时下线");
        ui->userlabel->setText(QString("在线人数:%1").arg(ui->tableWidget->rowCount()));
        Mesages.enqueue(QString(username+"用户于 "+time+" 时下线"));

    }
}

void Widget::ReceiveMessage()
{
    qint64 size = m_udpSocket->pendingDatagramSize();
    int mysize = static_cast<int>(size);
    QByteArray *array = new QByteArray(mysize,0);
    m_udpSocket->readDatagram(array->data(),size);
    QDataStream stream(array,QIODevice::ReadOnly);
    int mytype;
    stream>>mytype;
    QString name,msg;
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    switch (mytype) {
        case MsgType::Msg:
            stream>>name>>msg;
            ui->textBrowser->setTextColor(QColor(Qt::blue));
            ui->textBrowser->append("["+name+"] "+time);
            ui->textBrowser->append(msg); 

        break;
        case MsgType::UserExit:
            stream>>name;
            userExit(name,time);
        break;
        case MsgType::UserEnter:
            stream>>name;
            userEnter(name,time);
        break;
    }

}

void Widget::closeEvent(QCloseEvent *event)
{
    emit this->closeWidget(); //激活信号

    sendMsg(MsgType::UserExit);
    this->m_udpSocket->close();
    this->m_udpSocket->deleteLater();
    this->close();
}

//发送按钮
void Widget::on_m_sendBtn_clicked()
{
    sendMsg(MsgType::Msg);
}

//退出按钮
void Widget::on_m_exitBtn_clicked()
{
    QCloseEvent *event;
    closeEvent(event);
}
