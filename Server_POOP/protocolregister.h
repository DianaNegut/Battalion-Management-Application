#ifndef PROTOCOLREGISTER_H
#define PROTOCOLREGISTER_H

#include "cprotocol.h"

class ProtocolRegister : public CProtocol
{
public:
    ProtocolRegister(QString Username,
                  QString Passwordd,
                  QString Oras,
                  QString Judet,
                  QString Telefon,
                  QString Nume,
                  QString Prenume,
                  int AnStudiu,
                  int Companie,
                  int Batalion,
                  int Pluton,
                  QString SerieArma,
                  QString GrupaStudiu);
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();

private:
    QString Username;
    QString Passwordd;
    QString Oras;
    QString Judet;
    QString Telefon;
    QString Nume;
    QString Prenume;
    int AnStudiu;
    int Companie;
    int Batalion;
    int Pluton;
    QString SerieArma;
    QString GrupaStudiu;

};

#endif // PROTOCOLREGISTER_H
