#ifndef SERVER_H
#define SERVER_H
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QObject>
#include "thread.h"


class Server : public QTcpServer
{
    Q_OBJECT
public:

    static Server &getServer();
    static void destroyServer();
    void StartServer();

protected:
    void incomingConnection(qintptr socketDescriptor);
signals:

public slots:
    void newConnection();

private:
    static Server *instance;
    QTcpServer *server;
    explicit Server(QObject *parent = nullptr);
    Server(const Server&)=delete;
    ~Server(){};



};

#endif // SERVER_H
