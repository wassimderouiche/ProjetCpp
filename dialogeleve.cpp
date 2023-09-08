#include "dialogeleve.h"
#include "ui_dialogeleve.h"

DialogEleve::DialogEleve(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEleve)
{
    ui->setupUi(this);
}

DialogEleve::~DialogEleve()
{
    delete ui;
}
