#include "landingpage.h"
#include "ui_landingpage.h"


LandingPage::LandingPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LandingPage)
{
    ui->setupUi(this);

}


LandingPage::~LandingPage()
{
    delete ui;
}
