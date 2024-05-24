#ifndef CLIENT_H
#define CLIENT_H

#include "iclient.h"

class Client : public iClient
{
    Q_OBJECT
private:
    QTcpSocket *socket;
    QStringList lastResponseMsg;
    QString username;
    QString usertype;
    QString topic_accesat;

public:
    explicit Client(QString ip, int port);
    QTcpSocket* getSocket();
    QStringList getLastMsg();
    void setUsername(QString user);
    void setUserType(QString type);
    QString getUsername();
    QString getUserType();


signals:

public slots:
    void onReadyRead();

};

#endif // CLIENT_H
