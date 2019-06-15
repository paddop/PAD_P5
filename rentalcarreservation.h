#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H

#include <string>
#include "booking.h"

using namespace std;

class RentalCarReservation : public Booking
{
public:
    RentalCarReservation(long id, long travelId, double price, string fromDate, string toDate, string pickupLocation, string returnLocation, string company, string insurance);

    virtual ~RentalCarReservation() override;

    string getPickupLocation() const;

    string getReturnLocation() const;

    string getCompany() const;

    string getInsurance() const;

    virtual string showDetails() override;

private:
    string pickupLocation;
    string returnLocation;
    string company;
    string insurance;
};

#endif // RENTALCARRESERVATION_H
