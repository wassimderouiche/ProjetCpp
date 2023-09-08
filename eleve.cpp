#include "eleve.h"
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QFile>
#include <QSqlQueryModel>
#include <QPieSlice>
#include <QChart>
#include<QSqlRecord>

Eleve::Eleve()
{
    id=0;
    nom=" ";
    prenom=" ";
    age=0;
    adresse=" ";
    sexe=" ";
    classe=" ";

}
Eleve::Eleve(int id, QString nom, QString prenom,int age,QString adresse,  QString sexe,QString classe ){
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->age=age;
    this->adresse=adresse;
    this->sexe=sexe;
    this->classe=classe;

}
int Eleve::getid() {return id;}
QString Eleve::getnom(){return nom;}
QString Eleve::getprenom(){return prenom;}
QString Eleve::getadresse(){return adresse;}
int Eleve::getage() {return age;}
QString Eleve::getsexe() {return sexe;}
QString Eleve::getClasse() {return classe;}

void Eleve::setid(int id){this->id=id;}
void Eleve::setnom(QString nom){this->nom=nom;}
void Eleve::setprenom(QString prenom){this->prenom=prenom;}
void Eleve::setadresse(QString adresse){this->adresse=adresse;}
void Eleve::setage(int age){this->age=age;}
void Eleve::setsexe(QString sexe){this->sexe=sexe;}
void Eleve::setClasse(QString classe ){this->classe=classe;}




bool Eleve::ajouter()
{

    QString id_string= QString::number(id);
    QString age_string= QString::number(age);


    QSqlQuery query;
    query.prepare("INSERT INTO eleve ( id, nom, prenom, age, adresse, sexe, classe) values (:id, :nom, :prenom, :age, :adresse, :sexe, :classe)");
    query.bindValue(":id",id_string);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":age",age_string);
    query.bindValue(":adresse",adresse);
    query.bindValue(":sexe",sexe);
    query.bindValue(":classe",classe);







    return query.exec();
}


QSqlQueryModel* Eleve::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


          model->setQuery("SELECT * FROM eleve");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal,  QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal,  QObject::tr("prenom"));
          model->setHeaderData(3,Qt::Horizontal,  QObject::tr("age"));
          model->setHeaderData(3,Qt::Horizontal,  QObject::tr("adresse"));
          model->setHeaderData(3,Qt::Horizontal,  QObject::tr("sexe"));
          model->setHeaderData(3,Qt::Horizontal,  QObject::tr("classe"));

    return model;
}

bool Eleve::modifier()
{
    QString id_string= QString::number(id);
    QString age_string= QString::number(age);


    QSqlQuery query;
    query.prepare("update eleve set id= :id, nom= :nom, prenom= :prenom, age= :age, adresse= :adresse, sexe= :sexe, classe= :classe where id= :id");
    query.bindValue(":id",id_string);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":age",age_string);
    query.bindValue(":adresse",adresse);
    query.bindValue(":sexe",sexe);
    query.bindValue(":classe",classe);


    return query.exec();

}

bool Eleve::supprimer(int id)
{
    QSqlQuery query;
    QString String_id=QString::number(id);
    query.prepare("Delete from eleve where id= :id");
    query.bindValue(":id",String_id);

    return query.exec();


}


QSqlQueryModel * Eleve::rechercher(QString nom_e)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM eleve WHERE  nom LIKE '%"+nom_e+"%'" );

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,  QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal,  QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,  QObject::tr("age"));
    model->setHeaderData(4,Qt::Horizontal,  QObject::tr("adresse"));
    model->setHeaderData(5,Qt::Horizontal,  QObject::tr("sexe"));
    model->setHeaderData(6,Qt::Horizontal,  QObject::tr("classe"));

    return model ;


}

QSqlQueryModel * Eleve::trier()
{

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM eleve  ORDER BY id ;");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,  QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal,  QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,  QObject::tr("age"));
    model->setHeaderData(4,Qt::Horizontal,  QObject::tr("adresse"));
    model->setHeaderData(5,Qt::Horizontal,  QObject::tr("sexe"));
    model->setHeaderData(6,Qt::Horizontal,  QObject::tr("classe"));

    return model;

}


QSqlQueryModel * Eleve::trierN()
{

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM eleve  ORDER BY nom ;");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,  QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal,  QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,  QObject::tr("age"));
    model->setHeaderData(4,Qt::Horizontal,  QObject::tr("adresse"));
    model->setHeaderData(5,Qt::Horizontal,  QObject::tr("sexe"));
    model->setHeaderData(6,Qt::Horizontal,  QObject::tr("classe"));


    return model;
}


QSqlQueryModel * Eleve::trierA()
{

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM eleve  ORDER BY age ;");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,  QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal,  QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,  QObject::tr("age"));
    model->setHeaderData(4,Qt::Horizontal,  QObject::tr("adresse"));
    model->setHeaderData(5,Qt::Horizontal,  QObject::tr("sexe"));
    model->setHeaderData(6,Qt::Horizontal,  QObject::tr("classe"));


    return model;

}

void Eleve::stats(QString table,QString critere,int valeur1,int valeur2,QString unite)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString valeur1QString=QString::number(valeur1);
    QString valeur2QString=QString::number(valeur2);
                model->setQuery("select * from "+table+" where "+critere+"<"+valeur1QString);
                float countFirst=model->rowCount();
                model->setQuery("select * from "+table+" where " +critere+" between " +valeur1QString+ " and "+valeur2QString);
                float countSecond=model->rowCount();
                model->setQuery("select * from "+table+" where " +critere+">"+valeur2QString);
                float countThird=model->rowCount();
                float total=countFirst+countSecond+countThird;
                QString a=QString("moins de "+valeur1QString+" "+unite+" "+QString::number((countFirst*100)/total,'f',2)+"%" );
                QString b=QString("entre "+valeur1QString+ " et " +valeur2QString+" "+unite+" "+QString::number((countSecond*100)/total,'f',2)+"%" );
                QString c=QString("Plus que "+valeur2QString +" "+unite+" "+QString::number((countThird*100)/total,'f',2)+"%" );
                QPieSeries *series = new QPieSeries();
                series->append(a,countFirst);
                series->append(b,countSecond);
                series->append(c,countThird);
        if (countFirst!=0)
        {QPieSlice *slice = series->slices().at(0);
         slice->setLabelVisible();
         slice->setPen(QPen());}
        if ( countSecond!=0)
        {
                 QPieSlice *slice1 = series->slices().at(1);
                 slice1->setLabelVisible();
        }
       if(countThird!=0)
        {
                 QPieSlice *slice2 = series->slices().at(2);
                 slice2->setLabelVisible();
        }
                QChart *chart = new QChart();
                chart->addSeries(series);
                if(critere=="AGE")
                    critere="age";
                chart->setTitle("Pourcentage Par " +critere+":Nombre Des " +table+" :" +QString::number(total));
                chart->legend()->hide();
                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->resize(1000,500);
                chartView->show();


}

bool Eleve::EXCEL()
{
    QSqlQuery q("select * from eleve");
      QSqlRecord rec = q.record();

      QFile fichier("C:/Users/MSI/resultat.csv");

      if(fichier.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
      {
          QTextStream stream(&fichier);

      int idCol = rec.indexOf("id");
      int nomCol = rec.indexOf("nom");
      int prenomCol = rec.indexOf("prenom");
      int ageCol = rec.indexOf("age");
      int adresseCol = rec.indexOf("adresse");
       int sexeCol = rec.indexOf("sexe");
       int classeCol = rec.indexOf("classe");



      stream << "id" << "," << "nom" << "," << "prenom" << "," << "age" << "," << "adresse" <<  "," << "sexe" << "," << "classe" << "\n";

      while (q.next())
          stream  << q.value(idCol).toString() << "," << q.value(nomCol).toString() << "," << q.value(prenomCol).toString() << ","
                  << q.value(ageCol).toString()<< "," <<  q.value(adresseCol).toString()<< "," <<  q.value(sexeCol).toString()<< "," <<  q.value(classeCol).toString()<< "\n";
    fichier.close();
    }
}


