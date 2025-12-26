#include "idatabase.h"
#include<QDebug>
#include<QUuid>
// void IDatabase::ininDatabase()
// {
//     database=QSqlDatabase::addDatabase("QSQLITE");
//     QString aFile="C:\\Users\\cd050\\Desktop\\Lab4a.db";
//     database.setDatabaseName(aFile);

//     if(!database.open()){
//         qDebug()<<"failed to open database";
//     }
//     else
//         qDebug()<<"open database is ok";
// }




void IDatabase::ininDatabase() // 修正拼写：inin → init
{
    // 避免重复添加连接
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        database = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        database = QSqlDatabase::addDatabase("QSQLITE");
    }

    QString aFile = "C:\\Users\\cd050\\Desktop\\Lab4a.db";
    database.setDatabaseName(aFile);

    if (!database.open()) {
        qDebug() << "打开数据库失败：" << database.lastError().text();
        // 可抛出异常或返回错误码
    } else {
        qDebug() << "数据库打开成功";
    }
}





// bool IDatabase::initPatientModel()
// {
//     patientTabModel=new QSqlTableModel(this,database);
//     patientTabModel->setTable("patient");
//     patientTabModel->setEditStrategy(QSqlTableModel ::OnManualSubmit);
//     patientTabModel->setSort(patientTabModel->fieldIndex("name"),Qt::AscendingOrder);
//     if(!(patientTabModel->select()))
//         return false;
//     thePatientSelection=new QItemSelectionModel(patientTabModel);
//     return true;
// }





bool IDatabase::initPatientModel()
{
    qDebug() << "===== 初始化患者模型 =====";
    if (!database.isOpen()) { // 先检查数据库是否打开
        qDebug() << "数据库未打开，初始化模型失败";
        return false;
    }
    patientTabModel=new QSqlTableModel(this,database);
    qDebug() << "patientTabModel 创建：" << patientTabModel; // 打印指针地址，若为0则崩溃
    patientTabModel->setTable("patient");
    qDebug() << "设置表为patient：" << patientTabModel->lastError().text();
    patientTabModel->setEditStrategy(QSqlTableModel ::OnManualSubmit);
    patientTabModel->setSort(patientTabModel->fieldIndex("name"),Qt::AscendingOrder);
    qDebug() << "排序字段：" << patientTabModel->fieldIndex("name"); // 若为-1，说明字段名错误
    if(!(patientTabModel->select())) {
        qDebug() << "查询patient表失败：" << patientTabModel->lastError().text();
        return false;
    }
    thePatientSelection=new QItemSelectionModel(patientTabModel);
    qDebug() << "thePatientSelection 创建：" << thePatientSelection;
    return true;
}













 int IDatabase::addNewPatient()
{
    patientTabModel->insertRow(patientTabModel->rowCount(),
                               QModelIndex());
    QModelIndex curIndex=patientTabModel->index(patientTabModel->rowCount()-1,
                                                  1);

    int curRecNo=curIndex.row();
    QSqlRecord curRec=patientTabModel->record(curRecNo);
    curRec.setValue("CREATEDTIMESAMP",QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    curRec.setValue("ID",QUuid::createUuid().toString(QUuid::WithoutBraces));
    patientTabModel->setRecord(curRecNo,curRec);
    return curIndex.row();

}



//1dgd
// int IDatabase::addNewPatient()
// {
//     // 1. 防护空模型
//     if (patientTabModel == nullptr) {
//         qDebug() << "patientTabModel 未初始化";
//         return -1;
//     }

//     // 2. 仅插入空行（核心：不赋值、不提交）
//     int newRow = patientTabModel->rowCount();
//     if (!patientTabModel->insertRow(newRow)) {
//         qDebug() << "插入空行失败：" << patientTabModel->lastError().text();
//         return -1;
//     }

//     // 3. 不设置任何字段！交给编辑页面填写
//     qDebug() << "新增空行成功，行号：" << newRow;
//     return newRow;
// }









// int IDatabase::addNewPatient()
// {
//     // 1. 检查模型是否初始化成功
//     if (patientTabModel == nullptr) {
//         qDebug() << "patientTabModel 未初始化";
//         return -1;
//     }

//     // 2. 插入新行（插在最后一行）
//     int newRow = patientTabModel->rowCount();
//     if (!patientTabModel->insertRow(newRow)) { // 检查插入是否成功
//         qDebug() << "插入行失败：" << patientTabModel->lastError().text();
//         return -1;
//     }

//     // 3. 获取新行的记录并赋值
//     QSqlRecord curRec = patientTabModel->record(newRow);
//     // 注意：字段名必须和数据库表完全一致（大小写敏感）
//     curRec.setValue("CREATEDTIMESAMP", QDateTime::currentDateTime().toString("yyyy-MM-dd"));
//     curRec.setValue("ID", QUuid::createUuid().toString(QUuid::WithoutBraces));
//     // 其他字段若有默认值可留空，由编辑界面补充

//     // 4. 设置记录到模型（仅修改内存）
//     if (!patientTabModel->setRecord(newRow, curRec)) {
//         qDebug() << "设置记录失败：" << patientTabModel->lastError().text();
//         patientTabModel->revertRow(newRow); // 回滚当前行的修改
//         return -1;
//     }

//     // 5. 提交所有未保存的修改（兼容低版本Qt，替代submitRow）
//     // 由于仅新增了一行，submitAll() 只会提交这行的修改
//     if (!patientTabModel->submitAll()) {
//         qDebug() << "提交新患者失败：" << patientTabModel->lastError().text();
//         patientTabModel->revertAll(); // 回滚所有未提交的修改
//         return -1;
//     }

//     // 6. 重新查询，确保模型与数据库同步
//     patientTabModel->select();

//     return newRow;
// }








// bool IDatabase::searchPatient(QString filter)
// {
//     patientTabModel->setFilter(filter);
//     return patientTabModel;

// }







bool IDatabase::searchPatient(QString filter)
{
    patientTabModel->setFilter(filter);
    bool ok = patientTabModel->select(); // 应用过滤并重新查询
    if (!ok) {
        qDebug() << "查询失败：" << patientTabModel->lastError().text();
    }
    return ok;
}















// bool IDatabase::deleteCurrentPatient()
// {
//     QModelIndex curIndex=thePatientSelection->currentIndex();
//     patientTabModel->removeRow(curIndex.row());
//     patientTabModel->submitAll();
//     patientTabModel->select();
//     return true;
// }





bool IDatabase::deleteCurrentPatient()
{
    QModelIndex curIndex = thePatientSelection->currentIndex();
    if (!curIndex.isValid()) { // 检查是否选中行
        qDebug() << "未选中要删除的患者";
        return false;
    }

    if (!patientTabModel->removeRow(curIndex.row())) { // 移除内存中的行
        qDebug() << "移除行失败：" << patientTabModel->lastError().text();
        return false;
    }

    if (!patientTabModel->submitAll()) { // 提交删除到数据库
        qDebug() << "删除提交失败：" << patientTabModel->lastError().text();
        patientTabModel->revertAll(); // 回滚
        return false;
    }

    patientTabModel->select(); // 重新查询，更新模型
    return true;
}











bool IDatabase::submitPatientEdit()
{
   return patientTabModel->submitAll();
}

void IDatabase::revertPatientEdit()
{

     patientTabModel->revertAll();
}


QString IDatabase::userLogin(QString userName, QString password)
{
    QSqlQuery query;
    query.prepare("select username,password from user where username= :ID");
    query.bindValue(":ID",userName);
    query.exec();
    if(query.first() && query.value("username").isValid()){
        QString passwd=query.value("password").toString();
        if(passwd==password){
            qDebug()<<"loginOK";
            return "loginOK";
        }
        else{
            qDebug()<<"wrongPassword";
            return "wrongPassword";
        }
    }
    else{
        qDebug()<<"no such user";
        return "wrongUsername";
    }
}

IDatabase::IDatabase(QObject *parent)
    : QObject{parent}
{
    ininDatabase();
}
