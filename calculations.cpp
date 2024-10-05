#include "calculations.h"

double calculateSpeed(double distance, double time) {
    return distance / time;
}

double calculateDistance(double speed, double time) {
    return speed * time;
}

double calculateTime(double distance, double speed) {
    return distance / speed;
}