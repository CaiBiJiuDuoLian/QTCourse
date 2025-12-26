/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QStackedWidget *stackedWidget;
    QWidget *ChatPage;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout;
    QTextEdit *roomTextEdit;
    QListWidget *userlistWidget;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *inputMessageLineEdit;
    QPushButton *sendbtn;
    QPushButton *loginoutbtn;
    QWidget *LoginPage;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QFrame *loginFrame;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLineEdit *ServerLineEdit;
    QLabel *userNameLabel;
    QLineEdit *userNameLineEdit;
    QLabel *ServerLabel;
    QSpacerItem *verticalSpacer;
    QPushButton *Loginbtn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("#titleLabel{\n"
"    /* \350\203\214\346\231\257\357\274\232\346\265\205\350\223\235\346\270\220\345\217\230+\350\275\273\345\276\256\351\200\217\346\230\216\345\272\246\357\274\214\346\257\224\347\272\257\347\231\275\346\233\264\346\234\211\345\261\202\346\254\241\346\204\237 */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #f0f8ff, stop:1 #e8f4f8);\n"
"    /* \346\226\207\345\255\227\357\274\232\346\267\261\350\223\235\350\211\262\357\274\210\346\257\224\347\272\257\350\223\235\346\233\264\346\237\224\345\222\214\357\274\211\357\274\214\351\201\277\345\205\215\345\210\272\347\234\274 */\n"
"    color: #2c5aa0;\n"
"    border: none;\n"
"    /* \345\255\227\344\275\223\357\274\232\345\276\256\350\275\257\351\233\205\351\273\221+\345\212\240\347\262\227+22px\357\274\214\346\270\205\346\231\260\346\230\223\350\257\273 */\n"
"    font-family: \"Microsoft YaHei\", \"SimHei\", Arial;\n"
"    font-size: 22px;\n"
"    font-weight: 600; /* \345\215\212\345\212\240\347\262\227\357\274\214\346\257\224"
                        "bold\346\233\264\350\207\252\347\204\266 */\n"
"    /* \345\272\225\351\203\250\350\276\271\346\241\206\357\274\232\346\265\205\347\201\260\350\211\262\347\273\206\350\276\271\346\241\206\357\274\214\346\257\224\347\272\257\351\273\221\346\233\264\346\237\224\345\222\214\357\274\214\345\242\236\345\212\240\345\234\206\350\247\222\350\277\207\346\270\241 */\n"
"    border-bottom: 1px solid #d0d7e0;\n"
"    /* \345\206\205\350\276\271\350\267\235\357\274\232\344\270\212\344\270\2138px\357\274\214\345\267\246\345\217\2635px\357\274\214\346\226\207\345\255\227\345\236\202\347\233\264\345\261\205\344\270\255\346\233\264\350\210\222\351\200\202 */\n"
"    padding: 8px 5px;\n"
"    /* \345\217\257\351\200\211\357\274\232\346\226\207\345\255\227\345\267\246\345\257\271\351\275\220\357\274\210\351\273\230\350\256\244\357\274\211\357\274\214\345\246\202\351\234\200\345\261\205\344\270\255\345\212\240 text-align: center; */\n"
"    text-align: left;\n"
"}\n"
"#mainFrame{\n"
"border:none;\n"
"background:white;\n"
"}\n"
"#"
                        "loginFrame{\n"
"background: qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 #2e7d32,stop:1 #a5d6a7);\n"
"border:1px solid gray;\n"
"padding:10px;\n"
"border-radius:25px;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");

        verticalLayout->addWidget(titleLabel);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        ChatPage = new QWidget();
        ChatPage->setObjectName("ChatPage");
        gridLayout_5 = new QGridLayout(ChatPage);
        gridLayout_5->setObjectName("gridLayout_5");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        roomTextEdit = new QTextEdit(ChatPage);
        roomTextEdit->setObjectName("roomTextEdit");

        horizontalLayout->addWidget(roomTextEdit);

        userlistWidget = new QListWidget(ChatPage);
        userlistWidget->setObjectName("userlistWidget");
        userlistWidget->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(userlistWidget);


        gridLayout_5->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        inputMessageLineEdit = new QLineEdit(ChatPage);
        inputMessageLineEdit->setObjectName("inputMessageLineEdit");

        horizontalLayout_2->addWidget(inputMessageLineEdit);

        sendbtn = new QPushButton(ChatPage);
        sendbtn->setObjectName("sendbtn");

        horizontalLayout_2->addWidget(sendbtn);

        loginoutbtn = new QPushButton(ChatPage);
        loginoutbtn->setObjectName("loginoutbtn");

        horizontalLayout_2->addWidget(loginoutbtn);


        gridLayout_5->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        stackedWidget->addWidget(ChatPage);
        LoginPage = new QWidget();
        LoginPage->setObjectName("LoginPage");
        gridLayout_4 = new QGridLayout(LoginPage);
        gridLayout_4->setObjectName("gridLayout_4");
        verticalSpacer_3 = new QSpacerItem(20, 181, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(253, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 0, 1, 1);

        loginFrame = new QFrame(LoginPage);
        loginFrame->setObjectName("loginFrame");
        loginFrame->setFrameShape(QFrame::Shape::StyledPanel);
        loginFrame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_3 = new QGridLayout(loginFrame);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        ServerLineEdit = new QLineEdit(loginFrame);
        ServerLineEdit->setObjectName("ServerLineEdit");

        gridLayout->addWidget(ServerLineEdit, 0, 1, 1, 1);

        userNameLabel = new QLabel(loginFrame);
        userNameLabel->setObjectName("userNameLabel");

        gridLayout->addWidget(userNameLabel, 1, 0, 1, 1);

        userNameLineEdit = new QLineEdit(loginFrame);
        userNameLineEdit->setObjectName("userNameLineEdit");

        gridLayout->addWidget(userNameLineEdit, 1, 1, 1, 1);

        ServerLabel = new QLabel(loginFrame);
        ServerLabel->setObjectName("ServerLabel");

        gridLayout->addWidget(ServerLabel, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 1, 0, 1, 1);

        Loginbtn = new QPushButton(loginFrame);
        Loginbtn->setObjectName("Loginbtn");

        gridLayout_3->addWidget(Loginbtn, 2, 0, 1, 1);


        gridLayout_4->addWidget(loginFrame, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(253, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 181, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer_4, 2, 1, 1, 1);

        stackedWidget->addWidget(LoginPage);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\201\212\345\244\251\345\256\244\345\256\242\346\210\267\347\253\257", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "\351\231\210\350\276\276\347\232\204\350\201\212\345\244\251\345\256\244", nullptr));
        sendbtn->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        loginoutbtn->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        ServerLineEdit->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        userNameLabel->setText(QCoreApplication::translate("MainWindow", "\346\230\265\347\247\260", nullptr));
        userNameLineEdit->setText(QCoreApplication::translate("MainWindow", "\351\231\210\350\276\276", nullptr));
        ServerLabel->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", nullptr));
        Loginbtn->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225\350\201\212\345\244\251\345\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
