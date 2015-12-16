#include "areyousure.h"
#include "ui_areyousure.h"

areyousure::areyousure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::areyousure){
    ui->setupUi(this);
}

areyousure::~areyousure(){
    delete ui;
}

void areyousure::setLabel(QString newLabel){
    ui->label_text->setText(newLabel);
}

void areyousure::on_buttonBox_accepted(){
    sure = true;
}

bool areyousure::isSure() const{
    return sure;
}

void areyousure::on_buttonBox_rejected(){
    sure = false;
}
