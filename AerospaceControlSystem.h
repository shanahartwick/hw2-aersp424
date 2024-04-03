#pragma once
#ifndef AEROSPACE_CONTROL_SYSTEM_H
#define AEROSPACE_CONTROL_SYSTEM_H
#include <vector>
#include "Sensor.h"

class AerospaceControlSystem
{
private:
    std::vector<Sensor*> sensors;

public:
    // Function to add a sensor to the control system
    void addSensor(Sensor* sensor);

    // Function to monitor sensors, gather and process data, and adjust controls
    void monitorAndAdjust();
};

#endif // AEROSPACE_CONTROL_SYSTEM_H