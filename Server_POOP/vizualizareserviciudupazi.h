#ifndef VIZUALIZARESERVICIUDUPAZI_H
#define VIZUALIZARESERVICIUDUPAZI_H
#include "cprotocol.h"
class vizualizareServiciuDupaZi:public CProtocol
{
public:
    vizualizareServiciuDupaZi(QString data);
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();
protected:
    QString  data;
};

#endif // VIZUALIZARESERVICIUDUPAZI_H
