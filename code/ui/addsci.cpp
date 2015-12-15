#include "addsci.h"
#include "ui_addsci.h"

addsci::addsci(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addsci)
{
    ui->setupUi(this);

}

addsci::~addsci()
{
    delete ui;
}
