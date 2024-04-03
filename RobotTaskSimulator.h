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

private:
    // Mutex for synchronizing access to output stream
    std::mutex coutMutex;

    // Define the number of robots and tools
    static const int numRobots = 5;
    static const int numTools = 5;

    // Mutexes for synchronizing access to tools
    std::mutex toolMutex[numTools];
};

#endif // ROBOT_TASK_SIMULATOR_H