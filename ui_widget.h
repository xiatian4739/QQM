/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QFontComboBox *fontComboBox;
    QComboBox *sizeBox;
    QToolButton *Boldtool;
    QToolButton *Slanttool;
    QToolButton *Unlinetool;
    QToolButton *Colortool;
    QToolButton *Cleantool;
    QTextEdit *MsgEdit;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *m_sendBtn;
    QSpacerItem *horizontalSpacer;
    QLabel *userlabel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *m_exitBtn;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(933, 713);
        horizontalLayout_5 = new QHBoxLayout(Widget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        widget_6 = new QWidget(Widget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        widget_4 = new QWidget(widget_6);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget = new QWidget(widget_3);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        frame = new QFrame(widget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        fontComboBox = new QFontComboBox(frame);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));

        horizontalLayout->addWidget(fontComboBox);

        sizeBox = new QComboBox(frame);
        sizeBox->setObjectName(QStringLiteral("sizeBox"));

        horizontalLayout->addWidget(sizeBox);

        Boldtool = new QToolButton(frame);
        Boldtool->setObjectName(QStringLiteral("Boldtool"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        Boldtool->setIcon(icon);
        Boldtool->setCheckable(true);

        horizontalLayout->addWidget(Boldtool);

        Slanttool = new QToolButton(frame);
        Slanttool->setObjectName(QStringLiteral("Slanttool"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        Slanttool->setIcon(icon1);
        Slanttool->setCheckable(true);

        horizontalLayout->addWidget(Slanttool);

        Unlinetool = new QToolButton(frame);
        Unlinetool->setObjectName(QStringLiteral("Unlinetool"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/under.png"), QSize(), QIcon::Normal, QIcon::Off);
        Unlinetool->setIcon(icon2);
        Unlinetool->setCheckable(true);

        horizontalLayout->addWidget(Unlinetool);

        Colortool = new QToolButton(frame);
        Colortool->setObjectName(QStringLiteral("Colortool"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        Colortool->setIcon(icon3);

        horizontalLayout->addWidget(Colortool);

        Cleantool = new QToolButton(frame);
        Cleantool->setObjectName(QStringLiteral("Cleantool"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        Cleantool->setIcon(icon4);

        horizontalLayout->addWidget(Cleantool);


        verticalLayout->addWidget(frame);


        verticalLayout_2->addWidget(widget);

        MsgEdit = new QTextEdit(widget_3);
        MsgEdit->setObjectName(QStringLiteral("MsgEdit"));
        MsgEdit->setMaximumSize(QSize(16777215, 100));

        verticalLayout_2->addWidget(MsgEdit);


        verticalLayout_3->addWidget(widget_3);

        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        m_sendBtn = new QPushButton(widget_2);
        m_sendBtn->setObjectName(QStringLiteral("m_sendBtn"));

        horizontalLayout_2->addWidget(m_sendBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        userlabel = new QLabel(widget_2);
        userlabel->setObjectName(QStringLiteral("userlabel"));

        horizontalLayout_2->addWidget(userlabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        m_exitBtn = new QPushButton(widget_2);
        m_exitBtn->setObjectName(QStringLiteral("m_exitBtn"));

        horizontalLayout_2->addWidget(m_exitBtn);


        verticalLayout_3->addWidget(widget_2);


        horizontalLayout_4->addWidget(widget_4);

        widget_5 = new QWidget(widget_6);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(widget_5);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        horizontalLayout_3->addWidget(tableWidget);


        horizontalLayout_4->addWidget(widget_5);


        horizontalLayout_5->addWidget(widget_6);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        sizeBox->clear();
        sizeBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "2", Q_NULLPTR)
         << QApplication::translate("Widget", "3", Q_NULLPTR)
         << QApplication::translate("Widget", "4", Q_NULLPTR)
         << QApplication::translate("Widget", "5", Q_NULLPTR)
         << QApplication::translate("Widget", "6", Q_NULLPTR)
         << QApplication::translate("Widget", "7", Q_NULLPTR)
         << QApplication::translate("Widget", "8", Q_NULLPTR)
         << QApplication::translate("Widget", "9", Q_NULLPTR)
         << QApplication::translate("Widget", "10", Q_NULLPTR)
         << QApplication::translate("Widget", "11", Q_NULLPTR)
         << QApplication::translate("Widget", "12", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        Boldtool->setToolTip(QApplication::translate("Widget", "\345\212\240\347\262\227", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        Boldtool->setText(QApplication::translate("Widget", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        Slanttool->setToolTip(QApplication::translate("Widget", "\345\200\276\346\226\234", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        Slanttool->setText(QApplication::translate("Widget", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        Unlinetool->setToolTip(QApplication::translate("Widget", "\344\270\213\345\210\222\347\272\277", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        Unlinetool->setText(QApplication::translate("Widget", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        Colortool->setToolTip(QApplication::translate("Widget", "\351\242\234\350\211\262", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        Colortool->setText(QApplication::translate("Widget", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        Cleantool->setToolTip(QApplication::translate("Widget", "\346\270\205\347\251\272", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        Cleantool->setText(QApplication::translate("Widget", "...", Q_NULLPTR));
        m_sendBtn->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", Q_NULLPTR));
        userlabel->setText(QApplication::translate("Widget", "\345\275\223\345\211\215\345\234\250\347\272\277\344\272\272\346\225\260:", Q_NULLPTR));
        m_exitBtn->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
