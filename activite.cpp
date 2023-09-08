#include "activite.h"
#include"qsqlerror.h"
Activite::Activite()
{
   idAc=0;
   nomAc=" ";
   domaine=" ";


}
Activite::Activite(int idAc,QString nomAc,QString domaine, QDateTime dateDebut, QDateTime dateFin)
{
    this->idAc=idAc;
    this->nomAc=nomAc;
    this->domaine=domaine;
    this->dateDebut=dateDebut;
    this->dateFin=dateFin;
}
 int Activite::getId(){

    return idAc;
}
 QString Activite::getNomAc(){
     return nomAc;
 }
 QDateTime Activite::getDateDebut(){
     return dateDebut ;
 }
 QDateTime Activite::getDateFin(){
     return dateFin;
 }
 QString Activite::getDomaine(){
     return domaine ;
 }
 void Activite::setIDAc(int a){
     this->idAc=a;
 }
 void Activite::setNomAc(QString a){
     this->nomAc=a;
 }
 void Activite::setDomaine(QString a){
     this->domaine=a;
 }
 void Activite::setDateDebut(QDateTime a){
     this->dateDebut=a;
 }
 void Activite::setDateFin(QDateTime a){
     this->dateFin=a;
 }

 bool Activite::ajouter()
 {
     QString id_string= QString::number(idAc);
     QSqlQuery query;
     query.prepare("INSERT INTO activite ( idAc, nomAc, domaine, dateDebut,dateFin) values (:idAc, :nomAc, :domaine, :dateDebut, :dateFin)");
     query.bindValue(":idAc",id_string);
     query.bindValue(":nomAc",nomAc);
     query.bindValue(":domaine",domaine);
query.bindValue(":dateDebut",dateDebut);
query.bindValue(":dateFin",dateFin);
     return query.exec();
 }
 QSqlQueryModel* Activite::afficher()
 {
     QSqlQueryModel* model=new QSqlQueryModel();


           model->setQuery("SELECT * FROM activite");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("idAc"));
           model->setHeaderData(1, Qt::Horizontal,  QObject::tr("nomAc"));
           model->setHeaderData(2, Qt::Horizontal,  QObject::tr("domaine"));
           model->setHeaderData(2, Qt::Horizontal,  QObject::tr("DateDebut"));
           model->setHeaderData(2, Qt::Horizontal,  QObject::tr("DateFin"));




     return model;
 }
 bool Activite::modifier()
 {
     QString id_string= QString::number(idAc);

     QSqlQuery query;
     query.prepare("update activite set idAc= :idAc, nomAc= :nomAc, domaine= :domaine, dateDebut= :dateDebut, dateFin= :dateFin  where idAc= :idAc");
     query.bindValue(":idAc",id_string);
     query.bindValue(":nomAc",nomAc);
     query.bindValue(":domaine",domaine);
     query.bindValue(":dateDebut",dateDebut);
     query.bindValue(":dateFin",dateFin);



     return query.exec();

 }
 bool Activite::supprimer(int idAc)
 {
     QSqlQuery query;
     QString String_id=QString::number(idAc);
     query.prepare("Delete from activite where idAc= :idAc");
     query.bindValue(":idAc",String_id);

     return query.exec();


 }

 QSqlQueryModel * Activite::rechercher(QString nom_e)
 {

     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM activite WHERE  nomAc LIKE '%"+nom_e+"%'" );

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("idAc"));
     model->setHeaderData(1, Qt::Horizontal,  QObject::tr("nomAc"));
     model->setHeaderData(2, Qt::Horizontal,  QObject::tr("domaine"));
     model->setHeaderData(3, Qt::Horizontal,  QObject::tr("dateDebut"));
     model->setHeaderData(4, Qt::Horizontal,  QObject::tr("dateFin"));



     return model ;


 }
 QSqlQueryModel *Activite::rechercherParDate(QDate date)
 {
     QSqlQueryModel * model = new QSqlQueryModel();
     QString dateString = date.toString("dd-MM-yy");
     qDebug() << "Recherche par date : " << dateString;

     // Utilisez TO_DATE pour convertir la date recherchée au format Oracle
     QString query = "SELECT * FROM activite WHERE TO_DATE(dateDebut, 'DD-MM-YYYY HH24:MI:SS') = TO_DATE(:date, 'DD-MM-YYYY HH24:MI:SS') OR TO_DATE(dateFin, 'DD-MM-YYYY HH24:MI:SS') = TO_DATE(:date, 'DD-MM-YYYY HH24:MI:SS')";
     QSqlQuery q;
     q.prepare(query);
     q.bindValue(":date", dateString);

     if (q.exec())
     {
         model->setQuery(q);
         return model;
     }
     else
     {
         qDebug() << "Erreur de requête : " << q.lastError().text();
         return nullptr;
     }
 }
/*
 QSqlQueryModel *Activite::rechercherParDate(QDate date)
 {
     QSqlQueryModel *model = new QSqlQueryModel();
        QString dateString = date.toString("dd-MM-yyyy");
        qDebug() << "Recherche par date : " << dateString;

        // Utilisez TO_DATE pour convertir la date recherchée au format Oracle
        QString query = "SELECT * FROM activite WHERE TO_DATE(dateDebut, 'DD-MM-YYYY HH24:MI:SS') = TO_DATE(:date, 'DD-MM-YYYY HH24:MI:SS') OR TO_DATE(dateFin, 'YYYY-MM-DD HH24:MI:SS') = TO_DATE(:date, 'DD-MM-YYYY HH24:MI:SS')";
        QSqlQuery q;
        q.prepare(query);
        q.bindValue(":date", dateString);

        if (q.exec())
        {
            model->setQuery(q);
            return model;
        }
        else
        {
            qDebug() << "Erreur de requête : " << q.lastError().text();

 }}
*/
/* QSqlQueryModel *Activite::rechercherParDate(const QString &date)
 {
     QSqlQueryModel *model = new QSqlQueryModel();
     model->setQuery("SELECT * FROM activite WHERE date_debut <= :date AND date_fin >= :date");
     model->query().bindValue(":date", date);

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("idAc"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomAc"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("domaine"));

     return model;
 }*/

 QSqlQueryModel * Activite::trier()
 {

     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM activite  ORDER BY idAc ;");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1, Qt::Horizontal,  QObject::tr("nomAc"));
     model->setHeaderData(2, Qt::Horizontal,  QObject::tr("domaine"));
     model->setHeaderData(3, Qt::Horizontal,  QObject::tr("dateDebut"));
     model->setHeaderData(4, Qt::Horizontal,  QObject::tr("dateFin"));


     return model;

 }


 QSqlQueryModel * Activite::trierN()
 {

     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM activite  ORDER BY nomAc ;");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("idAc"));
     model->setHeaderData(1, Qt::Horizontal,  QObject::tr("nomAc"));
     model->setHeaderData(2, Qt::Horizontal,  QObject::tr("domaine"));
     model->setHeaderData(3, Qt::Horizontal,  QObject::tr("dateDebut"));
     model->setHeaderData(4, Qt::Horizontal,  QObject::tr("dateFin"));

     return model;
 }


 QSqlQueryModel * Activite::trierD()
 {

     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM activite  ORDER BY domaine ;");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("idAc"));
     model->setHeaderData(1, Qt::Horizontal,  QObject::tr("nomAc"));
     model->setHeaderData(2, Qt::Horizontal,  QObject::tr("domaine"));
     model->setHeaderData(3, Qt::Horizontal,  QObject::tr("dateDebut"));
     model->setHeaderData(4, Qt::Horizontal,  QObject::tr("dateFin"));


     return model;

 }

 QList<Activite> Activite::toutesLesActivites()
 {
     QList<Activite> activites;
     QSqlQuery query;
     if (query.exec("SELECT * FROM activite"))
     {
         while (query.next())
         {
             int id = query.value(0).toInt();
             QString nom = query.value(1).toString();
             QString domaine = query.value(2).toString();
             QDateTime dateDebut = query.value(3).toDateTime();
             QDateTime dateFin = query.value(4).toDateTime();

             Activite activite(id, nom, domaine, dateDebut, dateFin);
             activites.append(activite);
         }
     }
     return activites;
 }
