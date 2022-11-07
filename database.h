#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>

class Database
{
public:
    Database();

    QSqlDatabase db;
};

#endif // DATABASE_H
