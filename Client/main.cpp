#include "startwindow.h"

#include <QApplication>
#include <QCoreApplication>
#include <QtSql>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow w;
    w.show();
    return a.exec();
}
