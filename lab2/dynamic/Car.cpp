// Car.cpp

#include <iostream>
#include "Car.h"

namespace AutoFleet {

Car::Car()
    : mCode(-1), mBrandCode(-1), mYearOfManufacture(-1), mMileage(0), mDriverCode(-1), mMechanicCode(-1) {}

Car::Car(int code, int brandCode, std::string registrationNumber, std::string chassisNumber,
         std::string engineNumber, int yearOfManufacture, double mileage, int driverCode,
         std::string lastServiceDate, int mechanicCode, std::string specialMarkings)
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

std::string Car::getRegistrationNumber() const {
    return mRegistrationNumber;
}

std::string Car::getChassisNumber() const {
    return mChassisNumber;
}

std::string Car::getEngineNumber() const {
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

std::string Car::getLastServiceDate() const {
    return mLastServiceDate;
}

int Car::getMechanicCode() const {
    return mMechanicCode;
}

std::string Car::getSpecialMarkings() const {
    return mSpecialMarkings;
}

// Setters
void Car::setCode(int code) {
    mCode = code;
}

void Car::setBrandCode(int brandCode) {
    mBrandCode = brandCode;
}

void Car::setRegistrationNumber(std::string registrationNumber) {
    mRegistrationNumber = registrationNumber;
}

void Car::setChassisNumber(std::string chassisNumber) {
    mChassisNumber = chassisNumber;
}

void Car::setEngineNumber(std::string engineNumber) {
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

void Car::setLastServiceDate(std::string lastServiceDate) {
    mLastServiceDate = lastServiceDate;
}

void Car::setMechanicCode(int mechanicCode) {
    mMechanicCode = mechanicCode;
}

void Car::setSpecialMarkings(std::string specialMarkings) {
    mSpecialMarkings = specialMarkings;
}

// Display car information
void Car::display() const {
    std::cout << "Car Code: " << getCode() << std::endl;
    std::cout << "Brand Code: " << getBrandCode() << std::endl;
    std::cout << "Registration Number: " << getRegistrationNumber() << std::endl;
    std::cout << "Chassis Number: " << getChassisNumber() << std::endl;
    std::cout << "Engine Number: " << getEngineNumber() << std::endl;
    std::cout << "Year of Manufacture: " << getYearOfManufacture() << std::endl;
    std::cout << "Mileage: " << getMileage() << " miles" << std::endl;
    std::cout << "Driver Code: " << getDriverCode() << std::endl;
    std::cout << "Last Service Date: " << getLastServiceDate() << std::endl;
    std::cout << "Mechanic Code: " << getMechanicCode() << std::endl;
    std::cout << "Special Markings: " << getSpecialMarkings() << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}


}  // namespace AutoFleet
