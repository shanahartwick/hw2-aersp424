#pragma once
#ifndef PRESSURE_SENSOR_H
#define PRESSURE_SENSOR_H
#include "Sensor.h"

class PressureSensor :
    public Sensor
{
public:
    // Simulate data collection for pressure
    void gatherData() override;

    // Process pressure data
    void processData() override;
};

#endif // PRESSURE_SENSOR_H