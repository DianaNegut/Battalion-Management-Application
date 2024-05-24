#ifndef RASPUNSAPROBARERAPORT_H
#define RASPUNSAPROBARERAPORT_H
#include "cprotocol.h"

class raspunsAprobareRaport: public CProtocol
{
public:
    raspunsAprobareRaport(QString username,QString raspuns,QString id_Raport);
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();
    QString getNume();
    QString getPrenume();
    int whoami();
protected:
    QString  username;
    QString id_Raport;
    QString raspuns;
};

#endif // RASPUNSAPROBARERAPORT_H
