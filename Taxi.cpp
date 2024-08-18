#include "Taxi.h"
#include "ServiceDetails.h"
#include <cmath>

Taxi::Taxi(int id) : Tid(id), location('A'), available(true), earning(0), nextFreeTime(6) {}

long Taxi::calculate_fare(char pickup, char drop) {
    int distance = abs(pickup - drop)*15;
    return 100 + (distance-5)*10;
}

void Taxi::book (int bookingId, int customerId, char pickup, char drop, char time) {
    long fare = calculate_fare(pickup, drop);
    earning += fare;
    available = false;
    int travelTime = time + abs(pickup - drop);
    nextFreeTime = travelTime;
    location = drop;
    details.push_back(ServiceDetails(bookingId, customerId, pickup, drop, time, time+travelTime, fare));
}