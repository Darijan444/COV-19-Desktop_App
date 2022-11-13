#include "landingpage.h"
#include "adminmain.h"
#include "adminusers.h"
#include "adminreports.h"
#include "adminlogs.h"
#include "ui_adminmain.h"

#include <QtCharts/QChartView>
#include <QtCharts/QAbstractBarSeries>
#include <QtCharts/QPercentBarSeries>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtCore/QRandomGenerator>
#include <QtCharts/QValueAxis>

#include <QtCharts/QBarCategoryAxis>

AdminMain::AdminMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminMain)
{
    ui->setupUi(this);

    //User Icon size
    int iconSize = 20;

    QPixmap admin(":/Images/user.png");
    ui->labelAdmin->setPixmap(admin.scaled(iconSize,iconSize));



    //->Landingpage
    connect(ui->pushButtonLogout,&QPushButton::clicked,[=](){
        LandingPage * landingpage = new LandingPage(this);
        this->hide();
        landingpage->show();
    });

    //->AdminMain
    connect(ui->pushButtonDashboard,&QPushButton::clicked,[=](){
        AdminMain * adminmain = new AdminMain(this);
        this->hide();
        adminmain->show();
    });

    //->AdminUsers
    connect(ui->pushButtonUsers,&QPushButton::clicked,[=](){
        AdminUsers * adminUsers = new AdminUsers(this);
        this->hide();
        adminUsers->show();
    });

    //->AdminReports
    connect(ui->pushButtonReports,&QPushButton::clicked,[=](){
        AdminReports * adminReports = new AdminReports(this);
        this->hide();
        adminReports->show();
    });

    //->AdminLogs
    connect(ui->pushButtonLogs,&QPushButton::clicked,[=](){
        AdminLogs * adminLogs = new AdminLogs(this);
        this->hide();
        adminLogs->show();
    });


    //create charts
    QChartView *chartView;

    int m_valueCount = 5;


    //User Count
    auto query = QSqlQuery(db);

    query.exec("select count(*) from user");
    query.next();
    userCount = query.value(0).toInt();

    //2 Doses Count
    query.exec("select count(*) from user where Dose2Date!='---'");
    query.next();
    twoDosesCount = query.value(0).toInt();

    //RAT Positive Count
    query.exec("select count(*) from user where RAT1Result = 'Positive' OR RAT2Result = 'Positive'");
    query.next();
    RATPositiveCount = query.value(0).toInt();

    //Issued Vaccine Pass Count
    query.exec("select count(*) from user where VaccinePass='Issued'");
    query.next();
    issuedVaccinePassCount = query.value(0).toInt();

    query.exec("select count(*) from reports");
    query.next();
    reportsCount = query.value(0).toInt();


//    qDebug() << issuedVaccinePassCount;

    chartView = new QChartView(createBarChart(m_valueCount));
    ui->gridLayout->addWidget(chartView, 2, 0);
    charts << chartView;
}


AdminMain::~AdminMain()
{
    delete ui;
}


QChart *AdminMain::createBarChart(int valueCount) const
{
    Q_UNUSED(valueCount);
    QChart *chart = new QChart();
    chart->setTitle("Bar chart");

    QBarSet *set = new QBarSet("Count");
    *set << userCount << twoDosesCount << RATPositiveCount << issuedVaccinePassCount << reportsCount;

    QBarSeries *series = new QBarSeries();
    series->append(set);

    chart->addSeries(series);
    chart->setTitle("Summary");

    //Animation
    chart->setAnimationOptions(QChart::AllAnimations);

    //X-Axis
    QStringList categories;
    categories << "Users" << "2 Doses" << "RAT Positive" << "issued Pass" << "Reports";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);

    //Set default setting
    chart->createDefaultAxes();
    chart->setAxisX(axisX, series);
    chart->axes(Qt::Vertical).first()->setRange(0, 10);
    //chart->setAxisY(0, 10);



    return chart;
}
