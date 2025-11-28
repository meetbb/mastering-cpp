#ifndef SEDAN_H
#define SEDAN_H

#include "Vehicle.h"

class Sedan : public Vehicle
{
public:
    void startRide() override {
        std::cout << "Sedan ride started!" << std::endl;
    }
};

#endif