#ifndef DIALOGAC_H
#define DIALOGAC_H

#include <QDialog>
#include "activite.h"
namespace Ui {
class DialogAc;
}

class DialogAc : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAc(QWidget *parent = nullptr);
    ~DialogAc();

private slots:
    void on_ajouter_clicked();

    void on_btnAfficher_clicked();

    void on_btnmodifAc_clicked();

    void on_btnsupAc_clicked();

    void on_rechercheAc_clicked();

    void on_triNom_clicked();

    void on_triD_clicked();

    void on_triId_clicked();
void  controlsaisir();
void dateSelectionChanged();
private:
    Ui::DialogAc *ui;
    Activite ac;
};

#endif // DIALOGAC_H
