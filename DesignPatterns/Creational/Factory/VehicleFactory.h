#ifndef VEHICLE_FACTORY_H
#define VEHICLE_FACTORY_H

#include <string>
#include "Auto.h"
#include "Mini.h"
#include "Sedan.h"

class VehicleFactory
{
public:
    static Vehicle* createVehicle(const std::string& type) {
        if (type == "auto")
        {
            return new Auto();
        } else if (type == "mini")
        {
            return new Mini();
        } else if (type == "sedan")
        {
            return new Sedan();
        }
        return nullptr;
    }
};

#endif