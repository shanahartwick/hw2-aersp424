#include "AerospaceControlSystem.h"
#include <iostream>

void AerospaceControlSystem::addSensor(Sensor* sensor) {
    sensors.push_back(sensor);
}

void AerospaceControlSystem::monitorAndAdjust() {
    // Iterate through all sensors
    for (Sensor* sensor : sensors) {
        // Gather data from sensor
        sensor->gatherData();

        // Process data from sensor
        sensor->processData();

        // Adjust controls based on sensor data
        std::cout << "Adjusting controls based on sensor data." << std::endl;
    }
}