#ifndef RESETAREPAROLA_H
#define RESETAREPAROLA_H
#include "cprotocol.h"

class resetareparola: public CProtocol
{
public:
    resetareparola(QString UserName,QString NewPassword);
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();
protected:


private:
    QString Username,NewPassword;
};

#endif // RESETAREPAROLA_H
