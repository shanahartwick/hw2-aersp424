#pragma once

#ifndef AIRSPEED_SENSOR_H
#define AIRSPEED_SENSOR_H

#include "Sensor.h"

class AirspeedSensor :
    public Sensor
{
    // Simulate data collection for airspeed
    void gatherData() override;

    // Process airspeed data
    void processData() override;
};

#endif // AIRSPEED_SENSOR_H