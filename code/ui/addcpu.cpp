#include "addcpu.h"
#include "ui_addcpu.h"
#include "areyousure.h"
addcpu::addcpu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addcpu)
{
    ui->setupUi(this);

}

addcpu::~addcpu(){
    delete ui;
}

bool addcpu::shouldSave() const{
    return save;
}
std::string addcpu::getName() const{
    return name;
}
int addcpu::getType() const{
    return type;
}
int addcpu::getYearBuilt() const{
    return yearBuilt;
}
bool addcpu::getWasBuilt() const{
    return wasBuilt;
}
std::string addcpu::getInfo() const{
    return info;
}

void addcpu::setName(std::string newName){
    ui->lineEdit_Name->setText(QString::fromStdString(newName));
}

void addcpu::setType(int newType){
    ui->comboBox_Type->setCurrentIndex(newType);
}

void addcpu::setYearBuilt(int newYear){
    ui->spinBox_Buildyear->setValue(newYear);
}

void addcpu::setWasBuilt(bool newWas){
    ui->comboBox_WasBuilt->setCurrentIndex(newWas);
}

void addcpu::setInfo(std::string newInfo){
    ui->textEdit_info->setText(QString::fromStdString(newInfo));
}


void addcpu::on_button_ok_clicked()
{
    areyousure open;
    open.setWindowTitle("Are you sure?");

    name = ui->lineEdit_Name->text().toStdString();
    type = ui->comboBox_Type->currentIndex();
    yearBuilt = ui->spinBox_Buildyear->text().toInt();
    wasBuilt = ui->comboBox_WasBuilt->currentIndex();
    info = ui->textEdit_info->toPlainText().toStdString();

    open.setLabel("Would you like to save this Computer?");
    open.exec();

    if (open.isSure()){
        save = true;
        this->close();
    }
}

void addcpu::on_button_cancel_clicked()
{
    areyousure open;
    open.setWindowTitle("Are you sure?");
    open.setLabel("Cancel all changes?");
    open.exec();

    if (open.isSure()){
        save = false;
        this->close();
    }
}
