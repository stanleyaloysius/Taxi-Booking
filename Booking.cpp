#include "Booking.h"
#include <iostream>

using namespace std;

//Initializing taxi objects
void Booking::initialize_taxis(int n) {
    for (int i=0; i<n; i++) {
        taxis.push_back(Taxi(i+1));
    }
}

// To find available taxi

Taxi* Booking::find_taxi(char pickup, int time) {
    Taxi* nearestTaxi = nullptr;

    for (auto &taxi: taxis) {
        if (taxi.available && time >= taxi.nextFreeTime) {
            if (!nearestTaxi || abs(taxi.location - pickup) < abs(nearestTaxi->location - pickup)
                || (abs(taxi.location - pickup) == abs(nearestTaxi->location - pickup)
                    && taxi.earning < nearestTaxi->earning)
                ) {
                   nearestTaxi = &taxi; 
                }
        }
    }

    return nearestTaxi;
}

// to book the available taxi
void Booking::book_taxi (int bookingId, int customerId, char pickup, char drop, int time) {
    Taxi* taxi = find_taxi(pickup, time);

    if (taxi) {
        taxi->book(bookingId, customerId, pickup, drop, time);
        cout << "Taxi-" << taxi->Tid << " Alloted \nFare: Rs." << taxi->calculate_fare(pickup, drop) << endl << endl;
    }
    else {
        cout << "No taxi available, Booking rejected" << endl;
    }
}

//to display all details.
void Booking::display() {
    for (const auto &taxi: taxis) {
        cout << "Taxi-" << taxi.Tid << "    Total Earnings: Rs. " << taxi.earning << endl;
        cout << "BookingID    CustomerID    From    To    PickupTime    DropTime    Amount" << endl;

        for (const auto &detail : taxi.details) {
            cout << detail.bookingId << "    " << detail.CustomerId << "    "
                      << detail.from << "    " << detail.to << "    " << detail.pickupTime
                      << "    " << detail.dropTime << "    " << detail.amount << endl;
        }

        cout << endl;  
    }
}