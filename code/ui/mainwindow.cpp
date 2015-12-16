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

    ui->button_cpu_edit->setShortcut(QKeySequence(Qt::Key_E));
    ui->button_cpu_remove->setShortcut(QKeySequence(Qt::Key_R));
    ui->button_sci_edit->setShortcut(QKeySequence(Qt::Key_E));
    ui->button_sci_remove->setShortcut(QKeySequence(Qt::Key_R));
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
    ui->list_rel_cpu->setColumnHidden(0,true);

    //Clear all existing rows
    while(ui->list_rel_cpu->rowCount() > 0){
        ui->list_rel_cpu->removeRow(0);
    }
    // Go thorugh all computers
    for (unsigned int i = 0; i < computers.size(); i++){
        QTableWidgetItem *column0 = new QTableWidgetItem(QString::number(computers.at(i).getId()));
        QTableWidgetItem *column1 = new QTableWidgetItem(QString::fromStdString(computers.at(i).getName()));

        //Adding each coloumn to the row
        ui->list_rel_cpu->insertRow(i);
        ui->list_rel_cpu->setItem(i,0,column0);
        ui->list_rel_cpu->setItem(i,1,column1);

    }
}

void MainWindow::displayRelationScientists(std::vector<Scientist> scientists)
{
    ui->list_rel_sci->setColumnHidden(0,true);

    //Clear all existing rows
    while(ui->list_rel_sci->rowCount() > 0){
        ui->list_rel_sci->removeRow(0);
    }
    // Go thorugh all computers
    for (unsigned int i = 0; i < scientists.size(); i++){
        QTableWidgetItem *column0 = new QTableWidgetItem(QString::number(scientists.at(i).getId()));
        QTableWidgetItem *column1 = new QTableWidgetItem(QString::fromStdString(scientists.at(i).getName()));

        //Adding each coloumn to the row
        ui->list_rel_sci->insertRow(i);
        ui->list_rel_sci->setItem(i,0,column0);
        ui->list_rel_sci->setItem(i,1,column1);

    }
}

void MainWindow::displayCommonComputers(std::vector<Computer> computers){
    ui->list_rel_common->setColumnHidden(0,true);

    //Clear all existing rows
    while(ui->list_rel_common->rowCount() > 0){
        ui->list_rel_common->removeRow(0);
    }
    // Go thorugh all computers
    for (unsigned int i = 0; i < computers.size(); i++){
        QTableWidgetItem *column0 = new QTableWidgetItem(QString::number(computers.at(i).getId()));
        QTableWidgetItem *column1 = new QTableWidgetItem(QString::fromStdString(computers.at(i).getName()));

        //Adding each coloumn to the row
        ui->list_rel_common->insertRow(i);
        ui->list_rel_common->setItem(i,0,column0);
        ui->list_rel_common->setItem(i,1,column1);

    }
}

void MainWindow::displayCommonScientists(std::vector<Scientist> scientists){
    ui->list_rel_common->setColumnHidden(0,true);

    //Clear all existing rows
    while(ui->list_rel_common->rowCount() > 0){
        ui->list_rel_common->removeRow(0);
    }
    // Go thorugh all computers
    for (unsigned int i = 0; i < scientists.size(); i++){
        QTableWidgetItem *column0 = new QTableWidgetItem(QString::number(scientists.at(i).getId()));
        QTableWidgetItem *column1 = new QTableWidgetItem(QString::fromStdString(scientists.at(i).getName()));

        //Adding each coloumn to the row
        ui->list_rel_common->insertRow(i);
        ui->list_rel_common->setItem(i,0,column0);
        ui->list_rel_common->setItem(i,1,column1);

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
        relScientists = sci_service.getAllScientists("id",true);
        displayScientists(scientists);
        displayRelationScientists(relScientists);
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
        relComputers = cpu_service.getAllComputers("id",true);
        displayComputers(computers);
        displayRelationComputers(relComputers);
    }
}

void MainWindow::on_button_sci_edit_clicked(){
    addsci editScientist;

    QItemSelectionModel *select = ui->table_sci_view->selectionModel();
    std::vector<QModelIndex> index = select->selectedRows().toVector().toStdVector();
    int sci_id = ui->table_sci_view->item(index.at(0).row(),0)->text().toInt();
    Scientist sci = sci_service.fetchById(sci_id);

    editScientist.setName(sci.getName());
    editScientist.setGender(sci.getSex());
    editScientist.setYearBorn(sci.getYearBorn());
    editScientist.setYearDeath(sci.getYearDied());
    editScientist.setInfo(sci.getInfo());

    editScientist.setWindowTitle("Edit the scientist");
    editScientist.exec();

    if (editScientist.shouldSave()) {
        Scientist editSci(editScientist.getName(),
                      static_cast<sexType>(editScientist.getGender()),
                      editScientist.getBirth(),
                      editScientist.getDeath()
                      );
        editSci.setInfo(editScientist.getInfo());
        sci_service.editScientist(editSci, sci_id);
        scientists = sci_service.getAllScientists("id", true);
        displayScientists(scientists);
        ui->button_sci_edit->setEnabled(false);
        ui->button_sci_remove->setEnabled(false);
    }
}

void MainWindow::on_button_cpu_edit_clicked(){
    addcpu editComputer;

    QItemSelectionModel *select = ui->table_cpu_view->selectionModel();
    std::vector<QModelIndex> index = select->selectedRows().toVector().toStdVector();
    int cpu_id = ui->table_cpu_view->item(index.at(0).row(),0)->text().toInt();
    Computer cpu = cpu_service.fetchById(cpu_id);

    editComputer.setName(cpu.getName());
    editComputer.setType(cpu.getType());
    editComputer.setYearBuilt(cpu.getYearBuilt());
    editComputer.setWasBuilt(cpu.wasBuilt());
    editComputer.setInfo(cpu.getInfo());

    editComputer.setWindowTitle("Edit the computer");
    editComputer.exec();

    if (editComputer.shouldSave()) {
        Computer editCpu(editComputer.getName(),
                      static_cast<computerType>(editComputer.getType()),
                      editComputer.getYearBuilt()
                      );
        editCpu.setWasBuilt(editComputer.getWasBuilt());
        editCpu.setInfo(editComputer.getInfo());
        cpu_service.editComputer(editCpu, cpu_id);
        computers = cpu_service.getAllComputers("id", true);
        displayComputers(computers);
        ui->button_cpu_edit->setEnabled(false);
        ui->button_cpu_remove->setEnabled(false);
    }
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

void MainWindow::actionAdd_Relation_triggered(){
    on_button_rel_add_clicked();
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

    ui->button_sci_edit->setEnabled(true);
    ui->button_sci_remove->setEnabled(true);
}

void MainWindow::on_table_cpu_view_clicked(const QModelIndex &index){
    QString name = ui->table_cpu_view->item(index.row(),1)->text();
    QString info = ui->table_cpu_view->item(index.row(),5)->text();
    ui->label_cpu_bio->setText("<h2>About " + name + "</h2>");
    ui->text_cpu_bio->setText(info);

    ui->button_cpu_edit->setEnabled(true);
    ui->button_cpu_remove->setEnabled(true);
}

void MainWindow::on_button_sci_remove_clicked(){
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
            ui->button_sci_edit->setEnabled(false);
            ui->button_sci_remove->setEnabled(false);
        }
    }
}

void MainWindow::on_button_cpu_remove_clicked(){
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
            ui->button_cpu_edit->setEnabled(false);
            ui->button_cpu_remove->setEnabled(false);
        }
    }
}

void MainWindow::on_list_rel_sci_clicked(const QModelIndex &index){
    int sci_id = ui->list_rel_sci->item(index.row(),0)->text().toInt();
    Scientist sci = sci_service.fetchById(sci_id);
    commonComputers = sci_service.queryComputersByScientist(sci);
    displayCommonComputers(commonComputers);

    QItemSelectionModel *selectCpu = ui->list_rel_cpu->selectionModel();
    if (selectCpu->hasSelection()){
        ui->button_rel_add->setEnabled(true);
    }

}

void MainWindow::on_list_rel_cpu_clicked(const QModelIndex &index){
    int cpu_id = ui->list_rel_cpu->item(index.row(),0)->text().toInt();
    Computer cpu = cpu_service.fetchById(cpu_id);
    commonScientists = cpu_service.queryScientistsByComputer(cpu);
    displayCommonScientists(commonScientists);

    QItemSelectionModel *selectSci = ui->list_rel_sci->selectionModel();
    if (selectSci->hasSelection()){
        ui->button_rel_add->setEnabled(true);
    }
}
void MainWindow::on_input_sci_rel_search_textChanged(const QString &arg1){
    relScientists = sci_service.searchForScientists(arg1.toStdString());
    displayRelationScientists(relScientists);
}

void MainWindow::on_input_rel_cpu_search_textChanged(const QString &arg1){
    relComputers = cpu_service.searchForComputers(arg1.toStdString());
    displayRelationComputers(relComputers);
}

void MainWindow::on_button_rel_add_clicked()
{
    int cpu_id;
    QItemSelectionModel *selectCpu = ui->list_rel_cpu->selectionModel();
    if (selectCpu->hasSelection()){
        std::vector<QModelIndex> indexCpu = selectCpu->selectedIndexes().toVector().toStdVector();
        cpu_id = ui->list_rel_cpu->item(indexCpu.at(0).row(),0)->text().toInt();
    }
    int sci_id;
    QItemSelectionModel *selectSci = ui->list_rel_sci->selectionModel();
    if (selectSci->hasSelection()){
        std::vector<QModelIndex> index = selectSci->selectedIndexes().toVector().toStdVector();
        sci_id = ui->list_rel_sci->item(index.at(0).row(),0)->text().toInt();
    }
    areyousure window;
    window.setWindowTitle("Add relation");
    window.setLabel("Are you sure you want to connect those two together?");
    window.exec();

    if (window.isSure()){
        link_service.addLink(sci_id,cpu_id);
        ui->button_rel_add->setEnabled(false);
    }
}
