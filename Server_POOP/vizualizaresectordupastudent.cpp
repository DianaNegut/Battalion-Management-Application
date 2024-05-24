#include "vizualizaresectordupastudent.h"

VizualizareSectorDupaStudent::VizualizareSectorDupaStudent(QString Nume,QString Prenume,QString AnStudiu, QString Companie, QString Batalion, QString Pluton )
{
    this->Prenume=Prenume;
    this->Nume=Nume;
    this->AnStudiu=AnStudiu;
    this->Batalion=Batalion;
    this->Companie=Companie;
    this->Pluton=Pluton;

     qInfo() <<this->Nume<<" "<<this->Prenume<<" "<<this->AnStudiu<<" "<<this->Batalion<<" "<<this->Companie<<" "<<this->Pluton;
}

QString searchSector(QString Nume, QString Prenume,QString AnStudiu, QString Companie, QString Batalion, QString Pluton)
{
    QSqlQuery query;
    QString output="";

    query.prepare("select DENUMIRE_SECTOR from SECTOARE where NUME='"+Nume+"' and PRENUME='"+Prenume+"' and AnStudiu='"+AnStudiu+"' and Companie='"+Companie+"' and BATALION='"+Batalion+"' and PLUTON='"+Pluton+"'");
        if (query.exec())
        {
            while (query.next())
            {
                output+=query.value(0).toString();
            }
        }

    return output;
}


void VizualizareSectorDupaStudent::createMessage()
{
    this->Message="3|";


    if (searchSector(this->Nume,this->Prenume, this->AnStudiu, this->Companie, this->Batalion, this->Pluton)=="")
    {
        this->Message+="0";
    }
    else {
        this->Message+=searchSector(this->Nume,this->Prenume, this->AnStudiu, this->Companie, this->Batalion, this->Pluton).toUtf8();
    }


}
void VizualizareSectorDupaStudent::writeOnSocket(QTcpSocket* socket,DataBase db)
{
    db.getDataBase().open();
    createMessage();
    db.getDataBase().close();
    socket->write(Message);
}
