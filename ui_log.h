/********************************************************************************
** Form generated from reading UI file 'log.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_H
#define UI_LOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Log
{
public:
    QVBoxLayout *verticalLayout;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *vlayout;

    void setupUi(QWidget *Log)
    {
        if (Log->objectName().isEmpty())
            Log->setObjectName(QStringLiteral("Log"));
        Log->resize(388, 891);
        verticalLayout = new QVBoxLayout(Log);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        toolBox = new QToolBox(Log);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 388, 859));
        vlayout = new QVBoxLayout(page);
        vlayout->setObjectName(QStringLiteral("vlayout"));
        toolBox->addItem(page, QString::fromUtf8("\347\276\244\346\210\220\345\221\230"));

        verticalLayout->addWidget(toolBox);


        retranslateUi(Log);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Log);
    } // setupUi

    void retranslateUi(QWidget *Log)
    {
        Log->setWindowTitle(QApplication::translate("Log", "Form", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("Log", "\347\276\244\346\210\220\345\221\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Log: public Ui_Log {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_H
