#include "userpage.h"
#include "ui_userpage.h"

UserPage::UserPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserPage)
{
    ui->setupUi(this);

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

    //UserPage->UserCovid19TestResult
//    connect(ui->pushButtonCovid19TestResult,&QPushButton::clicked,[=](){
//        UserCovid19TestResult * covid19TestResult = new UserCovid19TestResult(this);
//        this->hide();
//        covid19TestResult->show();
//    });


    //UserPage->UserProfile
//    connect(ui->pushButtonViewProfile,&QPushButton::clicked,[=](){
//        UserProfile * userProfile = new UserProfile(this);
//        this->hide();
//        userProfile->show();
//    });

    //UserPage->Landingpage
//    connect(ui->pushButtonLogout,&QPushButton::clicked,[=](){
//        LandingPage * landingpage = new LandingPage(this);
//        this->hide();
//        landingpage->show();
//    });
}






UserPage::~UserPage()
{
    delete ui;
}
