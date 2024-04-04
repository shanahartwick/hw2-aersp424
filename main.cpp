// hw2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "AerospaceControlSystem.h"
#include "Altimeter.h"
#include "PressureSensor.h"
#include "AirspeedSensor.h"
#include "RobotTaskSimulator.h"
#include "AirTrafficController.h"
#include <iostream>
#include <vector>
#include <thread>

void airplaneFunc(AirTrafficController& atc, int planeID) {
    std::this_thread::sleep_for(std::chrono::seconds(planeID)); // Simulate airplanes arriving at different times
    atc.handleLandingRequest(planeID);
}

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
    std::vector<std::thread> threads;

    for (int i = 0; i < 10; ++i) {
        threads.push_back(std::thread(airplaneFunc, std::ref(atc), i));
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}