#include "landingpage.h"
#include "signup.h"
#include "userpage.h"

#include "./ui_signup.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

#include <regex>


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
    QSqlQuery query(db);

    //1. Blank Check
    if (isBlankExist() == true)
   {
        //2. Email Check
        if(isEmailValid(email) == true)
        {
            //3. Existing Email Check
            if(isEmailExist(email) == true)
            {
                //4. Password Check
                if(isPasswordValid(password) == true)
                {
                    //5. Password Matching Check
                    if(isPasswordMatch() == true)
                    {
                        //QMessageBox::information(this,"Signup","Signup successfully!");
                        showMessage("Signup successfully!");


                        //Register uer information
                        query.exec("INSERT INTO "
                                      "user(FirstName, LastName, Email, NHINumber,Password,UserStatus) "
                                      "VALUES('"+firstName+"', '"+lastName+"', '"+email+"', '"+NHINumber+"', '"+password+"', 'User')");
                        //->UserPage
                        UserPage * userPage = new UserPage(this, email);
                        this->hide();
                        userPage->show();
                    }
                }
            }
        }
    }
}


bool Signup::isBlankExist()
{
    firstName = ui->lineEditFirstName->text();
    lastName = ui->lineEditLastName->text();
    email = ui->lineEditEmail->text();
    NHINumber = ui->lineEditNHINumber->text();
    password = ui->lineEditPassword->text();
    passwordConfirm = ui->lineEditPasswordConfirm->text();

    if(!firstName.isEmpty() && !lastName.isEmpty() && !email.isEmpty() && !NHINumber.isEmpty() && !password.isEmpty()  && !passwordConfirm.isEmpty())
    {
        return true;
    }else{
        //QMessageBox::information(this,"Signup","Please fill out all");
        showMessage("Please fill out all");

        Signup * signUp = new Signup(this);
        this->hide();
        signUp->show();
    }
}


bool Signup::isPasswordValid(QString password)
{
    bool result;
    int digitFlag = 0, upperFlag = 0, lowerFlag = 0, specialCharacterFlag = 0, numberFlag = 0;

    //check 5 requirements separetely
    QRegularExpression digitPattern(".{8,}");
    QRegularExpression upperCasePattern("[A-Z]+");
    QRegularExpression lowerCasePattern("[a-z]+");
    QRegularExpression specialCharacterPattern("[@!?#]+");
    QRegularExpression numberPattern("[0-9]+");

    QRegularExpressionMatch digitMatch = digitPattern.match(password);
    QRegularExpressionMatch upperCaseMatch = upperCasePattern.match(password);
    QRegularExpressionMatch lowerCaseMatch = lowerCasePattern.match(password);
    QRegularExpressionMatch specialCharacterMatch = specialCharacterPattern.match(password);
    QRegularExpressionMatch numberMatch = numberPattern.match(password);

    bool digitHasMatch = digitMatch.hasMatch();
    bool upperCaseHasMatch = upperCaseMatch.hasMatch();
    bool lowerCaseHasMatch = lowerCaseMatch.hasMatch();
    bool specialCharacterCaseHasMatch = specialCharacterMatch.hasMatch();
    bool numberHasMatch = numberMatch.hasMatch();

    if (digitHasMatch == false){
        //QMessageBox::information(this,"Validation","Password: \nAt least 8 characters");
        showMessage("Password: \nAt least 8 characters");
        digitFlag = 1;
    }else if (upperCaseHasMatch == false){
        //QMessageBox::information(this,"Validation","Password: At least one upper case character");
        showMessage("Password: \nAt least 8 characters");
        upperFlag = 1;
    }else if (lowerCaseHasMatch == false){
        //QMessageBox::information(this,"Validation","Password: At least one lower case character");
        showMessage("Password: At least one lower case character");
        lowerFlag = 1;
    }else if (specialCharacterCaseHasMatch == false){
        //QMessageBox::information(this,"Validation","Password: At least one special character (@, !, ?, #)");
        showMessage("Password: At least one special character (@, !, ?, #)");
        specialCharacterFlag = 1;
    }else if (numberHasMatch == false){
        //QMessageBox::information(this,"Validation","Password: At least one number");
        showMessage("Password: At least one number");
        numberFlag = 1;
    }

    int totalFlagNum = digitFlag + upperFlag + lowerFlag + numberFlag + specialCharacterFlag;

    if (totalFlagNum == 0){
        result = true;
    } else {
        result = false;

        Signup * signUp = new Signup(this);
        this->hide();
        signUp->show();
    }
    return result;
}



bool Signup::isPasswordMatch()
{
    password = ui->lineEditPassword->text();
    passwordConfirm = ui->lineEditPasswordConfirm->text();

    if (password==passwordConfirm)
    {
        return true;
    }else{
       //QMessageBox::information(this,"Signup","The password doesn't match");
       showMessage("The password doesn't match");
    }
}

bool Signup::isEmailValid(QString email)
{
    QRegularExpression digit("(\\w+)(\\.|_)?@(\\w+)(\\.(\\w+))");
    QRegularExpressionMatch match = digit.match(email);

    bool hasMatch = match.hasMatch();

    if (hasMatch==true)
    {
        return true;
    }else{
       //QMessageBox::information(this,"Signup","Please enter a valid email address");
       showMessage("Please enter a valid email address");

       Signup * signUp = new Signup(this);
       this->hide();
       signUp->show();
    }
}

bool Signup::isEmailExist(QString email)
{
    QSqlQuery query(db);

    query.exec("select count(*) from user WHERE email='"+email+"'");
    query.next();
    int exsistingUserCount = query.value(0).toInt();

    if (exsistingUserCount == 0) {
        return true;

    }else{
        //QMessageBox::information(this,"Signup","Your email address is already registered.");
        showMessage("Your email address is already registered.");

        Signup * signUp = new Signup(this);
        this->hide();
        signUp->show();

        return false;
    }
}

void Signup::showMessage(QString text)
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
