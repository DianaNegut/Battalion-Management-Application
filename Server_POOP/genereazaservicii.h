#ifndef GENEREAZASERVICII_H
#define GENEREAZASERVICII_H
#include "cprotocol.h"

class genereazaServicii: public CProtocol
{
public:
    genereazaServicii(QString luna, QString an);
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();
    int schimbare();
    void parsare();
protected:
    QString luna, an;
};

#endif // GENEREAZASERVICII_H
