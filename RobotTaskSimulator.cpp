#include "RobotTaskSimulator.h"

// Function to represent the behavior of each robot
void RobotTaskSimulator::robotTask(int robotID) {
    int firstTool = robotID;
    int secondTool = (robotID + 1) % numTools;

    // Collecting data
    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "Robot " << robotID << " is collecting data." << std::endl;
    }

    // Reach and grab both tools and begins tasks
    toolMutex[firstTool].lock();
    toolMutex[secondTool].lock();
    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "Robot " << robotID << " acquired tools and starts performing a task." << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Ends task and returns tools
    std::this_thread::sleep_for(std::chrono::seconds(5));
    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "Robot " << robotID << " finished the task and returning the tools." << std::endl;
    }

    // Return tools to their original location
    toolMutex[secondTool].unlock();
    toolMutex[firstTool].unlock();
}

// Function to run the simulation
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
    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "Duration: " << totalTime.count() << " seconds" << std::endl;
    }
}