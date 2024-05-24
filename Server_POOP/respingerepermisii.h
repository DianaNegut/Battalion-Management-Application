#ifndef RESPINGEREPERMISII_H
#define RESPINGEREPERMISII_H
#include "cprotocol.h"

class respingerePermisii: public CProtocol
{
public:
    respingerePermisii(QString id);
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();
protected:


private:
    QString id;
};

#endif // RESPINGEREPERMISII_H
