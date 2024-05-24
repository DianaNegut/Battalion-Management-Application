#include "database.h"
#include <QtCore>
#include<QCoreApplication>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

DataBase *DataBase::instance=nullptr;

DataBase &DataBase::getInstance()
{
    if(!instance)
        instance=new DataBase();
    return *instance;
}

void DataBase::destroyDatabase()
{
    if(instance)
    {
        delete instance;
        instance=nullptr;
    }
}

DataBase::DataBase()
{

}

void DataBase::ConnectDB()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    QString serverName="DESKTOP-J2E60KF";
    QString dataBase="MANAGEMENTUL_BATALIOANELOR";
    QString connectionString = QString("DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(serverName).arg(dataBase);
    db.setDatabaseName(connectionString);
    if (!db.open())
    {
         qInfo()<<"EROARE TO CONNECT TO DATABASE"<<db.lastError().text();
    }
    else
         qInfo()<<"CONNECTED TO DATABASE";
    this->db=db;
}
