#include "adminuserdetail.h"
#include "landingpage.h"
#include "adminmain.h"
#include "adminusers.h"
#include "adminreports.h"
#include "adminlogs.h"
#include "ui_adminuserdetail.h"

#include <QVBoxLayout>

//AdminUserDetail::AdminUserDetail(QWidget *parent, int id) :
AdminUserDetail::AdminUserDetail(QWidget *parent, int num) :
    QDialog(parent),
    ui(new Ui::AdminUserDetail)
{
    ui->setupUi(this);

    //Get User ID
//    this->id = id;
    this->num = num;


    QVBoxLayout * lay = new QVBoxLayout(this);
//    for (int i = 0; i < 15; ++i)
//    {
//        QPushButton *boton = new QPushButton("Hello, this is a button, and iam large");
//        lay->addWidget(boton);
//    }
    ui->scrollArea->setLayout(lay);





    //Get User Information
    getUesrInfo();

    //Icons
    int iconSizeL = 200;

    QPixmap qrcode(":/Images/qrcode.png");
    ui->labelQRCode->setPixmap(qrcode.scaled(iconSizeL,iconSizeL));

    //Set User Information
    ui->labelName->setText(firstName + " "+ lastName);
    ui->labelEmail->setText(email);
    ui->labelNHINumber->setText(NHINumber);
    ui->labelDateOfBirth->setText(birthday);
    ui->labelMobileNumber->setText(phone);


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

AdminUserDetail::~AdminUserDetail()
{
    delete ui;
}

//Get User Information
void AdminUserDetail::getUesrInfo()
{
    auto query = QSqlQuery(db);

//    QString email = "test3@gmail.com";
    qDebug() << "ID: " << id;

    QString numString = QString::number(num);
//    QString idString = QString::number(id);

//    if (query.exec("select * from user WHERE email='"+email+"'")) {
//    if (query.exec("select * from user WHERE ID="+id)) {
    if (query.exec("select * from user WHERE ID='"+numString+"'")) {
//    if (query.exec("select * from user WHERE UID='"+idString+"'")) {
//    if (query.exec("select * from user WHERE ID=3")) {
        query.next();
        id = query.value(0).toInt();
        firstName = query.value(1).toString();
        lastName = query.value(2).toString();
        birthday = query.value(3).toString();
        NHINumber = query.value(4).toString();
        email = query.value(5).toString();
        phone = query.value(6).toString();
//        password = query.value(7).toString();
//        dose1Date = query.value(8).toString();
//        dose1Manufacturer = query.value(9).toString();
//        dose1BatchNumber = query.value(10).toString();
//        dose2Date = query.value(11).toString();
//        dose2Manufacturer = query.value(12).toString();
//        dose2BatchNumber = query.value(13).toString();
//        RAT1Date = query.value(14).toString();
//        RAT1KitName = query.value(15).toString();
//        RAT1Result = query.value(16).toString();
//        RAT2Date = query.value(17).toString();
//        RAT2KitName = query.value(18).toString();
//        RAT2Result = query.value(19).toString();

    } else {
        qWarning() << query.lastError();
    }
}
