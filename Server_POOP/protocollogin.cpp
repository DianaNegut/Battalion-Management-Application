#include "protocollogin.h"
#include <QCryptographicHash>
QString calculateSha512Hashh(const QString& input)
{
    QByteArray data = input.toUtf8();
    QByteArray hash = QCryptographicHash::hash(data, QCryptographicHash::Sha512);
    return QString(hash.toHex());
}
ProtocolLogin::ProtocolLogin(QString UserName,QString Password)
{
    this->Username=UserName;

     qInfo() <<"ESTI IN CONSTRUCTOR SI AFISEZI PAROLA INAINTE DE HASH" <<Password;
    this->Password=calculateSha512Hashh(Password);
     qInfo() << this->Password;

}

int searchUser(QString Username, QString Password)
{
    QSqlQuery query;
    query.prepare("select* from REGISTER_STUDENTI where Username='"+Username+"'and Passwordd='"+Password+"'");
    query.exec();

    while(query.next())
    {
        return 0;
    }
    query.prepare("select* from COMANDANT_COMPANIE where USERNAME='"+Username+"'and PASS='"+Password+"'");
    query.exec();
    while(query.next())
    {
        return 1;
    }
    query.prepare("select* from COMANDANT_BATALION where USERNAME='"+Username+"'and PASS='"+Password+"'");
    query.exec();
    while(query.next())
    {
        return 2;
    }
    query.prepare("select* from INDRUMATOR_GRUPA where USERNAME='"+Username+"'and PASS='"+Password+"'");
    query.exec();
    while(query.next())
    {
        return 3;
    }
    return -1;

}

void ProtocolLogin::createMessage()
{

    if(searchUser(this->Username,this->Password)==0)
    {
        this->Message="1|1|0"; //student
    }
    else
        if(searchUser(this->Username,this->Password)==1)
    {
        this->Message="1|1|1"; // cdt cp
    }
    else
        if(searchUser(this->Username,this->Password)==2)
        {
            this->Message="1|1|2"; // cdt bat
        }
    else if(searchUser(this->Username,this->Password)==3)
    {
        this->Message="1|1|3"; // indrumator grupa
    }
    else
        this->Message="1|0"; //nu exista in baza de date

}
void ProtocolLogin::writeOnSocket(QTcpSocket* socket,DataBase db)
{
    db.getDataBase().open();
    createMessage();
    db.getDataBase().close();
    socket->write(Message);
}
