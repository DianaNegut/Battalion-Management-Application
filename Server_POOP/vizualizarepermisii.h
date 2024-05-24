#ifndef VIZUALIZAREPERMISII_H
#define VIZUALIZAREPERMISII_H
#include "cprotocol.h"

class vizualizarePermisii: public CProtocol
{
public:
    vizualizarePermisii(QString username);
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();
    QString getNume();
    QString getPrenume();
    int whoami();
    QString getCompanie();
    QString getBatalion();
    QString getAnStudiu();
protected:
    QString username;
};

#endif // VIZUALIZAREPERMISII_H
