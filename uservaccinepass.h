#ifndef USERVACCINEPASS_H
#define USERVACCINEPASS_H

#include <QDialog>

#include "database.h"

namespace Ui {
class UserVaccinePass;
}

class UserVaccinePass : public QDialog
{
    Q_OBJECT

public:
    explicit UserVaccinePass(QWidget *parent = nullptr, QString email="email");
    ~UserVaccinePass();

    void getUesrInfo();

private:
    Ui::UserVaccinePass *ui;

    QSqlDatabase db;

    //Uer Info
    int id;
    QString firstName;
    QString lastName;
    QString email;
    QString birthday;
    QString phone;
    QString QRVaccinePass;
};

#endif // USERVACCINEPASS_H
