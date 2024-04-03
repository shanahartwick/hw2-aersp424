#pragma once
#ifndef SENSOR_FACTORY_H
#define SENSOR_FACTORY_H
#include "Sensor.h"
#include <memory>
#include <string>
#include "Altimeter.h"
#include "AirspeedSensor.h"
#include "PressureSensor.h"

class SensorFactory :
    public Sensor
{
public:
    // Static function to create a sensor based on input string
    static Sensor* createSensor(const std::string& sensorType);
};

#endif // SENSOR_FACTORY_H