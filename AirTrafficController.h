#pragma once

#ifndef AIR_TRAFFIC_CONTROLLER_H
#define AIR_TRAFFIC_CONTROLLER_H

#include <vector>
#include <mutex>

class AirTrafficController {
    public:
        void handleLandingRequest(int planeID);
        std::mutex& getMutex();
        bool isAsleep();
        void wakeUp();
        bool isTrafficFull();
        void incrementTraffic();
        void decrementTraffic();
        void sleep();
    private:
        bool isAwake = false;
        std::vector<int> trafficPattern;
        const int maxTrafficPattern = 3;
        std::mutex mtx;
        int trafficCount = 0;
};

#endif // AIR_TRAFFIC_CONTROLLER_H