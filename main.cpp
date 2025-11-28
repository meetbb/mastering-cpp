#include <iostream>
#include "DesignPatterns/Creational/Factory/VehicleFactory.h"

int main() {    
    std::string choice;

    std::cout << "Enter ride type (auto / mini / sedan): ";
    std::cin >> choice;

    Vehicle* ride = VehicleFactory::createVehicle(choice);
    if (ride)
    {
        ride->startRide();
    } else {
        std::cout << "Invalid ride type selected!" << std::endl;
    }
    
    delete ride; // Cleanup
    return 0;
}