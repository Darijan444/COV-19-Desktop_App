#include "landingpage.h"
#include "userpage.h"
#include "uservaccinepass.h"
#include "ui_uservaccinepass.h"


UserVaccinePass::UserVaccinePass(QWidget *parent, QString email) :
    QDialog(parent),
    ui(new Ui::UserVaccinePass)
{
    ui->setupUi(this);

    //Get User ID
    this->email = email;

    //Get User Information
    getUesrInfo();


    //Icons
    int iconSize = 25;
    int iconSizeL = 200;

    QPixmap user(":/Images/user.png");
    ui->labelIconUser->setPixmap(user.scaled(iconSize,iconSize));
    QPixmap qrcode(QRVaccinePass);
    ui->labelQRCode->setPixmap(qrcode.scaled(iconSizeL,iconSizeL));

    //Set User Information
    ui->labelUserName->setText(firstName);
    ui->labelName->setText(firstName + " "+ lastName);
    ui->labelEmail->setText(email);
    ui->labelDateOfBirth->setText(birthday);
    ui->labelMobileNumber->setText(phone);


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

UserVaccinePass::~UserVaccinePass()
{
    delete ui;
}



//Get User Information
void UserVaccinePass::getUesrInfo()
{
    auto query = QSqlQuery(db);

    if (query.exec("select * from user WHERE Email='"+email+"'")) {
        query.next();
        id = query.value(0).toInt();
        firstName = query.value(1).toString();
        lastName = query.value(2).toString();
        birthday = query.value(3).toString();
        phone = query.value(6).toString();
        QRVaccinePass = query.value(22).toString();
    } else {
        qWarning() << query.lastError();
    }
}
