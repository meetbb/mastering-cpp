#include <iostream>
#include "DesignPatterns/Creational/Factory/VehicleFactory.h"
#include "DSAJourney/Strings/ValidAnagram.h"

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
    // ContainsDuplicate solution;
    // vector<int> nums = {1, 2, 3, 2};

    // if (solution.containsDuplicate(nums))
    // {
    //     cout << "Duplicates found" << endl;
    // }
    // else
    // {
    //     cout << "No duplicates" << endl;
    // }
    ValidAnagram solution;
    string s = "anagram";
    string t = "nagaram";
    if (solution.isAnagram(s, t))
    {
        cout << "Both strings are anagram of each other." << endl;
    }
    else
    {
        cout << "Both strings are not anagram of each other." << endl;
    }
    
    return 0;
}