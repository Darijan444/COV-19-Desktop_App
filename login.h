#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>


namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    QSqlDatabase db;

private:
    Ui::Login *ui;

    QString email, password;
};

#endif // LOGIN_H
