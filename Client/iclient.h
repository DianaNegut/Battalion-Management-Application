#ifndef ICLIENT_H
#define ICLIENT_H

#include <QObject>
#include <iostream>
#include <string>
#include <QString>
#include <QTcpSocket>

class iClient : public QObject
{
    Q_OBJECT
public:
    explicit iClient(QObject *parent = nullptr);
    virtual QTcpSocket* getSocket() = 0;
    virtual QStringList getLastMsg() = 0;
    virtual void setUsername(QString user) = 0;
    virtual void setUserType(QString type) = 0;
    virtual QString getUserType() = 0;
    virtual QString getUsername() = 0;

signals:

};

#endif // ICLIENT_H
