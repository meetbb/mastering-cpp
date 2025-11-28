#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>

class Vehicle
{
private:
public:
    virtual void startRide() = 0; // Pure virtual function
    virtual ~Vehicle() {}
};

#endif