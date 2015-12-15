#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addsci.h"
#include "addcpu.h"

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

void MainWindow::on_button_sci_add_clicked()
{
    addsci addScientist;
    addScientist.exec();
}

void MainWindow::on_button_cpu_add_clicked()
{
    addcpu addComputer;
    addComputer.exec();
}

void MainWindow::on_button_sci_edit_clicked()
{
    addsci editScientist;
    editScientist.exec();
}

void MainWindow::on_button_cpu_edit_clicked()
{
    addcpu editComputer;
    editComputer.exec();
}
