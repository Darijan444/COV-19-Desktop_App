#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <QDialog>

#include "database.h"



namespace Ui {
class UserProfile;
}

class UserProfile : public QDialog
{
    Q_OBJECT

public:
    explicit UserProfile(QWidget *parent = nullptr, QString email="email");
    ~UserProfile();

    void getUesrInfo();


private:
    Ui::UserProfile *ui;

    QSqlDatabase db;

    //Uer Info
    int id;
    QString firstName;
    QString lastName;
    QString email;
    QString birthday;
    QString NHINumber;
    QString phone;
    QString QRNHINumber;
};

#endif // USERPROFILE_H
