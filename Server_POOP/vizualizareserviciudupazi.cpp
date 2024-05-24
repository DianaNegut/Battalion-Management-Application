#include "vizualizareserviciudupazi.h"

vizualizareServiciuDupaZi::vizualizareServiciuDupaZi(QString data )
{
    this->data=data;
}

QString searchServiciu(QString data)
{
    QSqlQuery query;
    QString output="";

    query.prepare("select NUME_PAZA, PRENUME_PAZA,BATALION_PAZA, CP_PAZA,PLUTON_PAZA, NUME_GSC, PRENUME_GSC, BATALION_GSC, CP_GSC, PLUTON_GSC, NUME_PLANTON1,PRENUME_PLANTON1, BATALION_PLANTON1, CP_PLANTON1, PLUTON_PLANTON1, NUME_PLANTON2,PRENUME_PLANTON2, BATALION_PLANTON2, CP_PLANTON2, PLUTON_PLANTON2,NUME_PLANTON3,PRENUME_PLANTON3, BATALION_PLANTON3, CP_PLANTON3, PLUTON_PLANTON3 FROM Servicii WHERE DATASERVICIU='"+data+"' ");
    if (query.exec())
    {
        while (query.next())
        {
            output+=query.value(0).toString();
            output+=query.value(1).toString();
            output+=query.value(2).toString();
            output+=query.value(3).toString();
            output+=query.value(4).toString();
            output+="|";
            output+=query.value(5).toString();
            output+=query.value(6).toString();
            output+=query.value(7).toString();
            output+=query.value(8).toString();
            output+=query.value(9).toString();
            output+="|";
            output+=query.value(10).toString();
            output+=query.value(11).toString();
            output+=query.value(12).toString();
            output+=query.value(13).toString();
            output+=query.value(14).toString();
            output+="|";
            output+=query.value(15).toString();
            output+=query.value(16).toString();
            output+=query.value(17).toString();
            output+=query.value(18).toString();
            output+=query.value(19).toString();
            output+="|";
            output+=query.value(20).toString();
            output+=query.value(21).toString();
            output+=query.value(22).toString();
            output+=query.value(23).toString();
            output+=query.value(24).toString();





        }
    }
    qInfo()<<output;

    return output;
}


void vizualizareServiciuDupaZi::createMessage()
{
    this->Message="16|";
    this->Message+=searchServiciu(this->data).toUtf8();




}
void vizualizareServiciuDupaZi::writeOnSocket(QTcpSocket* socket,DataBase db)
{
    db.getDataBase().open();
    createMessage();
    db.getDataBase().close();
    socket->write(Message);
}

