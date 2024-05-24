#include "solicitarepermisie.h"
#include <QDate>


SolicitarePermisie::SolicitarePermisie(QString username, QString DataPlecare, QString OraPlecare, QString DataSosire, QString OraSosire) {
    this->DataPlecare=DataPlecare;
    this->DataSosire=DataSosire;
    this->OraPlecare=OraPlecare;
    this->OraSosire=OraSosire;
    this->username=username;
}
QString SolicitarePermisie::getNume()
{
    QSqlQuery query;
    QString output;
    query.prepare("select Nume from REGISTER_STUDENTI where Username='"+this->username+"'");
    if (query.exec())
    {
        while (query.next())
        {
            output+=query.value(0).toString();
        }
    }
    return output;
}
QString SolicitarePermisie::getPrenume()
{
    QSqlQuery query;
    QString output;
    query.prepare("select Prenume from REGISTER_STUDENTI where Username='"+this->username+"'");
    if (query.exec())
    {
        while (query.next())
        {
            output+=query.value(0).toString();
        }
    }
    return output;

}
QString SolicitarePermisie::getAn()
{
    QSqlQuery query;
    QString output;
    query.prepare("select AnStudiu from REGISTER_STUDENTI where Username='"+this->username+"'");
    if (query.exec())
    {
        while (query.next())
        {
            output+=query.value(0).toString();
        }
    }
    return output;

}
QString SolicitarePermisie::getCompanie()
{
    QSqlQuery query;
    QString output;
    query.prepare("select Companie from REGISTER_STUDENTI where Username='"+this->username+"'");
    if (query.exec())
    {
        while (query.next())
        {
            output+=query.value(0).toString();
        }
    }
    return output;

}
QString SolicitarePermisie::getPluton()
{
    QSqlQuery query;
    QString output;
    query.prepare("select PLUTON from REGISTER_STUDENTI where Username='"+this->username+"'");
    if (query.exec())
    {
        while (query.next())
        {
            output+=query.value(0).toString();
        }
    }
    return output;

}
QString SolicitarePermisie::getBatalion()
{
    QSqlQuery query;
    QString output;
    query.prepare("select Batalion from REGISTER_STUDENTI where Username='"+this->username+"'");
    if (query.exec())
    {
        while (query.next())
        {
            output+=query.value(0).toString();
        }
    }
    return output;

}



void SolicitarePermisie::createMessage()
{


    QString Nume, Prenume, Batalion, AnStudiu, Companie, Pluton;
    Nume=this->getNume();
    Prenume=this->getPrenume();
    Batalion=this->getBatalion();
    AnStudiu=this->getAn();
    Companie=this->getCompanie();
    Pluton=this->getPluton();

    QSqlQuery query;
    query.prepare("INSERT INTO PERMISII (NUME, PRENUME, COMPANIE,BATALION,AN_STUDIU,PLUTON,DATA_PLECARE,DATA_SOSIRE,ORA_PLECARE,ORA_SOSIRE) VALUES ('"+Nume+"', '"+Prenume+"', '"+Companie+"', '"+Batalion+"', '"+AnStudiu+"', '"+Pluton+"', '"+this->DataPlecare+"', '"+this->DataSosire+"', '"+this->OraPlecare+"', '"+this->OraSosire+"')");
    query.exec();
    query.prepare("select IDPERMISIE from Permisii where COMPANIE= :Companie and PLUTON= :Pluton and BATALION= :Batalion and AN_STUDIU= :AnStudiu and NUME= :Nume and PRENUME= :Prenume and DATA_SOSIRE= :DataS and DATA_PLECARE= :DataP and ORA_PLECARE= :OraP and ORA_SOSIRE= :OraS");
    query.bindValue(":Companie", Companie);
    query.bindValue(":Pluton", Pluton);
    query.bindValue(":Batalion", Batalion);
    query.bindValue(":AnStudiu", AnStudiu);
    query.bindValue(":Nume", Nume);
    query.bindValue(":Prenume", Prenume);
    query.bindValue(":DataS", DataSosire);
    query.bindValue(":DataP", DataPlecare);
    query.bindValue(":OraS", OraSosire);
    query.bindValue(":OraP", OraPlecare);
    QString idPermisie="";
    if (query.exec())
    {
        while (query.next())
        {
            idPermisie+=query.value(0).toString();
        }
    }

    query.prepare("update Permisii set STATUS_APROBARE=1 where COMPANIE= :Companie and PLUTON= :Pluton and BATALION= :Batalion and AN_STUDIU= :AnStudiu and NUME= :Nume and PRENUME= :Prenume and DATA_SOSIRE= :DataS and DATA_PLECARE= :DataP and ORA_PLECARE= :OraP and ORA_SOSIRE= :OraS");
    this->Message="9|1";
    //this->Message+=idPermisie.toUtf8();
    query.bindValue(":Companie", Companie);
    query.bindValue(":Pluton", Pluton);
    query.bindValue(":Batalion", Batalion);
    query.bindValue(":AnStudiu", AnStudiu);
    query.bindValue(":Nume", Nume);
    query.bindValue(":Prenume", Prenume);
    query.bindValue(":DataS", DataSosire);
    query.bindValue(":DataP", DataPlecare);
    query.bindValue(":OraS", OraSosire);
    query.bindValue(":OraP", OraPlecare);
    query.exec();






}
void SolicitarePermisie::writeOnSocket(QTcpSocket* socket,DataBase db)
{
    db.getDataBase().open();
    createMessage();
    db.getDataBase().close();
    socket->write(Message);
}

