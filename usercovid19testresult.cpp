#include "landingpage.h"
#include "userpage.h"
#include "usercovid19testresult.h"
#include "ui_usercovid19testresult.h"

UserCovid19TestResult::UserCovid19TestResult(QWidget *parent, QString email) :
    QDialog(parent),
    ui(new Ui::UserCovid19TestResult)
{
    ui->setupUi(this);

    //Get User email
    this->email = email;

    //Get User Information
    getUesrInfo();


    //Icons
    int iconSize = 25;

    QPixmap user(":/Images/user.png");
    ui->labelIconUser->setPixmap(user.scaled(iconSize,iconSize));
    QPixmap kit1(":/Images/test.png");
    ui->labelCapsule1->setPixmap(kit1.scaled(iconSize,iconSize));
    QPixmap kit2(":/Images/test.png");
    ui->labelCapsule2->setPixmap(kit2.scaled(iconSize,iconSize));


    //Set User Information
    ui->labelUserName->setText(firstName);
    ui->labelTestKitName1->setText(RAT1KitName);
    ui->labelTestKitName2->setText(RAT2KitName);
    ui->labelRAT1Date->setText(RAT1Date);
    ui->labelRAT2Date->setText(RAT2Date);
    ui->labelRAT1Result->setText(RAT1Result);
    ui->labelRAT2Result->setText(RAT2Result);

    //->Home
    connect(ui->pushButtonHome,&QPushButton::clicked,[=](){
        UserPage * userpage = new UserPage(this, email);
        this->hide();
        userpage->show();
    });

    //->Landingpage
    connect(ui->pushButtonLogout,&QPushButton::clicked,[=](){
        LandingPage * landingpage = new LandingPage(this);
        this->hide();
        landingpage->show();
    });

}

UserCovid19TestResult::~UserCovid19TestResult()
{
    delete ui;
}


//Get User Information
void UserCovid19TestResult::getUesrInfo()
{
    auto query = QSqlQuery(db);

    if (query.exec("select * from [user] WHERE email='"+email+"'")) {
        query.next();
        id = query.value(0).toInt();
        firstName = query.value(1).toString();
        lastName = query.value(2).toString();
        birthday = query.value(3).toString();
        NHINumber = query.value(4).toString();
        email = query.value(5).toString();
        phone = query.value(6).toString();
        password = query.value(7).toString();
        dose1Date = query.value(8).toString();
        dose1Manufacturer = query.value(9).toString();
        dose1BatchNumber = query.value(10).toString();
        dose2Date = query.value(11).toString();
        dose2Manufacturer = query.value(12).toString();
        dose2BatchNumber = query.value(13).toString();
        RAT1Date = query.value(14).toString();
        RAT1KitName = query.value(15).toString();
        RAT1Result = query.value(16).toString();
        RAT2Date = query.value(17).toString();
        RAT2KitName = query.value(18).toString();
        RAT2Result = query.value(19).toString();

    } else {
        qWarning() << query.lastError();
        qInfo() << query.lastQuery() << query.boundValues();
    }
}



