#include "genereazaservicii.h"
#include <QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <QObject>
#include <QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <QFile>
#include <QObject>

void runExternalProcess( QString argument1, QString argument2) {
    QProcess process;
    QString program = "C:\\Users\\Diana\\Desktop\\testare\\ServiciiPOOP.exe";
    // Set working directory
    process.setWorkingDirectory("C:\\Users\\Diana\\Desktop\\testare\\");
    QStringList arguments;
    arguments<<argument1<<argument2;
    // Start the process
    process.start(program, arguments);

    // Wait for the process to finish
    process.waitForFinished(-1); // -1 indicates an unlimited wait time until the process finishes

    // Print standard output and error
    QString standardOutput = process.readAllStandardOutput();
    QString standardError = process.readAllStandardError();

    if (!standardOutput.isEmpty()) {
        qInfo() << "Standard Output:" << standardOutput;
    }

    if (!standardError.isEmpty()) {
        qInfo() << "Standard Error:" << standardError;
    }

    // Print exit code
    qInfo() << "Process finished with exit code" << process.exitCode();
}


genereazaServicii::genereazaServicii(QString luna, QString an) {
    this->an=an;
    this->luna=luna;
}


void genereazaServicii::parsare()
{

    QFile inputFile("C:\\Users\\Diana\\Desktop\\testare\\serviciiCurente.txt");
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qInfo() << "Cannot open file for reading:" << inputFile.errorString();
        exit(-1);
    }
    QTextStream in(&inputFile);

    // Read the file line by line
     QString line = in.readLine();
    qInfo()<<line;
    for(int i=0;i<line.toInt();i++)
     {
        QString data, gsc, pl1, pl2, pl3, paza;
        QString line = in.readLine(); //data
        data=line;
       // qInfo()<<line;
        qInfo()<<"Data: "<<data;
       line = in.readLine();//gsc
        gsc=line;
       qInfo()<<"gsc: "<<gsc;
//qInfo()<<line;
         line = in.readLine(); //pl1
        pl1=line;
         qInfo()<<"pl1: "<<pl1;
      //  qInfo()<<line;
         line = in.readLine(); //pl2
        pl2=line;
         qInfo()<<"pl2: "<<pl2;
       // qInfo()<<line;
         line = in.readLine(); //pl3
        pl3=line;
         qInfo()<<"pl3: "<<pl3;
       /// qInfo()<<line;
         line = in.readLine();//paza
        paza=line;
         qInfo()<<"paza: "<<paza;
      //  qInfo()<<line;
         line = in.readLine(); // --
      //  qInfo()<<line;
        QString aux,nume_gsc, prenume_gsc, bat_gsc, cp_gsc,plt_gsc;
        QStringList dataList= QString(gsc).split(' ');
        aux=dataList.value(0);
        qInfo()<<"aux"<<aux;
        QStringList dataList2= QString(aux).split('-');
        nume_gsc=dataList2.value(0);
        prenume_gsc=dataList2.value(1);
        bat_gsc=dataList.value(1);
        cp_gsc=dataList.value(2);
        plt_gsc=dataList.value(3);
        qInfo()<<"nume"<<nume_gsc<<"prenume"<<prenume_gsc<<"bat_gsc"<<bat_gsc<<"cp_gsc"<<cp_gsc<<"plt_gsc"<<plt_gsc;

        QString aux1,nume_paza, prenume_paza, bat_paza, cp_paza,plt_paza;
        dataList= QString(paza).split(' ');
        aux1=dataList.value(0);
        qInfo()<<"aux1"<<aux1;
        dataList2=QString(aux1).split('-');
        nume_paza=dataList2.value(0);
        prenume_paza=dataList2.value(1);
        bat_paza=dataList.value(1);
        cp_paza=dataList.value(2);
        plt_paza=dataList.value(3);
        qInfo()<<"nume"<<nume_paza<<"prenume"<<prenume_paza<<"bat_paza"<<bat_paza<<"cp_paza"<<cp_paza<<"plt_paza"<<plt_paza;
        QString aux2,nume_pl1, prenume_pl1, bat_pl1, cp_pl1,plt_pl1;
        dataList= QString(pl1).split(' ');
        aux2=dataList.value(0);
        qInfo()<<"aux2"<<aux2;
        dataList2=QString(aux2).split('-');
        nume_pl1=dataList2.value(0);
        prenume_pl1=dataList2.value(1);
        bat_pl1=dataList.value(1);
        cp_pl1=dataList.value(2);
        plt_pl1=dataList.value(3);
         qInfo()<<"nume"<<nume_pl1<<"prenume"<<prenume_pl1<<"bat_pl1"<<bat_pl1<<"cp_pl1"<<cp_pl1<<"plt_pl1"<<plt_pl1;

        QString aux3,nume_pl2, prenume_pl2, bat_pl2, cp_pl2,plt_pl2;
        dataList= QString(pl2).split(' ');
        aux3=dataList.value(0);
        qInfo()<<"aux3"<<aux3;
        dataList2=QString(aux3).split('-');
        nume_pl2=dataList2.value(0);
        prenume_pl2=dataList2.value(1);
        bat_pl2=dataList.value(1);
        cp_pl2=dataList.value(2);
        plt_pl2=dataList.value(3);
        qInfo()<<"nume"<<nume_pl2<<"prenume"<<prenume_pl2<<"bat_pl2"<<bat_pl2<<"cp_pl2"<<cp_pl2<<"plt_pl2"<<plt_pl2;


        QString aux4,nume_pl3, prenume_pl3, bat_pl3, cp_pl3,plt_pl3;
        dataList= QString(pl3).split(' ');
        aux4=dataList.value(0);
        qInfo()<<"aux4"<<aux4;
        dataList2=QString(aux4).split('-');
        nume_pl3=dataList2.value(0);
        prenume_pl3=dataList2.value(1);
        bat_pl3=dataList.value(1);
        cp_pl3=dataList.value(2);
        plt_pl3=dataList.value(3);
        qInfo()<<"nume"<<nume_pl3<<"prenume"<<prenume_pl3<<"bat_pl3"<<bat_pl3<<"cp_pl3"<<cp_pl3<<"plt_pl3"<<plt_pl3;



         QSqlQuery query;
        query.prepare("INSERT INTO Servicii (DATASERVICIU, NUME_PAZA, PRENUME_PAZA, BATALION_PAZA, CP_PAZA, PLUTON_PAZA, NUME_GSC, PRENUME_GSC, "
                      "BATALION_GSC, CP_GSC, PLUTON_GSC, NUME_PLANTON1, PRENUME_PLANTON1, BATALION_PLANTON1, CP_PLANTON1, PLUTON_PLANTON1, "
                      "NUME_PLANTON2, PRENUME_PLANTON2, BATALION_PLANTON2, CP_PLANTON2, PLUTON_PLANTON2, NUME_PLANTON3, PRENUME_PLANTON3, "
                      "BATALION_PLANTON3, CP_PLANTON3, PLUTON_PLANTON3) "
                      "VALUES ('" + data + "', '" + nume_paza + "', '" + prenume_paza + "', '" + bat_paza + "', '" + cp_paza + "', '" + plt_paza + "', '"
                      + nume_gsc + "', '" + prenume_gsc + "', '" + bat_gsc + "', '" + cp_gsc + "', '" + plt_gsc + "', '"
                      + nume_pl1 + "', '" + prenume_pl1 + "', '" + bat_pl1 + "', '" + cp_pl1 + "', '" + plt_pl1 + "', '"
                      + nume_pl2 + "', '" + prenume_pl2 + "', '" + bat_pl2 + "', '" + cp_pl2 + "', '" + plt_pl2 + "', '"
                      + nume_pl3 + "', '" + prenume_pl3 + "', '" + bat_pl3 + "', '" + cp_pl3 + "', '" + plt_pl3 + "')");

        query.exec();



     }

    // Close the file
    inputFile.close();








}

void genereazaServicii::createMessage()
{
    QSqlQuery query;
    this->Message="17|1";
    runExternalProcess(this->luna, this->an);
    parsare();


}

void genereazaServicii::writeOnSocket(QTcpSocket* socket,DataBase db)
{
    db.getDataBase().open();
    createMessage();
    db.getDataBase().close();
    socket->write(Message);
}
