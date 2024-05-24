#include "completareraportpermisie.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

CompletareRaportPermisie::CompletareRaportPermisie(QString nameuser,QString dataPlecare,QString oraP, QString oraS,QString dataSosire)
{
    this->nameuser=nameuser;
    this->dataPlecare=dataPlecare;
    this->dataSosire=dataSosire;
    this->oraP=oraP;
    this->oraS=oraS;
}
void CompletareRaportPermisie::populareCampuriCadre()
{
    qInfo()<<"esti in populareCADRE!";
    QSqlQuery query;
    QString batalion="";
    QString companie="";
    QString grupa="";
    query.prepare("select REGISTER_STUDENTI.Batalion, REGISTER_STUDENTI.Companie, REGISTER_STUDENTI.GrupaStudiu FROM REGISTER_STUDENTI WHERE REGISTER_STUDENTI.Username='"+this->nameuser+"'");
    if (query.exec())
    {
        while (query.next())
        {
            batalion+=query.value(0).toString();
            companie+=query.value(1).toString();
            grupa+=query.value(2).toString();
        }
    }

    qInfo()<<batalion<<" "<<companie<<" "<<grupa;

    QString idCdtCp="";
    QString idCdtBat="";
    QString idIndrumator="";
    query.prepare("SELECT IDCADRUCOMPANIE FROM COMANDANT_COMPANIE WHERE COMPANIE = :companie AND BATALION = :batalion");
    query.bindValue(":companie", companie);
    query.bindValue(":batalion", batalion);
    if (query.exec())
    {
        while (query.next())
        {
            idCdtCp+=query.value(0).toString();
        }

    }
    query.prepare("select COMANDANT_BATALION.IDCADRUBATALION FROM COMANDANT_BATALION WHERE BATALION= :batalion");
    query.bindValue(":batalion", batalion);
    if (query.exec())
    {
        while (query.next())
        {
            idCdtBat+=query.value(0).toString();

        }
    }

    query.prepare("select INDRUMATOR_GRUPA.ID_INDRUMATOR_GRUPA FROM INDRUMATOR_GRUPA WHERE GRUPA_STUDII= :grupa");
    query.bindValue(":grupa", grupa);
    if (query.exec())
    {
        while (query.next())
        {
            idIndrumator+=query.value(0).toString();

        }
    }

     qInfo() <<"idCp: " <<idCdtCp<<" idBat: "<<idCdtBat<<" idIndrumator: "<<idIndrumator;


    query.prepare("update Rapoarte_Studenti set ID_COMANDANT_BATALION= :idCdtBat, ID_COMANDANT_COMPANIE= :idCdtCp, ID_INDRUMATOR_GRUPA= :idIndrumator where Rapoarte_Studenti.USERNAME_STUDENT='"+this->nameuser+"'");
    query.bindValue(":idCdtBat", idCdtBat);
    query.bindValue(":idCdtCp", idCdtCp);
    query.bindValue(":idIndrumator", idIndrumator);

    query.exec();




}

QString readFilee() {
    QFile inputFile("C:\\Users\\Diana\\Desktop\\POOP_PROIECT\\raport_permisie.txt");
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
         qInfo() << "Nu am putut deschide fisierul:" << "raport_invoire.txt";
        return "";
    }

    // Citirea conținutului fișierului într-un șir de caractere
    QTextStream in(&inputFile);
    QString fileContent = in.readAll();

    // Închide fișierul
    inputFile.close();

    return fileContent;
}
QString replacePlaceholderss(QString& text, const QString& placeholder, const QString& replacement) {
    int pos = text.indexOf(placeholder);
    if (pos != -1) {
        text.replace(pos, placeholder.length(), replacement);
    }

    return text;


}

void writeToFilee(const QString& fileName, const QString& content) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
         qInfo() << "Nu am putut deschide fișierul pentru scriere:" << fileName;
        return;
    }

    QTextStream out(&file);
    out << content;
    file.close();
}
QString searchStudentt (QString username, QString Nume,QString Prenume,QString dataPlecare,QString oraP, QString oraS,QString dataSosire)
{
    QSqlQuery query;
    QString output="";
    QString template_raport=readFilee();
    query.prepare("SELECT REGISTER_STUDENTI.PLUTON, REGISTER_STUDENTI.Companie, REGISTER_STUDENTI.Batalion, REGISTER_STUDENTI.Oras, REGISTER_STUDENTI.Telefon FROM REGISTER_STUDENTI WHERE REGISTER_STUDENTI.Nume='"+Nume+"' and REGISTER_STUDENTI.Prenume='"+Prenume+"'");
    if (query.exec())
    {
        while (query.next())
        {

            template_raport=replacePlaceholderss(template_raport, ".......", Nume);
            template_raport=replacePlaceholderss(template_raport, ".......", Prenume);
            QString pluton=query.value(0).toString();
             qInfo() << pluton;
            template_raport=replacePlaceholderss(template_raport, ".......", pluton);
            QString companie=query.value(1).toString();
            template_raport=replacePlaceholderss(template_raport, ".......", companie);
             qInfo() << companie;
            QString batalion=query.value(2).toString();
            template_raport=replacePlaceholderss(template_raport, ".......", batalion);
            template_raport=replacePlaceholderss(template_raport, ".......", dataPlecare);
            template_raport=replacePlaceholderss(template_raport, ".......", oraP);
            template_raport=replacePlaceholderss(template_raport, ".......", dataSosire);
            template_raport=replacePlaceholderss(template_raport, ".......", oraS);
            QString oras=query.value(3).toString();
            template_raport=replacePlaceholderss(template_raport, ".......", oras);
            QString telefon=query.value(4).toString();
             qInfo() <<oras;
            template_raport=replacePlaceholderss(template_raport, ".......", telefon);
            template_raport=replacePlaceholderss(template_raport, ".......", dataPlecare);
            QString filename="";
            filename+=Nume+Prenume+"raport_permisie.txt";
            writeToFilee(filename, template_raport);
            output+=template_raport;


        }
    }
    query.prepare("INSERT INTO Rapoarte_Studenti (CONTINUT_RAPORT, USERNAME_STUDENT) VALUES ('"+template_raport+"','"+username+"')");
    query.exec();
     qInfo() << username;
     qInfo()<<template_raport;

    return output;
}
QString CompletareRaportPermisie::getNume()
{
    QSqlQuery query;
    QString output;
    query.prepare("select Nume from REGISTER_STUDENTI where Username='"+this->nameuser+"'");
    if (query.exec())
    {
        while (query.next())
        {
            output+=query.value(0).toString();
        }
    }
    return output;
}
QString CompletareRaportPermisie::getPrenume()
{
    QSqlQuery query;
    QString output;
    query.prepare("select Prenume from REGISTER_STUDENTI where Username='"+this->nameuser+"'");
    if (query.exec())
    {
        while (query.next())
        {
            output+=query.value(0).toString();
        }
    }
    return output;

}


void CompletareRaportPermisie::createMessage()
{
    this->Message="6|";
    QString Nume=this->getNume();
    QString Prenume=this->getPrenume();
    if (searchStudentt(this->nameuser,Nume,Prenume,this->dataPlecare, this->oraP, this->dataSosire,this->oraS)=="")
    {
        this->Message+="0";
    }
    else {
        this->populareCampuriCadre();
        this->Message+="1";
    }


}
void CompletareRaportPermisie::writeOnSocket(QTcpSocket* socket,DataBase db)
{
    db.getDataBase().open();
    createMessage();
    db.getDataBase().close();
    socket->write(Message);
}

