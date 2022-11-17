#include "landingpage.h"
#include "userpage.h"
#include "userprofile.h"
#include "userrequestvaccinepass.h"
#include "ui_userrequestvaccinepass.h"
#include <QMessageBox>

#include <QDateTime>

UserRequestVaccinePass::UserRequestVaccinePass(QWidget *parent, QString email) :
    QDialog(parent),
    ui(new Ui::UserRequestVaccinePass)
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

    //Set User Information
    ui->labelUserName->setText(firstName);

    //Set hint Text
    hintText();

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

    //->UserProfile
    connect(ui->pushButtonViewProfile,&QPushButton::clicked,[=](){
        UserProfile * userProfile = new UserProfile(this, email);
        this->hide();
        userProfile->show();
    });

    //Back
    connect(ui->pushButtonBack,&QPushButton::clicked,[=](){
        UserPage * userpage = new UserPage(this,email);
        this->hide();
        userpage->show();
    });
}

UserRequestVaccinePass::~UserRequestVaccinePass()
{
    delete ui;
}

void UserRequestVaccinePass::hintText()
{
    ui->lineEditFirstName->setPlaceholderText("First name");
    ui->lineEditLastName->setPlaceholderText("Last name");
    ui->lineEditDay->setPlaceholderText("01");
    ui->lineEditMonth->setPlaceholderText("01");
    ui->lineEditYear->setPlaceholderText("2000");
    ui->lineEditEmail->setPlaceholderText("email@gmail.com");
}


//Get User Information
void UserRequestVaccinePass::getUesrInfo()
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



void UserRequestVaccinePass::on_pushButtonRequest_clicked()
{
    QString userInputFirstName = ui->lineEditFirstName->text();
    QString userInputLastName = ui->lineEditLastName->text();
    QString userInputDay = ui->lineEditDay->text();
    QString userInputMonth = ui->lineEditMonth->text();
    QString userInputYear = ui->lineEditYear->text();
    QString userInputEmail = ui->lineEditEmail->text();

    //Submit request (Need to update(Birth is not included))
    if(userInputFirstName == firstName && userInputLastName == lastName && userInputEmail == email){
        //QMessageBox::information(this,"Submit","Successfully submitted");
        showMessage("Successfully submitted");

        //Update the Vaccine Pass status of user table
        QSqlQuery query(db);
        query.exec("UPDATE user SET VaccinePass = 'Requested' WHERE Email='"+email+"'");

        //RecordLog
        QString message= "User " + firstName + " requested Vaccine Pass";
        recordLog(message);

        //->UserPage
        UserPage * userpage = new UserPage(this, email);
        this->hide();
        userpage->show();

    } else {
        //QMessageBox::information(this,"Submit","You entered wrong informaion");
        showMessage("You entered wrong informaion");

        UserRequestVaccinePass * userRequestVaccinePass = new UserRequestVaccinePass(this, email);
        this->hide();
        userRequestVaccinePass->show();
    }
}

void UserRequestVaccinePass::recordLog(QString message)
{
    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");

    QSqlQuery query(db);
    query.exec("INSERT INTO "
               "logs(Date, FirstName, LastName, NHINumber, Log) "
               "VALUES('"+formattedTime+"', '"+firstName+"', '"+lastName+"', '"+NHINumber+"', '"+message+"')");
}

void UserRequestVaccinePass::showMessage(QString text)
{
    QMessageBox message;
    message.setMinimumSize(700,200);
    message.setWindowTitle("Message");
    message.setText(text);
    message.setInformativeText("Please press OK");
    message.setIcon(QMessageBox::Information);
    message.setStandardButtons(QMessageBox::Ok);
    message.exec();
}
