#ifndef ADMINMAIN_H
#define ADMINMAIN_H

#include <QDialog>

namespace Ui {
class AdminMain;
}

class AdminMain : public QDialog
{
    Q_OBJECT

public:
    explicit AdminMain(QWidget *parent = nullptr);
    ~AdminMain();

//Slot
public slots:
    void labelUsers();



private:
    Ui::AdminMain *ui;
};

#endif // ADMINMAIN_H
