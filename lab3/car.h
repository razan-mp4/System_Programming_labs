// Car.h

#pragma once

#include "QtCore/qstring.h"
#include <iostream>
#include <QString>
#include <string>

namespace AutoFleet {

class Car {
public:
    // Constructors
    Car();
    Car(int code, int brandCode, QString registrationNumber, QString chassisNumber,
        QString engineNumber, int yearOfManufacture, double mileage, int driverCode,
        QString lastServiceDate, int mechanicCode, QString specialMarkings);

    // Accessors and setters
    int getCode() const;
    int getBrandCode() const;
    QString getRegistrationNumber() const;
    QString getChassisNumber() const;
    QString getEngineNumber() const;
    int getYearOfManufacture() const;
    double getMileage() const;
    int getDriverCode() const;
    QString getLastServiceDate() const;
    int getMechanicCode() const;
    QString getSpecialMarkings() const;

    void setCode(int code);
    void setBrandCode(int brandCode);
    void setRegistrationNumber(QString registrationNumber);
    void setChassisNumber(QString chassisNumber);
    void setEngineNumber(QString engineNumber);
    void setYearOfManufacture(int yearOfManufacture);
    void setMileage(double mileage);
    void setDriverCode(int driverCode);
    void setLastServiceDate(QString lastServiceDate);
    void setMechanicCode(int mechanicCode);
    void setSpecialMarkings(QString specialMarkings);

    // Display car information
    void display() const;

private:
    int mCode;
    int mBrandCode;
    QString mRegistrationNumber;
    QString mChassisNumber;
    QString mEngineNumber;
    int mYearOfManufacture;
    double mMileage;
    int mDriverCode;
    QString mLastServiceDate;
    int mMechanicCode;
    QString mSpecialMarkings;
};

}  // namespace AutoFleet
