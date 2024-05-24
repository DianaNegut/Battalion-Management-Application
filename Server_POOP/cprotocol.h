#ifndef CPROTOCOL_H
#define CPROTOCOL_H
#include "iprotocol.h"
class CProtocol : public IProtocol
{
public:
    CProtocol();
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db)=0;
    virtual void createMessage()=0;

protected:
    QByteArray Message;
    bool searchAnswerOrQuestion(QString type, QString Text);
};

#endif // CPROTOCOL_H
