#ifndef USERPAGE_H
#define USERPAGE_H

#include <QDialog>

#include <QSqlDatabase>

namespace Ui {
class UserPage;
}

class UserPage : public QDialog
{
    Q_OBJECT

public:
    explicit UserPage(QWidget *parent = nullptr);
    ~UserPage();

private:
    Ui::UserPage *ui;

    QSqlDatabase db;
};

#endif // USERPAGE_H
