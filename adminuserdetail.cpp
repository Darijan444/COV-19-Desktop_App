#include "adminuserdetail.h"
#include "ui_adminuserdetail.h"

AdminUserDetail::AdminUserDetail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminUserDetail)
{
    ui->setupUi(this);
}

AdminUserDetail::~AdminUserDetail()
{
    delete ui;
}
