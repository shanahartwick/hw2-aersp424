// hw2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "AerospaceControlSystem.h"
#include "Altimeter.h"
#include "PressureSensor.h"
#include "AirspeedSensor.h"
#include "RobotTaskSimulator.h"
#include <iostream>

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

    return 0;
}
