#include <vector>
#include <string>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui/addsci.h"
#include "ui/addcpu.h"
#include "ui/areyousure.h"
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

    relComputers = cpu_service.getAllComputers("id",true);
    relScientists = sci_service.getAllScientists("id",true);
    displayRelationComputers(relComputers);
    displayRelationScientists(relScientists);

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::displayComputers(std::vector<Computer> computers){
    ui->table_cpu_view->setColumnHidden(0,true);
    ui->table_cpu_view->setColumnHidden(5,true);
    //Clear all existing rows
    while(ui->table_cpu_view->rowCount() > 0){
        ui->table_cpu_view->removeRow(0);
    }
    // Go thorugh all computers
    for (unsigned int i = 0; i < computers.size(); i++){
        QString Was;
        QTableWidgetItem *column0 = new QTableWidgetItem(QString::number(computers.at(i).getId()));
        QTableWidgetItem *column1 = new QTableWidgetItem(QString::fromStdString(computers.at(i).getName()));
        QTableWidgetItem *column2 = new QTableWidgetItem(QString::fromStdString(computers.at(i).getTypeName()));
        QTableWidgetItem *column3 = new QTableWidgetItem(QString::number(computers.at(i).getYearBuilt()));
        if (computers.at(i).wasBuilt()){
            Was = "Yes";
        }else {
            Was = "No";
        }
        QTableWidgetItem *column4 = new QTableWidgetItem(Was);
        QTableWidgetItem *column5 = new QTableWidgetItem(QString::fromStdString(computers.at(i).getInfo()));

        //Adding each coloumn to the row
        ui->table_cpu_view->insertRow(i);
        ui->table_cpu_view->setItem(i,0,column0);
        ui->table_cpu_view->setItem(i,1,column1);
        ui->table_cpu_view->setItem(i,2,column2);
        ui->table_cpu_view->setItem(i,3,column3);
        ui->table_cpu_view->setItem(i,4,column4);
        ui->table_cpu_view->setItem(i,5,column5);

    }
}

void MainWindow::displayScientists(std::vector<Scientist> scientists){
    ui->table_sci_view->setColumnHidden(0,true);
    ui->table_sci_view->setColumnHidden(5,true);
    ui->table_sci_view->horizontalHeader()->show();
    //Clear all existing rows
    while(ui->table_sci_view->rowCount() > 0){
        ui->table_sci_view->removeRow(0);
    }
    // Go thorugh all computers
    for (unsigned int i = 0; i < scientists.size(); i++){
        QTableWidgetItem *column0 = new QTableWidgetItem(QString::number(scientists.at(i).getId()));
        QTableWidgetItem *column1 = new QTableWidgetItem(QString::fromStdString(scientists.at(i).getName()));
        QTableWidgetItem *column2 = new QTableWidgetItem(QString::fromStdString(scientists.at(i).getSexType()));
        QTableWidgetItem *column3 = new QTableWidgetItem(QString::number(scientists.at(i).getYearBorn()));
        int alive = scientists.at(i).getYearDied();
        QTableWidgetItem *column4;
        if (alive == 0){
            column4 = new QTableWidgetItem("Still alive");
        }else {
            column4 = new QTableWidgetItem(QString::number(scientists.at(i).getYearDied()));
        }
        QTableWidgetItem *column5 = new QTableWidgetItem(QString::fromStdString(scientists.at(i).getInfo()));

        //Adding each coloumn to the row
        ui->table_sci_view->insertRow(i);
        ui->table_sci_view->setItem(i,0,column0);
        ui->table_sci_view->setItem(i,1,column1);
        ui->table_sci_view->setItem(i,2,column2);
        ui->table_sci_view->setItem(i,3,column3);
        ui->table_sci_view->setItem(i,4,column4);
        ui->table_sci_view->setItem(i,5,column5);
    }
}

void MainWindow::displayRelationComputers(std::vector<Computer> computers)
{
    ui->list_rel_cpu->clear();
    for (unsigned int i = 0; i < computers.size(); i++){
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(computers.at(i).getName()));
        QVariant v;
        v.setValue(computers.at(i).getId());
        item->setData(Qt::UserRole,v);
        ui->list_rel_cpu->addItem(item);
    }
}

void MainWindow::displayRelationScientists(std::vector<Scientist> scientists)
{
    ui->list_rel_sci->clear();
    for (unsigned int i = 0; i < scientists.size(); i++){
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(scientists.at(i).getName()));
        QVariant v;
        v.setValue(scientists.at(i).getId());
        item->setData(Qt::UserRole,v);
        ui->list_rel_sci->addItem(item);
    }
}

void MainWindow::on_button_sci_add_clicked(){
    addsci addScientist;
    addScientist.setWindowTitle("Add a scientist");
    addScientist.exec();

    if (addScientist.shouldSave()) {
        Scientist sci(addScientist.getName(),
                      static_cast<sexType>(addScientist.getGender()),
                      addScientist.getBirth(),
                      addScientist.getDeath()
                      );
        sci.setInfo(addScientist.getInfo());
        sci_service.addScientist(sci);
        scientists.push_back(sci);
        displayScientists(scientists);
    }
}
void MainWindow::on_button_cpu_add_clicked(){
    addcpu addComputer;
    addComputer.setWindowTitle("Add a computer");
    addComputer.exec();

    if (addComputer.shouldSave()){
        Computer cpu(addComputer.getName(),
                     static_cast<computerType>(addComputer.getType()),
                     addComputer.getYearBuilt()
                     );
        cpu.setInfo(addComputer.getInfo());
        cpu.setWasBuilt(addComputer.getWasBuilt());
        cpu_service.addComputer(cpu);
        computers.push_back(cpu);
        displayComputers(computers);
    }
}

void MainWindow::on_button_sci_edit_clicked(){
    addsci editScientist;
    editScientist.setWindowTitle("Edit the scientist");
    editScientist.exec();
}

void MainWindow::on_button_cpu_edit_clicked(){
    addcpu editComputer;
    editComputer.setWindowTitle("Edit the computer");
    editComputer.exec();  
}

void MainWindow::on_actionExit_triggered(){
    QApplication::quit();
}

void MainWindow::on_actionAdd_Scientist_triggered(){
    on_button_sci_add_clicked();

}

void MainWindow::on_actionAdd_Computer_triggered(){
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

void MainWindow::on_table_sci_view_clicked(const QModelIndex &index){
    QString name = ui->table_sci_view->item(index.row(),1)->text();
    QString info = ui->table_sci_view->item(index.row(),5)->text();
    ui->label_sci_bio->setText("<h2>About " + name + "</h2>");
    ui->text_sci_bio->setText(info);

    ui->button_sci_remove->setEnabled(true);
}

void MainWindow::on_table_cpu_view_clicked(const QModelIndex &index){
    QString name = ui->table_cpu_view->item(index.row(),1)->text();
    QString info = ui->table_cpu_view->item(index.row(),5)->text();
    ui->label_cpu_bio->setText("<h2>About " + name + "</h2>");
    ui->text_cpu_bio->setText(info);

    ui->button_cpu_remove->setEnabled(true);
}

void MainWindow::on_button_sci_remove_clicked()
{
    areyousure window;
    window.setWindowTitle("Are you sure?");
    window.setLabel("Are you sure you want to delete this scientist?");
    window.exec();
    if (window.isSure()){
        QItemSelectionModel *select = ui->table_sci_view->selectionModel();
        std::vector<QModelIndex> index = select->selectedRows().toVector().toStdVector();
        for (unsigned int i = 0; i < index.size();i++){
            int sci_id = ui->table_sci_view->item(index.at(i).row(),0)->text().toInt();
            sci_service.removeScientist(sci_id);
            scientists = sci_service.getAllScientists("id",true);
            displayScientists(scientists);
            ui->button_sci_remove->setEnabled(false);
        }
    }
}

void MainWindow::on_button_cpu_remove_clicked()
{
    areyousure window;
    window.setWindowTitle("Are you sure?");
    window.setLabel("Are you sure you want to delete this computer?");
    window.exec();
    if (window.isSure()){
        QItemSelectionModel *select = ui->table_cpu_view->selectionModel();
        std::vector<QModelIndex> index = select->selectedRows().toVector().toStdVector();
        for (unsigned int i = 0; i < index.size();i++){
            int cpu_id = ui->table_cpu_view->item(index.at(i).row(),0)->text().toInt();
            cpu_service.removeComputer(cpu_id);
            computers = cpu_service.getAllComputers("id",true);
            displayComputers(computers);
            ui->button_cpu_remove->setEnabled(false);
        }
    }
}

void MainWindow::on_list_rel_sci_clicked(const QModelIndex &index)
{
    QVariant v = ui->list_rel_sci->itemAt(index.row(),index.column())->data(Qt::UserRole);
    int id = v.value<int>();
    qDebug() << id;
}

void MainWindow::on_list_rel_cpu_clicked(const QModelIndex &index)
{
    QVariant v = ui->list_rel_cpu->itemAt(index.row(),index.column())->data(Qt::UserRole);
    int id = v.value<int>();
    qDebug() << id;
}
