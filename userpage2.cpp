#include "userpage2.h"
#include "ui_userpage2.h"

UserPage2::UserPage2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserPage2)
{
    ui->setupUi(this);
}

UserPage2::~UserPage2()
{
    delete ui;
}
