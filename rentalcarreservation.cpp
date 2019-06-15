#include "rentalcarreservation.h"

RentalCarReservation::RentalCarReservation(long id, long travelId, double price, string fromDate, string toDate, string pickupLocation, string returnLocation, string company, string insurance)
    : Booking(id, travelId, price, fromDate, toDate), pickupLocation(pickupLocation), returnLocation(returnLocation), company(company), insurance(insurance)
{

}

RentalCarReservation::~RentalCarReservation()
{
    //cout << "Deleting RentalCarReservation";
}

string RentalCarReservation::getPickupLocation() const
{
    return pickupLocation;
}

string RentalCarReservation::getReturnLocation() const
{
    return returnLocation;
}

string RentalCarReservation::getCompany() const
{
    return company;
}

string RentalCarReservation::getInsurance() const
{
    return insurance;
}

string RentalCarReservation::showDetails()
{
    return insurance;
}
