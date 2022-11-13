#ifndef DATABASE_H
#define DATABASE_H

#include <QString>

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>

class Database
{
public:
    Database();

    void database();
//    void databaseReports();
//    void databaseLogs();




private:
    QString firstName;

};

#endif // DATABASE_H
