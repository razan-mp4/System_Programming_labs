// mainwindow.h

#ifndef CARDATABASEGUI_H
#define CARDATABASEGUI_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QListWidget>
#include <QTextEdit>
#include <QCloseEvent>

#include "database.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void addCar();
    void displayAllCars();
    void displayCarsWithMarkings();
    void deleteCar();
    void modifyMileage();

    // Add these declarations for file input/output
    void saveToFile(const std::string& fileName);
    void loadFromFile(const std::string& fileName);

protected:
    // Add this declaration for handling the close event
    void closeEvent(QCloseEvent* event);

private:
    Database mCarDB;

    // Widgets
    QLineEdit* brandCodeEdit;
    QLineEdit* registrationNumberEdit;
    QLineEdit* chassisNumberEdit;
    QLineEdit* engineNumberEdit;
    QLineEdit* yearOfManufactureEdit;
    QLineEdit* mileageEdit;
    QLineEdit* driverCodeEdit;
    QLineEdit* lastServiceDateEdit;
    QLineEdit* mechanicCodeEdit;
    QLineEdit* specialMarkingsEdit;

    QListWidget* carListWidget;

    void setupUI();
    void clearInputFields();
};

#endif // mainwindow.h
