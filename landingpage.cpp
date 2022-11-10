#include "landingpage.h"
#include "ui_landingpage.h"


LandingPage::LandingPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LandingPage)
{
    ui->setupUi(this);

}


LandingPage::~LandingPage()
{
    delete ui;
}


//#include "database.h"
//#include "ui_database.h"

//#include <QSql>
//#include <QSqlDatabase>
//#include <QSqlQuery>
//#include <QSqlError>
//#include <QSqlDriver>

//Database::Database(QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::Database)
//{
//    ui->setupUi(this);

//    //Connect Database
//    Databaseconect();
//}

//Database::~Database()
//{
//    delete ui;
//}



//////////////////////////////////////////////////////////////////////////////////////////
////Connect database
//////////////////////////////////////////////////////////////////////////////////////////
//void Database::Databaseconect()
//{
//    const QString DRIVER("QSQLITE");

//    if(QSqlDatabase::isDriverAvailable(DRIVER))
//    {
//        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);

//        //Ryuu's database path
//        db.setDatabaseName("/Users/Ryuuuu/QtProjects/Covid19RegistrationSystem2/database.db");



//        if(!db.open()){
//            qWarning() << "MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();
//        }else{
//            qDebug() << "Database Open";
//        }
//    }
//    else
//        qWarning() << "MainWindow::DatabaseConnect - ERROR: no driver " << DRIVER << "available";
//}
