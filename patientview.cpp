#include "patientview.h"
#include "ui_patientview.h"
#include "idatabase.h"
#include<QDebug>
PatientView::PatientView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PatientView)
{
    ui->setupUi(this);
    qDebug()<<"第一处";
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    qDebug()<<"第er处";
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    qDebug()<<"第一三处";
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    qDebug()<<"第四处";
    ui->tableView->setAlternatingRowColors(true);

    IDatabase &iDatabase=IDatabase::getInstance();
    if(iDatabase.initPatientModel()){
        ui->tableView->setModel(iDatabase.patientTabModel);
        ui->tableView->setSelectionModel(iDatabase.thePatientSelection);
    }


}

PatientView::~PatientView()
{
    delete ui;
}

void PatientView::on_btAdd_clicked()
{
    qDebug()<<"真你妈礼品";
    int currow=IDatabase::getInstance().addNewPatient();
    qDebug()<<"我就不信不过";
    emit goPatientEditView(currow);
}


void PatientView::on_btSearch_clicked()
{
    QString filter =QString("name like '%%1%'").arg(ui->txtSearch->text());

    IDatabase::getInstance().searchPatient(filter);
}


void PatientView::on_btDelete_clicked()
{
    qDebug()<<"奇怪";
    IDatabase::getInstance().deleteCurrentPatient();
    qDebug()<<"为什么不能行";
}


void PatientView::on_btEdit_clicked()
{
    QModelIndex curIndex=
        IDatabase::getInstance().thePatientSelection->currentIndex();
    emit goPatientEditView(curIndex.row());
}

