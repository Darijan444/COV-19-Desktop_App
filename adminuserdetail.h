#ifndef ADMINUSERDETAIL_H
#define ADMINUSERDETAIL_H

#include <QDialog>

namespace Ui {
class AdminUserDetail;
}

class AdminUserDetail : public QDialog
{
    Q_OBJECT

public:
    explicit AdminUserDetail(QWidget *parent = nullptr);
    ~AdminUserDetail();

private:
    Ui::AdminUserDetail *ui;
};

#endif // ADMINUSERDETAIL_H
