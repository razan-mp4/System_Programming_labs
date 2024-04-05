// mainwindow.cpp
#include <QInputDialog>
#include <QMessageBox>
#include <fstream>
#include <iostream>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    loadFromFile("/Users/nazarodemchuk/Desktop/lab3/1.txt");
}

void MainWindow::setupUI()
{
    // Create input fields
    brandCodeEdit = new QLineEdit(this);
    registrationNumberEdit = new QLineEdit(this);
    chassisNumberEdit = new QLineEdit(this);
    engineNumberEdit = new QLineEdit(this);
    yearOfManufactureEdit = new QLineEdit(this);
    mileageEdit = new QLineEdit(this);
    driverCodeEdit = new QLineEdit(this);
    lastServiceDateEdit = new QLineEdit(this);
    mechanicCodeEdit = new QLineEdit(this);
    specialMarkingsEdit = new QLineEdit(this);

    // Create buttons
    QPushButton* addButton = new QPushButton("Add Car", this);
    QPushButton* displayAllButton = new QPushButton("Display All Cars", this);
    QPushButton* displayMarkingsButton = new QPushButton("Display Cars with Markings", this);
    QPushButton* deleteButton = new QPushButton("Delete Car", this);
    QPushButton* modifyMileageButton = new QPushButton("Modify Mileage", this);

    // Create list widget
    carListWidget = new QListWidget(this);

    // Layout
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* inputLayout = new QHBoxLayout();

    // Add input fields and labels to the layout
    inputLayout->addWidget(new QLabel("Brand Code:"));
    inputLayout->addWidget(brandCodeEdit);

    inputLayout->addWidget(new QLabel("Registration Number:"));
    inputLayout->addWidget(registrationNumberEdit);

    inputLayout->addWidget(new QLabel("Chassis Number:"));
    inputLayout->addWidget(chassisNumberEdit);

    inputLayout->addWidget(new QLabel("Engine Number:"));
    inputLayout->addWidget(engineNumberEdit);

    inputLayout->addWidget(new QLabel("Year of Manufacture:"));
    inputLayout->addWidget(yearOfManufactureEdit);

    inputLayout->addWidget(new QLabel("Mileage:"));
    inputLayout->addWidget(mileageEdit);

    inputLayout->addWidget(new QLabel("Driver Code:"));
    inputLayout->addWidget(driverCodeEdit);

    inputLayout->addWidget(new QLabel("Last Service Date:"));
    inputLayout->addWidget(lastServiceDateEdit);

    inputLayout->addWidget(new QLabel("Mechanic Code:"));
    inputLayout->addWidget(mechanicCodeEdit);

    inputLayout->addWidget(new QLabel("Special Markings:"));
    inputLayout->addWidget(specialMarkingsEdit);

    // Add buttons to the layout
    mainLayout->addLayout(inputLayout);
    mainLayout->addWidget(addButton);
    mainLayout->addWidget(displayAllButton);
    mainLayout->addWidget(displayMarkingsButton);
    mainLayout->addWidget(deleteButton);
    mainLayout->addWidget(modifyMileageButton);
    mainLayout->addWidget(carListWidget);

    // Connect buttons to slots
    connect(addButton, SIGNAL(clicked()), this, SLOT(addCar()));
    connect(displayAllButton, SIGNAL(clicked()), this, SLOT(displayAllCars()));
    connect(displayMarkingsButton, SIGNAL(clicked()), this, SLOT(displayCarsWithMarkings()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteCar()));
    connect(modifyMileageButton, SIGNAL(clicked()), this, SLOT(modifyMileage()));

    // Set the central widget
    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);


}



void MainWindow::clearInputFields()
{
    // Clear all input fields after adding a car
    brandCodeEdit->clear();
    registrationNumberEdit->clear();
    chassisNumberEdit->clear();
    engineNumberEdit->clear();
    yearOfManufactureEdit->clear();
    mileageEdit->clear();
    driverCodeEdit->clear();
    lastServiceDateEdit->clear();
    mechanicCodeEdit->clear();
    specialMarkingsEdit->clear();
}

void MainWindow::addCar()
{
    // Retrieve values from input fields and add a new car to the database
    int brandCode = brandCodeEdit->text().toInt();
    QString registrationNumber = registrationNumberEdit->text();
    QString chassisNumber = chassisNumberEdit->text();
    QString engineNumber = engineNumberEdit->text();
    int yearOfManufacture = yearOfManufactureEdit->text().toInt();
    double mileage = mileageEdit->text().toDouble();
    int driverCode = driverCodeEdit->text().toInt();
    QString lastServiceDate = lastServiceDateEdit->text();
    int mechanicCode = mechanicCodeEdit->text().toInt();
    QString specialMarkings = specialMarkingsEdit->text();

    try {
        AutoFleet::Car& newCar = mCarDB.addCar(brandCode, registrationNumber, chassisNumber,
                                               engineNumber, yearOfManufacture, mileage,
                                               driverCode, lastServiceDate, mechanicCode,
                                               specialMarkings);

        // Optionally, you can display a success message
        QMessageBox::information(this, "Car Added", "Car added successfully.\nCar Code: " + QString::number(newCar.getCode()));

        // Clear input fields after successful addition
        clearInputFields();
    } catch (std::exception& ex) {
        // Handle exception (e.g., show an error message)
        QMessageBox::critical(this, "Error", "Unable to add new car!\n" + QString(ex.what()));
    }
}

void MainWindow::displayAllCars()
{
    // Display all cars in the list widget
    carListWidget->clear();
    mCarDB.displayAllCars();
}

void MainWindow::displayCarsWithMarkings()
{
    // Retrieve markings from input field and display cars with those markings
    QString markings = specialMarkingsEdit->text();
    carListWidget->clear();
    mCarDB.displayCarsWithMarkings(markings);
}

void MainWindow::deleteCar()
{
    // Retrieve car code from input field and delete the corresponding car
    bool ok;
    QString carCodeText = QInputDialog::getText(this, "Delete Car", "Enter car code to delete:", QLineEdit::Normal, "", &ok);

    if (ok && !carCodeText.isEmpty()) {
        int carCode = carCodeText.toInt();
        try {
            mCarDB.deleteCar(carCode);
            displayAllCars(); // Refresh the displayed cars after deletion
        } catch (std::exception& ex) {
            // Handle exception (e.g., show an error message)
        }
    }
}

void MainWindow::modifyMileage()
{
    // Retrieve car code and new mileage from input fields and modify the mileage
    bool ok;
    QString carCodeText = QInputDialog::getText(this, "Modify Mileage", "Enter car code to modify mileage:", QLineEdit::Normal, "", &ok);

    if (ok && !carCodeText.isEmpty()) {
        int carCode = carCodeText.toInt();

        QString newMileageText = QInputDialog::getText(this, "Modify Mileage", "Enter new mileage:", QLineEdit::Normal, "", &ok);

        if (ok && !newMileageText.isEmpty()) {
            double newMileage = newMileageText.toDouble();
            try {
                mCarDB.modifyMileage(carCode, newMileage);
                displayAllCars(); // Refresh the displayed cars after modification
            } catch (std::exception& ex) {
                // Handle exception (e.g., show an error message)
            }
        }
    }
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    saveToFile("/Users/nazarodemchuk/Desktop/lab3/1.txt"); // Adjust the file name accordingly
    event->accept();
}


void MainWindow::saveToFile(const std::string& fileName)
{
    std::ofstream outFile(fileName, std::ios::out);

    if (!outFile.is_open())
    {
        QMessageBox::critical(this, "Error", "Unable to open file for writing!");
        return;
    }

    // Save each car's information to the file
    for (const auto& car : mCarDB.getCars()) {
        outFile << car.getCode() << " "
                << car.getBrandCode() << " "
                << car.getRegistrationNumber().toStdString() << " "
                << car.getChassisNumber().toStdString() << " "
                << car.getEngineNumber().toStdString() << " "
                << car.getYearOfManufacture() << " "
                << car.getMileage() << " "
                << car.getDriverCode() << " "
                << car.getLastServiceDate().toStdString() << " "
                << car.getMechanicCode() << " "
                << car.getSpecialMarkings().toStdString() << "\n";
    }

    outFile.close();
}


void MainWindow::loadFromFile(const std::string& fileName)
{
    std::ifstream inFile(fileName, std::ios::in);

    if (!inFile.is_open())
    {
        QMessageBox::critical(this, "Error", "Unable to open file for reading!");
        return;
    }

    // Clear the current database before loading from the file
    mCarDB.getCars().clear();

    while (!inFile.eof())
    {
        int code, brandCode, yearOfManufacture, driverCode, mechanicCode;
        double mileage;
        std::string registrationNumber, chassisNumber, engineNumber, lastServiceDate, specialMarkings;

        // Read car information from the file
        inFile >> code >> brandCode >> registrationNumber >> chassisNumber >> engineNumber
            >> yearOfManufacture >> mileage >> driverCode >> lastServiceDate
            >> mechanicCode >> specialMarkings;

        // Create a new car and add it to the database
        mCarDB.getCars().emplace_back(code, brandCode, QString::fromStdString(registrationNumber),
                                      QString::fromStdString(chassisNumber), QString::fromStdString(engineNumber),
                                      yearOfManufacture, mileage, driverCode, QString::fromStdString(lastServiceDate),
                                      mechanicCode, QString::fromStdString(specialMarkings));
    }

    inFile.close();
}
