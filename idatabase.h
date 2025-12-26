#ifndef IDATABASE_H
#define IDATABASE_H

#include <QObject>
#include<QtSql>
#include<QSqlDatabase>
#include<QDataWidgetMapper>

class IDatabase : public QObject
{
    Q_OBJECT
public:
    static IDatabase &getInstance(){
        static IDatabase instance;
        return instance;
    }

    // 禁用拷贝构造和赋值
    IDatabase(const IDatabase&) = delete;
    IDatabase& operator=(const IDatabase&) = delete;

    // 成员变量声明（需public或提供getter）
    QSqlTableModel *patientTabModel = nullptr;
    QItemSelectionModel *thePatientSelection = nullptr;

    QString userLogin(QString userName,QString password);

private:
      explicit IDatabase(QObject *parent = nullptr);
      QSqlDatabase database;
       void ininDatabase();
  public:
      bool initPatientModel();

      int addNewPatient();
      bool searchPatient(QString filter);
      bool deleteCurrentPatient();
      bool submitPatientEdit();
      void revertPatientEdit();



signals:



};

#endif // IDATABASE_H
