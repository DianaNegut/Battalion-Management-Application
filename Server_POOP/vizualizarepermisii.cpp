#include "vizualizarepermisii.h"

vizualizarePermisii::vizualizarePermisii(QString username) {
    this->username=username;
}

int vizualizarePermisii::whoami()
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

QString vizualizarePermisii::getPrenume()
{
    QSqlQuery query;
    QString output;
    if(whoami()==1)
    {
        query.prepare("select Prenume from COMANDANT_COMPANIE where Username='"+this->username+"'");
        if (query.exec())
        {
            while (query.next())
            {
                output+=query.value(0).toString();
            }
        }
        return output;
    }
    else if(whoami()==2)
    {
        query.prepare("select Prenume from COMANDANT_BATALION where Username='"+this->username+"'");
        if (query.exec())
        {
            while (query.next())
            {
                output+=query.value(0).toString();
            }
        }
        return output;
    }
    else if(whoami()==3)
    {
        query.prepare("select Prenume from INDRUMATOR_GRUPA where Username='"+this->username+"'");
        if (query.exec())
        {
            while (query.next())
            {
                output+=query.value(0).toString();
            }
        }
        return output;
    }
     return output;
}

QString vizualizarePermisii::getNume()
{
    QSqlQuery query;
    QString output;
    if(whoami()==1)
    {
        query.prepare("select Nume from COMANDANT_COMPANIE where Username='"+this->username+"'");
        if (query.exec())
        {
            while (query.next())
            {
                output+=query.value(0).toString();
            }
        }
        return output;
    }
    else if(whoami()==2)
    {
        query.prepare("select Nume from COMANDANT_BATALION where Username='"+this->username+"'");
        if (query.exec())
        {
            while (query.next())
            {
                output+=query.value(0).toString();
            }
        }
        return output;
    }
    else if(whoami()==3)
    {
        query.prepare("select Nume from INDRUMATOR_GRUPA where Username='"+this->username+"'");
        if (query.exec())
        {
            while (query.next())
            {
                output+=query.value(0).toString();
            }
        }
        return output;
    }

     return output;
}

QString vizualizarePermisii::getCompanie()
{
    QSqlQuery query;
    QString output;
    if(whoami()==1)
    {
        query.prepare("select COMPANIE from COMANDANT_COMPANIE where Username='"+this->username+"'");
        if (query.exec())
        {
            while (query.next())
            {
                output+=query.value(0).toString();
            }
        }
        return output;
    }
    else if(whoami()==2)
    {

        return output;
    }
    else if(whoami()==3)
    {

        return output;
    }
    return output;
}

QString vizualizarePermisii::getBatalion()
{
    QSqlQuery query;
    QString output;
    if(whoami()==1)
    {
        query.prepare("select BATALION from COMANDANT_COMPANIE where Username='"+this->username+"'");
        if (query.exec())
        {
            while (query.next())
            {
                output+=query.value(0).toString();
            }
        }
        return output;
    }
    else if(whoami()==2)
    {
        query.prepare("select BATALION from COMANDANT_BATALION where Username='"+this->username+"'");
        if (query.exec())
        {
            while (query.next())
            {
                output+=query.value(0).toString();
            }
        }
        return output;
    }
    else if(whoami()==3)
    {

        return output;
    }

    return output;
}

QString vizualizarePermisii::getAnStudiu()
{
    QSqlQuery query;
    QString output;
    if(whoami()==1)
    {
        query.prepare("select AN_STUDIU from COMANDANT_COMPANIE where Username='"+this->username+"'");
        if (query.exec())
        {
            while (query.next())
            {
                output+=query.value(0).toString();
            }
        }
        return output;
    }
    else if(whoami()==2)
    {
        query.prepare("select AN_STUDIU from COMANDANT_BATALION where Username='"+this->username+"'");
        if (query.exec())
        {
            while (query.next())
            {
                output+=query.value(0).toString();
            }
        }
        return output;
    }
    else if(whoami()==3)
    {

        return output;
    }

    return output;
}


void vizualizarePermisii::createMessage()
{

    this->Message="13";
    QString output;
    if(whoami()==1)
    {
        QSqlQuery query;
        QString output;
        query.prepare("select IDPERMISIE, NUME,PRENUME FROM PERMISII WHERE COMPANIE= :Companie AND BATALION= :Batalion ");
        query.bindValue(":Companie", this->getCompanie());
         qInfo()<<"Comapnie: "<<this->getCompanie();
        query.bindValue(":Batalion", this->getBatalion());
         qInfo()<<"Batalion: "<<this->getBatalion();

         qInfo()<<"URMEAZA SA EXECUTI CAUTAREA DE PERMISII";
        if (query.exec())
        {
            while (query.next())
            {
                output+="|";
                output+=query.value(0).toString();
                output+="|";
                output+=query.value(1).toString();
                output+="|";
                output+=query.value(2).toString();



            }
        }
        this->Message+=output.toUtf8();
    }
    else if (whoami()==2)
    {
        QString append="|Nu aveti drepturi sa faceti aceasta actiune!";
        this->Message+=append.toUtf8();
    }
    else if (whoami()==3)
    {
        QString append="|Nu aveti drepturi sa faceti aceasta actiune!";
        this->Message+=append.toUtf8();
    }



}






void vizualizarePermisii::writeOnSocket(QTcpSocket* socket,DataBase db)
{
    db.getDataBase().open();
    createMessage();
    db.getDataBase().close();
    socket->write(Message);
}

