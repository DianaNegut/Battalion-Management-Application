#ifndef VIZUALIZARESECTORDUPASTUDENT_H
#define VIZUALIZARESECTORDUPASTUDENT_H
#include "cprotocol.h"

class VizualizareSectorDupaStudent: public CProtocol
{
public:
    VizualizareSectorDupaStudent(QString Nume,QString Prenume,QString AnStudiu, QString Companie, QString Batalion, QString Pluton );
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();
protected:
    QString  Nume, Prenume;
    QString AnStudiu, Companie, Batalion, Pluton;


};

#endif // VIZUALIZARESECTORDUPASTUDENT_H
