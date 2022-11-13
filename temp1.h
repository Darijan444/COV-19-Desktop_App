#ifndef TEMP1_H
#define TEMP1_H

#include <QDialog>

namespace Ui {
class Temp1;
}

class Temp1 : public QDialog
{
    Q_OBJECT

public:
    explicit Temp1(QWidget *parent = nullptr);
    ~Temp1();

private:
    Ui::Temp1 *ui;
};

#endif // TEMP1_H
