#ifndef USERCOVID19TESTRESULT_H
#define USERCOVID19TESTRESULT_H

#include <QDialog>

#include "database.h"

namespace Ui {
class UserCovid19TestResult;
}

class UserCovid19TestResult : public QDialog
{
    Q_OBJECT

public:
    explicit UserCovid19TestResult(QWidget *parent = nullptr, QString email="email");
    ~UserCovid19TestResult();

    void getUesrInfo();


private:
    Ui::UserCovid19TestResult *ui;

    QSqlDatabase db;

    //Uer Info
    int id;
    QString firstName;
    QString lastName;
    QString birthday;
    QString NHINumber;
    QString email;
    QString phone;
    QString password;
    QString dose1Date;
    QString dose1Manufacturer;
    QString dose1BatchNumber;
    QString dose2Date;
    QString dose2Manufacturer;
    QString dose2BatchNumber;
    QString RAT1Date;
    QString RAT1KitName;
    QString RAT1Result;
    QString RAT2Date;
    QString RAT2KitName;
    QString RAT2Result;


};

#endif // USERCOVID19TESTRESULT_H
