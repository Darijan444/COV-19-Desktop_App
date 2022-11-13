#include "landingpage.h"
#include "signup.h"
#include "userpage.h"

#include "./ui_signup.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>


Signup::Signup(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Signup)
{
    ui->setupUi(this);

    //Hide password
    ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    ui->lineEditPasswordConfirm->setEchoMode(QLineEdit::Password);

    //Hint text
    hintText();

    //Signup->LandingPage
    connect(ui->pushButtonBack,&QPushButton::clicked,[=](){
        LandingPage * landingPage = new LandingPage(this);
        this->hide();
        landingPage->show();
    });

}

Signup::~Signup()
{
    delete ui;
}



void Signup::reset()
{
    ui->lineEditFirstName->clear();
    ui->lineEditLastName->clear();
    ui->lineEditEmail->clear();
    ui->lineEditNHINumber->clear();
    ui->lineEditPassword->clear();
    ui->lineEditPasswordConfirm->clear();
}

void Signup::hintText()
{
    ui->lineEditFirstName->setPlaceholderText("First name");
    ui->lineEditLastName->setPlaceholderText("Last name");
    ui->lineEditEmail->setPlaceholderText("email@gmail.com");
    ui->lineEditNHINumber->setPlaceholderText("AA0001");
    ui->lineEditPassword->setPlaceholderText("aaAA11##");
    ui->lineEditPasswordConfirm->setPlaceholderText("aaAA11##");
}



void Signup::on_pushButtonConfirm_clicked()
{
    firstName = ui->lineEditFirstName->text();
    lastName = ui->lineEditLastName->text();
    email = ui->lineEditEmail->text();
    NHINumber = ui->lineEditNHINumber->text();
    password = ui->lineEditPassword->text();
    passwordConfirm = ui->lineEditPasswordConfirm->text();

    QSqlQuery query(db);

    //1. Check blanks
    if(!firstName.isEmpty() && !lastName.isEmpty() && !email.isEmpty() && !NHINumber.isEmpty() && !password.isEmpty()  && !passwordConfirm.isEmpty())
    {
        //2. Check password matching
        if(password==passwordConfirm){

            //3. Check exisiting email address
            query.exec("select count(*) from user WHERE email='"+email+"'");
            query.next();
            int exsistingUserCount = query.value(0).toInt();

            if (exsistingUserCount == 0) {
                query.exec("INSERT INTO "
                              "user(FirstName, LastName, Email, NHINumber,Password) "
                              "VALUES('"+firstName+"', '"+lastName+"', '"+email+"', '"+NHINumber+"', '"+password+"')");

                QMessageBox::information(this,"Signup","Signup successfully!");

                //->UserPage
                UserPage * userPage = new UserPage(this, email);
                this->hide();
                userPage->show();

            }else{
                QMessageBox::information(this,"Signup","Your email address is already registered.");
            }
        } else{
            QMessageBox::information(this,"Signup","The password doesn't match");
        }
    }else{
        QMessageBox::information(this,"Signup","Please fill out all");
    }
}

