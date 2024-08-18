#ifndef SERVICEDETAILS_H
#define SERVICEDETAILS_H

class ServiceDetails {
    public:
    int bookingId;
    int CustomerId;
    char from;
    char to;
    int pickupTime;
    int dropTime;
    long amount;

    ServiceDetails (int bId, int cId, char from, char to, int pickup, int drop, long fare) 
        : bookingId(bId), CustomerId(cId), from(from), to(to), pickupTime(pickup), dropTime(drop), amount(fare) {}
};

#endif