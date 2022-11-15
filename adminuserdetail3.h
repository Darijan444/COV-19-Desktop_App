#ifndef ADMINUSERDETAIL3_H
#define ADMINUSERDETAIL3_H

#include <QDialog>

#include "database.h"

namespace Ui {
class AdminUserDetail3;
}

class AdminUserDetail3 : public QDialog
{
    Q_OBJECT

public:
    explicit AdminUserDetail3(QWidget *parent = nullptr, int num=0);
    ~AdminUserDetail3();

    void getUesrInfo();
    void hintText();
    void update(QString itemName, QString itemValue);


private slots:
    void on_pushButtonUpdateQRNHI_clicked();

    void on_pushButtonDeletepushButtonQRNHI_clicked();

    void on_pushButtonUpdateQRVaccinePass_clicked();

    void on_pushButtonDeleteQRVaccinePass_clicked();

private:
    Ui::AdminUserDetail3 *ui;

    QSqlDatabase db;

    //Uer Info
    int id;
    QString firstName;
    QString lastName;
    QString email;
    QString birthday;
    QString NHINumber;
    QString phone;
    int num;

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
    QString VaccinePass;
    QString QRNHINumber;
    QString QRVaccinePass;
};

#endif // ADMINUSERDETAIL3_H
