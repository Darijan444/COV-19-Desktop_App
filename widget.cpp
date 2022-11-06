#include "widget.h"
#include "./ui_widget.h"

#include <QMessageBox>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}


//Test
void Widget::on_pushButton_clicked()
{
    QMessageBox::information(this,"Information","Hello Darijan!!");
}


void Widget::on_pushButton_2_clicked()
{
    QMessageBox::information(this,"Information","Hello to you too Ryuu!!");
}

