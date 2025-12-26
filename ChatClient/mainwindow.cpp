#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QHostAddress>
#include<QJsonValue>
#include<QJsonObject>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->stackedWidget->setCurrentWidget(ui->LoginPage);
    m_chatClient=new ChatClient(this);
     connect(m_chatClient,&ChatClient::connected,this,&MainWindow::connectedToServer);
   //  connect(m_chatClient,&ChatClient::messageReceived,this,&MainWindow::messageReceived);
     connect(m_chatClient,&ChatClient::jsonReceived,this,&MainWindow::jsonReceived);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sendbtn_clicked()
{
    if(!ui->inputMessageLineEdit->text().isEmpty())
        m_chatClient->sendMessage(ui->inputMessageLineEdit->text());

 }

void MainWindow::on_Loginbtn_clicked()
{
    m_chatClient->connectToServer(QHostAddress(ui->ServerLineEdit->text()),1967);

}

void MainWindow::on_loginoutbtn_clicked()
{
    m_chatClient->disconnectFromHost();
     ui->stackedWidget->setCurrentWidget(ui->LoginPage);

    for( auto aItem :ui->userlistWidget->findItems(ui->userNameLineEdit->text(),Qt::MatchExactly)){
         qDebug("remove");
        ui->userlistWidget->removeItemWidget(aItem);
         delete aItem;
    }
}

void MainWindow::connectedToServer()
{
        ui->stackedWidget->setCurrentWidget(ui->ChatPage);
            m_chatClient->sendMessage(ui->userNameLineEdit->text(),"login");
}

void MainWindow::messageReceived(const QString &sender, const QString &text)
{
     ui->roomTextEdit->append(QString("%1 : %2 ").arg(sender,text));
}





void MainWindow::jsonReceived(const QJsonObject &docObj)
{
    const QJsonValue typeVal=docObj.value("type");
    if(typeVal.isNull()||!typeVal.isString()){
        return;
    }
    if(typeVal.toString().compare("message",Qt::CaseInsensitive)==0){
        const QJsonValue textVal=docObj.value("text");
        const QJsonValue senderVal=docObj.value("sender");
        if(textVal.isNull()||!textVal.isString()){
            return;
        }

        if(senderVal.isNull()||!senderVal.isString())
            return;

        // const QString text=textVal.toString().trimmed();
        // if(text.isEmpty()){
        //     return;

        // }


        messageReceived(senderVal.toString(),textVal.toString());
       // QJsonObject message;
        // message[QStringLiteral("type")]="message";
        // message[QStringLiteral("text")]=text;
        // message[QStringLiteral("sender")]=sender->userName();
        // broadcast(message,sender);

    }
    else if(typeVal.toString().compare("newuser",Qt::CaseInsensitive)==0){
        const QJsonValue usernameVal=docObj.value("username");
        if(usernameVal.isNull()||!usernameVal.isString())
            return;

        //sender->setUserName(usernameVal.toString());
       // QJsonObject connectedMessage;
        //connectedMessage["type"]="newuser";
       // connectedMessage["username"]=usernameVal.toString();
       // broadcast(connectedMessage,sender);

        userJoined(usernameVal.toString());

    }
    else if(typeVal.toString().compare("userdisconnected",Qt::CaseInsensitive)==0){
        const QJsonValue usernameVal=docObj.value("username");
        if(usernameVal.isNull()||!usernameVal.isString())
            return;
        userLeft(usernameVal.toString());
    }
    else if(typeVal.toString().compare("userlist",
                                          Qt::CaseInsensitive)==0){
        const QJsonValue  userlistVal=docObj.value("userlist");
        if(userlistVal.isNull()||!userlistVal.isArray())
            return;
        qDebug()<<userlistVal.toVariant().toStringList();
        userListReceived(userlistVal.toVariant().toStringList());
    }

}

void MainWindow::userJoined(const QString &user)
{
    ui->userlistWidget->addItem(user);
}

void MainWindow::userLeft(const QString &user)
{
    for( auto aItem :ui->userlistWidget->findItems(user,Qt::MatchExactly)){
        qDebug("remove");
        ui->userlistWidget->removeItemWidget(aItem);
        delete aItem;
    }
}

void MainWindow::userListReceived(const QStringList &list)
{
    ui->userlistWidget->clear();
    ui->userlistWidget->addItems(list);
}

























