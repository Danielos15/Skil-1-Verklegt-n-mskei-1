#include "areyousure.h"
#include "ui_areyousure.h"

areyousure::areyousure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::areyousure)
{
    ui->setupUi(this);
}

areyousure::~areyousure()
{
    delete ui;
}
