#include "landingpage.h"
#include "userpage.h"
#include "userreportratresult.h"
#include "ui_userreportratresult.h"

#include <QButtonGroup>
#include <QMessageBox>

UserReportRATResult::UserReportRATResult(QWidget *parent, QString email) :
    QDialog(parent),
    ui(new Ui::UserReportRATResult)
{
    ui->setupUi(this);

    //Get User email
    this->email = email;

    //Get User Information
    getUesrInfo();


    //Add function to the ui widget by using QButtonGroup
    QButtonGroup * group1 = new QButtonGroup(this);
    group1->addButton(ui->checkBoxCYes);
    group1->addButton(ui->checkBoxCNo);
    group1->setExclusive(true);

    QButtonGroup * group2 = new QButtonGroup(this);
    group2->addButton(ui->checkBoxTYes);
    group2->addButton(ui->checkBoxTNo);
    group2->setExclusive(true);


    //Icons
    int iconSize = 25;
    int iconSizeL = 250;

    QPixmap user(":/Images/user.png");
    ui->labelIconUser->setPixmap(user.scaled(iconSize,iconSize));
    QPixmap ratKitImage(":/Images/RATKit.png");
    ui->labelRATKitImage->setPixmap(ratKitImage.scaled(iconSizeL,iconSizeL));

    //Set User Information
    ui->labelUserName->setText(firstName);

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
    //Back
    connect(ui->pushButtonBack,&QPushButton::clicked,[=](){
        UserPage * userpage = new UserPage(this,email);
        this->hide();
        userpage->show();
    });

    /////////////////////////////////////////////////////////////////////////////
    //External Link
    /////////////////////////////////////////////////////////////////////////////
    ui->labelLink->setText("<a href=\"https://covid19.govt.nz/testing-and-isolation/covid-19-testing/how-to-use-a-rat///\">How to use a RAT</a>");
    ui->labelLink->setTextFormat(Qt::RichText);
    ui->labelLink->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->labelLink->setOpenExternalLinks(true);
}

UserReportRATResult::~UserReportRATResult()
{
    delete ui;
}

//Get User Information
void UserReportRATResult::getUesrInfo()
{
    auto query = QSqlQuery(db);

    if (query.exec("select * from [user] WHERE email='"+email+"'")) {
        query.next();
        id = query.value(0).toInt();
        firstName = query.value(1).toString();
//        lastName = query.value(2).toString();
//        birthday = query.value(3).toString();
//        NHINumber = query.value(4).toString();
//        email = query.value(5).toString();
//        phone = query.value(6).toString();
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
        qInfo() << query.lastQuery() << query.boundValues();
    }
}

void UserReportRATResult::on_pushButtonSubmit_clicked()
{


    if(ui->checkBoxCYes->isChecked() && ui->checkBoxTYes->isChecked()){
        ratResult = "Positive";
    }else if(ui->checkBoxCYes->isChecked() && ui->checkBoxTNo->isChecked()){
        ratResult = "Negative";
    }else{
        QMessageBox::information(this,"Caution","Your test result is invalid. Please try again.");
        return;
    }

    ratDate = ui->dateEdit->text();

    QMessageBox::information(this,"Submit","Successfully submitted");

    QSqlQuery query(db);
    query.exec("UPDATE user SET RAT1Result='"+ratResult+"', RAT1Date='"+ratDate+"' WHERE Email='"+email+"'");



    UserPage * userpage = new UserPage(this, email);
    this->hide();
    userpage->show();
}

