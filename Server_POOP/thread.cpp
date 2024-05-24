#include "thread.h"
//#include "DataBase.h"
#include "cfactoryprotocol.h"
#include <QString>



void Thread::run(){
    //thread starts here
     qInfo() << "Starting thread";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor)){
         qInfo() << "There was a problem connecting";
        return;
    }

    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

     qInfo() << socketDescriptor << " Client connected";

    DataBase::getInstance().ConnectDB();
    // db.ConnectDB();
    exec();
}


void Thread::readyRead()
{

    QByteArray Data = socket->readAll();

     qInfo() <<"ESTI IN THREAD SI AFISEZI CE PRIMESTI DE LA DARIA" << Data;
    QStringList dataList=QString(Data).split('|');
    if (dataList.value(0)=="1")
        CFactoryProtocol::createProtocol(Data,Login)->writeOnSocket(socket,DataBase::getInstance());
    if (dataList.value(0)=="2")
        CFactoryProtocol::createProtocol(Data,Register)->writeOnSocket(socket,DataBase::getInstance());
    if (dataList.value(0)=="3")
        CFactoryProtocol::createProtocol(Data,VizualizareSectorDupaStudent)->writeOnSocket(socket,DataBase::getInstance());
    if (dataList.value(0)=="4")
        CFactoryProtocol::createProtocol(Data,VizualizareStudentDupaSector)->writeOnSocket(socket,DataBase::getInstance());
    if (dataList.value(0)=="5")
        CFactoryProtocol::createProtocol(Data,CompletareRaportInvoire)->writeOnSocket(socket,DataBase::getInstance());
    if (dataList.value(0)=="6")
        CFactoryProtocol::createProtocol(Data,CompletareRaportPermisie)->writeOnSocket(socket,DataBase::getInstance());
    if (dataList.value(0)=="7")
        CFactoryProtocol::createProtocol(Data, ResetareParola)->writeOnSocket(socket,DataBase::getInstance());
    if (dataList.value(0)=="8")
        CFactoryProtocol::createProtocol(Data, SchimbareSector)->writeOnSocket(socket,DataBase::getInstance());
    if (dataList.value(0)=="9")
        CFactoryProtocol::createProtocol(Data, SolicitarePermisie)->writeOnSocket(socket,DataBase::getInstance());
    if (dataList.value(0)=="10")
        CFactoryProtocol::createProtocol(Data, raspunsAprobareRaport)->writeOnSocket(socket,DataBase::getInstance());
    if (dataList.value(0)=="11")
        CFactoryProtocol::createProtocol(Data, vizualizareRapoarte)->writeOnSocket(socket,DataBase::getInstance());
    if (dataList.value(0)=="12")
        CFactoryProtocol::createProtocol(Data, vizualizareRaportSpecific)->writeOnSocket(socket,DataBase::getInstance());
    if (dataList.value(0)=="13")
        CFactoryProtocol::createProtocol(Data, vizualizarePermisii)->writeOnSocket(socket,DataBase::getInstance());
    if (dataList.value(0)=="14")
        CFactoryProtocol::createProtocol(Data, vizualizarePermisii)->writeOnSocket(socket,DataBase::getInstance());
    if (dataList.value(0)=="15")
        CFactoryProtocol::createProtocol(Data, respingerePermisii)->writeOnSocket(socket,DataBase::getInstance());
    if (dataList.value(0)=="16")
        CFactoryProtocol::createProtocol(Data, vizualizareserviciudupazi)->writeOnSocket(socket,DataBase::getInstance());
    if (dataList.value(0)=="17")
        CFactoryProtocol::createProtocol(Data, genereazaServicii)->writeOnSocket(socket,DataBase::getInstance());
    if (dataList.value(0)=="18")
        CFactoryProtocol::createProtocol(Data, schimbareServiciu)->writeOnSocket(socket,DataBase::getInstance());





}

void Thread::disconnected(){

     qInfo() << socketDescriptor << " Disconnected";
    socket->deleteLater();
    // Protocol::stopDatabase();
    exit(0);
}
