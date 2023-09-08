#ifndef DIALOGELEVE_H
#define DIALOGELEVE_H
#include"eleve.h"
#include <QDialog>

namespace Ui {
class DialogEleve;
}

class DialogEleve : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEleve(QWidget *parent = nullptr);
    ~DialogEleve();

private:
    Ui::DialogEleve *ui;
    Eleve e;
};

#endif // DIALOGELEVE_H
