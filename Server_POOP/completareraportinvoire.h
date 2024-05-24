#ifndef COMPLETARERAPORTINVOIRE_H
#define COMPLETARERAPORTINVOIRE_H
#include "cprotocol.h"
class CompletareRaportInvoire:public CProtocol
{
public:
    CompletareRaportInvoire(QString nameuser,    QString data,QString oraS, QString oraP);
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();
    QString getNume();
    QString getPrenume();
    void populareCampuriCadre();
protected:
    QString  nameuser;
    QString data;
    QString oraS;
    QString oraP;
};

#endif // COMPLETARERAPORTINVOIRE_H
