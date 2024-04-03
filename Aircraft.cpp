#include "Aircraft.h"
#include <iostream>
#include <chrono>
#include <thread>

Aircraft::Aircraft(int _id, AirTrafficController& _atc) : id(_id), atc(_atc) {}

void Aircraft::approach() {
    {
        std::lock_guard<std::mutex> guard(atc.getMutex());
        if (atc.isAsleep()) {
            std::cout << "Aircraft " << id << " wakes up the ATC.\n";
            atc.wakeUp();
        }
        else if (!atc.isTrafficFull()) {
            std::cout << "Aircraft " << id << " enters the traffic pattern.\n";
            atc.incrementTraffic();
        }
        else {
            std::cout << "Aircraft " << id << " diverts to another airport.\n";
            return;
        }
    }

    std::this_thread::sleep_for(std::chrono::seconds(1)); // Landing process

    {
        std::lock_guard<std::mutex> guard(atc.getMutex());
        std::cout << "Aircraft " << id << " lands.\n";
        atc.decrementTraffic();
        atc.sleep();
    }
}