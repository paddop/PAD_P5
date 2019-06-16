#include "travelagency.h"
#include <iostream>
#include <fstream>
#include <iomanip> // setprecision
#include <sstream> // stringstream

using namespace std;


TravelAgency::TravelAgency()
{

}

TravelAgency::~TravelAgency()
{
    //for (Booking* b : allBookings)
    //    delete b;
    for (Customer* c : allCustomers)
        delete c;
    //for (Travel* t : allTravels)
    //    delete t;
}

void TravelAgency::deleteRecords()
{
    //for (Booking* b : allBookings)
    //    delete b;
    for (Customer* c : allCustomers)
        delete c;
    //for (Travel* t : allTravels)
    //    delete t;

    allTravels = {};
    bookingList.empty();
    allCustomers = {};
}



Booking* TravelAgency::findBooking(long id)
{
    bookingList.reset();
    while (!bookingList.isAtEnd()) {
        Booking* b = bookingList.getNode();
        if (b->getId() == id) return b;
        bookingList.advance();
    }
    return nullptr;
}

Customer *TravelAgency::findCustomer(long id)
{
    for (Customer* c : allCustomers)
        if (c->getId() == id) return c;
    return nullptr;
}

int TravelAgency::createBooking(char type, double price, string start, string end, long travelId, vector<string> bookingDetails)
{
    Booking* newBooking = nullptr;

    if (!findTravel(travelId))
    {
        return -1;
    }

    long bookingId = 0;
    bookingList.reset();
    while (!bookingList.isAtEnd())
    {
        Booking* b = bookingList.getNode();
        if (b->getId() > bookingId)
            bookingId = b->getId();
        bookingList.advance();
    }
    bookingId += 1;

    switch (type) {
    case 'F':
    {
        newBooking = new Flightbookings(bookingId,travelId,price,start,end,bookingDetails[0],bookingDetails[1],bookingDetails[2],bookingDetails[3][0]);
        break;
    }
    case 'R':
    {
        newBooking = new RentalCarReservation(bookingId,travelId,price,start,end,bookingDetails[0],bookingDetails[1],bookingDetails[2],bookingDetails[3]);
        break;
    }
    case 'H':
    {
        newBooking = new HotelBookings(bookingId,travelId,price,start,end,bookingDetails[0],bookingDetails[1],bookingDetails[2][0]);
        break;
    }
    default:
    {
        cout << "Fehler beim Bestimmen des Typs der Buchung!" << endl;
        return -2;
    }
    }

    bookingList.insertNode(newBooking);
    findTravel(travelId)->addBooking(newBooking);

    return bookingId;

}

Booking *TravelAgency::getBookingByNo(int i)
{
    Booking* b = bookingList[i];
    return b;
}

Travel *TravelAgency::getTravelByNo(int i)
{
    return allTravels[i];
}

Travel *TravelAgency::findTravel(long id)
{
    for (Travel* t : allTravels)
        if (t->getId() == id) return t;
    return nullptr;
}

string TravelAgency::readFile()
{
    ifstream quelle;
    string dateiname = "bookings_praktikum5.txt";
    //string dateiname = "pups.txt";

    quelle.open(dateiname,ios::in);

    if (!quelle) {
        return "Datei nicht gefunden!";
    }

    //cout << "[Lese Daten ein...]" << endl;

    int zeile = 0;



    do {
        // Einzelne Zeilen
        // Zeilenanfang
        zeile++;
        cout << ":: Zeile " << zeile << endl;

        // Alle
        char typ;
        long bookingId;
        double price;
        long travelId, customerId;
        string fromDate;
        string toDate;
        string customerName;
        int vA=-1, vB=-1;
        // Nur F
        string fromDest;
        string toDest;
        string airline;
        char seatPref;
        // Nur R
        string pickupLocation;
        string returnLocation;
        string company;
        string insurance;
        string insurance_tmp;
        // Nur H
        string hotel;
        string town;
        char smoke;

        // Spalte 1
        quelle >> typ;
        quelle.ignore(1);
        if(typ != 'F' && typ != 'H' && typ != 'R') throw zeile;
        // Spalte 2
        quelle >> bookingId;
        quelle.ignore(1);
        if(bookingId == 0) throw zeile;
        // Spalte 3
        quelle >> price;
        quelle.ignore(1);
        if(price == 0.0) throw zeile;
        // Spalte 4
        //quelle.read(fromDate, sizeof(fromDate)-1);
        getline(quelle, fromDate, '|');
        if(fromDate.length() != 8) throw zeile;
        // Spalte 5
        //quelle.read(toDate, sizeof(toDate)-1);
        getline(quelle, toDate, '|');
        if(toDate.length() != 8) throw zeile;
        // Spalte 6
        quelle >> travelId;
        quelle.ignore(1);
        if(travelId == 0) throw zeile;
        // Spalte 7
        quelle >> customerId;
        quelle.ignore(1);
        if(customerId == 0) throw zeile;
        // Spalte 8
        getline(quelle, customerName, '|');
        if(customerName.length() == 0) throw zeile;

        // Spalten 9-11

        switch (typ) {
        case 'F': {
            getline(quelle, fromDest, '|');
            if(fromDest.length() == 0 || fromDest.find('\n')!=string::npos) throw zeile;
            getline(quelle, toDest, '|');
            if(toDest.length() == 0 || toDest.find('\n')!=string::npos) throw zeile;
            getline(quelle, airline, '|');
            if(airline.length() == 0 || airline.find('\n')!=string::npos) throw zeile;
            quelle.get(seatPref);
            if(seatPref != 'W' && seatPref != 'A') throw zeile;
            quelle.ignore(1);
            Booking* neuerFlug = new Flightbookings(bookingId,travelId,price,fromDate,toDate,fromDest,toDest,airline,seatPref);
            bookingList.insertNode(neuerFlug);
            break;
        }
        case 'R': {
            getline(quelle, pickupLocation, '|');
            if(pickupLocation.length() == 0 || pickupLocation.find('\n')!=string::npos) throw zeile;
            getline(quelle, returnLocation, '|');
            if(returnLocation.length() == 0 || returnLocation.find('\n')!=string::npos) throw zeile;
            getline(quelle, company, '|');
            if(company.length() == 0 || company.find('\n')!=string::npos) throw zeile;
            /*!*/      getline(quelle, insurance_tmp, '\n');
            if (insurance_tmp.find('|')!=string::npos) {
                // '|' kommt vor, d.h. insurance_tmp enthält insurance UND die erste Vorgängerbuchung vA
                stringstream sso;
                sso << insurance_tmp;
                getline(sso, insurance, '|');
                sso >> vA;
            } else {
                // insurance_tmp enthält nur insurance
                insurance = insurance_tmp;
            }
            if(insurance.length() == 0 || insurance.find('\n')!=string::npos) throw zeile;
            Booking* neuesAuto = new RentalCarReservation(bookingId,travelId,price,fromDate,toDate,pickupLocation,returnLocation,company,insurance);
            bookingList.insertNode(neuesAuto);
            break;
        }
        case 'H': {
            getline(quelle, hotel, '|');
            if(hotel.length() == 0 || hotel.find('\n')!=string::npos) throw zeile;
            getline(quelle, town, '|');
            if(town.length() == 0 || town.find('\n')!=string::npos) throw zeile;
            quelle.get(smoke);
            if(smoke != '0' && smoke != '1') throw zeile;
            quelle.ignore(1);
            Booking* neuesHotel = new HotelBookings(bookingId,travelId,price,fromDate,toDate,hotel,town,smoke);
            bookingList.insertNode(neuesHotel);
            break;
        }
        }



        if(quelle.peek() >= '0' && quelle.peek() <= '9')
        {
            quelle >> vA; quelle.ignore(1);

            if(quelle.peek() >= '0' && quelle.peek() <= '9')
            {
                quelle >> vB; quelle.ignore(1);
            }
        }
        // new customer?
        if (!findCustomer(customerId))
        {
            Customer* newCustomer = new Customer(customerId, customerName);
            allCustomers.push_back(newCustomer);
        }

        // new travel?
        if (!findTravel(travelId))
        {
            Travel* newTravel = new Travel(travelId,customerId);
            allTravels.push_back(newTravel);

            // Reise dem Kunden zuweisen
            if(Customer* c = findCustomer(customerId))
            {
                c->addTravel(newTravel);
            }
            else
            {
                cout << "Fehler: Kunde mit Nummer " << customerId << "nicht gefunden." << endl;
            }
        }

        // Reise heraussuchen
        if(Travel* thisTravel = findTravel(travelId))
        {
            // Buchung der Reise zuweisen
            if(Booking* b = findBooking(bookingId))
            {
                thisTravel->addBooking(b);

                // Graphen aufbauen

                // Aktueller Knoten
                //if (thisTravel->existsNodeWithId(b->getId())) {
                //    thisTravel->updateGraphValueOfNode(b->getId(), b);
                //} else {
                thisTravel->addNodeToGraph(b->getId(), b);
                //}

                if (vA != -1) {
                    // Erster Vorgängerknoten
                    if (!thisTravel->existsNodeWithId(vA)) {
                        thisTravel->addNodeToGraph(vA, nullptr);
                    }
                    thisTravel->addArcToGraph(vA, b->getId());



                    if (vB != -1) {
                        // Zweiter Vorgängerknoten
                        if (!thisTravel->existsNodeWithId(vB)) {
                            thisTravel->addNodeToGraph(vB, nullptr);
                        }
                        thisTravel->addArcToGraph(vB, b->getId());
                    }
                }

                //thisTravel->debugGraph();
            }
            else
            {
                cout << "Fehler: Buchung mit Nummer " << bookingId << "nicht gefunden." << endl;
            }
        }
        else
        {
            cout << "Fehler: Reise mit Nummer " << travelId << "nicht gefunden." << endl;
        }

        // Reise heraussuchen
        // Travel* thisTravel = findTravel(travelId)
        // Reise dem Kunden zuweisen
        // findCustomer(customerId)->addTravel(thisTravel);
        // Buchung der Reise zuweisen
        // thisTravel->addBooking(findBooking(bookingId));




        // Zeilenende
    } while (!quelle.eof());

    //cout << "[Daten eingelesen.]" << endl;

    quelle.close();

    return printNumbers();
}

string TravelAgency::printNumbers()
{
    //cout << "[Statistiken]\n" << endl;

    double gesamtwert_fluege = 0, gesamtwert_autos = 0, gesamtwert_hotels = 0;
    int amtFbookings = 0, amtRbookings = 0, amtHbookings = 0;

    bookingList.reset();
    while (!bookingList.isAtEnd()) {
        Booking* b = bookingList.getNode();
        if (dynamic_cast<Flightbookings*>(b))
        {
            gesamtwert_fluege += b->getPrice();
            amtFbookings++;
        }
        else if (dynamic_cast<RentalCarReservation*>(b))
        {
            gesamtwert_autos += b->getPrice();
            amtRbookings++;
        }
        else if (dynamic_cast<HotelBookings*>(b))
        {
            gesamtwert_hotels += b->getPrice();
            amtHbookings++;
        }
        else
        {
            cout << "Fehler beim Zaehlen!" << endl;
        }
        bookingList.advance();
    }


    //cout << "Es wurden insgesamt " << allBookings.size() << " Buchungen, " << allTravels.size() << " Reisen und " << allCustomers.size() << " Kunden angelegt." << endl;

    //Preis precision
    stringstream stream;
    stream << fixed << setprecision(2) << (gesamtwert_autos+gesamtwert_fluege+gesamtwert_hotels);

    string erg = "Es wurden insgesamt " + to_string(bookingList.getSize()) + " Buchungen, "
            + to_string(allTravels.size()) + " Reisen und "
            + to_string(allCustomers.size()) + " Kunden "
            + "im Gesamtwert von " + stream.str()+"€ angelegt.";
    /*
    cout << "\nEs wurden \n"
         << setw(5) << amtFbookings << " Flugbuchungen "
         << "im Wert von " << setw(10) << gesamtwert_fluege << "EUR, \n"
         << setw(5) << amtRbookings << " Mietwagenbuchungen "
         << "im Wert von " << setw(10) << gesamtwert_autos << "EUR und \n"
         << setw(5) << amtHbookings << " Hotelreservierungen "
         << "im Wert von " << setw(10) << gesamtwert_hotels << "EUR "
         << " angelegt.\n" << endl;

    cout << "Der Kunde mit der ID 1 hat " << findCustomer(1)->getNumberOfTravel() << " Reisen gebucht." << endl;
    cout << "Die Reise mit der ID 17 beinhaltet " << findTravel(17)->getNumberOfBookings() << " Buchungen." << endl;
*/
    return erg;
}

