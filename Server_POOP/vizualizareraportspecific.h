#ifndef VIZUALIZARERAPORTSPECIFIC_H
#define VIZUALIZARERAPORTSPECIFIC_H
#include "cprotocol.h"

class vizualizareRaportSpecific: public CProtocol
{
public:
    vizualizareRaportSpecific(QString username, QString indexRaport);
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();
    int whoami();
protected:
    QString username, indexRaport;
};

#endif // VIZUALIZARERAPORTSPECIFIC_H
