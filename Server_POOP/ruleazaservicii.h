#ifndef RULEAZASERVICII_H
#define RULEAZASERVICII_H
#include <QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <QObject>
#include



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QProcess process;
    QString program = "C:\\Users\\Diana\\Desktop\\testare\\ServiciiPOOP.exe";

    QStringList arguments;
    // Adaugă argumentele necesare aici
    arguments << "11" << "2024";

    // Conectează semnalul pentru a afișa ieșirea standard și eroarea
    // QObject::connect(&process, &QProcess::readyReadStandardOutput, [&]() {
    //     // qDebug() << process.readAllStandardOutput();
    // });
    // QObject::connect(&process, &QProcess::readyReadStandardError, [&]() {
    //     // qDebug() << process.readAllStandardError();
    // });

    // set working directory
    process.setWorkingDirectory("C:\\Users\\Diana\\Desktop\\testare\\");
    // Start the process
    process.start(program, arguments);

    // Așteaptă finalizarea procesului
    process.waitForFinished(-1); // -1 indică o așteptare nelimitată până când procesul se termină

    qInfo() << "C++ Style Info Message";
    // Afișează codul de ieșire
    // qDebug() << "Process finished with exit code" << process.exitCode();

    return a.exec();
}

#endif // RULEAZASERVICII_H
