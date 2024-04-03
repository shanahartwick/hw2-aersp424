#pragma once

#ifndef ROBOT_TASK_SIMULATOR_H
#define ROBOT_TASK_SIMULATOR_H

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>

class RobotTaskSimulator
{
public:
    // Function to represent the behavior of each robot
    void robotTask(int robotID);

    // Function to run the simulation
    void runSimulation();

    // Mutex for synchronizing access to output stream
    std::mutex coutMutex;
};

#endif // ROBOT_TASK_SIMULATOR_H