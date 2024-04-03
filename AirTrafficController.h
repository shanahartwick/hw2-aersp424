#pragma once

#ifndef AIR_TRAFFIC_CONTROLLER_H
#define AIR_TRAFFIC_CONTROLLER_H

#include <mutex>

class AirTrafficController
{
private:
    std::mutex mtx;
    bool asleep;
    int trafficPatternCount;

public:
    AirTrafficController();
    void wakeUp();
    void sleep();
    bool isAsleep();
    void incrementTraffic();
    void decrementTraffic();
    bool isTrafficFull();
    std::mutex& getMutex();
};

#endif // AIR_TRAFFIC_CONTROLLER_H