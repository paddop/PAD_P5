#ifndef FLIGHTS_H
#define FLIGHTS_H

#include <string>
#include "booking.h"

using namespace std;

class Flightbookings : public Booking
{
public:
    Flightbookings(long id, long travelId, double price, string fromDate, string toDate, string fromDest, string toDest, string airline, char seatPref);

    virtual ~Flightbookings() override;

    string getFromDest() const;

    string getToDest() const;

    string getAirline() const;

    char getSeatPref() const;

    virtual string showDetails() override;

private:
    string fromDest;
    string toDest;
    string airline;
    char seatPref;
};

#endif // FLIGHTS_H
