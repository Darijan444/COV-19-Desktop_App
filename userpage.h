#ifndef USERPAGE_H
#define USERPAGE_H

#include <QDialog>

#include "database.h"


namespace Ui {
class UserPage;
}

class UserPage : public QDialog
{
    Q_OBJECT

public:
    explicit UserPage(QWidget *parent = nullptr, QString email="email");
    ~UserPage();

    void getUesrInfo();


private:
    Ui::UserPage *ui;

    QSqlDatabase db;

    //Uer Info
    int id;
    QString firstName;
    QString lastName;
    QString email;


};

#endif // USERPAGE_H
