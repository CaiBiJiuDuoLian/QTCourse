#include "masterview.h"
#include "ui_masterview.h"
#include<QDebug>
#include"idatabase.h"
MasterView::MasterView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MasterView)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    goLoginView();
    IDatabase::getInstance();
}

MasterView::~MasterView()
{
    delete ui;
}

void MasterView::goLoginView()
{
    loginView=new LoginView(this);
    pushWidgetToStackView(loginView);

    connect(loginView,SIGNAL(loginSuccess()),this,SLOT(goWelcomView()));

}

void MasterView::goWelcomView()
{
    welcomeView=new WelcomView(this);
    pushWidgetToStackView(welcomeView);
    connect(welcomeView,SIGNAL(goDoctorView()),this,SLOT(goDoctorView()));
    connect(welcomeView,SIGNAL(goPatientView()),this,SLOT(goPatientView()));
    connect(welcomeView,SIGNAL(goDepartmentView()),this,SLOT(goDepartmentView()));
}

void MasterView::goDoctorView()
{
    doctorView=new DoctorView(this);
    pushWidgetToStackView(doctorView);
}

void MasterView::goDepartmentView()
{
    departmentView=new DepartmentView(this);
    pushWidgetToStackView(departmentView);
}

// void MasterView::goPatientView()
// {
//     patientView=new PatientView(this);
//     pushWidgetToStackView(patientView);
//     connect(patientView,SIGNAL(goPatientEditView(int)),this,SLOT(goPatientEditView(int)));
// }


void MasterView::goPatientView()
{
    qDebug() << "===== 进入患者管理 =====";
    patientView=new PatientView(this);
    qDebug() << "PatientView 创建成功";
    pushWidgetToStackView(patientView);
    qDebug() << "PatientView 加入栈成功";
    connect(patientView,SIGNAL(goPatientEditView(int)),this,SLOT(goPatientEditView(int)));
    qDebug() << "信号连接成功";
}







void MasterView::goPatientEditView(int rowNo)
{
    qDebug()<<"草泥马";
    patientEditView=new PatientEditView(this,rowNo);
    qDebug()<<"怎么不行";
    pushWidgetToStackView(patientEditView);
    qDebug()<<"草泥马";
    connect(patientEditView,SIGNAL(goPreviousView()),this,SLOT(goPreviousView()));
}

void MasterView::goPreviousView()
{
    qDebug()<< "test";
    int count=ui->stackedWidget->count();
    if(count>1){
        ui->stackedWidget->setCurrentIndex(count-2);
        //on_stackedWidget_currentChanged(1);
        ui->labelTitle->setText(ui->stackedWidget->currentWidget()->windowTitle());
        QWidget *widget= ui->stackedWidget->widget(count-1);
        ui->stackedWidget->removeWidget(widget);
        delete widget;
    }
}

void MasterView::pushWidgetToStackView(QWidget *widget)
{
    ui->stackedWidget->addWidget(widget);
    int count=ui->stackedWidget->count();
    ui->stackedWidget->setCurrentIndex(count -1);
    ui->labelTitle->setText(widget->windowTitle());
}

void MasterView::on_btBack_clicked()
{
    goPreviousView();
}


void MasterView::on_stackedWidget_currentChanged(int arg1)
{
    qDebug()<< "why";
    int count =ui->stackedWidget->count();
    if(count>1)
        ui->btBack->setEnabled(true);
    else
        ui->btBack->setEnabled(false);
    QString title=ui->stackedWidget->currentWidget()->windowTitle();
    if(title=="欢迎"){
        ui->btLogout->setEnabled(true);
        ui->btBack->setEnabled(false);
    }
    else
        ui->btLogout->setEnabled(false);
    if(title=="登录"){
        ui->btBack->setEnabled(false);
    }
}


void MasterView::on_btLogout_clicked()
{
    goPreviousView();
}

