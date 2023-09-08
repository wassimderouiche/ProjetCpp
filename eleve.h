#ifndef ELEVE_H
#define ELEVE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDateTimeEdit>
#include <QtNetwork/QSslSocket>

class Eleve
{
    int id, age;
    QString nom, prenom, adresse, classe, sexe;


public:
    Eleve();
    Eleve(int,QString,QString,int,QString,QString,QString);

    int getid();
    QString getnom();
    QString getprenom();
    QString getadresse();
    int getage();
    QString getsexe();
    QString getClasse();

    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setadresse(QString);
    void setage(int);
    void setsexe(QString);
    void setClasse(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    void  controlsaisir();

    QSqlQueryModel * rechercher(QString );
    QSqlQueryModel * trier();
    QSqlQueryModel * trierN();
    QSqlQueryModel * trierA();
    void stats(QString ,QString ,int,int,QString);
    bool EXCEL();

};

#endif // ELEVE_H
