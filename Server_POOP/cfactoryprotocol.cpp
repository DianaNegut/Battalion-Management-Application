#include "cfactoryprotocol.h"
#include "protocollogin.h"
#include "protocolregister.h"
#include "vizualizaresectordupastudent.h"
#include "vizualizarestudentdupasector.h"
#include "completareraportinvoire.h"
#include "completareraportpermisie.h"
#include "resetareparola.h"
#include "solicitarepermisie.h"
#include "schimbaresector.h"
#include "raspunsAprobareRaport.h"
#include "vizualizarerapoarte.h"
#include "vizualizareraportspecific.h"
#include "vizualizarepermisii.h"
#include "respingerepermisii.h"
#include "vizualizareserviciudupazi.h"
#include "genereazaservicii.h"
#include "schimbareserviciu.h""
CFactoryProtocol::CFactoryProtocol()
{

}

IProtocol* CFactoryProtocol::createProtocol(QString Data,Protocol Name)
{
    //adauga 2 caractere extra si le sterg
    //pentru putty, cand te conectezi normal merge
   //Data = Data.chopped(1);
   //Data = Data.chopped(1);
    QStringList dataList= QString(Data).split('|');
    if(Name==Login)
    {

        qInfo() <<"ESTI IN CFACTORY SI AFISEZI TOT CE AI DE LA DARIA FARA 1| " <<Data << " " ;
        return new ProtocolLogin(dataList.value(1),dataList.value(2));
    }
    if (Name==Register)
    {

        qInfo() << Data << " " << Name;
        return new  ProtocolRegister(dataList.value(1),dataList.value(2),dataList.value(3),dataList.value(4),dataList.value(5),dataList.value(6),dataList.value(7),dataList.value(8).toInt(),dataList.value(9).toInt(),dataList.value(10).toInt(),dataList.value(11).toInt(),dataList.value(12),dataList.value(13));
    }
    if (Name==VizualizareSectorDupaStudent)
    {
        return new class VizualizareSectorDupaStudent(dataList.value(1),dataList.value(2), dataList.value(3),dataList.value(4),dataList.value(5),dataList.value(6));
    }
    if (Name==VizualizareStudentDupaSector)
    {
        return new class VizualizareStudentDupaSector(dataList.value(1));
    }
    if (Name==CompletareRaportInvoire)
    {
        return new class CompletareRaportInvoire(dataList.value(1),dataList.value(2),dataList.value(3),dataList.value(4));
    }
    if (Name==CompletareRaportPermisie)
    {
        return new class CompletareRaportPermisie(dataList.value(1),dataList.value(2),dataList.value(3),dataList.value(4),dataList.value(5));
    }
    if (Name==ResetareParola)
    {
        return new class resetareparola(dataList.value(1),dataList.value(2));
    }
    if (Name==SchimbareSector)
    {

        qInfo() <<"ESTI IN CFACTORY  " <<Data << " " ;
        return new class schimbareSector(dataList.value(1),dataList.value(2),dataList.value(3),dataList.value(4),dataList.value(5),dataList.value(6),dataList.value(7),dataList.value(8),dataList.value(9),dataList.value(10),dataList.value(11),dataList.value(12));
    }
    if (Name==SolicitarePermisie)
    {

        qInfo() <<"ESTI IN CFACTORY  " <<Data << " " ;
        return new class SolicitarePermisie(dataList.value(1),dataList.value(2),dataList.value(3),dataList.value(4),dataList.value(5));
    }
    if (Name==raspunsAprobareRaport)
    {

        qInfo() <<"ESTI IN CFACTORY  " <<Data << " " ;
        return new class raspunsAprobareRaport(dataList.value(1),dataList.value(2), dataList.value(3));
    }
    if (Name==vizualizareRapoarte)
    {

        qInfo()  <<"ESTI IN CFACTORY  " <<Data << " " ;
        return new class vizualizareRapoarte(dataList.value(1));
    }
    if (Name==vizualizareRaportSpecific)
    {

        qInfo()  <<"ESTI IN CFACTORY  " <<Data << " " ;
        return new class vizualizareRaportSpecific(dataList.value(1),dataList.value(2));
    }
    if (Name==vizualizarePermisii)
    {

        qInfo() <<"ESTI IN CFACTORY  " <<Data << " " ;
        return new class vizualizarePermisii(dataList.value(1));
    }
    if (Name==respingerePermisii)
    {

         qInfo() <<"ESTI IN CFACTORY  " <<Data << " " ;
        return new class respingerePermisii(dataList.value(1));
    }
    if (Name==vizualizareserviciudupazi)
    {

         qInfo() <<"ESTI IN CFACTORY  " <<Data << " " ;
        return new class vizualizareServiciuDupaZi(dataList.value(1));
    }
    if (Name==genereazaServicii)
    {

        qInfo() <<"ESTI IN CFACTORY  " <<Data << " " ;
        return new class genereazaServicii(dataList.value(1), dataList.value(2));
    }
    if (Name==schimbareServiciu)
    {

        qInfo() <<"ESTI IN CFACTORY  " <<Data << " " ;
        return new class schimbareServiciu(dataList.value(1), dataList.value(2), dataList.value(3), dataList.value(4), dataList.value(5), dataList.value(6), dataList.value(7), dataList.value(8), dataList.value(9), dataList.value(10), dataList.value(11), dataList.value(12));
    }








    return NULL;
        //socket->write(Protocol::LogIn(dataList.value(1),dataList.value(2)));

}
