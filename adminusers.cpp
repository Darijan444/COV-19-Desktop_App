#include "landingpage.h"
#include "adminmain.h"
#include "adminusers.h"
#include "adminreports.h"
#include "adminlogs.h"
#include "adminuserdetail3.h"
#include "ui_adminusers.h"

#include <QSqlQuery>
#include<QSqlQueryModel>

AdminUsers::AdminUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminUsers)
{
    ui->setupUi(this);

    //User Icon size
    int iconSize = 25;

    QPixmap admin(":/Images/user.png");
    ui->labelAdmin->setPixmap(admin.scaled(iconSize,iconSize));

    //Show user lists
    userList();

    //->Landingpage
    connect(ui->pushButtonLogout,&QPushButton::clicked,[=](){
        LandingPage * landingpage = new LandingPage(this);
        this->hide();
        landingpage->show();
    });

    //->AdminMain
    connect(ui->pushButtonDashboard,&QPushButton::clicked,[=](){
        AdminMain * adminmain = new AdminMain(this);
        this->hide();
        adminmain->show();
    });

    //->AdminUsers
    connect(ui->pushButtonUsers,&QPushButton::clicked,[=](){
        AdminUsers * adminUsers = new AdminUsers(this);
        this->hide();
        adminUsers->show();
    });

    //->AdminReports
    connect(ui->pushButtonReports,&QPushButton::clicked,[=](){
        AdminReports * adminReports = new AdminReports(this);
        this->hide();
        adminReports->show();
    });

    //->AdminLogs
    connect(ui->pushButtonLogs,&QPushButton::clicked,[=](){
        AdminLogs * adminLogs = new AdminLogs(this);
        this->hide();
        adminLogs->show();
    });

    //->AdminUserDetail
    connect(ui->pushButtonEdit,&QPushButton::clicked,[=](){
        num = ui->spinBoxUserID->value();

        AdminUserDetail3 * adminuserdetail = new AdminUserDetail3(this, num);
        this->hide();
        adminuserdetail->show();
    });
}

AdminUsers::~AdminUsers()
{
    delete ui;
}



void AdminUsers::userList()
{
    auto query = QSqlQuery(db);
    if(!query.exec("select * from user;"))
        qDebug() << "Cannot select from members";

    //define the model
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(query);
    ui->tableView->setModel(model);
//        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


