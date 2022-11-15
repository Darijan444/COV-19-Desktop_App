#include "landingpage.h"
#include "userpage.h"
#include "userprofile.h"
#include "usercovid19testresult.h"
#include "uservaccinationresult.h"
#include "userrequestvaccinepass.h"
#include "userreportratresult.h"
#include "userreportissue.h"
#include "uservaccinepass.h"
#include "ui_userpage.h"



UserPage::UserPage(QWidget *parent, QString email) :
    QDialog(parent),
    ui(new Ui::UserPage)
{
    ui->setupUi(this);

    this->email = email;

    getUesrInfo();


    //Icons
    int iconSize = 25;

    QPixmap view1(":/Images/view.png");
    ui->labelIconView1->setPixmap(view1.scaled(iconSize,iconSize));
    QPixmap view2(":/Images/view.png");
    ui->labelIconView2->setPixmap(view2.scaled(iconSize,iconSize));
    QPixmap pass(":/Images/pass.png");
    ui->labelIconPass->setPixmap(pass.scaled(iconSize,iconSize));
    QPixmap send1(":/Images/document.png");
    ui->labelIconSend1->setPixmap(send1.scaled(iconSize,iconSize));
    QPixmap send2(":/Images/document.png");
    ui->labelIconSend2->setPixmap(send2.scaled(iconSize,iconSize));
    QPixmap user(":/Images/user.png");
    ui->labelIconUser->setPixmap(user.scaled(iconSize,iconSize));


    //->UserCovid19TestResult
    connect(ui->pushButtonCovid19TestResult,&QPushButton::clicked,[=](){
        UserCovid19TestResult * covid19TestResult = new UserCovid19TestResult(this, email);
        this->hide();
        covid19TestResult->show();
    });

    //->UserProfile
    connect(ui->pushButtonViewProfile,&QPushButton::clicked,[=](){
        UserProfile * userProfile = new UserProfile(this, email);
        this->hide();
        userProfile->show();
    });

    //->Landingpage
    connect(ui->pushButtonLogout,&QPushButton::clicked,[=](){
        LandingPage * landingpage = new LandingPage(this);
        this->hide();
        landingpage->show();
    });

    //->Vaccination Record
    connect(ui->pushButtonVaccinationRecord,&QPushButton::clicked,[=](){
        UserVaccinationResult * userVaccinationResult = new UserVaccinationResult(this, email);
        this->hide();
        userVaccinationResult->show();
    });

    //->Vaccination Pass
    if(QRVaccinePass == "---"){
        connect(ui->pushButtonVaccinePass,&QPushButton::clicked,[=](){
            UserRequestVaccinePass * userRequestVaccinePass = new UserRequestVaccinePass(this, email);
            this->hide();
            userRequestVaccinePass->show();
        });
    }else{
        connect(ui->pushButtonVaccinePass,&QPushButton::clicked,[=](){
            UserVaccinePass * userVaccinePass = new UserVaccinePass(this, email);
            this->hide();
            userVaccinePass->show();
        });
    }



    //->Report RAT Result
    connect(ui->pushButtonRATResult,&QPushButton::clicked,[=](){
        UserReportRATResult * userReportRATResult = new UserReportRATResult(this, email);
        this->hide();
        userReportRATResult->show();
    });

    //->Report issue
    connect(ui->pushButtonReportIssue,&QPushButton::clicked,[=](){
        UserReportIssue * userReportRATResult = new UserReportIssue(this, email);
        this->hide();
        userReportRATResult->show();
    });



//    if(!db.open()){
//        qWarning() << "MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();
////        return;
//    }



    //Label Name
    ui->labelUserName->setText(firstName);



}

UserPage::~UserPage()
{
    delete ui;
}


void UserPage::getUesrInfo()
{
    auto query = QSqlQuery(db);

    if (query.exec("select * from user WHERE email='"+email+"'")) {
        query.next();

        id = query.value(0).toInt();
        firstName = query.value(1).toString();
        lastName = query.value(2).toString();

        QRVaccinePass = query.value(22).toString();
    } else {
        qWarning() << query.lastError();
    }
}



