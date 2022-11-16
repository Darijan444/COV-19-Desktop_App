#include "landingpage.h"

#include <QApplication>

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LandingPage l;
    l.show();


    ////////////////////////////////////////////////////////////////////////////////////////
    //Connect Database Users
    ////////////////////////////////////////////////////////////////////////////////////////
    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);

//        db.setDatabaseName("/Users/Ryuuuu/Desktop/Share/COV-19-Desktop_App/database2.db");

        db.setDatabaseName("C:/Users/darij/OneDrive/Desktop/COV-19 Project/COV-19-Desktop_App/database2.db");

        if(!db.open()){
            qWarning() << "MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();
        }else{
            qDebug() << "Database Open";
        }
    }
    else
        qWarning() << "MainWindow::DatabaseConnect - ERROR: no driver " << DRIVER << "available";


    return a.exec();
}
