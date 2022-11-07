#ifndef ADMINLOGS_H
#define ADMINLOGS_H

#include <QDialog>

namespace Ui {
class AdminLogs;
}

class AdminLogs : public QDialog
{
    Q_OBJECT

public:
    explicit AdminLogs(QWidget *parent = nullptr);
    ~AdminLogs();

private:
    Ui::AdminLogs *ui;
};

#endif // ADMINLOGS_H
