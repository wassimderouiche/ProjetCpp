#include "dialoge.h"
#include "ui_dialoge.h"
#include"eleve.h"
#include<QApplication>
#include<QMessageBox>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QSqlQuery>
#include<QChartView>
#include<QtCharts>
DialogE::DialogE(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogE)
{
    ui->setupUi(this);
    ui->comboBoxE->addItem("homme");
    ui->comboBoxE->addItem("femme");
    ui->comboBox_2->addItem("homme");
    ui->comboBox_2->addItem("femme");
    ui->tabeleve->setModel(e.afficher());




}

DialogE::~DialogE()
{
    delete ui;
}




void DialogE::on_ajouterE_clicked()
{
    int Id=ui->id_2->text().toInt();
    QString nom=ui->nomE->text();
    QString prenom=ui->prenomE->text();
    QString adresse=ui->Adresse->text();
    int age=ui->Age->text().toInt();
    QString sexe=ui->comboBoxE->currentText();
    QString classe=ui->classe->text();
        Eleve e(Id ,nom ,prenom,age,adresse, sexe,classe);

        bool test=e.ajouter();
        if(test)
        {

            QMessageBox::information(nullptr, QObject::tr("OK"),
                        QObject::tr("Ajout effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr(" not ok"),
                        QObject::tr("Ajout non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}



void DialogE::on_afficherE_clicked()
{
      ui->tabeleve->setModel(e.afficher());
}



void DialogE:: controlsaisir()
{
   // ui->tab_6->close();

    //ajouter
    ui->id_2->setMaxLength(8);
    ui->nomE->setMaxLength(25);
    ui->prenomE->setMaxLength(25);
    ui->Adresse->setMaxLength(25);
    ui->Age->setMaxLength(2);
    ui->classe->setMaxLength(2);//




    ui->ModId->setMaxLength(8);
    ui->ModNom->setMaxLength(25);
    ui->ModPrenom->setMaxLength(25);
    ui->modadresse->setMaxLength(25);
    ui->modAge->setMaxLength(2);
    ui->modClasse->setMaxLength(2);//

    // supprimer
    ui->suppID->setMaxLength(8);

}
void DialogE::on_ModifierE_clicked()
{
int id=ui->ModId->text().toInt();
QString nom=ui->ModNom->text();
QString prenom=ui->ModPrenom->text();
int age=ui->modAge->text().toInt();
QString adresse=ui->modadresse->text();
QString sexe=ui->comboBox_2->currentText();
QString classe=ui->modClasse->text();

Eleve e(id ,nom ,prenom,age, adresse, sexe, classe);

bool test=e.modifier();
if(test)
{
    ui->tabeleve->setModel(e.afficher());

    QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("update effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr(" not ok"),
                QObject::tr("update non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void DialogE::on_supprimerE_clicked()
{
    int id=ui->suppID->text().toInt();
    bool test=e.supprimer(id);
    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Suppression effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr(" not ok"),
                    QObject::tr("Suppression non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void DialogE::on_recherche_clicked()
{
    QString nom=ui->le_rech->text();
     ui->tabrech->setModel(e.rechercher(nom));
}

void DialogE::on_triClasse_clicked()
{
    ui->tabrech->setModel(e.trier());

}

void DialogE::on_triAge_clicked()
{
    ui->tabrech->setModel(e.trierA());

}


void DialogE::on_nom_clicked()
{

  ui->tabrech->setModel(e.trierN());

}

void DialogE::stats(QString table,QString critere,int valeur1,int valeur2,QString unite)
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
                QChartView *chartView = new QChartView(chart); // Création dynamique avec 'new'
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->resize(1000, 500);
                chartView->show();

}



void DialogE::on_statAge_clicked()
{
      stats("eleve","AGE",2,6,"ANS");
}

void DialogE::on_excel_clicked()
{

    Eleve t;
    t.EXCEL();
}
