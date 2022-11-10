#include "database.h"

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>

Database::Database()
{
    //Connect Database
    Databaseconect();
}


//////////////////////////////////////////////////////////////////////////////////////////
////Connect database
//////////////////////////////////////////////////////////////////////////////////////////
void Database::Databaseconect()
{
    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);

        //Ryuu's database path
        db.setDatabaseName("/Users/Ryuuuu/QtProjects/Covid19RegistrationSystem2/database.db");



        if(!db.open()){
            qWarning() << "MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();
        }else{
            qDebug() << "Database Open";
        }
    }
    else
        qWarning() << "MainWindow::DatabaseConnect - ERROR: no driver " << DRIVER << "available";
}
