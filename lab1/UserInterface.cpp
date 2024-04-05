// UserInterface.cpp

#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"

using namespace std;
using namespace Records;

int displayMenu();
void doAddCar(Database& inDB);
void doDisplayAllCars(Database& inDB);
void doDisplayCarsWithMarkings(Database& inDB);

int main()
{
    // Create one instance on the stack
    Database carDB1;

    // Create another instance on the heap
    Database* carDB2 = new Database;

    bool done = false;

    while (!done) {
        int selection = displayMenu();

        switch (selection) {
        case 1:
            // Use the first instance
            doAddCar(carDB1);
            break;
        case 2:
            // Use the first instance
            doDisplayAllCars(carDB1);
            break;
        case 3:
            // Use the first instance
            doDisplayCarsWithMarkings(carDB1);
            break;
        case 4: // Additional case for the second database
            // Use the second instance
            doAddCar(*carDB2);
            break;
        case 5: // Additional case for the second database
            // Use the second instance
            doDisplayAllCars(*carDB2);
            break;
        case 6: // Additional case for the second database
            // Use the second instance
            doDisplayCarsWithMarkings(*carDB2);
            break;
        case 0:
            done = true;
            break;
        default:
            cerr << "Unknown command." << endl;
        }
    }

    // Delete the heap-allocated instance
    delete carDB2;

    return 0;
}


int displayMenu()
{
    int selection;
    cout << endl;
    cout << "Car Database" << endl;
    cout << "-------------" << endl;
    cout << "1) Add a new car (Database 1)" << endl;
    cout << "2) Display all cars (Database 1)" << endl;
    cout << "3) Display cars with specific markings (Database 1)" << endl;
    cout << "4) Add a new car (Database 2)" << endl;
    cout << "5) Display all cars (Database 2)" << endl;
    cout << "6) Display cars with specific markings (Database 2)" << endl;
    cout << "0) Quit" << endl;
    cout << endl;

    cout << "---> ";
    cin >> selection;

    return selection;
}


void doAddCar(Database& inDB)
{
    int brandCode;
    string registrationNumber, chassisNumber, engineNumber, lastServiceDate, specialMarkings;
    int yearOfManufacture, driverCode, mechanicCode;
    double mileage;

    cout << "Brand Code? ";
    cin >> brandCode;
    cout << "Registration Number? ";
    cin >> registrationNumber;
    cout << "Chassis Number? ";
    cin >> chassisNumber;
    cout << "Engine Number? ";
    cin >> engineNumber;
    cout << "Year of Manufacture? ";
    cin >> yearOfManufacture;
    cout << "Mileage? ";
    cin >> mileage;
    cout << "Driver Code? ";
    cin >> driverCode;
    cout << "Last Service Date? ";
    cin >> lastServiceDate;
    cout << "Mechanic Code? ";
    cin >> mechanicCode;
    cout << "Special Markings? ";
    cin >> specialMarkings;

    try {
        inDB.addCar(brandCode, registrationNumber, chassisNumber, engineNumber,
                    yearOfManufacture, mileage, driverCode, lastServiceDate,
                    mechanicCode, specialMarkings);
    } catch (std::exception& ex) {
        cerr << "Unable to add new car!" << endl;
    }
}

void doDisplayAllCars(Database& inDB)
{
    inDB.displayAllCars();
}

void doDisplayCarsWithMarkings(Database& inDB)
{
    string markings;
    cout << "Enter special markings: ";
    cin >> markings;
    inDB.displayCarsWithMarkings(markings);
}
