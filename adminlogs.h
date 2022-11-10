#ifndef ADMINLOGS_H
#define ADMINLOGS_H

#include <QDialog>

#include <QSqlDatabase>

namespace Ui {
class AdminLogs;
}

class AdminLogs : public QDialog
{
    Q_OBJECT

public:
    explicit AdminLogs(QWidget *parent = nullptr);
    ~AdminLogs();

    void logs();

    QSqlDatabase db;

private:
    Ui::AdminLogs *ui;
};

#endif // ADMINLOGS_H
