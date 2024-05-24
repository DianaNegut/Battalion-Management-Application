#ifndef VIZUALIZARERAPOARTE_H
#define VIZUALIZARERAPOARTE_H
#include "cprotocol.h""

class vizualizareRapoarte: public CProtocol
{
public:
    vizualizareRapoarte(QString username);
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();
    QString getNume();
    QString getPrenume();
    int whoami();
protected:
    QString username;
};

#endif // VIZUALIZARERAPOARTE_H
