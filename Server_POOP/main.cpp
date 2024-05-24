#include <QCoreApplication>
#include "server.h"
#include <QSqlError>
#include <QDir>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server::getServer().StartServer();

    return a.exec();
}
