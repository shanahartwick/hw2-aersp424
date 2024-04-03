#pragma once

#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "AirTrafficController.h"

class Aircraft
{
private:
    int id;
    AirTrafficController& atc;

public:
    Aircraft(int _id, AirTrafficController& _atc);
    void approach();
};

#endif // AIRCRAFT_