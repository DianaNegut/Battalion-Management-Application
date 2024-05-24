#ifndef SCHIMBARESERVICIU_H
#define SCHIMBARESERVICIU_H
#include "cprotocol.h"

class schimbareServiciu:public CProtocol
{
public:
    schimbareServiciu(QString Nume1,QString Prenume1,  QString Batalion1,QString Companie1, QString Pluton1,
                    QString Nume2,QString Prenume2, QString Batalion2,QString Companie2,  QString Pluton2 ,QString Data1, QString Data2);
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();
    void schimbare();
protected:
    QString Nume1, Prenume1,  Batalion1,  Companie1,Pluton1,
        Nume2, Prenume2,Batalion2,   Companie2,   Pluton2;
    QString Data1, Data2;
};

#endif // SCHIMBARESERVICIU_H
