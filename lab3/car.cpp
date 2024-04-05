// Car.cpp

#include <iostream>
#include <QString>
#include "car.h"

namespace AutoFleet {

Car::Car()
    : mCode(-1), mBrandCode(-1), mYearOfManufacture(-1), mMileage(0), mDriverCode(-1), mMechanicCode(-1) {}

Car::Car(int code, int brandCode, QString registrationNumber, QString chassisNumber,
         QString engineNumber, int yearOfManufacture, double mileage, int driverCode,
         QString lastServiceDate, int mechanicCode, QString specialMarkings)
    : mCode(code), mBrandCode(brandCode), mRegistrationNumber(registrationNumber),
    mChassisNumber(chassisNumber), mEngineNumber(engineNumber), mYearOfManufacture(yearOfManufacture),
    mMileage(mileage), mDriverCode(driverCode), mLastServiceDate(lastServiceDate),
    mMechanicCode(mechanicCode), mSpecialMarkings(specialMarkings) {}

// Accessors
int Car::getCode() const {
    return mCode;
}

int Car::getBrandCode() const {
    return mBrandCode;
}

QString Car::getRegistrationNumber() const {
    return mRegistrationNumber;
}

QString Car::getChassisNumber() const {
    return mChassisNumber;
}

QString Car::getEngineNumber() const {
    return mEngineNumber;
}

int Car::getYearOfManufacture() const {
    return mYearOfManufacture;
}

double Car::getMileage() const {
    return mMileage;
}

int Car::getDriverCode() const {
    return mDriverCode;
}

QString Car::getLastServiceDate() const {
    return mLastServiceDate;
}

int Car::getMechanicCode() const {
    return mMechanicCode;
}

QString Car::getSpecialMarkings() const {
    return mSpecialMarkings;
}

// Setters
void Car::setCode(int code) {
    mCode = code;
}

void Car::setBrandCode(int brandCode) {
    mBrandCode = brandCode;
}

void Car::setRegistrationNumber(QString registrationNumber) {
    mRegistrationNumber = registrationNumber;
}

void Car::setChassisNumber(QString chassisNumber) {
    mChassisNumber = chassisNumber;
}

void Car::setEngineNumber(QString engineNumber) {
    mEngineNumber = engineNumber;
}

void Car::setYearOfManufacture(int yearOfManufacture) {
    mYearOfManufacture = yearOfManufacture;
}

void Car::setMileage(double mileage) {
    mMileage = mileage;
}

void Car::setDriverCode(int driverCode) {
    mDriverCode = driverCode;
}

void Car::setLastServiceDate(QString lastServiceDate) {
    mLastServiceDate = lastServiceDate;
}

void Car::setMechanicCode(int mechanicCode) {
    mMechanicCode = mechanicCode;
}

void Car::setSpecialMarkings(QString specialMarkings) {
    mSpecialMarkings = specialMarkings;
}

// Display car information
void Car::display() const {
    std::cout << "Car Code: " << getCode() << std::endl;
    std::cout << "Brand Code: " << getBrandCode() << std::endl;
    std::cout << "Registration Number: " << getRegistrationNumber().toStdString() << std::endl;
    std::cout << "Chassis Number: " << getChassisNumber().toStdString() << std::endl;
    std::cout << "Engine Number: " << getEngineNumber().toStdString() << std::endl;
    std::cout << "Year of Manufacture: " << getYearOfManufacture() << std::endl;
    std::cout << "Mileage: " << getMileage() << " miles" << std::endl;
    std::cout << "Driver Code: " << getDriverCode() << std::endl;
    std::cout << "Last Service Date: " << getLastServiceDate().toStdString() << std::endl;
    std::cout << "Mechanic Code: " << getMechanicCode() << std::endl;
    std::cout << "Special Markings: " << getSpecialMarkings().toStdString() << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}



}  // namespace AutoFleet
