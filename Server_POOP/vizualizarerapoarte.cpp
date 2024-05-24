#include "vizualizarerapoarte.h"

vizualizareRapoarte::vizualizareRapoarte(QString username) {
    this->username=username;
}


int vizualizareRapoarte::whoami()
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



QString vizualizareRapoarte::getPrenume()
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

QString vizualizareRapoarte::getNume()
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






void vizualizareRapoarte::createMessage()
{
    this->Message="11";
    QString rapoarte="";
    QSqlQuery query;
    QString id;
    if (this->whoami()==1)
    {
        query.prepare("select COMANDANT_COMPANIE.IDCADRUCOMPANIE from COMANDANT_COMPANIE WHERE username= :username");
        query.bindValue(":username", this->username);
        if (query.exec())
        {
            while (query.next())
            {
                id+=query.value(0).toString();

            }
        }

    }
    else if (this->whoami()==2)
    {
        query.prepare("select COMANDANT_BATALION.IDCADRUBATALION from COMANDANT_BATALION WHERE username= :username");
        query.bindValue(":username", this->username);
        if (query.exec())
        {
            while (query.next())
            {
                id+=query.value(0).toString();

            }
        }


    }
    else if (this->whoami()==3)
    {
        query.prepare("select INDRUMATOR_GRUPA.ID_INDRUMATOR_GRUPA from INDRUMATOR_GRUPA WHERE username= :username");
        query.bindValue(":username", this->username);
        if (query.exec())
        {
            while (query.next())
            {
                id+=query.value(0).toString();

            }
        }
    }
    else
        this->Message+="|0";




    if (this->whoami()==1)
    {
        query.prepare("select Rapoarte_Studenti.IDRAPORT from Rapoarte_Studenti where ID_COMANDANT_COMPANIE= :id");
        query.bindValue(":id", id);
        if (query.exec())
        {
            while (query.next())
            {
                rapoarte+="|";
                rapoarte+=query.value(0).toString();


            }
        }

    }
    else if (this->whoami()==2)
    {
        query.prepare("select Rapoarte_Studenti.IDRAPORT from Rapoarte_Studenti where ID_COMANDANT_BATALION= :id");
        query.bindValue(":id", id);
        if (query.exec())
        {
            while (query.next())
            {

                rapoarte+="|";
                rapoarte+=query.value(0).toString();


            }
        }


    }
    else if (this->whoami()==3)
    {
        query.prepare("select Rapoarte_Studenti.IDRAPORT from Rapoarte_Studenti where ID_INDRUMATOR_GRUPA= :id");
        query.bindValue(":username", this->username);
        if (query.exec())
        {
            while (query.next())
            {

                rapoarte+="|";
                rapoarte+=query.value(0).toString();

            }
        }
    }




    this->Message+=rapoarte.toUtf8();


}






void vizualizareRapoarte::writeOnSocket(QTcpSocket* socket,DataBase db)
{
    db.getDataBase().open();
    createMessage();
    db.getDataBase().close();
    socket->write(Message);
}



