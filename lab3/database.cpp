#include "database.h"

Database::Database(QObject *parent)
    : QObject(parent), mNextCarCode(1000) {}

Database::~Database() {}

AutoFleet::Car& Database::addCar(int brandCode, const QString& registrationNumber, const QString& chassisNumber,
                      const QString& engineNumber, int yearOfManufacture, double mileage,
                      int driverCode, const QString& lastServiceDate, int mechanicCode,
                      const QString& specialMarkings)
{
    AutoFleet::Car newCar(mNextCarCode++, brandCode, registrationNumber, chassisNumber,
               engineNumber, yearOfManufacture, mileage, driverCode,
               lastServiceDate, mechanicCode, specialMarkings);

    mCars.append(newCar);
    emit updateOutput("Car added successfully.");
    return mCars.last();
}

AutoFleet::Car& Database::getCar(int carCode)
{
    for (auto& car : mCars) {
        if (car.getCode() == carCode) {
            return car;
        }
    }

    emit updateOutput("No car with code " + QString::number(carCode));
    throw std::exception();
}

void Database::displayAllCars()
{
    for (const auto& car : mCars) {
        car.display();
    }
}

void Database::displayCarsWithMarkings(const QString& markings)
{
    for (const auto& car : mCars) {
        if (car.getSpecialMarkings() == markings) {
            car.display();
        }
    }
}

void Database::deleteCar(int carCode)
{
    auto carIt = std::remove_if(mCars.begin(), mCars.end(),
                                [carCode](const AutoFleet::Car& car) { return car.getCode() == carCode; });

    if (carIt != mCars.end()) {
        mCars.erase(carIt, mCars.end());
        emit updateOutput("Car with code " + QString::number(carCode) + " deleted successfully.");
    } else {
        emit updateOutput("No car with code " + QString::number(carCode));
        throw std::exception();
    }
}

void Database::modifyMileage(int carCode, double newMileage)
{
    auto carIt = std::find_if(mCars.begin(), mCars.end(),
                              [carCode](const AutoFleet::Car& car) { return car.getCode() == carCode; });

    if (carIt != mCars.end()) {
        carIt->setMileage(newMileage);
        emit updateOutput("Mileage for car with code " + QString::number(carCode) + " modified successfully.");
    } else {
        emit updateOutput("No car with code " + QString::number(carCode));
        throw std::exception();
    }
}

const QVector<AutoFleet::Car>& Database::getCars() const {
    return mCars;
}
