#ifndef SOLICITAREPERMISIE_H
#define SOLICITAREPERMISIE_H
#include "cprotocol.h"

class SolicitarePermisie: public CProtocol
{
public:
    SolicitarePermisie(QString username, QString DataPlecare, QString OraPlecare, QString DataSosire, QString OraSosire);
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();
    QString getNume();
    QString getPrenume();
    QString getAn();
    QString getCompanie();
    QString getPluton();
    QString getBatalion();
protected:
    QString username,  DataPlecare,  OraPlecare,  DataSosire,  OraSosire;

};

#endif // SOLICITAREPERMISIE_H
