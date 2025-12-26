#include "patienteditview.h"
#include "ui_patienteditview.h"
#include<QSqlTableModel>
#include "idatabase.h"
#include "masterview.h"
#include<QDebug>
// PatientEditView::PatientEditView(QWidget *parent ,int index)
//     : QWidget(parent)
//     , ui(new Ui::PatientEditView)
// {
//     ui->setupUi(this);
//     qDebug()<<"草泥马1";
//     dataMapper=new QDataWidgetMapper();
//     qDebug()<<"草泥马2";
//     QSqlTableModel *tabModel=IDatabase::getInstance().patientTabModel;
//     qDebug()<<"草泥马3";
//     dataMapper->setModel(IDatabase::getInstance().patientTabModel);
//     qDebug()<<"草泥马4";
//     dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
//     qDebug()<<"草泥马5";
//     dataMapper->addMapping(ui->IDInput,tabModel->fieldIndex("ID"));
//     dataMapper->addMapping(ui->nameInput,tabModel->fieldIndex("NAME"));
//     dataMapper->addMapping(ui->identificationInput,tabModel->fieldIndex("ID_CARD"));
//     dataMapper->addMapping(ui->sexInput,tabModel->fieldIndex("SEX"));
//     dataMapper->addMapping(ui->birthInput,tabModel->fieldIndex("DOB"));
//     dataMapper->addMapping(ui->heightInput,tabModel->fieldIndex("HEIGHT"));
//     dataMapper->addMapping(ui->weightInput,tabModel->fieldIndex("WEIGHT"));
//     dataMapper->addMapping(ui->phonrNumberInput,tabModel->fieldIndex("MOBILPHONE"));
//     dataMapper->addMapping(ui->createTime,tabModel->fieldIndex("CREATEDTIMESAMP"));

//     dataMapper->setCurrentIndex(index);

// }


PatientEditView::PatientEditView(QWidget *parent ,int index)
    : QWidget(parent)
    , ui(new Ui::PatientEditView)
{
    ui->setupUi(this);
    qDebug()<<"草泥马1";
    dataMapper=new QDataWidgetMapper(this); // 关键：给mapper设置父对象，避免内存泄漏
    qDebug()<<"草泥马2";
    QSqlTableModel *tabModel=IDatabase::getInstance().patientTabModel;
    qDebug()<<"草泥马3";
    dataMapper->setModel(tabModel);
    qDebug()<<"草泥马4";
    // 临时改为手动提交，避免AutoSubmit失效
    dataMapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    qDebug()<<"草泥马5";

    // 核对字段名！必须和数据库表完全一致（比如MOBILPHONE是否是MOBILEPHONE）
    dataMapper->addMapping(ui->IDInput,tabModel->fieldIndex("ID"));
    dataMapper->addMapping(ui->nameInput,tabModel->fieldIndex("NAME")); // 核心必填字段
    dataMapper->addMapping(ui->identificationInput,tabModel->fieldIndex("ID_CARD"));
    dataMapper->addMapping(ui->sexInput,tabModel->fieldIndex("SEX"));
    dataMapper->addMapping(ui->birthInput,tabModel->fieldIndex("DOB"));
    dataMapper->addMapping(ui->heightInput,tabModel->fieldIndex("HEIGHT"));
    dataMapper->addMapping(ui->weightInput,tabModel->fieldIndex("WEIGHT"));
    // 修正拼写错误：phonrNumberInput → phoneNumberInput（UI控件名也要改！）
    dataMapper->addMapping(ui->phonrNumberInput,tabModel->fieldIndex("MOBILPHONE"));
    dataMapper->addMapping(ui->createTime,tabModel->fieldIndex("CREATEDTIMESAMP"));

    dataMapper->setCurrentIndex(index);
    qDebug()<<"映射完成，当前行："<<index;
}

// 修复保存按钮：先提交mapper，再提交模型
void PatientEditView::on_btSave_clicked()
{
    // 1. 手动提交mapper的控件值到模型（关键！）
    dataMapper->submit();
    qDebug()<<"mapper提交完成";

    // 2. 提交模型到数据库
    bool ok = IDatabase::getInstance().submitPatientEdit();
    if(ok){
        qDebug()<<"数据写入数据库成功";
        emit goPreviousView();
    }else{
        qDebug()<<"写入失败："<<IDatabase::getInstance().patientTabModel->lastError().text();
        // 回滚
        IDatabase::getInstance().revertPatientEdit();
    }
}









PatientEditView::~PatientEditView()
{
    delete ui;
}

// void PatientEditView::on_btSave_clicked()
// {
//     IDatabase::getInstance().submitPatientEdit();
//     emit goPreviousView();
// }


void PatientEditView::on_btCancel_clicked()
{
    IDatabase::getInstance().revertPatientEdit();
    emit goPreviousView();
}

