#ifndef DATABASE_H
#define DATABASE_H

#include <QDialog>
#include <QSqlDatabase>

class Database
{
public:
    Database();

    QSqlDatabase db;
    void Databaseconect();
};

#endif // DATABASE_H
