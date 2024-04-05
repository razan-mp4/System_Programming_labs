// Database.h

#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include "Car.h"

namespace Records {

    const int kMaxCars = 100;
    const int kFirstCarCode = 1000;

    class Database
    {
    public:
        Database();
        ~Database();
        AutoFleet::Car& addCar(int brandCode, std::string registrationNumber, std::string chassisNumber,
            std::string engineNumber, int yearOfManufacture, double mileage,
            int driverCode, std::string lastServiceDate, int mechanicCode,
            std::string specialMarkings);
        AutoFleet::Car& getCar(int carCode);
        void displayAllCars();
        void displayCarsWithMarkings(std::string markings);

    protected:
        AutoFleet::Car mCars[kMaxCars];
        int mNextSlot;
        int mNextCarCode;
    };

}  // namespace Records
