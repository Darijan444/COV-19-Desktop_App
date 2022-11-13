#ifndef USERREPORTISSUE_H
#define USERREPORTISSUE_H

#include <QDialog>

#include "database.h"

namespace Ui {
class UserReportIssue;
}

class UserReportIssue : public QDialog
{
    Q_OBJECT

public:
    explicit UserReportIssue(QWidget *parent = nullptr, QString email="email");
    ~UserReportIssue();

    void getUesrInfo();

private slots:
    void on_pushButtonRequest_clicked();

private:
    Ui::UserReportIssue *ui;

    QSqlDatabase db;

    //Uer Info
    int id;
    QString firstName;
    QString lastName;
    QString birthday;
    QString email;
    QString report;
};

#endif // USERREPORTISSUE_H
