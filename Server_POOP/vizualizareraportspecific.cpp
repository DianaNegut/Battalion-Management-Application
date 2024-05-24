#include "vizualizareraportspecific.h"

vizualizareRaportSpecific::vizualizareRaportSpecific(QString username, QString indexRaport) {
    this->indexRaport=indexRaport;
    this->username=username;
}


int vizualizareRaportSpecific::whoami()
{

    QSqlQuery query;
    query.prepare("select* from COMANDANT_COMPANIE where USERNAME='"+this->username+"'");
    query.exec();
    while(query.next())
    {
        return 1;
    }
    query.prepare("select* from COMANDANT_BATALION where USERNAME='"+this->username+"'");
    query.exec();
    while(query.next())
    {
        return 2;
    }
    query.prepare("select* from INDRUMATOR_GRUPA where USERNAME='"+this->username+"s");
    query.exec();
    while(query.next())
    {
        return 3;
    }
    return -1;


}

void vizualizareRaportSpecific::createMessage()
{
    this->Message="12|";
    QString continut="";
    QSqlQuery query;
    query.prepare("select Rapoarte_Studenti.CONTINUT_RAPORT from Rapoarte_Studenti where IDRAPORT= :idraport");
    query.bindValue(":idraport", this->indexRaport);
    if (query.exec())
    {
        while (query.next())
        {
            continut+=query.value(0).toString();

        }
    }
    this->Message+=continut.toUtf8();
    if (continut=="")
        this->Message+="0";




}



void vizualizareRaportSpecific::writeOnSocket(QTcpSocket* socket,DataBase db)
{
    db.getDataBase().open();
    createMessage();
    db.getDataBase().close();
    socket->write(Message);
}



