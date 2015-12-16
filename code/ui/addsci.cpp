#include "addsci.h"
#include "ui_addsci.h"
#include "areyousure.h"

addsci::addsci(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addsci)
{
    ui->setupUi(this);

}

addsci::~addsci(){
    delete ui;
}

bool addsci::shouldSave() const{
    return save;
}

std::string addsci::getName() const{
    return name;
}
int addsci::getGender() const{
    return gender;
}
int addsci::getBirth() const{
    return yearBorn;
}
int addsci::getDeath() const{
    return yearDeath;
}
std::string addsci::getInfo() const{
    return info;
}

void addsci::setName(std::string newName){
    ui->lineEdit_name->setText(QString::fromStdString(newName));
}

void addsci::setGender(int newGender)
{
    ui->comboBox_Gender->setCurrentIndex(newGender);
}

void addsci::setYearBorn(int newYear)
{
    ui->spinBox_Born->setValue(newYear);
}

void addsci::setYearDeath(int newYear)
{
    ui->spinBox_Died->setValue(newYear);
}

void addsci::setInfo(std::string newInfo)
{
    ui->textEdit_info->setText(QString::fromStdString(newInfo));
}

void addsci::on_button_ok_clicked()
{
    areyousure open;
    open.setWindowTitle("Are you sure?");
    name = ui->lineEdit_name->text().toStdString();
    gender = ui->comboBox_Gender->currentIndex();
    yearBorn = ui->spinBox_Born->text().toInt();
    yearDeath = ui->spinBox_Died->text().toInt();
    info = ui->textEdit_info->toPlainText().toStdString();

    open.setLabel("Would you like to save this Scientist?");
    open.exec();

    if (open.isSure()){
        save = true;
        this->close();
    }
}

void addsci::on_button_cancel_clicked()
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
