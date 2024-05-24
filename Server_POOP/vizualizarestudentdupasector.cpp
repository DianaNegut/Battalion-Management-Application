#include "vizualizarestudentdupasector.h"

VizualizareStudentDupaSector::VizualizareStudentDupaSector(QString NumeSector)
{
    this->NumeSector=NumeSector;
}

QString searchStudent(QString NumeSector)
{
    QSqlQuery query;
    QString output="";


    query.prepare("select Nume, Prenume, AnStudiu, Companie, Batalion from SECTOARE where DENUMIRE_SECTOR='"+NumeSector+"'");
    if (query.exec())
    {
        while (query.next())
        {
            output+=query.value(0).toString();
            output+=" ";
            output+=query.value(1).toString();
            output+=" ";
            output+=query.value(2).toString();
            output+=" ";
            output+=query.value(3).toString();
            output+=" ";
            output+=query.value(4).toString();
            output+="|";
        }

    }

    return output;
}


void VizualizareStudentDupaSector::createMessage()
{
    this->Message="4|";
    if(searchStudent(this->NumeSector)=="")
    {
        this->Message+="0";
    }
    else
    {
        this->Message+=searchStudent(this->NumeSector).toUtf8();
    }



}
void VizualizareStudentDupaSector::writeOnSocket(QTcpSocket* socket,DataBase db)
{
    db.getDataBase().open();
    createMessage();
    db.getDataBase().close();
    socket->write(Message);
}
