#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTableWidgetItem>
#include <QDir>
#include <QDateTime>

#include "safetyanalysis.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->flightTable->setColumnCount(8);

    ui->flightTable->setHorizontalHeaderLabels(
        QStringList()
        << "Flight ID"
        << "Aircraft Type"
        << "Altitude"
        << "Speed"
        << "Fuel"
        << "Vertical Speed"
        << "Risk Score"
        << "Status");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadButton_clicked()
{
    QFile file(
        "C:/Users/RAJA BABU/Desktop/FlightSafety/flight_log.json");

    if(!file.open(QIODevice::ReadOnly))
    {
        ui->warningsText->setPlainText(
            "Cannot open JSON file");
        return;
    }

    QByteArray data = file.readAll();

    QJsonDocument doc =
        QJsonDocument::fromJson(data);

    QJsonObject root =
        doc.object();

    QJsonArray flights =
        root["flights"].toArray();

    ui->flightTable->setRowCount(flights.size());

    for(int i = 0; i < flights.size(); i++)
    {
        QJsonObject flight =
            flights[i].toObject();

        QString flightId =
            flight["flight_id"].toString();

        QString aircraftType =
            flight["aircraft_type"].toString();

        int altitude =
            flight["altitude"].toInt();

        int speed =
            flight["speed"].toInt();

        int fuel =
            flight["fuel"].toInt();

        int verticalSpeed =
            flight["vertical_speed"].toInt();

        int riskScore =
            SafetyAnalysis::calculateRiskScore(
                fuel,
                speed,
                verticalSpeed);

        QString status;

        if(riskScore >= 70)
        {
            status = "HIGH RISK";
        }
        else if(riskScore >= 30)
        {
            status = "MEDIUM RISK";
        }
        else
        {
            status = "LOW RISK";
        }

        ui->flightTable->setItem(
            i, 0,
            new QTableWidgetItem(flightId));

        ui->flightTable->setItem(
            i, 1,
            new QTableWidgetItem(aircraftType));

        ui->flightTable->setItem(
            i, 2,
            new QTableWidgetItem(
                QString::number(altitude)));

        ui->flightTable->setItem(
            i, 3,
            new QTableWidgetItem(
                QString::number(speed)));

        ui->flightTable->setItem(
            i, 4,
            new QTableWidgetItem(
                QString::number(fuel)));

        ui->flightTable->setItem(
            i, 5,
            new QTableWidgetItem(
                QString::number(verticalSpeed)));

        ui->flightTable->setItem(
            i, 6,
            new QTableWidgetItem(
                QString::number(riskScore)));

        ui->flightTable->setItem(
            i, 7,
            new QTableWidgetItem(status));
    }

    ui->warningsText->setPlainText(
        "Loaded " +
        QString::number(flights.size()) +
        " flight records successfully.");
}

void MainWindow::on_uploadButton_clicked()
{
    QString sourceFile =
        "C:/Users/RAJA BABU/Desktop/FlightSafety/flight_log.json";

    QString cloudFolder =
        "C:/Users/RAJA BABU/Desktop/FlightSafety/cloud_storage";

    QDir dir;

    if(!dir.exists(cloudFolder))
    {
        dir.mkpath(cloudFolder);
    }

    QString timestamp =
        QDateTime::currentDateTime()
            .toString("yyyyMMdd_hhmmss");

    QString destinationFile =
        cloudFolder +
        "/flight_" +
        timestamp +
        ".json";

    if(!QFile::exists(sourceFile))
    {
        ui->warningsText->setPlainText(
            "Source JSON file not found!");
        return;
    }

    bool success =
        QFile::copy(sourceFile, destinationFile);

    if(success)
    {
        ui->warningsText->setPlainText(
            "Upload Successful!\n\nSaved to:\n" +
            destinationFile);
    }
    else
    {
        ui->warningsText->setPlainText(
            "Upload Failed!\nCheck file path.");
    }
}
void MainWindow::on_pushButton_clicked()
{
    QString sourceFile =
        "C:/Users/RAJA BABU/Desktop/FlightSafety/flight_log.json";

    QString cloudFolder =
        "C:/Users/RAJA BABU/Desktop/FlightSafety/cloud_storage";

    QDir dir;

    if(!dir.exists(cloudFolder))
    {
        dir.mkpath(cloudFolder);
    }

    QString timestamp =
        QDateTime::currentDateTime()
            .toString("yyyyMMdd_hhmmss");

    QString destinationFile =
        cloudFolder +
        "/flight_" +
        timestamp +
        ".json";

    if(!QFile::exists(sourceFile))
    {
        ui->warningsText->setPlainText(
            "Source JSON file not found!");
        return;
    }

    bool success =
        QFile::copy(sourceFile, destinationFile);

    if(success)
    {
        ui->warningsText->setPlainText(
            "Upload Successful!\n" +
            destinationFile);
    }
    else
    {
        ui->warningsText->setPlainText(
            "Upload Failed!");
    }
}
