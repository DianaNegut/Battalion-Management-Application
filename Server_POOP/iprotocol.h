#ifndef IPROTOCOL_H
#define IPROTOCOL_H
#include <QDebug>
#include <QString>
#include <QTcpSocket>
#include "database.h"
class IProtocol
{
public:
    IProtocol();
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db)=0;
    virtual void createMessage()=0;
    //virtual QByteArray getMessage()=0;

};

#endif // IPROTOCOL_H
