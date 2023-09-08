#ifndef DIALOGE_H
#define DIALOGE_H

#include <QDialog>
#include"eleve.h"
#include"QChartView"
namespace Ui {
class DialogE;
}

class DialogE : public QDialog
{
    Q_OBJECT

public:
    explicit DialogE(QWidget *parent = nullptr);
    ~DialogE();

private slots:


    void on_ajouterE_clicked();

    void on_pushButton_2_clicked();

    void on_afficherE_clicked();

    void on_ModifierE_clicked();

    void on_supprimerE_clicked();

    void on_recherche_clicked();

    void on_triClasse_clicked();

    void on_triAge_clicked();

    void on_nom_clicked();

    void on_statAge_clicked();
    void stats(QString,QString,int,int,QString);

    void on_excel_clicked();
void  controlsaisir();
private:
    Ui::DialogE *ui;
    Eleve e;
};

#endif // DIALOGE_H
