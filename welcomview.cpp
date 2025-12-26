#include "welcomview.h"
#include "ui_welcomview.h"

WelcomView::WelcomView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WelcomView)
{
    ui->setupUi(this);
}

WelcomView::~WelcomView()
{
    delete ui;
}

void WelcomView::on_pushButton_clicked()
{
    emit goDepartmentView();
}


void WelcomView::on_btDoctor_clicked()
{
    emit goDoctorView();
}


void WelcomView::on_btPatient_clicked()
{
   emit goPatientView();
}

