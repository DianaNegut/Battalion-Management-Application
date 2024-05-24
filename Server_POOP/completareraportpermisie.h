#ifndef COMPLETARERAPORTPERMISIE_H
#define COMPLETARERAPORTPERMISIE_H
#include "cprotocol.h"

class CompletareRaportPermisie:public CProtocol
{
public:
    CompletareRaportPermisie(QString nameuser,QString dataPlecare,QString oraP, QString oraS,QString dataSosire);
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();
    QString getNume();
    QString getPrenume();
    void populareCampuriCadre();
protected:
    QString  nameuser;
    QString dataPlecare;
    QString dataSosire;
    QString oraS;
    QString oraP;
};

#endif // COMPLETARERAPORTPERMISIE_H
