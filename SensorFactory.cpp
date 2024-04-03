#include "SensorFactory.h"

Sensor* SensorFactory::createSensor(const std::string& sensorType) {
    // Check the input string to determine the sensor type
    if (sensorType == "Altimeter") {
        // Allocate heap memory for AltimeterSensor and return it
        return new Altimeter();
    }
    else if (sensorType == "Airspeed") {
        // Allocate heap memory for AirspeedSensor and return it
        return new AirspeedSensor();
    }
    else if (sensorType == "Pressure") {
        // Allocate heap memory for PressureSensor and return it
        return new PressureSensor();
    }
    else {
        // If the sensor type is not recognized, return nullptr
        return nullptr;
    }
}