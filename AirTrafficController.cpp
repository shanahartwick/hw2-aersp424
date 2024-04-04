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
        std::cout << "Plane " << planeID << " enters the traffic pattern.\n";
        trafficPattern.push_back(planeID);
        lck.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Landing process
        lck.lock();
        std::cout << "Plane " << planeID << " lands.\n";
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

std::mutex& AirTrafficController::getMutex() {
    return mtx;
}

bool AirTrafficController::isAsleep() {
    return !isAwake;
}

void AirTrafficController::wakeUp() {
    isAwake = true;
}

bool AirTrafficController::isTrafficFull() {
    return trafficPattern.size() >= maxTrafficPattern;
}

void AirTrafficController::incrementTraffic() {
    ++trafficCount;
}

void AirTrafficController::decrementTraffic() {
    --trafficCount;
}

void AirTrafficController::sleep() {
    isAwake = false;
}