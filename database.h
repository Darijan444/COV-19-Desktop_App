#ifndef DATABASE_H
#define DATABASE_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class Database;
}

class Database : public QDialog
{
    Q_OBJECT

public:
    explicit Database(QWidget *parent = nullptr);
    ~Database();

    QSqlDatabase db;
    void Databaseconect();

private:
    Ui::Database *ui;
};

#endif // DATABASE_H
