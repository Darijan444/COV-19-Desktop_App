#ifndef USERVACCINATIONRESULT_H
#define USERVACCINATIONRESULT_H

#include <QDialog>

#include "database.h"

namespace Ui {
class UserVaccinationResult;
}

class UserVaccinationResult : public QDialog
{
    Q_OBJECT

public:
    explicit UserVaccinationResult(QWidget *parent = nullptr, QString email="email");
    ~UserVaccinationResult();

    void getUesrInfo();

private:
    Ui::UserVaccinationResult *ui;

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

#endif // USERVACCINATIONRESULT_H
