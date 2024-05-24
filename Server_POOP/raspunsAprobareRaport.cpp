#include "raspunsAprobareRaport.h"

raspunsAprobareRaport::raspunsAprobareRaport(QString username, QString raspuns,QString id_Raport ) {
    this->username=username;
    this->raspuns=raspuns;
    this->id_Raport=id_Raport;
}
int raspunsAprobareRaport::whoami()
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









void raspunsAprobareRaport::createMessage()
{

        this->Message="10|";

        QSqlQuery query;
        if (this->whoami()==1)
        {
            query.prepare("update Rapoarte_Studenti set APROBARE_CDT_CP= :raspuns WHERE IDRAPORT= :idRaport");
            query.bindValue(":raspuns", this->raspuns);
            query.bindValue(":idRaport", this->id_Raport);
            query.exec();
        }
        else if (this->whoami()==2)
        {
            query.prepare("update Rapoarte_Studenti set APROBARE_CDT_BAT= :raspuns WHERE IDRAPORT= :idRaport");
            query.bindValue(":raspuns", this->raspuns);
            query.bindValue(":idRaport", this->id_Raport);
            query.exec();
        }
        else if (this->whoami()==3)
        {
            query.prepare("update Rapoarte_Studenti set APROBARE_INDRUMATOR= :raspuns WHERE IDRAPORT= :idRaport");
            query.bindValue(":raspuns", this->raspuns);
            query.bindValue(":idRaport", this->id_Raport);
            query.exec();
        }
        else
            this->Message+="0";

        this->Message+="1";


}






void raspunsAprobareRaport::writeOnSocket(QTcpSocket* socket,DataBase db)
{
    db.getDataBase().open();
    createMessage();
    db.getDataBase().close();
    socket->write(Message);
}

