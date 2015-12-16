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

void addsci::on_button_ok_clicked()
{
    areyousure open;

    name = ui->lineEdit_name->text().toStdString();
    gender = ui->comboBox_Gender->currentIndex();
    yearBorn = ui->spinBox_Born->text().toInt();
    yearDeath = ui->spinBox_Died->text().toInt();
    info = ui->textEdit_info->toPlainText().toStdString();

    open.setLabel("Would you like to save this Scientists?");
    open.exec();

    if (open.isSure()){
        save = true;
        this->close();
    }
}

void addsci::on_button_cancel_clicked()
{
    areyousure open;
    open.setLabel("Cancel all changes?");
    open.exec();

    if (open.isSure()){
        save = false;
        this->close();
    }
}
