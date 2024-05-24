#include "completareraportinvoire.h"
#include <QFile>
#include <QTextStream>

CompletareRaportInvoire::CompletareRaportInvoire(QString nameuser,QString data,QString oraS, QString oraP)
{
    this->nameuser=nameuser;
    this->oraP=oraP;
    this->oraS=oraS;
    this->data=data;
}





QString CompletareRaportInvoire::getNume()
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




QString CompletareRaportInvoire::getPrenume()
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




QString readFile() {
    QFile inputFile("C:\\Users\\Diana\\Desktop\\POOP_PROIECT\\raport_invoire.txt");
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
         qInfo() << "Nu am putut deschide fisierul:" << "raport_invoire.txt";
        return "";
    }
    QTextStream in(&inputFile);
    QString fileContent = in.readAll();
    inputFile.close();

    return fileContent;
}




void CompletareRaportInvoire::populareCampuriCadre()
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









QString replacePlaceholders(QString& text, const QString& placeholder, const QString& replacement) {
    int pos = text.indexOf(placeholder);
    if (pos != -1) {
        text.replace(pos, placeholder.length(), replacement);
    }

    return text;


}

void writeToFile(const QString& fileName, const QString& content) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qInfo() << "Nu am putut deschide fișierul pentru scriere:" << fileName;
        return;
    }

    QTextStream out(&file);
    out << content;
    file.close();
}
QString searchStudent(QString Nameuser,QString Nume,QString Prenume,QString data,QString oraS, QString oraP)
{
    QSqlQuery query;
    QString output="";
    QString template_raport=readFile();
    query.prepare("SELECT REGISTER_STUDENTI.PLUTON, REGISTER_STUDENTI.Companie, REGISTER_STUDENTI.Batalion, REGISTER_STUDENTI.Oras, REGISTER_STUDENTI.Telefon FROM REGISTER_STUDENTI WHERE REGISTER_STUDENTI.Nume='"+Nume+"' and REGISTER_STUDENTI.Prenume='"+Prenume+"'");
    if (query.exec())
    {
        while (query.next())
        {

            template_raport=replacePlaceholders(template_raport, ".......", Nume);
            template_raport=replacePlaceholders(template_raport, ".......", Prenume);
            QString pluton=query.value(0).toString();
            //debug << pluton;
            template_raport=replacePlaceholders(template_raport, ".......", pluton);
            QString companie=query.value(1).toString();
            template_raport=replacePlaceholders(template_raport, ".......", companie);
            //debug << companie;
            QString batalion=query.value(2).toString();
            template_raport=replacePlaceholders(template_raport, ".......", batalion);
            template_raport=replacePlaceholders(template_raport, ".......", data);
            template_raport=replacePlaceholders(template_raport, ".......", oraP);
            template_raport=replacePlaceholders(template_raport, ".......", oraS);
            QString oras=query.value(3).toString();
           // debug <<oras;
            template_raport=replacePlaceholders(template_raport, ".......", oras);
            QString telefon=query.value(4).toString();
            //debug <<oras;
            template_raport=replacePlaceholders(template_raport, ".......", telefon);
            template_raport=replacePlaceholders(template_raport, ".......", data);
            QString filename="";
            filename+=Nume+Prenume+"raport_invoire.txt";
            writeToFile(filename, template_raport);
            output+=template_raport;


        }
    }


    query.prepare("INSERT INTO Rapoarte_Studenti (CONTINUT_RAPORT, USERNAME_STUDENT) VALUES ('"+template_raport+"','"+Nameuser+"')");
    query.exec();


    return output;
}



void CompletareRaportInvoire::createMessage()
{
    this->Message="5|";
    QString Nume=this->getNume();
    QString Prenume=this->getPrenume();
    if (searchStudent(this->nameuser,Nume,Prenume,this->data, this->oraP, this->oraS)=="")
    {
        this->Message+="0";
    }
    else {
        this->populareCampuriCadre();
        this->Message+="1";
    }


}

void CompletareRaportInvoire::writeOnSocket(QTcpSocket* socket,DataBase db)
{
    db.getDataBase().open();
    createMessage();
    db.getDataBase().close();
    socket->write(Message);
}
