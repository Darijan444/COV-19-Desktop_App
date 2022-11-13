#include "landingpage.h"
#include "login.h"
#include "userpage.h"
#include "ui_login.h"
#include "adminmain.h"
#include "database.h"
#include "userpage.h"

#include <QDebug>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);


    //call database(Need to improve)
//    DatabaseUsers * databaseUsers = new DatabaseUsers();

    if(!db.open()){
        qWarning() << "MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();
    }

    //hide password
    ui->lineEditPassword->setEchoMode(QLineEdit::Password);


    //Login->UserPage (Need validation)
    connect(ui->pushButtonConfirm,&QPushButton::clicked,[=](){

        //Get user input
        email = ui->lineEditEmail->text();
        password = ui->lineEditPassword->text();


        QSqlQuery query(db);

        if(query.exec("SELECT * FROM user WHERE email='"+email+"' and password='"+password+"'")){

            int count = 0;

            while (query.next()) {
                count++;
            }

            if(email == "admin" && password == "admin"){
                QMessageBox::information(this,"Login","Login successfully!");
                AdminMain * adminmain = new AdminMain(this);
                this->hide();
                adminmain->show();

            } else if(count==1){
                QMessageBox::information(this,"Login","Login successfully!");

                //Give email to User Page
                UserPage * userPage = new UserPage(this,email);
                this->hide();
                userPage->show();


            }else{
                QMessageBox::information(this,"Login","You entered wrong information");
            }
        };
    });

    //->LandingPage
    connect(ui->pushButtonBack,&QPushButton::clicked,[=](){
        LandingPage * landingPage = new LandingPage(this);
        this->hide();
        landingPage->show();
    });

}

Login::~Login()
{
    delete ui;
}
