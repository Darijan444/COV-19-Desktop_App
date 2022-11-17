#ifndef USERREPORTRATRESULT_H
#define USERREPORTRATRESULT_H

#include <QDialog>

#include "database.h"

namespace Ui {
class UserReportRATResult;
}

class UserReportRATResult : public QDialog
{
    Q_OBJECT

public:
    explicit UserReportRATResult(QWidget *parent = nullptr, QString email="email");
    ~UserReportRATResult();

    void getUesrInfo();
    void recordLog(QString message);

    void showMessage(QString text);


private slots:
    void on_pushButtonSubmit_clicked();

private:
    Ui::UserReportRATResult *ui;

    QSqlDatabase db;

    //Uer Info
    int id;
    QString firstName;
    QString lastName;
    QString email;
    QString ratResult;
    QString ratDate;
    QString NHINumber;
};

#endif // USERREPORTRATRESULT_H
