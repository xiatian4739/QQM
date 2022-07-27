#include "log.h"
#include "ui_log.h"
#include "widget.h"
#include <QToolButton>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QThread>
#include "logfile.h"
#define COUNT_PERSON 9  //创建的人数


Log::Log(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Log)
{
    //创建日记线程
    QThread *log_thread = new QThread; //资源释放在最下面
    //创建任务
    LogFile *logw = new LogFile; //任务不能指定父对象
    logw->moveToThread(log_thread);
    connect(this,&Log::LogStart,logw,&LogFile::doWork);
    //发射信号
    emit this->LogStart();
    log_thread->start();  //启动任务

    ui->setupUi(this);
    //设置图标
    this->setWindowIcon(QIcon(":/images/qq.png"));
    //设置标题
    this->setWindowTitle("QQM");

    QList<QString> namelist;
    namelist<<"张山"<<"王二"<<"李麻子"<<"小猪"<<"太闹腾"<<"甜甜"<<"汪峰"<<"艾米"<<"小结";
    QStringList iconNameList;
    iconNameList<<"ymrl"<<"spqy"<<"qmnn"<<"lswh"<<"jj"<<"dr"<<"Cherry"<<"qq"<<"qq";

    //使用容器保存按钮，方便connect
    QVector<QToolButton*> V_Btn;

    //循环创建按钮
    for(int i = 0; i < COUNT_PERSON; i++)
    {
        QToolButton* btn = new QToolButton(this);
        //加载图片
        btn->setIcon(QPixmap(QString(":/images/%1.png").arg(iconNameList.at(i))));
        //设置图片大小
        btn->setIconSize(QPixmap(":/images/spqy.png").size());
        //设置网民
        btn->setText(QString("%1").arg(namelist.at(i)));
        //设置按钮透明度
        btn->setAutoRaise(true);
        //设置图片和文字都显示
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        //放到vlayout布局中
        ui->vlayout->addWidget(btn);
        V_Btn.push_back(btn);
        check.push_back(false);
    }

    //建立信号连接
    for (int i = 0; i < COUNT_PERSON; i++) {
        connect(V_Btn.at(i),&QToolButton::clicked,[=](){
           //防止重复打开一个窗口
            if(check.at(i))
           {
                QMessageBox::warning(this,"警告","该聊天窗口已经被打开");
                return;
           }
           check[i] = true;
           //qDebug()<<"创建对象";
           Widget * widget = new Widget(nullptr,V_Btn.at(i)->text());
           widget->setWindowTitle(V_Btn.at(i)->text());
           widget->setWindowIcon(V_Btn.at(i)->icon());
           widget->show();

           //窗口对象关闭时产生信号:closeWidget,释放对象内存和标志(check)
           connect(widget,&Widget::closeWidget,this,[=](){
              /*
               * 如果不释放对象，当点击人数多时或不适用将占用大量内存.
               *但每一个窗口关闭都需要经历创建和释放，性能将大大下降。
               * 应该可以通过定时器，定期检查已经关闭的不活跃的用户并销毁内存，
               * 这样的话可以性能应该可以得到一个平衡点。
               */
              // delete widget;
               //qDebug()<<"释放对象";
               check[i] = false;
           });

        });
    }

    //当窗口关闭时，释放资源
    connect(this,&Log::destroyed,this,[=](){
        log_thread->quit();
        log_thread->wait();
        log_thread->deleteLater();
        logw->deleteLater();
    });

}

Log::~Log()
{
    delete ui;
}

