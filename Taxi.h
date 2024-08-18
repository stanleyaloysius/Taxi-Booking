#ifndef TAXI_H
#define TAXI_H

#include <vector>
#include "ServiceDetails.h"

class Taxi {
    public:
        int Tid;
        char location;
        bool available;
        long earning;
        int nextFreeTime;
        std::vector<ServiceDetails> details;

        Taxi(int id);
        long calculate_fare(char pickup, char drop);
        void book(int bookingId, int customerId, char pickup, char drop, char time);
};

#endif