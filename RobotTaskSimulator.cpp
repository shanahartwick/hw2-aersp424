#include "RobotTaskSimulator.h"

void RobotTaskSimulator::robotTask(int robotID) {
    int firstTool = robotID;
    int secondTool = (robotID + 1) % numTools;

    // Collecting data
    std::cout << "Robot " << robotID << " is collecting data." << std::endl;

    // Reach and grab both tools
    toolMutex[firstTool].lock();
    std::cout << "Robot " << robotID << " acquired tool " << firstTool << "." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    toolMutex[secondTool].lock();
    std::cout << "Robot " << robotID << " acquired tool " << secondTool << "." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Perform the task
    std::cout << "Robot " << robotID << " begins the task." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Robot " << robotID << " completes the task." << std::endl;

    // Return tools to their original location
    toolMutex[secondTool].unlock();
    toolMutex[firstTool].unlock();
}

void RobotTaskSimulator::runSimulation() {
    auto start = std::chrono::steady_clock::now();

    // Create threads for each robot
    std::vector<std::thread> threads;
    for (int i = 0; i < numRobots; ++i) {
        threads.push_back(std::thread(&RobotTaskSimulator::robotTask, this, i));
    }

    // Join all threads
    for (auto& thread : threads) {
        thread.join();
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> totalTime = end - start;
    std::cout << "Total time taken by all robots to finish their tasks: " << totalTime.count() << " seconds" << std::endl;
}