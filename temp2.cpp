#include "temp2.h"
#include "ui_temp2.h"

temp2::temp2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::temp2)
{
    ui->setupUi(this);
}

temp2::~temp2()
{
    delete ui;
}
