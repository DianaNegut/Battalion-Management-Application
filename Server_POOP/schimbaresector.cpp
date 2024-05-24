#include "schimbaresector.h"

schimbareSector::schimbareSector(QString Nume1,QString Prenume1,QString AnStudiu1, QString Companie1, QString Batalion1, QString Pluton1,
                                 QString Nume2,QString Prenume2,QString AnStudiu2, QString Companie2, QString Batalion2, QString Pluton2)
                                {
                                    this->Nume1=Nume1;
                                    this->Nume2=Nume2;
                                    this->AnStudiu1=AnStudiu1;
                                    this->AnStudiu2=AnStudiu2;
                                    this->Companie1=Companie1;
                                    this->Companie2=Companie2;
                                    this->Pluton1=Pluton1;
                                    this->Pluton2=Pluton2;
                                    this->Prenume1=Prenume1;
                                    this->Prenume2=Prenume2;
                                    this->Batalion1=Batalion1;
                                    this->Batalion2=Batalion2;
                                }


int schimbareSector::schimbare()
{
     QSqlQuery query;
     QString sector1="";
     query.prepare("select DENUMIRE_SECTOR from SECTOARE where Nume='"+this->Nume1+"' and Prenume='"+this->Prenume1+"' and AnStudiu='"+this->AnStudiu1+"' and Companie='"+this->Companie1+"' AND Batalion='"+this->Batalion1+"' and Pluton='"+this->Pluton1+"'");
     if (query.exec())
     {
         while (query.next())
         {
             sector1+=query.value(0).toString();
         }
     }

     if (sector1=="")
         return 0;
     QString sector2="";
     query.prepare("select DENUMIRE_SECTOR from SECTOARE where Nume='"+this->Nume2+"' and Prenume='"+this->Prenume2+"' and AnStudiu='"+this->AnStudiu2+"' and Companie='"+this->Companie2+"' AND Batalion='"+this->Batalion2+"' and Pluton='"+this->Pluton2+"'");
     if (query.exec())
     {
         while (query.next())
         {
             sector2+=query.value(0).toString();
         }
     }


     if (sector2=="")
         return 0;
      query.prepare("update SECTOARE set DENUMIRE_SECTOR='"+sector1+"' where Nume='"+this->Nume2+"' and Prenume='"+this->Prenume2+"' and AnStudiu='"+this->AnStudiu2+"' and Companie='"+this->Companie2+"' AND Batalion='"+this->Batalion2+"' and Pluton='"+this->Pluton2+"'");
      query.exec();
      query.prepare("update SECTOARE set DENUMIRE_SECTOR='"+sector2+"' where Nume='"+this->Nume1+"' and Prenume='"+this->Prenume1+"' and AnStudiu='"+this->AnStudiu1+"' and Companie='"+this->Companie1+"' AND Batalion='"+this->Batalion1+"' and Pluton='"+this->Pluton1+"'");
      query.exec();
      return 1;

}


void schimbareSector::createMessage()
 {

   this->Message="8|";
   if (this->schimbare()==0)
       this->Message=this->Message+"0";
   else
       this->Message=this->Message+"1";



}
 void schimbareSector::writeOnSocket(QTcpSocket* socket,DataBase db)
 {
  db.getDataBase().open();
  createMessage();
  db.getDataBase().close();
  socket->write(Message);
 }

