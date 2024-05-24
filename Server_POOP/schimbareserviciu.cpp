#include "schimbareserviciu.h"

schimbareServiciu::schimbareServiciu(QString Nume1,QString Prenume1,  QString Batalion1,QString Companie1, QString Pluton1,
                                     QString Nume2,QString Prenume2, QString Batalion2,QString Companie2,  QString Pluton2,QString Data1, QString Data2)
{
    this->Nume1=Nume1;
    this->Nume2=Nume2;
    this->Companie1=Companie1;
    this->Companie2=Companie2;
    this->Pluton1=Pluton1;
    this->Pluton2=Pluton2;
    this->Prenume1=Prenume1;
    this->Prenume2=Prenume2;
    this->Batalion1=Batalion1;
    this->Batalion2=Batalion2;
    this->Data1=Data1;
    this->Data2=Data2;
}
int determinareTipServiciu(QString Nume1,QString Prenume1,  QString Batalion1,QString Companie1, QString Pluton1, QString Data1)
{
    qInfo()<<"Esti in determinare tip serviciu!";
    QSqlQuery query;
    QString output;
    query.prepare("SELECT IDSERVICIU FROM SERVICII WHERE DATASERVICIU= '"+Data1+"' AND NUME_GSC='"+Nume1+"' AND PRENUME_GSC='"+Prenume1+"' AND BATALION_GSC='"+Batalion1+"' AND CP_GSC='"+Companie1+"' AND PLUTON_GSC='"+Pluton1+"' ");
    if (query.exec())
    {
        while (query.next())
        {
            output+=query.value(0).toString();
        }
    }
    qInfo()<<"GSC:"<<output;
    if(output!="")
        return 1;
    query.prepare("SELECT IDSERVICIU FROM SERVICII WHERE DATASERVICIU= '"+Data1+"' AND NUME_PAZA='"+Nume1+"' AND PRENUME_PAZA='"+Prenume1+"' AND BATALION_PAZA='"+Batalion1+"' AND CP_PAZA='"+Companie1+"' AND PLUTON_PAZA='"+Pluton1+"' ");
    if (query.exec())
    {
        while (query.next())
        {
            output+=query.value(0).toString();
        }
    }
    qInfo()<<"PAZA:"<<output;
    if(output!="")
        return 2;
    query.prepare("SELECT IDSERVICIU FROM SERVICII WHERE DATASERVICIU= '"+Data1+"' AND NUME_PLANTON1='"+Nume1+"' AND PRENUME_PLANTON1='"+Prenume1+"' AND BATALION_PLANTON1='"+Batalion1+"' AND CP_PLANTON1='"+Companie1+"' AND PLUTON_PLANTON1='"+Pluton1+"' ");
    if (query.exec())
    {
        while (query.next())
        {
            output+=query.value(0).toString();
        }
    }
    qInfo()<<"PL1:"<<output;
    if(output!="")
        return 3;
    query.prepare("SELECT IDSERVICIU FROM SERVICII WHERE DATASERVICIU= '"+Data1+"' AND NUME_PLANTON2='"+Nume1+"' AND PRENUME_PLANTON2='"+Prenume1+"' AND BATALION_PLANTON2='"+Batalion1+"' AND CP_PLANTON2='"+Companie1+"' AND PLUTON_PLANTON2='"+Pluton1+"' ");
    if (query.exec())
    {
        while (query.next())
        {
            output+=query.value(0).toString();
        }
    }
    qInfo()<<"PL2:"<<output;
    if(output!="")
        return 4;
    query.prepare("SELECT IDSERVICIU FROM SERVICII WHERE DATASERVICIU= '"+Data1+"' AND NUME_PLANTON3='"+Nume1+"' AND PRENUME_PLANTON3='"+Prenume1+"' AND BATALION_PLANTON3='"+Batalion1+"' AND CP_PLANTON3='"+Companie1+"' AND PLUTON_PLANTON3='"+Pluton1+"' ");
    if (query.exec())
    {
        while (query.next())
        {
            output+=query.value(0).toString();
        }
    }
    qInfo()<<"PL3:"<<output;
    if(output!="")
        return 5;

    return -1;

}
void schimbareServiciu::schimbare()
{
      qInfo()<<"esti in schimbare";
    if (determinareTipServiciu( Nume1, Prenume1,   Batalion1, Companie1,  Pluton1,  Data1)==1  &&determinareTipServiciu( Nume2, Prenume2,   Batalion2, Companie2,  Pluton2,  Data2)==1)
    {
        //gsc cu gsc
        QSqlQuery query;
        query.prepare("update servicii set NUME_GSC='"+this->Nume2+"',PRENUME_GSC='"+this->Prenume2+"',BATALION_GSC='"+this->Batalion2+"',CP_GSC='"+this->Companie2+"',PLUTON_GSC='"+this->Pluton2+"' WHERE DATASERVICIU='"+this->Data1+"'");
        query.exec();
        query.prepare("update servicii set NUME_GSC='"+this->Nume1+"',PRENUME_GSC='"+this->Prenume1+"',BATALION_GSC='"+this->Batalion1+"',CP_GSC='"+this->Companie1+"',PLUTON_GSC='"+this->Pluton1+"' WHERE DATASERVICIU='"+this->Data2+"'");
        query.exec();
    }

    else
        if (determinareTipServiciu( Nume1, Prenume1,   Batalion1, Companie1,  Pluton1,  Data1)==2 && determinareTipServiciu( Nume2, Prenume2,   Batalion2, Companie2,  Pluton2,  Data2)==2)
        {
            //paza cu paza
        qInfo()<<"nu e gsc cu gsc";
        QSqlQuery query;
        query.prepare("update servicii set NUME_PAZA='"+this->Nume2+"', PRENUME_PAZA='"+this->Prenume2+"',BATALION_PAZA='"+this->Batalion2+"',CP_PAZA='"+this->Companie2+"',PLUTON_PAZA='"+this->Pluton2+"' WHERE DATASERVICIU='"+this->Data1+"'");
        query.exec();
        query.prepare("update servicii set NUME_PAZA='"+this->Nume1+"', PRENUME_PAZA='"+this->Prenume1+"',BATALION_PAZA='"+this->Batalion1+"',CP_PAZA='"+this->Companie1+"',PLUTON_PAZA='"+this->Pluton1+"' WHERE DATASERVICIU='"+this->Data2+"'");
        query.exec();

        }
    else
        if (determinareTipServiciu( Nume1, Prenume1,   Batalion1, Companie1,  Pluton1,  Data1)==3 && determinareTipServiciu( Nume2, Prenume2,   Batalion2, Companie2,  Pluton2,  Data2)==3)
        {
            //planton1 cu planton1
            qInfo()<<"nu e paza cu paza";
            QSqlQuery query;
            query.prepare("update servicii set NUME_PLANTON1='"+this->Nume2+"',PRENUME_PLANTON1='"+this->Prenume2+"',BATALION_PLANTON1='"+this->Batalion2+"',CP_PLANTON1='"+this->Companie2+"',PLUTON_PLANTON1='"+this->Pluton2+"' WHERE DATASERVICIU='"+this->Data1+"'");
            query.exec();
            query.prepare("update servicii set NUME_PLANTON1='"+this->Nume1+"',PRENUME_PLANTON1='"+this->Prenume1+"',BATALION_PLANTON1='"+this->Batalion1+"',CP_PLANTON1='"+this->Companie1+"',PLUTON_PLANTON1='"+this->Pluton1+"' WHERE DATASERVICIU='"+this->Data2+"'");
            query.exec();

        }

        else
            if (determinareTipServiciu( Nume1, Prenume1,   Batalion1, Companie1,  Pluton1,  Data1)==4 && determinareTipServiciu( Nume2, Prenume2,   Batalion2, Companie2,  Pluton2,  Data2)==4)
            {
                //planton2 cu planton2
            qInfo()<<"nu e pl1 cu pl1";
            QSqlQuery query;
            query.prepare("update servicii set NUME_PLANTON2='"+this->Nume2+"',PRENUME_PLANTON2='"+this->Prenume2+"',BATALION_PLANTON2='"+this->Batalion2+"',CP_PLANTON2='"+this->Companie2+"',PLUTON_PLANTON2='"+this->Pluton2+"' WHERE DATASERVICIU='"+this->Data1+"'");
            query.exec();
            query.prepare("update servicii set NUME_PLANTON2='"+this->Nume1+"',PRENUME_PLANTON2='"+this->Prenume1+"',BATALION_PLANTON2='"+this->Batalion1+"',CP_PLANTON2='"+this->Companie1+"',PLUTON_PLANTON2='"+this->Pluton1+"' WHERE DATASERVICIU='"+this->Data2+"'");
            query.exec();

            }
        else if (determinareTipServiciu(Nume1, Prenume1, Batalion1, Companie1, Pluton1, Data1) == 5 &&
                 determinareTipServiciu(Nume2, Prenume2, Batalion2, Companie2, Pluton2, Data2) == 5) {
            // planton3 cu planton3
            qInfo() << "nu e pl2 cu pl2";
            QSqlQuery query;
            query.prepare("update servicii set NUME_PLANTON3='" + this->Nume2 + "', PRENUME_PLANTON3='" + this->Prenume2 + "', BATALION_PLANTON3='" + this->Batalion2 + "', CP_PLANTON3='" + this->Companie2 + "', PLUTON_PLANTON3='" + this->Pluton2 + "' WHERE DATASERVICIU='" + this->Data1 + "'");
            query.exec();
            query.prepare("update servicii set NUME_PLANTON3='" + this->Nume1 + "', PRENUME_PLANTON3='" + this->Prenume1 + "', BATALION_PLANTON3='" + this->Batalion1 + "', CP_PLANTON3='" + this->Companie1 + "', PLUTON_PLANTON3='" + this->Pluton1 + "' WHERE DATASERVICIU='" + this->Data2 + "'");
            query.exec();
        } else if (determinareTipServiciu(Nume1, Prenume1, Batalion1, Companie1, Pluton1, Data1) == 1 &&
                   determinareTipServiciu(Nume2, Prenume2, Batalion2, Companie2, Pluton2, Data2) == 2) {
            // gsc -> data2 cu paza -> data1
            qInfo() << "nu e pl3 cu pl3";
            QSqlQuery query;
            query.prepare("update servicii set NUME_GSC='" + this->Nume2 + "', PRENUME_GSC='" + this->Prenume2 + "', BATALION_GSC='" + this->Batalion2 + "', CP_GSC='" + this->Companie2 + "', PLUTON_GSC='" + this->Pluton2 + "' WHERE DATASERVICIU='" + this->Data1 + "'");
            query.exec();
            query.prepare("update servicii set NUME_PAZA='" + this->Nume1 + "', PRENUME_PAZA='" + this->Prenume1 + "', BATALION_PAZA='" + this->Batalion1 + "', CP_PAZA='" + this->Companie1 + "', PLUTON_PAZA='" + this->Pluton1 + "' WHERE DATASERVICIU='" + this->Data2 + "'");
            query.exec();
        } else if (determinareTipServiciu(Nume1, Prenume1, Batalion1, Companie1, Pluton1, Data1) == 1 &&
                   determinareTipServiciu(Nume2, Prenume2, Batalion2, Companie2, Pluton2, Data2) == 3) {
            // gsc cu planton1
            qInfo() << "nu e gsc cu paza";
            QSqlQuery query;
            query.prepare("update servicii set NUME_GSC='" + this->Nume2 + "', PRENUME_GSC='" + this->Prenume2 + "', BATALION_GSC='" + this->Batalion2 + "', CP_GSC='" + this->Companie2 + "', PLUTON_GSC='" + this->Pluton2 + "' WHERE DATASERVICIU='" + this->Data1 + "'");
            query.exec();
            query.prepare("update servicii set NUME_PLANTON1='" + this->Nume1 + "', PRENUME_PLANTON1='" + this->Prenume1 + "', BATALION_PLANTON1='" + this->Batalion1 + "', CP_PLANTON1='" + this->Companie1 + "', PLUTON_PLANTON1='" + this->Pluton1 + "' WHERE DATASERVICIU='" + this->Data2 + "'");
            query.exec();
        } else if (determinareTipServiciu(Nume1, Prenume1, Batalion1, Companie1, Pluton1, Data1) == 1 &&
                   determinareTipServiciu(Nume2, Prenume2, Batalion2, Companie2, Pluton2, Data2) == 4) {
            // gsc cu planton2
            qInfo() << "nu e gsc cu pl1";
            QSqlQuery query;
            query.prepare("update servicii set NUME_GSC='" + this->Nume2 + "', PRENUME_GSC='" + this->Prenume2 + "', BATALION_GSC='" + this->Batalion2 + "', CP_GSC='" + this->Companie2 + "', PLUTON_GSC='" + this->Pluton2 + "' WHERE DATASERVICIU='" + this->Data1 + "'");
            query.exec();
            query.prepare("update servicii set NUME_PLANTON2='" + this->Nume1 + "', PRENUME_PLANTON2='" + this->Prenume1 + "', BATALION_PLANTON2='" + this->Batalion1 + "', CP_PLANTON2='" + this->Companie1 + "', PLUTON_PLANTON2='" + this->Pluton1 + "' WHERE DATASERVICIU='" + this->Data2 + "'");
            query.exec();
        } else if (determinareTipServiciu(Nume1, Prenume1, Batalion1, Companie1, Pluton1, Data1) == 1 &&
                   determinareTipServiciu(Nume2, Prenume2, Batalion2, Companie2, Pluton2, Data2) == 5) {
            // gsc cu planton3
            qInfo() << "nu e gsc cu pl2";
            QSqlQuery query;
            query.prepare("update servicii set NUME_GSC='" + this->Nume2 + "', PRENUME_GSC='" + this->Prenume2 + "', BATALION_GSC='" + this->Batalion2 + "', CP_GSC='" + this->Companie2 + "', PLUTON_GSC='" + this->Pluton2 + "' WHERE DATASERVICIU='" + this->Data1 + "'");
            query.exec();
            query.prepare("update servicii set NUME_PLANTON3='" + this->Nume1 + "', PRENUME_PLANTON3='" + this->Prenume1 + "', BATALION_PLANTON3='" + this->Batalion1 + "', CP_PLANTON3='" + this->Companie1 + "', PLUTON_PLANTON3='" + this->Pluton1 + "' WHERE DATASERVICIU='" + this->Data2 + "'");
            query.exec();
        } else if (determinareTipServiciu(Nume1, Prenume1, Batalion1, Companie1, Pluton1, Data1) == 2 &&
                   determinareTipServiciu(Nume2, Prenume2, Batalion2, Companie2, Pluton2, Data2) == 1) {
            // paza cu gsc
            qInfo() << "nu e gsc cu pl3";
            QSqlQuery query;
            query.prepare("update servicii set NUME_PAZA='" + this->Nume2 + "', PRENUME_PAZA='" + this->Prenume2 + "', BATALION_PAZA='" + this->Batalion2 + "', CP_PAZA='" + this->Companie2 + "', PLUTON_PAZA='" + this->Pluton2 + "' WHERE DATASERVICIU='" + this->Data1 + "'");
            query.exec();
            query.prepare("update servicii set NUME_GSC='" + this->Nume1 + "', PRENUME_GSC='" + this->Prenume1 + "', BATALION_GSC='" + this->Batalion1 + "', CP_GSC='" + this->Companie1 + "', PLUTON_GSC='" + this->Pluton1 + "' WHERE DATASERVICIU='" + this->Data2 + "'");
            query.exec();

        }
        else
            if (determinareTipServiciu( Nume1, Prenume1,   Batalion1, Companie1,  Pluton1,  Data1)==2 && determinareTipServiciu( Nume2, Prenume2,   Batalion2, Companie2,  Pluton2,  Data2)==3)
            {
                //paza cu planton1
                QSqlQuery query;
                query.prepare("update servicii set NUME_PAZA='" + this->Nume2 + "', PRENUME_PAZA='" + this->Prenume2 + "', BATALION_PAZA='" + this->Batalion2+ "', CP_PAZA='" + this->Companie2 + "', PLUTON_PAZA='" + this->Pluton2 + "' WHERE DATASERVICIU='" + this->Data1 + "'");
                query.exec();
                query.prepare("update servicii set NUME_PLANTON1='" + this->Nume1 + "', PRENUME_PLANTON1='" + this->Prenume1 + "', BATALION_PLANTON1='" + this->Batalion1 + "', CP_PLANTON1='" + this->Companie1 + "', PLUTON_PLANTON1='" + this->Pluton1 + "' WHERE DATASERVICIU='" + this->Data2 + "'");
                query.exec();

            }
            else
                if (determinareTipServiciu( Nume1, Prenume1,   Batalion1, Companie1,  Pluton1,  Data1)==2 && determinareTipServiciu( Nume2, Prenume2,   Batalion2, Companie2,  Pluton2,  Data2)==4)
                {
                    //paza cu planton2
                    QSqlQuery query;
                    query.prepare("update servicii set NUME_PAZA='" + this->Nume2 + "', PRENUME_PAZA='" + this->Prenume2 + "', BATALION_PAZA='" + this->Batalion2 + "', CP_PAZA='" + this->Companie2 + "', PLUTON_PAZA='" + this->Pluton2 + "' WHERE DATASERVICIU='" + this->Data1 + "'");
                    query.exec();
                    query.prepare("update servicii set NUME_PLANTON2='"+this->Nume1+"',PRENUME_PLANTON2='"+this->Prenume1+"',BATALION_PLANTON2='"+this->Batalion1+"',CP_PLANTON2='"+this->Companie1+"',PLUTON_PLANTON2='"+this->Pluton1+"' WHERE DATASERVICIU='"+this->Data2+"'");
                    query.exec();

                }

                else
                    if (determinareTipServiciu( Nume1, Prenume1,   Batalion1, Companie1,  Pluton1,  Data1)==2 && determinareTipServiciu( Nume2, Prenume2,   Batalion2, Companie2,  Pluton2,  Data2)==5)
                    {
                        //paza cu planton3
                        QSqlQuery query;
                        query.prepare("update servicii set NUME_PAZA='" + this->Nume2 + "', PRENUME_PAZA='" + this->Prenume2 + "', BATALION_PAZA='" + this->Batalion2 + "', CP_PAZA='" + this->Companie2+ "', PLUTON_PAZA='" + this->Pluton2 + "' WHERE DATASERVICIU='" + this->Data1 + "'");
                        query.exec();
                        query.prepare("update servicii set NUME_PLANTON3='" + this->Nume1 + "', PRENUME_PLANTON3='" + this->Prenume1 + "', BATALION_PLANTON3='" + this->Batalion1 + "', CP_PLANTON3='" + this->Companie1 + "', PLUTON_PLANTON3='" + this->Pluton1 + "' WHERE DATASERVICIU='" + this->Data2 + "'");
                        query.exec();

                    }
                else
        if (determinareTipServiciu( Nume1, Prenume1,   Batalion1, Companie1,  Pluton1,  Data1)==3 && determinareTipServiciu( Nume2, Prenume2,   Batalion2, Companie2,  Pluton2,  Data2)==2)
        {
            //planton1 cu paza
            QSqlQuery query;
            query.prepare("update servicii set NUME_PLANTON1='"+this->Nume2+"',PRENUME_PLANTON1='"+this->Prenume2+"',BATALION_PLANTON1='"+this->Batalion2+"',CP_PLANTON1='"+this->Companie2+"',PLUTON_PLANTON1='"+this->Pluton2+"' WHERE DATASERVICIU='"+this->Data1+"'");
            query.exec();
            query.prepare("update servicii set NUME_PAZA='"+this->Nume1+"', PRENUME_PAZA='"+this->Prenume1+"',BATALION_PAZA='"+this->Batalion1+"',CP_PAZA='"+this->Companie1+"',PLUTON_PAZA='"+this->Pluton1+"' WHERE DATASERVICIU='"+this->Data2+"'");
            query.exec();
        }
        else
            if (determinareTipServiciu( Nume1, Prenume1,   Batalion1, Companie1,  Pluton1,  Data1)==3 && determinareTipServiciu( Nume2, Prenume2,   Batalion2, Companie2,  Pluton2,  Data2)==1)
            {
                //planton1 cu gsc
                QSqlQuery query;
                query.prepare("update servicii set NUME_PLANTON1='"+this->Nume2+"',PRENUME_PLANTON1='"+this->Prenume2+"',BATALION_PLANTON1='"+this->Batalion2+"',CP_PLANTON1='"+this->Companie2+"',PLUTON_PLANTON1='"+this->Pluton2+"' WHERE DATASERVICIU='"+this->Data1+"'");
                query.exec();
                query.prepare("update servicii set NUME_GSC='"+this->Nume1+"',PRENUME_GSC='"+this->Prenume1+"',BATALION_GSC='"+this->Batalion1+"',CP_GSC='"+this->Companie1+"',PLUTON_GSC='"+this->Pluton1+"' WHERE DATASERVICIU='"+this->Data2+"'");
                query.exec();

            }
            else
                if (determinareTipServiciu( Nume1, Prenume1,   Batalion1, Companie1,  Pluton1,  Data1)==3 && determinareTipServiciu( Nume2, Prenume2,   Batalion2, Companie2,  Pluton2,  Data2)==4)
                {
                    //planton1 cu planton2
                    QSqlQuery query;
                    query.prepare("update servicii set NUME_PLANTON1='"+this->Nume2+"',PRENUME_PLANTON1='"+this->Prenume2+"',BATALION_PLANTON1='"+this->Batalion2+"',CP_PLANTON1='"+this->Companie2+"',PLUTON_PLANTON1='"+this->Pluton2+"' WHERE DATASERVICIU='"+this->Data1+"'");
                    query.exec();
                    query.prepare("update servicii set NUME_PLANTON2='"+this->Nume1+"',PRENUME_PLANTON2='"+this->Prenume1+"',BATALION_PLANTON2='"+this->Batalion1+"',CP_PLANTON2='"+this->Companie1+"',PLUTON_PLANTON2='"+this->Pluton1+"' WHERE DATASERVICIU='"+this->Data2+"'");
                    query.exec();

                }

                else
                    if (determinareTipServiciu( Nume1, Prenume1,   Batalion1, Companie1,  Pluton1,  Data1)==3 && determinareTipServiciu( Nume2, Prenume2,   Batalion2, Companie2,  Pluton2,  Data2)==5)
                    {
                        //planton1 cu planton3
                        QSqlQuery query;
                        query.prepare("update servicii set NUME_PLANTON1='"+this->Nume2+"',PRENUME_PLANTON1='"+this->Prenume2+"',BATALION_PLANTON1='"+this->Batalion2+"',CP_PLANTON1='"+this->Companie2+"',PLUTON_PLANTON1='"+this->Pluton2+"' WHERE DATASERVICIU='"+this->Data1+"'");
                        query.exec();
                        query.prepare("update servicii set NUME_PLANTON3='" + this->Nume1 + "', PRENUME_PLANTON3='" + this->Prenume1 + "', BATALION_PLANTON3='" + this->Batalion1 + "', CP_PLANTON3='" + this->Companie1 + "', PLUTON_PLANTON3='" + this->Pluton1 + "' WHERE DATASERVICIU='" + this->Data2 + "'");
                        query.exec();

                    }
        if (determinareTipServiciu( Nume1, Prenume1,   Batalion1, Companie1,  Pluton1,  Data1)==4 && determinareTipServiciu( Nume2, Prenume2,   Batalion2, Companie2,  Pluton2,  Data2)==2)
        {
            //planton2 cu paza
            QSqlQuery query;
            query.prepare("update servicii set NUME_PLANTON2='"+this->Nume2+"',PRENUME_PLANTON2='"+this->Prenume2+"',BATALION_PLANTON2='"+this->Batalion2+"',CP_PLANTON2='"+this->Companie2+"',PLUTON_PLANTON2='"+this->Pluton2+"' WHERE DATASERVICIU='"+this->Data1+"'");
            query.exec();
            query.prepare("update servicii set NUME_PAZA='"+this->Nume1+"', PRENUME_PAZA='"+this->Prenume1+"',BATALION_PAZA='"+this->Batalion1+"',CP_PAZA='"+this->Companie1+"',PLUTON_PAZA='"+this->Pluton1+"' WHERE DATASERVICIU='"+this->Data2+"'");
            query.exec();

        }
        else
            if (determinareTipServiciu( Nume1, Prenume1,   Batalion1, Companie1,  Pluton1,  Data1)==4 ||determinareTipServiciu( Nume2, Prenume2,   Batalion2, Companie2,  Pluton2,  Data2)==1)
            {
                //planton2 cu gsc
                QSqlQuery query;
                query.prepare("update servicii set NUME_PLANTON2='"+this->Nume2+"',PRENUME_PLANTON2='"+this->Prenume2+"',BATALION_PLANTON2='"+this->Batalion2+"',CP_PLANTON2='"+this->Companie2+"',PLUTON_PLANTON2='"+this->Pluton2+"' WHERE DATASERVICIU='"+this->Data1+"'");
                query.exec();
                query.prepare("update servicii set NUME_GSC='"+this->Nume1+"',PRENUME_GSC='"+this->Prenume1+"',BATALION_GSC='"+this->Batalion1+"',CP_GSC='"+this->Companie1+"',PLUTON_GSC='"+this->Pluton1+"' WHERE DATASERVICIU='"+this->Data2+"'");
                query.exec();

            }
            else
                if (determinareTipServiciu( Nume1, Prenume1,   Batalion1, Companie1,  Pluton1,  Data1)==4 ||determinareTipServiciu( Nume2, Prenume2,   Batalion2, Companie2,  Pluton2,  Data2)==3)
                {
                    //planton2 cu planton1

                    QSqlQuery query;
                    query.prepare("update servicii set NUME_PLANTON2='"+this->Nume2+"',PRENUME_PLANTON2='"+this->Prenume2+"',BATALION_PLANTON2='"+this->Batalion2+"',CP_PLANTON2='"+this->Companie2+"',PLUTON_PLANTON2='"+this->Pluton2+"' WHERE DATASERVICIU='"+this->Data1+"'");
                    query.exec();
                    query.prepare("update servicii set NUME_PLANTON1='"+this->Nume1+"',PRENUME_PLANTON1='"+this->Prenume1+"',BATALION_PLANTON1='"+this->Batalion1+"',CP_PLANTON1='"+this->Companie1+"',PLUTON_PLANTON1='"+this->Pluton1+"' WHERE DATASERVICIU='"+this->Data2+"'");
                    query.exec();
                }

                else
                    if (determinareTipServiciu( Nume1, Prenume1,   Batalion1, Companie1,  Pluton1,  Data1)==4 ||determinareTipServiciu( Nume2, Prenume2,   Batalion2, Companie2,  Pluton2,  Data2)==5)
                    {
                        //planton2 cu planton3
                        QSqlQuery query;
                        query.prepare("update servicii set NUME_PLANTON2='"+this->Nume2+"',PRENUME_PLANTON2='"+this->Prenume2+"',BATALION_PLANTON2='"+this->Batalion2+"',CP_PLANTON2='"+this->Companie2+"',PLUTON_PLANTON2='"+this->Pluton2+"' WHERE DATASERVICIU='"+this->Data1+"'");
                        query.exec();
                        query.prepare("update servicii set NUME_PLANTON3='" + this->Nume1 + "', PRENUME_PLANTON3='" + this->Prenume1 + "', BATALION_PLANTON3='" + this->Batalion1 + "', CP_PLANTON3='" + this->Companie1 + "', PLUTON_PLANTON3='" + this->Pluton1 + "' WHERE DATASERVICIU='" + this->Data2 + "'");
                        query.exec();

                    }

        if (determinareTipServiciu( Nume1, Prenume1,   Batalion1, Companie1,  Pluton1,  Data1)==5 ||determinareTipServiciu( Nume2, Prenume2,   Batalion2, Companie2,  Pluton2,  Data2)==2)
        {
            //planton3 cu paza
            QSqlQuery query;
            query.prepare("update servicii set NUME_PLANTON3='" + this->Nume2 + "', PRENUME_PLANTON3='" + this->Prenume2 + "', BATALION_PLANTON3='" + this->Batalion2 + "', CP_PLANTON3='" + this->Companie2 + "', PLUTON_PLANTON3='" + this->Pluton2 + "' WHERE DATASERVICIU='" + this->Data1 + "'");
            query.exec();
            query.prepare("update servicii set NUME_PAZA='"+this->Nume1+"', PRENUME_PAZA='"+this->Prenume1+"',BATALION_PAZA='"+this->Batalion1+"',CP_PAZA='"+this->Companie1+"',PLUTON_PAZA='"+this->Pluton1+"' WHERE DATASERVICIU='"+this->Data2+"'");
            query.exec();

        }
        else
            if (determinareTipServiciu( Nume1, Prenume1,   Batalion1, Companie1,  Pluton1,  Data1)==5 ||determinareTipServiciu( Nume2, Prenume2,   Batalion2, Companie2,  Pluton2,  Data2)==1)
            {
                //planton3 cu gsc
                QSqlQuery query;
                query.prepare("update servicii set NUME_PLANTON3='" + this->Nume2 + "', PRENUME_PLANTON3='" + this->Prenume2 + "', BATALION_PLANTON3='" + this->Batalion2 + "', CP_PLANTON3='" + this->Companie2 + "', PLUTON_PLANTON3='" + this->Pluton2 + "' WHERE DATASERVICIU='" + this->Data1 + "'");
                query.exec();
                query.prepare("update servicii set NUME_GSC='"+this->Nume1+"',PRENUME_GSC='"+this->Prenume1+"',BATALION_GSC='"+this->Batalion1+"',CP_GSC='"+this->Companie1+"',PLUTON_GSC='"+this->Pluton1+"' WHERE DATASERVICIU='"+this->Data2+"'");
                query.exec();
            }
            else
                if (determinareTipServiciu( Nume1, Prenume1,   Batalion1, Companie1,  Pluton1,  Data1)==5||determinareTipServiciu( Nume2, Prenume2,   Batalion2, Companie2,  Pluton2,  Data2)==3)
                {
                    //planton3 cu planton1
                    QSqlQuery query;
                    query.prepare("update servicii set NUME_PLANTON3='" + this->Nume2 + "', PRENUME_PLANTON3='" + this->Prenume2 + "', BATALION_PLANTON3='" + this->Batalion2 + "', CP_PLANTON3='" + this->Companie2 + "', PLUTON_PLANTON3='" + this->Pluton2 + "' WHERE DATASERVICIU='" + this->Data1 + "'");
                    query.exec();
                    query.prepare("update servicii set NUME_PLANTON1='"+this->Nume1+"',PRENUME_PLANTON1='"+this->Prenume1+"',BATALION_PLANTON1='"+this->Batalion1+"',CP_PLANTON1='"+this->Companie1+"',PLUTON_PLANTON1='"+this->Pluton1+"' WHERE DATASERVICIU='"+this->Data2+"'");
                    query.exec();


                }

                else
                    if (determinareTipServiciu( Nume1, Prenume1,   Batalion1, Companie1,  Pluton1,  Data1)==5 ||determinareTipServiciu( Nume2, Prenume2,   Batalion2, Companie2,  Pluton2,  Data2)==4)
                    {
                        //planton3 cu planton2
                        QSqlQuery query;
                        query.prepare("update servicii set NUME_PLANTON3='" + this->Nume2 + "', PRENUME_PLANTON3='" + this->Prenume2 + "', BATALION_PLANTON3='" + this->Batalion2 + "', CP_PLANTON3='" + this->Companie2 + "', PLUTON_PLANTON3='" + this->Pluton2 + "' WHERE DATASERVICIU='" + this->Data1 + "'");
                        query.exec();
                        query.prepare("update servicii set NUME_PLANTON2='"+this->Nume1+"',PRENUME_PLANTON2='"+this->Prenume1+"',BATALION_PLANTON2='"+this->Batalion1+"',CP_PLANTON2='"+this->Companie1+"',PLUTON_PLANTON2='"+this->Pluton1+"' WHERE DATASERVICIU='"+this->Data2+"'");
                        query.exec();

                    }







}







void schimbareServiciu::createMessage()
{

    this->Message="18|";
    if (determinareTipServiciu( Nume1, Prenume1,   Batalion1, Companie1,  Pluton1,  Data1)==-1 ||determinareTipServiciu( Nume2, Prenume2,   Batalion2, Companie2,  Pluton2,  Data2)==-1 )
        this->Message=this->Message+"0";
    else
    { this->Message=this->Message+"1";
        this->schimbare();
    }



}
void schimbareServiciu::writeOnSocket(QTcpSocket* socket,DataBase db)
{
    db.getDataBase().open();
    createMessage();
    db.getDataBase().close();
    socket->write(Message);
}

