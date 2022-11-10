#include "landingpage.h"
#include "adminmain.h"
#include "adminusers.h"
#include "adminreports.h"
#include "adminlogs.h"
#include "ui_adminmain.h"

AdminMain::AdminMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminMain)
{
    ui->setupUi(this);

    //User Icon size
    int iconSize = 25;

    QPixmap admin(":/Images/user.png");
    ui->labelAdmin->setPixmap(admin.scaled(iconSize,iconSize));

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


AdminMain::~AdminMain()
{
    delete ui;
}

void AdminMain::labelUsers()
{
    qDebug() << "Function";
    AdminUsers * adminUsers = new AdminUsers(this);
    this->hide();
    adminUsers->show();
}
