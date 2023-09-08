#include "dialogac.h"
#include "ui_dialogac.h"
#include<QMessageBox>
#include "activite.h"
#include<QTableWidgetItem>
DialogAc::DialogAc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAc)
{
    ui->setupUi(this);
    ui->tableac->setModel(ac.afficher());
    ui->comboBoxAc->addItem("Sportive");
    ui->comboBoxAc->addItem("Musique");
    ui->comboBoxAc->addItem("Jeu de societe");
    ui->comboBoxAc->addItem("Art plastique");
    ui->comboBoxmodifdomaine->addItem("Sportive");
    ui->comboBoxmodifdomaine->addItem("Musique");
    ui->comboBoxmodifdomaine->addItem("Jeu de societe");
    ui->comboBoxmodifdomaine->addItem("Art plastique");
    connect(ui->calendarWidget, SIGNAL(selectionChanged()), this, SLOT(dateSelectionChanged()));
    //connect(ui->calendarWidget, SIGNAL(selectionChanged()), this, SLOT(on_calendarWidget_selectionChanged()));

    QMap<QDate, QList<Activite>> activitesParDate;


}

DialogAc::~DialogAc()
{
    delete ui;
}
void DialogAc:: controlsaisir()
{
   // ui->tab_6->close();

    //ajouter
    ui->le_idAc->setMaxLength(8);
    ui->le_nomAc->setMaxLength(25);





    ui->modifacid->setMaxLength(8);
    ui->modifacnom->setMaxLength(25);


    // supprimer
    ui->suppAc->setMaxLength(8);

}


/*void DialogAc::dateSelectionChanged()
{
    qDebug() << "Selection changed!";
    QDate selectedDate = ui->calendarWidget->selectedDate();
       QString dateString = selectedDate.toString("yyyy-MM-dd");
       qDebug() << "Selected date: " << dateString;

       QList<Activite> activitesPourDate = activitesParDate[selectedDate];

        QSqlQueryModel *resultModel = ac.rechercherParDate(selectedDate);

        // Affichez les résultats dans votre QTableView ou autre widget approprié
        ui->tableCal->setModel(resultModel);
}*/

void DialogAc::on_ajouter_clicked()
{
    int Id=ui->le_idAc->text().toInt();
    QString nom=ui->le_nomAc->text();
    QString domaine=ui->comboBoxAc->currentText();
    QDateTime dateDebut = ui->dateTimeDebut->dateTime();
        QDateTime dateFin = ui->dateTimeFin->dateTime();

        Activite a(Id ,nom ,domaine, dateDebut, dateFin);

        bool test=a.ajouter();
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

void DialogAc::on_btnAfficher_clicked()
{
    ui->tableac->setModel(ac.afficher());
}

void DialogAc::on_btnmodifAc_clicked()
{
int idAc=ui->modifacid->text().toInt();
QString nomAc=ui->modifacnom->text();
QString domaine=ui->comboBoxmodifdomaine->currentText();
QDateTime dateDebut = ui->ModdateTimeDebut->dateTime();
QDateTime dateFin = ui->ModdateTimeFin->dateTime();

Activite a(idAc ,nomAc ,domaine, dateDebut, dateFin);

bool test=a.modifier();
if(test)
{
    ui->tableac->setModel(a.afficher());

    QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("update effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr(" not ok"),
                QObject::tr("update non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}


void DialogAc::on_btnsupAc_clicked()
{
    int idAc=ui->suppAc->text().toInt();
    bool test=ac.supprimer(idAc);
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

void DialogAc::on_rechercheAc_clicked()
{
    QString nom=ui->rechAc_2->text();
     ui->rechAc->setModel(ac.rechercher(nom));
}

void DialogAc::on_triNom_clicked()
{
    ui->rechAc->setModel(ac.trierN());

}

void DialogAc::on_triD_clicked()
{
    ui->rechAc->setModel(ac.trierD());

}

void DialogAc::on_triId_clicked()
{
    ui->rechAc->setModel(ac.trier());

}
void DialogAc::dateSelectionChanged()
{
    qDebug() << "Selection changed!";
    QDate selectedDate = ui->calendarWidget->selectedDate();
    qDebug() << "Selected date: " << selectedDate.toString("dd-MM-yy");

    QSqlQueryModel *resultModel = ac.rechercherParDate(selectedDate);

    // Affichez les résultats dans votre QTableView ou autre widget approprié
    ui->tableCal->setModel(resultModel);

    qDebug() << "Nombre d'activités pour la date sélectionnée : " << resultModel->rowCount();
}

/*
void DialogAc::dateSelectionChanged()
{
    qDebug() << "Selection changed!";
    QDate selectedDate = ui->calendarWidget->selectedDate();
    qDebug() << "Selected date: " << selectedDate.toString("dd-MM-yyyy");

    QList<Activite> activites = Activite::toutesLesActivites();
    QList<Activite> activitesPourDate;

    foreach (const Activite& activite, activites)
    {
        qDebug() << "Date de début : " << ac.getDateDebut().toString("dd-MM-yyyy HH:mm:ss");
        qDebug() << "Date de fin : " << ac.getDateFin().toString("dd-MM-yyyy HH:mm:ss");

        if (ac.getDateDebut().date() == selectedDate || ac.getDateFin().date() == selectedDate)
        {
            activitesPourDate.append(ac);
        }
    }
    qDebug() << "Nombre d'activités pour la date sélectionnée : " << activitesPourDate.size();
    foreach (const Activite& activite, activitesPourDate)
    {
        qDebug() << "Activité trouvée : " << ac.getNomAc(); // Ou une autre propriété pertinente de votre classe Activite
    }
    QSqlQueryModel *resultModel = ac.rechercherParDate(selectedDate);

    // Affichez les résultats dans votre QTableView ou autre widget approprié
    ui->tableCal->setModel(resultModel);


}*/
/*
void DialogAc::dateSelectionChanged()
{
    QDate selectedDate = ui->calendarWidget->selectedDate();
    qDebug() << "Selected date: " << selectedDate.toString("dd-MM-yyyy");

    QSqlQueryModel *model = ac.rechercherParDate(selectedDate);

    if (model)
    {
        ui->tableac->setModel(model);
        ui->tableac->resizeColumnsToContents();
    }
    else
    {
        // Gérer les erreurs ici
    }
}*/




