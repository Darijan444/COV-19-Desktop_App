#include "landingpage.h"
#include "adminmain.h"
#include "adminusers.h"
#include "adminreports.h"
#include "adminlogs.h"
#include "ui_adminlogs.h"

#include <QSqlQuery>
#include<QSqlQueryModel>

AdminLogs::AdminLogs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminLogs)
{
    ui->setupUi(this);

    //User Icon size
    int iconSize = 25;

    QPixmap admin(":/Images/user.png");
    ui->labelAdmin->setPixmap(admin.scaled(iconSize,iconSize));

    //Show user reports
    logs();

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

AdminLogs::~AdminLogs()
{
    delete ui;
}


void AdminLogs::logs()
{
    auto query = QSqlQuery(db);
    if(!query.exec("select * from logs;"))
        qDebug() << "Cannot select from members";

    //define the model
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(query);
    ui->tableView->setModel(model);
}
