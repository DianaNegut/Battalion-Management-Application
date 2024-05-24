#include "respingerepermisii.h"

respingerePermisii::respingerePermisii(QString id) {
    this->id=id;
}
void respingerePermisii::createMessage()
{

    QSqlQuery query;
    query.prepare("update Permisii set STATUS_APROBARE= :status where IDPERMISIE= :id");
    qInfo()<<"id-ul este:"<<id;
    query.bindValue(":id", this->id);
    query.bindValue(":status", 0);
    query.exec();
    this->Message="15|1";


}
void respingerePermisii::writeOnSocket(QTcpSocket* socket,DataBase db)
{
    db.getDataBase().open();
    createMessage();
    db.getDataBase().close();
    socket->write(Message);
}
