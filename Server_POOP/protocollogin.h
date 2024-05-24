#ifndef PROTOCOLLOGIN_H
#define PROTOCOLLOGIN_H
#include "cprotocol.h"

class ProtocolLogin : public CProtocol
{
public:
    ProtocolLogin(QString UserName,QString Password);
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();
protected:


private:
    QString Username,Password;

};

#endif // PROTOCOLLOGIN_H
