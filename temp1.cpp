#include "temp1.h"
#include "ui_temp1.h"

Temp1::Temp1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Temp1)
{
    ui->setupUi(this);
}

Temp1::~Temp1()
{
    delete ui;
}
