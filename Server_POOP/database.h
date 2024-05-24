#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
class DataBase
{
private:
    QSqlDatabase db;
    static DataBase *instance;
    DataBase();


public:


    static DataBase& getInstance();
    void ConnectDB();
    void destroyDatabase();
    QSqlDatabase getDataBase(){return db;}
    // ~DataBase();
};

#endif // DATABASE_H
