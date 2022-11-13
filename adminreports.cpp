#include "landingpage.h"
#include "adminmain.h"
#include "adminusers.h"
#include "adminreports.h"
#include "adminlogs.h"
#include "ui_adminreports.h"

#include <QSqlQuery>
#include<QSqlQueryModel>

AdminReports::AdminReports(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminReports)
{
    ui->setupUi(this);

    //User Icon size
    int iconSize = 25;

    QPixmap admin(":/Images/user.png");
    ui->labelAdmin->setPixmap(admin.scaled(iconSize,iconSize));

    //Show user reports
    userReports();

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
}

AdminReports::~AdminReports()
{
    delete ui;
}

void AdminReports::userReports()
{
    auto query = QSqlQuery(db);
    if(!query.exec("select * from reports;"))
        qDebug() << "Cannot select from members";

    //define the model
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(query);
    ui->tableView->setModel(model);
}

