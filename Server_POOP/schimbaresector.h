#ifndef SCHIMBARESECTOR_H
#define SCHIMBARESECTOR_H
#include "cprotocol.h"

class schimbareSector : public CProtocol
{
public:
    schimbareSector(QString Nume1,QString Prenume1,QString AnStudiu1, QString Companie1, QString Batalion1, QString Pluton1,
                   QString Nume2,QString Prenume2,QString AnStudiu2, QString Companie2, QString Batalion2, QString Pluton2);
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();
    int schimbare();
protected:
   QString Nume1, Prenume1, AnStudiu1,  Companie1,  Batalion1,  Pluton1,
           Nume2, Prenume2, AnStudiu2,  Companie2,  Batalion2,  Pluton2;

};

#endif // SCHIMBARESECTOR_H
