#include "flightbookings.h"

Flightbookings::Flightbookings(long id, long travelId, double price, string fromDate, string toDate, string fromDest, string toDest, string airline, char seatPref)
    : Booking(id, travelId, price, fromDate, toDate), fromDest(fromDest), toDest(toDest), airline(airline), seatPref(seatPref)
{

}

Flightbookings::~Flightbookings()
{
    //cout << "Deleting Flightbookings";
}

string Flightbookings::getFromDest() const
{
    return fromDest;
}

string Flightbookings::getToDest() const
{
    return toDest;
}

string Flightbookings::getAirline() const
{
    return airline;
}

char Flightbookings::getSeatPref() const
{
    return seatPref;
}

string Flightbookings::showDetails()
{
    if (seatPref == 'A') {
        return "Gang";
    } else if (seatPref == 'W') {
        return "Fenster";
    } else {
        return "Fehler";
    }
}
