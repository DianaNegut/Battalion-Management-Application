#include "protocolregister.h"
#include <QCryptographicHash>
QString calculateSha512Hash(const QString& input)
{
    QByteArray data = input.toUtf8();
    QByteArray hash = QCryptographicHash::hash(data, QCryptographicHash::Sha512);
    return QString(hash.toHex());
}
ProtocolRegister::ProtocolRegister(QString Username,
                             QString Passwordd,
                             QString Oras,
                             QString Judet,
                             QString Telefon,
                             QString Nume,
                             QString Prenume,
                             int AnStudiu,
                             int Companie,
                             int Batalion,
                             int Pluton,
                             QString SerieArma,
                             QString GrupaStudiu):
    Username(Username),  Oras(Oras), Judet(Judet), Telefon(Telefon), Nume(Nume), Prenume(Prenume), AnStudiu(AnStudiu),
    Companie(Companie), Batalion(Batalion), Pluton(Pluton), SerieArma(SerieArma), GrupaStudiu(GrupaStudiu) {
    this->Passwordd=calculateSha512Hash(Passwordd);
}


bool searchUsername(QString Username)
{
    QSqlQuery query;
    query.prepare("select* from REGISTER_STUDENTI where Username='"+Username+"'");
    query.exec();
    while(query.next())
    {
        return true;
    }
    return false;

}
void ProtocolRegister::createMessage()
{

    // Email.resize(Email.size()-2);

    if(searchUsername(Username))
    {
        this->Message="2|2";
        //exista deja in baza de date
    }
    else
    {
        QSqlQuery query;
        query.prepare("INSERT INTO [MANAGEMENTUL_BATALIOANELOR].[dbo].[REGISTER_STUDENTI](Username,Passwordd,Oras,Judet,Telefon,Nume,Prenume,AnStudiu,Companie,Batalion,Pluton,SerieArma,GrupaStudiu)  values (:Username,:Passwordd,:Oras,:Judet,:Telefon,:Nume,:Prenume,:AnStudiu,:Companie,:Batalion,:Pluton,:SerieArma,:GrupaStudiu)") ;
        query.bindValue(":Username",Username);
        query.bindValue(":Passwordd",Passwordd);
        query.bindValue(":Oras",Oras);
        query.bindValue(":Judet",Judet);
        query.bindValue(":Telefon",Telefon);
        query.bindValue(":Nume",Nume);
        query.bindValue(":Prenume",Prenume);
        query.bindValue(":AnStudiu",AnStudiu);
        query.bindValue(":Companie",Companie);
        query.bindValue(":Batalion",Batalion);
        query.bindValue(":Pluton",Pluton);
        query.bindValue(":SerieArma",SerieArma);
        query.bindValue(":GrupaStudiu",GrupaStudiu);

        if(query.exec())
            this->Message="2|1";
        else
            this->Message="2|0";
    }
}

void ProtocolRegister::writeOnSocket(QTcpSocket* socket,DataBase db)
{
    db.getDataBase().open();
    createMessage();
    db.getDataBase().close();
    socket->write(Message);
}
