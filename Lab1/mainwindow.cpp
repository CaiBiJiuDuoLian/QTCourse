#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<math.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    digitBTNs={
        {Qt::Key_0,ui->btnNum0},
        {Qt::Key_1,ui->btnNum1},
        {Qt::Key_2,ui->btnNum2},
        {Qt::Key_3,ui->btnNum3},
        {Qt::Key_4,ui->btnNum4},
        {Qt::Key_5,ui->btnNum5},
        {Qt::Key_6,ui->btnNum6},
        {Qt::Key_7,ui->btnNum7},
        {Qt::Key_8,ui->btnNum8},
        {Qt::Key_9,ui->btnNum9},
               };

    foreach(auto btn,digitBTNs)
    connect(btn,SIGNAL(clicked()),this,SLOT(btnNumClicked()));

    connect(ui->btnMultiple,SIGNAL(clicked()),this,SLOT(binaryOperatorClicked()));
    connect(ui->btnDivide,SIGNAL(clicked()),this,SLOT(binaryOperatorClicked()));
    connect(ui->btnAdd,SIGNAL(clicked()),this,SLOT(binaryOperatorClicked()));
    connect(ui->btnSubtract,SIGNAL(clicked()),this,SLOT(binaryOperatorClicked()));

    connect(ui->btnPercentage,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnCountdown,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSquare,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSqrt,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::calculation(bool *ok)
{
    double result=0;
    if(operands.size()==2&&opcodes.size()>0){

        //取操作数
        double operand1=operands.front().toDouble();
        operands.pop_front();
        double operand2=operands.front().toDouble();
        operands.pop_front();

        //取操作符
        QString op=opcodes.front();
        opcodes.pop_front();

        if(op=="+"){
            result=operand1+operand2;
        }
        else if(op=="-"){
            result=operand1-operand2;
        }
        else if(op=="×"){
            result=operand1*operand2;
        }
        else if(op=="➗"){
            result=operand1/operand2;
        }
        operands.push_back(QString::number(result));

         //ui->statusbar->showMessage("calculation is in progress ");
     }

    else{
        //ui->statusbar->showMessage(QString("operands is %1,opcode is %2 ").arg(operands.size()).arg(opcodes.size()));
    }
    return QString::number(result);
}

//数字键盘逻辑
void MainWindow::btnNumClicked()
{
    QString digit=qobject_cast<QPushButton*>(sender())->text();

    if(digit=="0"&&operand=="0")
        digit="";
     else if(operand=="0"&&digit!="0")operand="";
    operand+=digit;
    ui->btnInput->setText(operand);
     ui->statusbar->showMessage(qobject_cast<QPushButton*>(sender())->text()+"btn clicked");

}

//双操作符逻辑
void MainWindow::binaryOperatorClicked()
{
    //ui->statusbar->showMessage("last operand"+operand);
    QString opcode=qobject_cast<QPushButton*>(sender())->text();
    ui->statusbar->showMessage(qobject_cast<QPushButton*>(sender())->text()+"btn clicked");
    if(operand!=""){
        operands.push_back(operand);
        operand="";
        opcodes.push_back(opcode);
        opcode="";
    }

    QString result=calculation();
    ui->btnInput->setText(result);
}

//单操作符逻辑
void MainWindow::btnUnaryOperatorClicked()
{
    if(operand!=""){
        double result=operand.toDouble();
        operand="";
        QString op =qobject_cast<QPushButton*>(sender())->text();

        if(op=="%")
            result/=100.0;
        else if(op=="1/x")
            result=1/result;
        else if(op=="x^2")
            result*=result;
        else if(op=="√x")
            result=sqrt(result);

        //operands.push_back(QString::number(result));
         operand=QString::number(result);
        ui->btnInput->setText(QString::number(result));
    }
}

//小数点逻辑
void MainWindow::on_btnPoint_clicked()
{

    if(!operand.contains(".")&&operand!="")
        operand+=qobject_cast<QPushButton *>(sender())->text();
     ui->btnInput->setText(operand);
}


//删除键逻辑
void MainWindow::on_btnDelete_clicked()
{
    operand=operand.left(operand.length()-1);
    ui->btnInput->setText(operand);
}

//C/CE清除键逻辑
void MainWindow::on_btnC_clicked()
{
    operand.clear();
    ui->btnInput->setText(operand);
}

//等于号逻辑
void MainWindow::on_btnEqual_clicked()
{
    // if(operand!=""){
    //     operands.push_back(operand);//推进栈
    //     operand="";
    //     QString result=calculation();
    //     ui->btnInput->setText(result);
    // }
    if(operand!=""){
        operands.push_back(operand);
        operand="";
    }

    QString result=calculation();
    ui->btnInput->setText(result);
    operand=result;
     //ui->btnInput->setText(operand);
    operands.pop_front();
        }

//CE清除逻辑
void MainWindow::on_btnCE_clicked()
{
    operand.clear();
    ui->btnInput->setText(operand);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    foreach(auto btnKey,digitBTNs.keys())
    {
        if(event->key()==btnKey)
            digitBTNs[btnKey]->animateClick();
    }
    if(event->key()==Qt::Key_Backspace)
        ui->btnDelete->clicked();
    else if(event->key()==Qt::Key_Plus)
        ui->btnAdd->clicked();
    else if(event->key()==Qt::Key_Minus)
        ui->btnSubtract->clicked();
    else if(event->key()==Qt::Key_Asterisk)
        ui->btnMultiple->clicked();
    else if(event->key()==Qt::Key_Slash)
        ui->btnDivide->clicked();
    else if(event->key()==Qt::Key_Percent)
        ui->btnPercentage->clicked();
    else if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        ui->btnEqual->clicked();
    }

}


void MainWindow::on_btnAddSubtract_clicked()
{
    if(operand.isEmpty()){
        operand=ui->btnInput->text();

    }
    else if(operand.startsWith('-')){
        operand=operand.mid(1);
        if(operand=="0")
            operand="0";
    }
    else if (operand!="0"){
        operand="-"+operand;
    }
    ui->btnInput->setText(operand);
}

