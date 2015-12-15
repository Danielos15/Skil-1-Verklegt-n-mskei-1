#include "addsci.h"
#include "ui_addsci.h"
#include "areyousure.h"

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

void addsci::on_buttonBox_accepted()
{
    areyousure open;
    open.exec();
}
