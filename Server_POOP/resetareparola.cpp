#include "resetareparola.h"
#include <QCryptographicHash>
QString calculateSha512Hash_(const QString& input)
{
    QByteArray data = input.toUtf8();
    QByteArray hash = QCryptographicHash::hash(data, QCryptographicHash::Sha512);
    return QString(hash.toHex());
}
resetareparola::resetareparola(QString UserName,QString NewPassword)
{
    this->Username=UserName;
    this->NewPassword=calculateSha512Hash_(NewPassword);

}
int searchUser(QString Username)
{
    QSqlQuery query;
    query.prepare("select* from REGISTER_STUDENTI where Username='"+Username+"'");
    query.exec();

    while(query.next())
    {
        return 0;
    }
    query.prepare("select* from COMANDANT_COMPANIE where USERNAME='"+Username+"'");
    query.exec();
    while(query.next())
    {
        return 1;
    }
    query.prepare("select* from COMANDANT_BATALION where USERNAME='"+Username+"'");
    query.exec();
    while(query.next())
    {
        return 2;
    }
    return -1;

}
void resetareparola::createMessage()
{
    QSqlQuery query;
    this->Message="7|1";
    if(searchUser(this->Username)==0)
    {
        query.prepare("UPDATE REGISTER_STUDENTI SET Passwordd = '"+NewPassword+"' WHERE USERNAME ='"+Username+"'");
        query.exec();

    }
    else if (searchUser(this->Username)==1)
    {
        query.prepare("UPDATE COMANDANT_COMPANIE SET PASS = '"+NewPassword+"' WHERE USERNAME ='"+Username+"'");
        query.exec();

    }
    else if (searchUser(this->Username)==2)
    {
        query.prepare("UPDATE COMANDANT_BATALION SET PASS = '"+NewPassword+"' WHERE USERNAME ='"+Username+"'");
        query.exec();

    }
    else
        this->Message="7|0";




}
void resetareparola::writeOnSocket(QTcpSocket* socket,DataBase db)
{
    db.getDataBase().open();
    createMessage();
    db.getDataBase().close();
    socket->write(Message);
}
