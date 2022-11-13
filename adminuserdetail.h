#ifndef ADMINUSERDETAIL_H
#define ADMINUSERDETAIL_H

#include <QDialog>

#include "database.h"

namespace Ui {
class AdminUserDetail;
}

class AdminUserDetail : public QDialog
{
    Q_OBJECT

public:
//    explicit AdminUserDetail(QWidget *parent = nullptr, int id=1);
    explicit AdminUserDetail(QWidget *parent = nullptr, int num=0);
    ~AdminUserDetail();

    void getUesrInfo();

private:
    Ui::AdminUserDetail *ui;

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
//    QString UID;
};

#endif // ADMINUSERDETAIL_H
