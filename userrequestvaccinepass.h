#ifndef USERREQUESTVACCINEPASS_H
#define USERREQUESTVACCINEPASS_H

#include <QDialog>

#include "database.h"

namespace Ui {
class UserRequestVaccinePass;
}

class UserRequestVaccinePass : public QDialog
{
    Q_OBJECT

public:
    explicit UserRequestVaccinePass(QWidget *parent = nullptr, QString email="email");
    ~UserRequestVaccinePass();

    void getUesrInfo();

private slots:
    void on_pushButtonRequest_clicked();

private:
    Ui::UserRequestVaccinePass *ui;

    QSqlDatabase db;

    //Uer Info
    int id;
    QString firstName;
    QString lastName;
    QString birthday;
    QString email;

};

#endif // USERREQUESTVACCINEPASS_H
