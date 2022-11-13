#ifndef USERPAGE2_H
#define USERPAGE2_H

#include <QDialog>

namespace Ui {
class UserPage2;
}

class UserPage2 : public QDialog
{
    Q_OBJECT

public:
    explicit UserPage2(QWidget *parent = nullptr);
    ~UserPage2();

private:
    Ui::UserPage2 *ui;
};

#endif // USERPAGE2_H
