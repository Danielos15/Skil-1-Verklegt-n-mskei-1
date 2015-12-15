#include "addcpu.h"
#include "ui_addcpu.h"
#include "areyousure.h"
addcpu::addcpu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addcpu)
{
    ui->setupUi(this);

}

addcpu::~addcpu()
{
    delete ui;
}



void addcpu::on_buttonBox_accepted()
{
    areyousure open;
    open.exec();
}
