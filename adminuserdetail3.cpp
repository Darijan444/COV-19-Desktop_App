#include "landingpage.h"
#include "adminmain.h"
#include "adminusers.h"
#include "adminreports.h"
#include "adminlogs.h"
#include "adminuserdetail3.h"
#include "ui_adminuserdetail3.h"

#include <QVBoxLayout>
#include <QMessageBox>
#include <QFileDialog>


AdminUserDetail3::AdminUserDetail3(QWidget *parent, int num) :
    QDialog(parent),
    ui(new Ui::AdminUserDetail3)
{
    ui->setupUi(this);

    //Get User ID
    this->num = num;

    //Get User Information
    getUesrInfo();

    //Scroll Area
    QVBoxLayout * lay = new QVBoxLayout(this);
    ui->scrollArea->setLayout(lay);



    //Icons
    int iconSize = 25;
    int iconSizeL = 200;


    QPixmap user(":/Images/user.png");
    ui->labelIconUser->setPixmap(user.scaled(iconSize,iconSize));

    QPixmap qrcode(QRNHINumber);
    ui->labelQRCode->setPixmap(qrcode.scaled(iconSizeL,iconSizeL));

    QPixmap vaccine1(":/Images/vaccine.png");
    ui->labelIconVaccine1->setPixmap(vaccine1.scaled(iconSize,iconSize));
    QPixmap vaccine2(":/Images/vaccine.png");
    ui->labelIconVaccine2->setPixmap(vaccine2.scaled(iconSize,iconSize));

    QPixmap vaccinePass(QRVaccinePass);
    ui->labelVaccinePass->setPixmap(vaccinePass.scaled(iconSizeL,iconSizeL));

    QPixmap kit1(":/Images/test2.png");
    ui->labelRATKitImage1->setPixmap(kit1.scaled(iconSize,iconSize));
    QPixmap kit2(":/Images/test2.png");
    ui->labelRATKitImage2->setPixmap(kit2.scaled(iconSize,iconSize));


    //Set User Information
    hintText();

    ui->labelvaccine1Name->setText(dose1Manufacturer);
    ui->labelvaccine2Name->setText(dose2Manufacturer);



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


    //->Update
    connect(ui->pushButtonUpdate,&QPushButton::clicked,[=](){
        update("NHINumber",ui->lineEditNHINumber->text());
        update("FirstName",ui->lineEditFirstName->text());
        update("LastName",ui->lineEditLastName->text());
        update("Email",ui->lineEditEmail->text());

        //Refresh the page
        AdminUserDetail3 * adminUserDetail3 = new AdminUserDetail3(this,num);
        this->hide();
        adminUserDetail3->show();
    });

    connect(ui->pushButtonUpdate2,&QPushButton::clicked,[=](){
        update("Dose2Date",ui->lineEditDose2Date->text());
        update("Dose2Manufacturer",ui->lineEditDose2Manufacturer->text());
        update("Dose2BatchNumber",ui->lineEditDose2BatchNumber->text());
        update("Dose1Date",ui->lineEditDose1Date->text());
        update("Dose1Manufacturer",ui->lineEditDose1Manufacturer->text());
        update("Dose1BatchNumber",ui->lineEditDose1BatchNumber->text());

        //Refresh the page
        AdminUserDetail3 * adminUserDetail3 = new AdminUserDetail3(this,num);
        this->hide();
        adminUserDetail3->show();
    });
    connect(ui->pushButtonUpdate3,&QPushButton::clicked,[=](){
        update("RAT2KitName",ui->lineEditRAT2Name->text());
        update("RAT2Date",ui->lineEditRAT2Date->text());
        update("RAT2Result",ui->lineEditRAT2Result->text());
        update("RAT1KitName",ui->lineEditRAT1Name->text());
        update("RAT1Date",ui->lineEditRAT1Date->text());
        update("RAT1Result",ui->lineEditRAT1Result->text());

        //Refresh the page
        AdminUserDetail3 * adminUserDetail3 = new AdminUserDetail3(this,num);
        this->hide();
        adminUserDetail3->show();
    });




}

AdminUserDetail3::~AdminUserDetail3()
{
    delete ui;
}



//Get User Information
void AdminUserDetail3::getUesrInfo()
{
    auto query = QSqlQuery(db);

    QString numString = QString::number(num);

    if (query.exec("select * from user WHERE ID='"+numString+"'")) {
        query.next();
        id = query.value(0).toInt();
        firstName = query.value(1).toString();
        lastName = query.value(2).toString();
        birthday = query.value(3).toString();
        NHINumber = query.value(4).toString();
        email = query.value(5).toString();
        phone = query.value(6).toString();
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
        VaccinePass = query.value(20).toString();
        QRNHINumber = query.value(21).toString();
        QRVaccinePass = query.value(22).toString();

    } else {
        qWarning() << query.lastError();
    }
}

void AdminUserDetail3::hintText()
{
    ui->lineEditNHINumber->setPlaceholderText(NHINumber);
    ui->lineEditFirstName->setPlaceholderText(firstName);
    ui->lineEditLastName->setPlaceholderText(lastName);
    ui->lineEditBirthday->setPlaceholderText(birthday);
    ui->lineEditPhone->setPlaceholderText(phone);

    ui->lineEditEmail->setPlaceholderText(email);
    ui->lineEditDose2Date->setPlaceholderText(dose2Date);
    ui->lineEditDose2Manufacturer->setPlaceholderText(dose2Manufacturer);
    ui->lineEditDose2BatchNumber->setPlaceholderText(dose2BatchNumber);
    ui->lineEditDose1Date->setPlaceholderText(dose1Date);
    ui->lineEditDose1Manufacturer->setPlaceholderText(dose1Manufacturer);
    ui->lineEditDose1BatchNumber->setPlaceholderText(dose1BatchNumber);
    ui->lineEditRAT2Name->setPlaceholderText(RAT2KitName);
    ui->lineEditRAT2Date->setPlaceholderText(RAT2Date);
    ui->lineEditRAT2Result->setPlaceholderText(RAT2Result);
    ui->lineEditRAT1Name->setPlaceholderText(RAT1KitName);
    ui->lineEditRAT1Date->setPlaceholderText(RAT1Date);
    ui->lineEditRAT1Result->setPlaceholderText(RAT1Result);
}

void AdminUserDetail3::update(QString itemName, QString itemValue)
{
    QSqlQuery query(db);
    QString numString = QString::number(num);

    if(itemValue == ""){

    }else{
        query.exec("UPDATE user SET "+itemName+" = '"+itemValue+"' WHERE ID='"+numString+"'");
    }
}



void AdminUserDetail3::on_pushButtonUpdateQRNHI_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open File",
                                                      QString(),
                                                      tr("Images (*.png *.xpm *.jpg)"));

    int iconSizeL = 200;
    QPixmap qrcode(filePath);
    ui->labelQRCode->setPixmap(qrcode.scaled(iconSizeL,iconSizeL));

    QSqlQuery query(db);
    QString numString = QString::number(num);

    query.exec("UPDATE user SET QRNHINumber = '"+filePath+"' WHERE ID='"+numString+"'");
}


void AdminUserDetail3::on_pushButtonDeletepushButtonQRNHI_clicked()
{
    int iconSizeL = 200;
    QPixmap qrcode("");
    ui->labelQRCode->setPixmap(qrcode.scaled(iconSizeL,iconSizeL));

    QSqlQuery query(db);
    QString numString = QString::number(num);

    query.exec("UPDATE user SET QRNHINumber = '' WHERE ID='"+numString+"'");
}


void AdminUserDetail3::on_pushButtonUpdateQRVaccinePass_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open File",
                                                      QString(),
                                                      tr("Images (*.png *.xpm *.jpg)"));

    int iconSizeL = 200;
    QPixmap qrcode(filePath);
    ui->labelVaccinePass->setPixmap(qrcode.scaled(iconSizeL,iconSizeL));

    QSqlQuery query(db);
    QString numString = QString::number(num);

    query.exec("UPDATE user SET QRVaccinePass = '"+filePath+"' WHERE ID='"+numString+"'");
}


void AdminUserDetail3::on_pushButtonDeleteQRVaccinePass_clicked()
{
    int iconSizeL = 200;
    QPixmap qrcode("");
    ui->labelVaccinePass->setPixmap(qrcode.scaled(iconSizeL,iconSizeL));

    QSqlQuery query(db);
    QString numString = QString::number(num);

    query.exec("UPDATE user SET QRVaccinePass = '' WHERE ID='"+numString+"'");
}

