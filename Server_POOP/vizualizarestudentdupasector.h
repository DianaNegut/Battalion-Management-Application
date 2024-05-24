#ifndef VIZUALIZARESTUDENTDUPASECTOR_H
#define VIZUALIZARESTUDENTDUPASECTOR_H
#include "cprotocol.h"

class VizualizareStudentDupaSector: public CProtocol
{
public:
    VizualizareStudentDupaSector(QString NumeSector);
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();
protected:
    QString  NumeSector;
};

#endif // VIZUALIZARESTUDENTDUPASECTOR_H
