// Car.h

#pragma once

#include <iostream>
#include <string>

namespace AutoFleet {

class Car {
public:
    // Constructors
    Car();
    Car(int code, int brandCode, std::string registrationNumber, std::string chassisNumber,
        std::string engineNumber, int yearOfManufacture, double mileage, int driverCode,
        std::string lastServiceDate, int mechanicCode, std::string specialMarkings);

    // Accessors and setters
    int getCode() const;
    int getBrandCode() const;
    std::string getRegistrationNumber() const;
    std::string getChassisNumber() const;
    std::string getEngineNumber() const;
    int getYearOfManufacture() const;
    double getMileage() const;
    int getDriverCode() const;
    std::string getLastServiceDate() const;
    int getMechanicCode() const;
    std::string getSpecialMarkings() const;

    void setCode(int code);
    void setBrandCode(int brandCode);
    void setRegistrationNumber(std::string registrationNumber);
    void setChassisNumber(std::string chassisNumber);
    void setEngineNumber(std::string engineNumber);
    void setYearOfManufacture(int yearOfManufacture);
    void setMileage(double mileage);
    void setDriverCode(int driverCode);
    void setLastServiceDate(std::string lastServiceDate);
    void setMechanicCode(int mechanicCode);
    void setSpecialMarkings(std::string specialMarkings);

    // Display car information
    void display() const;

private:
    int mCode;
    int mBrandCode;
    std::string mRegistrationNumber;
    std::string mChassisNumber;
    std::string mEngineNumber;
    int mYearOfManufacture;
    double mMileage;
    int mDriverCode;
    std::string mLastServiceDate;
    int mMechanicCode;
    std::string mSpecialMarkings;
};

}  // namespace AutoFleet
