#include "travel.h"
#include "Digraph/algorithmen.cpp"
#include "TopologischesSortieren/heap.h"

Travel::Travel(long id, long customerId) : id(id), customerId(customerId)
{
    graph = new Graph<Booking*, MAX_NODES>();
}

Travel::~Travel()
{
    for (Booking* b : travelBookings)
        delete b;
}

void Travel::addBooking(Booking *booking)
{
    this->travelBookings.push_back(booking);
}

long Travel::getId() const
{
    return id;
}

long Travel::getNumberOfBookings() const
{
    return this->travelBookings.size();
}

long Travel::getCustomerId() const
{
    return customerId;
}

void swap(node_data *xp, node_data *yp)
{
    node_data temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(vector<node_data>& arr, int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (arr[j].end < arr[j+1].end)
                swap(&arr[j], &arr[j+1]);
}

bool Travel::checkRoundTrip()
{
    vector<node_data> sortedArray;
    node_data node;

    DepthFirstSearch(*graph);

    for (int n = 0; n < MAX_NODES; n++) {
        if (graph->getVertexValue(n) != nullptr) {
            node_data neu;
            neu.i = graph->getVertexValue(n)->getId();
            neu.bezeichner = graph->getVertexValue(n)->getFromDate();
            neu.end = graph->getEnd(n);
            sortedArray.push_back(neu);
        }
    }

    //Heap myHeap(sortedArray, sortedArray.size());
    bubbleSort(sortedArray, sortedArray.size());

    /*
    for (int i = 0; i < sortedArray.size(); i++) {
        //node = myHeap.pop();
        node = sortedArray[i];
        cout << i+1 << ". " << setw(15) << node.bezeichner << " " << node.end << endl;
    }
    */

    Flightbookings* firstFlight = static_cast<Flightbookings*>(getBookingById(sortedArray[0].i));
    Flightbookings* lastFlight = static_cast<Flightbookings*>(getBookingById(sortedArray[sortedArray.size()-1].i));
    bool erg = firstFlight->getFromDest() == lastFlight->getToDest();
    cout << "Correct? " << erg;

    return erg;
}

bool Travel::checkMissingHotel()
{
    vector<node_data> sortedArray;
    node_data node;

    DepthFirstSearch(*graph);

    for (int n = 0; n < MAX_NODES; n++) {
        if (graph->getVertexValue(n) != nullptr) {
            node_data neu;
            neu.i = graph->getVertexValue(n)->getId();
            neu.bezeichner = graph->getVertexValue(n)->getFromDate();
            neu.end = graph->getEnd(n);
            sortedArray.push_back(neu);
        }
    }

    bubbleSort(sortedArray, sortedArray.size());

    for (int i=0; i<sortedArray.size()-1; i++) {
        Booking* b = getBookingById(sortedArray[i].i);
        Booking* b2 = getBookingById(sortedArray[i+1].i);
        //Mietwagenbuchungen ignorieren
        if (dynamic_cast<RentalCarReservation*>(b))
            continue;
        //Auf Lücke prüfen
        if (b2->getFromDate() > b->getToDate())
            return false;
    }
    return true;
}

bool Travel::checkNeedlessHotel()
{
    vector<node_data> sortedArray;
    node_data node;

    DepthFirstSearch(*graph);

    for (int n = 0; n < MAX_NODES; n++) {
        if (graph->getVertexValue(n) != nullptr) {
            node_data neu;
            neu.i = graph->getVertexValue(n)->getId();
            neu.bezeichner = graph->getVertexValue(n)->getFromDate();
            neu.end = graph->getEnd(n);
            sortedArray.push_back(neu);
        }
    }

    bubbleSort(sortedArray, sortedArray.size());


    Booking* lastBooking = getBookingById(sortedArray[sortedArray.size()-1].i);
    for (int i=0; i<sortedArray.size()-1; i++) {
        Booking* b = getBookingById(sortedArray[i].i);
        if (HotelBookings* hotel1 = dynamic_cast<HotelBookings*>(b)) {
            //Hotel noch nach Rückreise gebucht?
            if (hotel1->getToDate() > lastBooking->getFromDate())
                return false;
            //Fängt eine neue Hotelbuchung an bevor diese Hotelbuchung endet? (Hotel unnötig lang gebucht)
            for (int j=i+1; j<sortedArray.size()-2; j++) {
                Booking* b2 = getBookingById(sortedArray[j].i);
                if (HotelBookings* hotel2 = dynamic_cast<HotelBookings*>(b2)) {
                    // Überlappung zwischen zwei Hotelbuchungen prüfen
                    if (hotel2->getFromDate() < hotel1->getToDate())
                        return false;
                }
            }
        }
    }
    return true;
}

bool Travel::checkNeedlessRentalCar()
{
    vector<node_data> sortedArray;
    node_data node;

    DepthFirstSearch(*graph);

    for (int n = 0; n < MAX_NODES; n++) {
        if (graph->getVertexValue(n) != nullptr) {
            node_data neu;
            neu.i = graph->getVertexValue(n)->getId();
            neu.bezeichner = graph->getVertexValue(n)->getFromDate();
            neu.end = graph->getEnd(n);
            sortedArray.push_back(neu);
        }
    }

    bubbleSort(sortedArray, sortedArray.size());


    Booking* lastBooking = getBookingById(sortedArray[sortedArray.size()-1].i);
    for (int i=0; i<sortedArray.size()-1; i++) {
        Booking* b = getBookingById(sortedArray[i].i);
        // Ist das Auto bereits gebucht bevor die Vorgängerbuchung (ausgenommen Hotels) endet?
        if (i > 0) { // (gegeben dass das Auto nicht die erste Buchung ist)
            int vorg_id = graph->getPredecessor(sortedArray[i].i);
            if (vorg_id > 0) {
                Booking* vorg = getBookingById(vorg_id);
                if (!dynamic_cast<HotelBookings*>(vorg)) // ausgenommen Hotels
                {
                        if (b->getFromDate() < vorg->getToDate())
                            return false;
                }
            }
        }

        if (RentalCarReservation* auto1 = dynamic_cast<RentalCarReservation*>(b)) {
            //Auto noch nach Rückreise gebucht?
            if (auto1->getToDate() > lastBooking->getFromDate())
                return false;
            //Fängt eine neue Autoreservierung an bevor diese Autoreservierung endet? (Auto unnötig lang gebucht)
            for (int j=i+1; j<sortedArray.size()-2; j++) {
                Booking* b2 = getBookingById(sortedArray[j].i);
                if (RentalCarReservation* auto2 = dynamic_cast<RentalCarReservation*>(b2)) {
                    // Überlappung zwischen zwei Hotelbuchungen prüfen
                    if (auto2->getFromDate() < auto1->getToDate())
                        return false;
                }
            }
        }
    }
    return true;
}
