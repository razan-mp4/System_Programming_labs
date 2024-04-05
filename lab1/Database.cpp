// Database.cpp

#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"
#include "Car.h"  // Include the Car header file with the correct namespace

using namespace std;

namespace Records {
    Database::Database()
        : mNextSlot(0), mNextCarCode(kFirstCarCode) {}

    Database::~Database() {}
AutoFleet::Car& Database::addCar(int brandCode, std::string registrationNumber, std::string chassisNumber,
                                 std::string engineNumber, int yearOfManufacture, double mileage,
                                 int driverCode, std::string lastServiceDate, int mechanicCode,
                                 std::string specialMarkings)
{
    if (mNextSlot >= kMaxCars) {
        cerr << "There is no more room to add the new car!" << endl;
        throw std::exception();
    }

    AutoFleet::Car& theCar = mCars[mNextSlot++];
    theCar.setCode(mNextCarCode++);
    theCar.setBrandCode(brandCode);
    theCar.setRegistrationNumber(registrationNumber);
    theCar.setChassisNumber(chassisNumber);
    theCar.setEngineNumber(engineNumber);
    theCar.setYearOfManufacture(yearOfManufacture);
    theCar.setMileage(mileage);
    theCar.setDriverCode(driverCode);
    theCar.setLastServiceDate(lastServiceDate);
    theCar.setMechanicCode(mechanicCode);
    theCar.setSpecialMarkings(specialMarkings);

    return theCar;
}

AutoFleet::Car& Database::getCar(int carCode)
{
    for (int i = 0; i < mNextSlot; i++) {
        if (mCars[i].getCode() == carCode) {
            return mCars[i];
        }
    }

    cerr << "No car with code " << carCode << endl;
    throw std::exception();
}

void Database::displayAllCars()
{
    for (int i = 0; i < mNextSlot; i++) {
        mCars[i].display();
    }
}

void Database::displayCarsWithMarkings(std::string markings)
{
    for (int i = 0; i < mNextSlot; i++) {
        if (mCars[i].getSpecialMarkings() == markings) {
            mCars[i].display();
        }
    }
}

}  // namespace Records
