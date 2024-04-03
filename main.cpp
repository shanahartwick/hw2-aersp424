// hw2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "AerospaceControlSystem.h"
#include "Altimeter.h"
#include "PressureSensor.h"
#include "AirspeedSensor.h"
#include "RobotTaskSimulator.h"
#include "AirTrafficController.h"
#include "Aircraft.h"
#include <iostream>
#include <vector>
#include <thread>

int main()
{
    // Instantiate AerospaceControlSystem object
    AerospaceControlSystem ctrlSys;

    // Add sensors to ctrlSys
    ctrlSys.addSensor(new Altimeter());
    ctrlSys.addSensor(new PressureSensor());
    ctrlSys.addSensor(new AirspeedSensor());

    // Monitor and adjust controls
    ctrlSys.monitorAndAdjust();

    // Create instance of RobotTaskSimulator and run simulation
    RobotTaskSimulator simulator;
    simulator.runSimulation();

    AirTrafficController atc;
    std::vector<std::thread> aircraftThreads;

    for (int i = 1; i <= 10; ++i) {
        Aircraft aircraft(i, atc);
        aircraftThreads.emplace_back(&Aircraft::approach, &aircraft);
    }

    for (auto& thread : aircraftThreads) {
        thread.join();
    }

    return 0;
}
