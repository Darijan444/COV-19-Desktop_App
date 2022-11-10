#ifndef LANDINGPAGE_H
#define LANDINGPAGE_H

#include <QDialog>


namespace Ui {
class LandingPage;
}

class LandingPage : public QDialog
{
    Q_OBJECT

public:
    explicit LandingPage(QWidget *parent = nullptr);
    ~LandingPage();



private:
    Ui::LandingPage *ui;
};

#endif // LANDINGPAGE_H



//#ifndef DATABASE_H
//#define DATABASE_H

//#include <QDialog>
//#include <QSqlDatabase>

//namespace Ui {
//class Database;
//}

//class Database : public QDialog
//{
//    Q_OBJECT

//public:
//    explicit Database(QWidget *parent = nullptr);
//    ~Database();

//    QSqlDatabase db;
//    void Databaseconect();

//private:
//    Ui::Database *ui;
//};

//#endif // DATABASE_H
