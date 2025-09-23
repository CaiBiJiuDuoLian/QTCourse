/********************************************************************************
** Form generated from reading UI file 'information.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMATION_H
#define UI_INFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Information
{
public:
    QLabel *label;
    QPushButton *OK;

    void setupUi(QWidget *Information)
    {
        if (Information->objectName().isEmpty())
            Information->setObjectName("Information");
        Information->resize(433, 300);
        label = new QLabel(Information);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 411, 261));
        QFont font;
        font.setPointSize(17);
        label->setFont(font);
        label->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        OK = new QPushButton(Information);
        OK->setObjectName("OK");
        OK->setGeometry(QRect(350, 200, 56, 18));
        OK->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        retranslateUi(Information);
        QObject::connect(OK, &QPushButton::clicked, Information, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(Information);
    } // setupUi

    void retranslateUi(QWidget *Information)
    {
        Information->setWindowTitle(QCoreApplication::translate("Information", "Form", nullptr));
        label->setText(QCoreApplication::translate("Information", "<html><head/><body><p align=\"center\">\345\274\200\345\217\221\344\272\272\345\221\230\344\277\241\346\201\257\357\274\232\351\231\210\350\276\276</p><p align=\"center\">\345\255\246\345\217\267\357\274\2322023414290103</p></body></html>", nullptr));
        OK->setText(QCoreApplication::translate("Information", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Information: public Ui_Information {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMATION_H
