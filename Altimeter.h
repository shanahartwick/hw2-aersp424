#pragma once

#ifndef ALTIMETER_H
#define ALTIMETER_H

#include "Sensor.h"

class Altimeter :
    public Sensor
{
public:
    // Simulate data collection for altimeter
    void gatherData() override;

    // Process altimeter data
    void processData() override;
};

#endif // ALTIMETER_H