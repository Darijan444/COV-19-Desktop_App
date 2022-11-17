#include "landingpage.h"
#include "userpage.h"
#include "userprofile.h"
#include "userreportissue.h"
#include "ui_userreportissue.h"
#include <QMessageBox>
#include <QDateTime>

UserReportIssue::UserReportIssue(QWidget *parent, QString email) :
    QDialog(parent),
    ui(new Ui::UserReportIssue)
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

UserReportIssue::~UserReportIssue()
{
    delete ui;
}

void UserReportIssue::hintText()
{
    ui->lineEditFirstName->setPlaceholderText("First name");
    ui->lineEditLastName->setPlaceholderText("Last name");
    ui->lineEditEmail->setPlaceholderText("email@gmail.com");
    ui->textEditMessage->setPlaceholderText("Write here");
}


//Get User Information
void UserReportIssue::getUesrInfo()
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

    } else {
        qWarning() << query.lastError();
        qInfo() << query.lastQuery() << query.boundValues();
    }
}



void UserReportIssue::on_pushButtonRequest_clicked()
{

    QString userInputFirstName = ui->lineEditFirstName->text();
    QString userInputLastName = ui->lineEditLastName->text();
    QString userInputEmail = ui->lineEditEmail->text();


    //Submit request(Birth is not included)
    if(userInputFirstName == firstName && userInputLastName == lastName && userInputEmail == email){
        //QMessageBox::information(this,"Submit","Successfully submitted");
        showMessage("Successfully submitted");

        //Add message to the report table
        QSqlQuery query(db);

        report = ui->textEditMessage->toPlainText();
        QDateTime date = QDateTime::currentDateTime();
        QString formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");

        query.exec("INSERT INTO "
                   "reports(Date, FirstName, LastName, Email, Report, Status) "
                   "VALUES('"+formattedTime+"', '"+firstName+"', '"+lastName+"', '"+email+"', '"+report+"', 'Not Assigned')");

        //RecordLog
        QString message= "User " + firstName + " submitted issues";
        recordLog(message);

        //->UserPage
        UserPage * userpage = new UserPage(this, email);
        this->hide();
        userpage->show();

    } else {
        //QMessageBox::information(this,"Submit","You entered wrong informaion");
        showMessage("You entered wrong informaion");

        UserReportIssue * userReportRATResult = new UserReportIssue(this, email);
        this->hide();
        userReportRATResult->show();
    }
}


void UserReportIssue::recordLog(QString message)
{
    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");

    QSqlQuery query(db);
    query.exec("INSERT INTO "
               "logs(Date, FirstName, LastName, NHINumber, Log) "
               "VALUES('"+formattedTime+"', '"+firstName+"', '"+lastName+"', '"+NHINumber+"', '"+message+"')");
}

void UserReportIssue::showMessage(QString text)
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

