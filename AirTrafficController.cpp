#include "AirTrafficController.h"

AirTrafficController::AirTrafficController() : asleep(true), trafficPatternCount(0) {}

void AirTrafficController::wakeUp() {
    asleep = false;
}

void AirTrafficController::sleep() {
    asleep = true;
}

bool AirTrafficController::isAsleep() {
    return asleep;
}

void AirTrafficController::incrementTraffic() {
    trafficPatternCount++;
}

void AirTrafficController::decrementTraffic() {
    trafficPatternCount--;
}

bool AirTrafficController::isTrafficFull() {
    return trafficPatternCount >= 3;
}

std::mutex& AirTrafficController::getMutex() {
    return mtx;
}
