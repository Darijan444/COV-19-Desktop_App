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

    bool isBlankExist();
    void showMessage(QString text);


private slots:
    void on_pushButtonConfirm_clicked();

private:
    Ui::Login *ui;

    QSqlDatabase db;

    QString email, password;
};

#endif // LOGIN_H
