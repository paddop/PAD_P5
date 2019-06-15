#include "test.h"
#include "travelagency.h"

Test::Test(QObject *parent) : QObject(parent)
{

}

void Test::test1()
/*
 * Eingelesen wurden 5 Mietwagenbuchungen der Firma Avis.
 */
{
    TravelAgency agency;
    agency.readFile();

    int counter = 0;
    for (int i=0; i<agency.getNumberOfBookings(); i++) {
        Booking* b = agency.getBookingByNo(i);
        if (RentalCarReservation* rental = dynamic_cast<RentalCarReservation*>(b))
            if (rental->getCompany() == "Avis")
                counter++;
    }

    QCOMPARE(counter, 5);
}

void Test::test2()
/*
 * Eingelesen wurden 3 Flugbuchungen der Fluglinie Unites Airlines.
 */
{
    TravelAgency agency;
    agency.readFile();

    int counter = 0;
    for (int i=0; i<agency.getNumberOfBookings(); i++) {
        Booking* b = agency.getBookingByNo(i);
        if (Flightbookings* flug = dynamic_cast<Flightbookings*>(b))
            if (flug->getAirline() == "United Airlines")
                counter++;
    }

    QCOMPARE(counter, 3);
}

void Test::test3()
/*
 * Eingelesen wurden 31 Buchungen mit einem Wert von mindestens 1000€.
 */
{
    TravelAgency agency;
    agency.readFile();

    int counter = 0;
    for (int i=0; i<agency.getNumberOfBookings(); i++) {
        Booking* b = agency.getBookingByNo(i);
        if (b->getPrice() >= 1000.0)
            counter++;
    }

    QCOMPARE(counter, 31);
}
