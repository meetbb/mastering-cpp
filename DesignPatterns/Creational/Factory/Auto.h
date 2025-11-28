#ifndef AUTO_H
#define AUTO_H
#include "Vehicle.h"

class Auto : public Vehicle
{
public:
    void startRide() override {
        std::cout << "Auto rickshaw ride started!" << std::endl;
    }
};

#endif