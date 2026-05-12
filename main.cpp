#include <iostream>
#include "DesignPatterns/Creational/Factory/VehicleFactory.h"
#include "DSAJourney/HashSet/ContainsDuplicate.h"

int main() {    
    // std::string choice;

    // std::cout << "Enter ride type (auto / mini / sedan): ";
    // std::cin >> choice;

    // Vehicle* ride = VehicleFactory::createVehicle(choice);
    // if (ride)
    // {
    //     ride->startRide();
    // } else {
    //     std::cout << "Invalid ride type selected!" << std::endl;
    // }
    
    // delete ride; // Cleanup
    ContainsDuplicate solution;
    vector<int> nums = {1, 2, 3, 2};

    if (solution.containsDuplicate(nums))
    {
        cout << "Duplicates found" << endl;
    }
    else
    {
        cout << "No duplicates" << endl;
    }
    return 0;
}