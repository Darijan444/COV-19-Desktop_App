#include "login.h"
#include "ui_login.h"
#include "landingpage.h"
#include "signup.h"
#include "userpage.h"
#include <QDebug>


Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);


    //Login -> UserPage(Need Validation)
    connect(ui->pushButtonConfirm,&QPushButton::clicked,[=]()
    {
        //Get user input
        email = ui->lineEditEmail->text();
        password = ui->lineEditPassword->text();

        QSqlQuery query(db);

        if(query.exec("SELECT * FROM user WHERE email= '"+email+"' and password='"+password+"'"))
        {
            int count = 0;

            while (query.next())
            {
                count++;
                qDebug() << count;
            }
            if(count==1)
            {
                QMessageBox::information(this,"Login","Login successfully!");

                UserPage * userPage = new UserPage(this);
                this->hide();
                userPage->show();
            }else
            {
              QMessageBox::information(this,"Login","You entered wrong information");
            }
        };
    });

    //Login->LandingPage
    connect(ui->pushButtonBack,&QPushButton::clicked,[=]()
    {
        LandingPage * landingPage = new LandingPage(this);
        this->hide();
        landingPage->show();
    });


}

Login::~Login()
{
    delete ui;
}
