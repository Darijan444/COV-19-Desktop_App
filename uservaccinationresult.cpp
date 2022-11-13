#include "landingpage.h"
#include "userpage.h"
#include "uservaccinationresult.h"
#include "ui_uservaccinationresult.h"

UserVaccinationResult::UserVaccinationResult(QWidget *parent, QString email) :
    QDialog(parent),
    ui(new Ui::UserVaccinationResult)
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
    QPixmap vaccine1(":/Images/vaccine.png");
    ui->labelIconVaccine1->setPixmap(vaccine1.scaled(iconSize,iconSize));
    QPixmap vaccine2(":/Images/vaccine.png");
    ui->labelIconVaccine2->setPixmap(vaccine2.scaled(iconSize,iconSize));

    //Set User Information
    ui->labelUserName->setText(firstName);
    ui->labelVaccine1Name->setText(dose1Manufacturer);
    ui->labelVaccine2Name->setText(dose2Manufacturer);
    ui->labelVaccine1Date->setText(dose1Date);
    ui->labelVaccine2Date->setText(dose2Date);
    ui->labelManufacturer1->setText(dose1Manufacturer);
    ui->labelManufacturer2->setText(dose2Manufacturer);
    ui->labelBatchNumber1->setText(dose1BatchNumber);
    ui->labelBatchNumber2->setText(dose2BatchNumber);

    //->Home
    connect(ui->pushButtonHome,&QPushButton::clicked,[=](){
        UserPage * userpage = new UserPage(this,email);
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

UserVaccinationResult::~UserVaccinationResult()
{
    delete ui;
}

//Get User Information
void UserVaccinationResult::getUesrInfo()
{
    auto query = QSqlQuery(db);

    if (query.exec("select * from user WHERE email='"+email+"'")) {
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
    }
}
