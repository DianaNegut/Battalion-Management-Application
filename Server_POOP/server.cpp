#include "server.h"

Server *Server::instance=nullptr;

Server &Server::getServer()
{
    if(!instance)
        instance=new Server();
    return *instance;
}

void Server::destroyServer()
{
    if(instance)
    {
        delete instance;
        instance=nullptr;
    }
}

Server::Server(QObject *parent)
    : QTcpServer{parent}
{
    server = new QTcpServer(this);
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
}

void Server::StartServer()
{
    if(!this->listen(QHostAddress::Any,1234)){

        return;
    }else{
         qInfo() << "Listening...";
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
     qInfo() << socketDescriptor <<" Connecting...";
    Thread *thr = new Thread(socketDescriptor,this);
    connect(thr,SIGNAL(finished()),thr,SLOT(deleteLater()));
    thr->start();

}

void Server::newConnection(){
    QTcpSocket *socket = server->nextPendingConnection();
    socket->write("Hello client\r\n");
    socket->flush();
    socket->waitForBytesWritten(3000);
    socket->close();
}
