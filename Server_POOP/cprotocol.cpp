#include "cprotocol.h"

CProtocol::CProtocol()
{

}
bool CProtocol::searchAnswerOrQuestion(QString type, QString Text)
{
    QSqlQuery query;
    query.prepare("select * from "+type+" where Text='"+Text+"'");
    query.exec();

    while(query.next())
    {
        return true;
    }
    return false;

}
