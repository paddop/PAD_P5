#include "booking.h"


Booking::Booking(long id, long travelId, double price, string fromDate, string toDate)
    : id(id), travelId(travelId), price(price), fromDate(fromDate), toDate(toDate)
{

}

Booking::~Booking()
{
    //cout << "Deleting Base Booking with ID " + to_string(id);
}

long Booking::getId() const
{
    return id;
}

long Booking::getTravelId() const
{
    return travelId;
}

double Booking::getPrice() const
{
    return price;
}

string Booking::getFromDate() const
{
    return fromDate;
}

string Booking::getToDate() const
{
    return toDate;
}


