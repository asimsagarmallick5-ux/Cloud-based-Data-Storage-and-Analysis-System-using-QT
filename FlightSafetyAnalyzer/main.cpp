#include <QCoreApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile file("C:/Users/RAJA BABU/Desktop/FlightSafety/flight_log.json");

    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Cannot open JSON file";
        return -1;
    }


    QByteArray data = file.readAll();

    QJsonDocument doc =
        QJsonDocument::fromJson(data);

    QJsonObject obj =
        doc.object();

    qDebug() << "Flight ID:"
             << obj["flight_id"].toString();

    qDebug() << "Altitude:"
             << obj["altitude"].toInt();

    qDebug() << "Speed:"
             << obj["speed"].toInt();

    qDebug() << "Fuel:"
             << obj["fuel"].toInt();

    qDebug() << "Vertical Speed:"
             << obj["vertical_speed"].toInt();
    //Safety Cheks

    int riskScore = 0;

    if(obj["fuel"].toInt() < 20)
    {
        qDebug() << "WARNING: LOW FUEL";
        riskScore += 30;
    }

    if(obj["vertical_speed"].toInt() < -1200)
    {
        qDebug() << "WARNING: HIGH DESCENT RATE";
        riskScore += 40;
    }

    if(obj["speed"].toInt() > 300)
    {
        qDebug() << "WARNING: OVERSPEED";
        riskScore += 30;
    }

    qDebug() << "Risk Score:" << riskScore;

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

    qDebug() << "Status:" << status;

    return 0;
}