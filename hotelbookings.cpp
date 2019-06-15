#include "hotelbookings.h"

HotelBookings::HotelBookings(long id, long travelId, double price, string fromDate, string toDate, string hotel, string town, char smoke)
    : Booking(id, travelId, price, fromDate, toDate), hotel(hotel), town(town), smoke(smoke)
{

}

HotelBookings::~HotelBookings()
{
    //cout << "Deleting HotelBookings";
}

string HotelBookings::getHotel() const
{
    return hotel;
}

string HotelBookings::getTown() const
{
    return town;
}

char HotelBookings::getSmoke() const
{
    return smoke;
}

string HotelBookings::showDetails()
{
    if(smoke)
        return "Raucherzimmer";
    else
        return "Nichtraucherzimmer";
}
