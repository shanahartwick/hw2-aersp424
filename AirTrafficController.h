#pragma once

#ifndef AIR_TRAFFIC_CONTROLLER_H
#define AIR_TRAFFIC_CONTROLLER_H

#include <vector>
#include <mutex>

class AirTrafficController {
    public:
        void handleLandingRequest(int planeID);
    private:
        bool isAwake = false;
        std::vector<int> trafficPattern;
        const int maxTrafficPattern = 3;
        std::mutex mtx;
};

#endif // AIR_TRAFFIC_CONTROLLER_H