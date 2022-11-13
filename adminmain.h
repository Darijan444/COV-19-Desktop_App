#ifndef ADMINMAIN_H
#define ADMINMAIN_H

#include <QDialog>

#include <QChartView>

#include "database.h"

namespace Ui {
class AdminMain;
}

class AdminMain : public QDialog
{
    Q_OBJECT

public:
    explicit AdminMain(QWidget *parent = nullptr);
    ~AdminMain();

//    void createBarChart();



private:
    Ui::AdminMain *ui;

    QList<QChartView *> charts;
//    Ui::Widget *ui;

    QChart *createBarChart(int valueCount) const;

    QSqlDatabase db;

    int userCount;
    int twoDosesCount;
    int RATPositiveCount;
    int issuedVaccinePassCount;
    int reportsCount;

};

#endif // ADMINMAIN_H
