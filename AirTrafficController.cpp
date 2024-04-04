#include "AirTrafficController.h"
#include <iostream>
#include <chrono>
#include <thread>

void AirTrafficController::handleLandingRequest(int planeID) {
    std::unique_lock<std::mutex> lck(mtx);
    if (!isAwake) {
        std::cout << "ATC wakes up.\n";
        isAwake = true;
    }
    if (trafficPattern.size() < maxTrafficPattern) {
        std::cout << "Plane " << planeID << " is requesting to land.\n";
        trafficPattern.push_back(planeID);
        lck.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Landing process
        lck.lock();
        std::cout << "Plane " << planeID << " lands and runway is available.\n";
        trafficPattern.pop_back();
    }
    else {
        std::cout << "Traffic pattern full. Plane " << planeID << " needs to divert to another airport.\n";
    }
    if (trafficPattern.empty()) {
        std::cout << "ATC falls asleep.\n";
        isAwake = false;
    }
}