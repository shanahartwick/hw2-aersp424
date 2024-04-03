#pragma once

#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
public:
    // Virtual function for simulating data collection
    virtual void gatherData() = 0;

    // Virtual function for data processing
    virtual void processData() = 0;

    // Virtual destructor
    virtual ~Sensor() {}
};

#endif // SENSOR_H