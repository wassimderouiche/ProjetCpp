#ifndef ACTIVITE_H
#define ACTIVITE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDateTimeEdit>
#include <QtNetwork/QSslSocket>

class Activite
{
    int idAc;
    QString nomAc, domaine;
    QDateTime dateDebut;
        QDateTime dateFin;

public:
    Activite();
    Activite(int, QString, QString, QDateTime, QDateTime );
    int getId();
    QString getNomAc();
    QString getDomaine();
    void  controlsaisir();

    void setIDAc(int);
    void setNomAc(QString);
    void setDomaine(QString);
    QDateTime getDateDebut();
    void setDateDebut( QDateTime );

       QDateTime getDateFin() ;
    void setDateFin( QDateTime );
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();

    QSqlQueryModel * rechercher(QString );
 QSqlQueryModel * rechercherParDate(QDate );
 QSqlQueryModel * trier();
    QSqlQueryModel * trierD();
    QSqlQueryModel * trierN();
    void stats(QString ,QString ,int,int,QString);
static QList<Activite> toutesLesActivites();
};

#endif // ACTIVITE_H
