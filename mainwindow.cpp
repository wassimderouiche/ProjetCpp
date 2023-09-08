#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialoge.h"
#include<QApplication>
#include<QMessageBox>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QFileDialog>
#include <QDebug>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "dialogac.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
     DialogE e;
     e.setModal(true);
     e.exec();
}

void MainWindow::on_gestiona_clicked()
{
    this->hide();
     DialogAc ac;
     ac.setModal(true);
     ac.exec();
}
