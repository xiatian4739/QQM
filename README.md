# QQM

QT入门小项目-群聊

 此项目来源于[B站](https://www.bilibili.com/video/BV1iy4y1t7PL?spm_id_from=333.1007.top_right_bar_window_default_collection.content.click)上的一个项目，原项目在保存功能模块上，采用弹出对话框方式保存聊天记录。

而本项目采用创建一个线程，使用队列容器每产生一条消息就放入队列中，线程所要做的任务是从队列容器中不断的取出里面的消息并写入文件。



### 截图
![主界面](https://github.com/xiatian4739/QQM/blob/main/Picture/zujm.png)
![聊天界面](https://github.com/xiatian4739/QQM/blob/main/Picture/liaot.png)
![记录](https://github.com/xiatian4739/QQM/blob/main/Picture/log.png)

