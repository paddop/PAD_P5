#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include "iostream"

using namespace std;

class Booking
{
public:
    Booking(long id, long travelId, double price, string fromDate, string toDate);
    virtual ~Booking();

    long getId() const;

    long getTravelId() const;

    double getPrice() const;

    string getFromDate() const;

    string getToDate() const;

    virtual string showDetails() = 0;

private:
    long id;
    long travelId;
    double price;
    string fromDate;
    string toDate;
};

#endif // BOOKING_H
