#ifndef HOTELBOOKINGS_H
#define HOTELBOOKINGS_H

#include <string>
#include "booking.h"

using namespace std;

class HotelBookings : public Booking
{
public:
    HotelBookings(long id, long travelId, double price, string fromDate, string toDate, string hotel, string town, char smoke);

    virtual ~HotelBookings() override;

    string getHotel() const;

    string getTown() const;

    char getSmoke() const;

    virtual string showDetails() override;

private:
    string hotel;
    string town;
    char smoke;
};

#endif // HOTELBOOKINGS_H
