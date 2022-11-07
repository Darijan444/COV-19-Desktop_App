#ifndef ADMINUSERS_H
#define ADMINUSERS_H

#include <QDialog>

#include <QSqlDatabase>

namespace Ui {
class AdminUsers;
}

class AdminUsers : public QDialog
{
    Q_OBJECT

public:
    explicit AdminUsers(QWidget *parent = nullptr);
    ~AdminUsers();

    void userList();


    QSqlDatabase db;

private:
    Ui::AdminUsers *ui;
};

#endif // ADMINUSERS_H
