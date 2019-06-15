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

bool Travel::checkRoundTrip()
{
    node_data sortedArray[MAX_NODES];
    node_data node;

    DepthFirstSearch(*graph);

    for (int i = 1; i <= MAX_NODES; i++) {
    sortedArray[i].i = i;
    sortedArray[i].bezeichner = graph->getVertexValue(i)->getFromDate();
    sortedArray[i].end =
    graph->getEnd(i);
    }

    Heap myHeap(sortedArray, MAX_NODES);

    for (int i = 1; i <= MAX_NODES; i++) {
        node = myHeap.pop();
        cout << i << " " << setw(15) << node.bezeichner << " " << node.end << endl;
    }

    return true;
}

bool Travel::checkMissingHotel()
{
    // Topologische Sortierung
    DepthFirstSearch(*graph);



    return true;
}
