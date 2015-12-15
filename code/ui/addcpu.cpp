#include "addcpu.h"
#include "ui_addcpu.h"

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


