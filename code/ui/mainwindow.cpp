#include <vector>
#include <string>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui/addsci.h"
#include "ui/addcpu.h"
#include <QDebug>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    ui->setupUi(this);

    computers = cpu_service.getAllComputers("id",true);
    scientists = sci_service.getAllScientists("id",true);
    displayComputers(computers);
    displayScientists(scientists);

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::displayComputers(std::vector<Computer> computers){
    //Clear all existing rows
    while(ui->table_cpu_view->rowCount() > 0){
        ui->table_cpu_view->removeRow(0);
    }
    // Go thorugh all computers
    for (unsigned int i = 0; i < computers.size(); i++){
        QString Was;
        QTableWidgetItem *column1 = new QTableWidgetItem(QString::fromStdString(computers.at(i).getName()));
        QTableWidgetItem *column2 = new QTableWidgetItem(QString::fromStdString(computers.at(i).getTypeName()));
        QTableWidgetItem *column3 = new QTableWidgetItem(QString::number(computers.at(i).getYearBuilt()));
        if (computers.at(i).wasBuilt()){
            Was = "Yes";
        }else {
            Was = "No";
        }
        QTableWidgetItem *column4 = new QTableWidgetItem(Was);

        //Adding each coloumn to the row
        ui->table_cpu_view->insertRow(i);
        ui->table_cpu_view->setItem(i,0,column1);
        ui->table_cpu_view->setItem(i,1,column2);
        ui->table_cpu_view->setItem(i,2,column3);
        ui->table_cpu_view->setItem(i,3,column4);
    }
}

void MainWindow::displayScientists(std::vector<Scientist> scientists){
    //Clear all existing rows
    while(ui->table_sci_view->rowCount() > 0){
        ui->table_sci_view->removeRow(0);
    }
    // Go thorugh all computers
    for (unsigned int i = 0; i < scientists.size(); i++){
        QTableWidgetItem *column1 = new QTableWidgetItem(QString::fromStdString(scientists.at(i).getName()));
        QTableWidgetItem *column2 = new QTableWidgetItem(QString::fromStdString(scientists.at(i).getSexType()));
        QTableWidgetItem *column3 = new QTableWidgetItem(QString::number(scientists.at(i).getYearBorn()));
        QTableWidgetItem *column4 = new QTableWidgetItem(QString::number(scientists.at(i).getYearDied()));

        //Adding each coloumn to the row
        ui->table_sci_view->insertRow(i);
        ui->table_sci_view->setItem(i,0,column1);
        ui->table_sci_view->setItem(i,1,column2);
        ui->table_sci_view->setItem(i,2,column3);
        ui->table_sci_view->setItem(i,3,column4);
    }
}

void MainWindow::on_button_sci_add_clicked(){
    addsci addScientist;
    addScientist.exec();
}

void MainWindow::on_button_cpu_add_clicked(){
    addcpu addComputer;
    addComputer.exec();
}

void MainWindow::on_button_sci_edit_clicked(){
    addsci editScientist;
    editScientist.exec();
}

void MainWindow::on_button_cpu_edit_clicked(){
    addcpu editComputer;
    editComputer.exec();  
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAdd_Scientist_triggered()
{
    on_button_sci_add_clicked();

}

void MainWindow::on_actionAdd_Computer_triggered()
{
    on_button_cpu_add_clicked();
}

void MainWindow::on_input_sci_search_textChanged(const QString &arg1){
    scientists = sci_service.searchForScientists(arg1.toStdString());
    displayScientists(scientists);
}

void MainWindow::on_input_cpu_search_textChanged(const QString &arg1){
    computers = cpu_service.searchForComputers(arg1.toStdString());
    displayComputers(computers);
}
