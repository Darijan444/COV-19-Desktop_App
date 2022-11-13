#include "landingpage.h"
#include "signup.h"
#include "login.h"
#include "ui_landingpage.h"

LandingPage::LandingPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LandingPage)
{
    ui->setupUi(this);


    /////////////////////////////////////////////////////////////////////////////
    //LandingPage->Signup
    /////////////////////////////////////////////////////////////////////////////
    connect(ui->pushButtonSignup,&QPushButton::clicked,[=](){
        Signup * signUp = new Signup(this);     //1.Heap style
        this->hide();
        signUp->show();

        //Signup signUp;                        //2.Stack style
        //this->hide();
        //signUp.exec();
    });

    /////////////////////////////////////////////////////////////////////////////
    //LandingPage->Login
    /////////////////////////////////////////////////////////////////////////////
    connect(ui->pushButtonLogin,&QPushButton::clicked,[=](){
        Login * login = new Login(this);
        this->hide();
        login->show();
    });


    /////////////////////////////////////////////////////////////////////////////
    //External Link
    /////////////////////////////////////////////////////////////////////////////
    ui->labelLink->setText("<a href=\"https://www.who.int//\">WHO Link (test)</a>");
    ui->labelLink->setTextFormat(Qt::RichText);
    ui->labelLink->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->labelLink->setOpenExternalLinks(true);


}

LandingPage::~LandingPage()
{
    delete ui;
}
