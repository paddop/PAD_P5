#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include <rentalcarreservation.h>
#include <hotelbookings.h>
#include <flightbookings.h>
#include <vector>
#include "travel.h"
#include "customer.h"
#include "booking.h"
#include <iomanip>
#include "linkedlist.h"

class TravelAgency
{
public:
    TravelAgency();
    ~TravelAgency();
    string readFile();
    void deleteRecords();
    string printNumbers();
    //void clearBookings() {allBookings = {};}
    void clearBookings() {}
    Booking* findBooking(long id);
    Travel* findTravel(long id);
    Customer* findCustomer(long id);
    int getNumberOfBookings() {return int (bookingList.getSize());}
    int getNumberOfTravels() {return int (allTravels.size());}

    int createBooking(char type, double price, string start, string end, long travelId, vector<string> bookingDetails);

    Booking* getBookingByNo(int i);
    Travel* getTravelByNo(int i);

private:
    //vector<Booking*> allBookings;
    LinkedList<Booking*> bookingList;
    vector<Travel*> allTravels;
    vector<Customer*> allCustomers;
};

#endif // TRAVELAGENCY_H
