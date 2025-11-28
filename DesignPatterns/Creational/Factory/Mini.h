#ifndef MINI_H
#define MINI_H
#include "Vehicle.h"

class Mini : public Vehicle
{
public:
    void startRide() override {
        std::cout << "Mini car ride started!" << std::endl;
    }    
};

#endif