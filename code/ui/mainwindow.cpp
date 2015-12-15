#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addsci.h"

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
    addScientist.setModal(true);
    addScientist.exec();
}
