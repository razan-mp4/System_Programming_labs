#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QVector>
#include "car.h"

class Database : public QObject
{
    Q_OBJECT

public:
    Database(QObject *parent = nullptr);
    ~Database();

    AutoFleet::Car& addCar(int brandCode, const QString& registrationNumber, const QString& chassisNumber,
                const QString& engineNumber, int yearOfManufacture, double mileage,
                int driverCode, const QString& lastServiceDate, int mechanicCode,
                const QString& specialMarkings);

    AutoFleet::Car& getCar(int carCode);
    void displayAllCars();
    void displayCarsWithMarkings(const QString& markings);
    void deleteCar(int carCode);
    void modifyMileage(int carCode, double newMileage);


    QVector<AutoFleet::Car>& getCars() {
        return mCars;
    }


    const QVector<AutoFleet::Car>& getCars() const;

signals:
    void updateOutput(const QString& message);

private:
    QVector<AutoFleet::Car> mCars;
    int mNextCarCode;
};

#endif // DATABASE_H
