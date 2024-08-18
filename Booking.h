#ifndef BOOKING_H
#define BOOKING_H

#include <vector>
#include "Taxi.h"

class Booking {
    public:
        std::vector<Taxi> taxis;

        void initialize_taxis(int n);
        Taxi* find_taxi(char pickup, int time);
        void book_taxi(int bookingId, int customerId, char pickip, char drop, int time);
        void display();
};

#endif