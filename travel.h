#ifndef TRAVEL_H
#define TRAVEL_H

#include <vector>
#include "booking.h"
#include "Digraph/graph.h"
#include "flightbookings.h"
#include "hotelbookings.h"
#include "rentalcarreservation.h"

class Travel
{
public:
    Travel(long id, long customerId);
    ~Travel();
    void addBooking(Booking* booking);
    long getId() const;
    long getNumberOfBookings() const;
    long getCustomerId() const;

    void addNodeToGraph(int n, Booking* b) {graph->insertVertex(n, b);}
    void addArcToGraph(int n, int m) {graph->insertArc(n, m, 1);}
    bool existsNodeWithId(int id) {return graph->existsVertex(id);}
    void updateGraphValueOfNode(int n, Booking* b) {graph->setVertexValue(n, b);}
    void debugGraph() {graph->printVertices(); graph->printAdjMatrix();}

    bool checkRoundTrip();
    bool checkMissingHotel();
    bool checkNeedlessHotel();

    Booking* getBookingById(int i)
    {
        for (Booking* b : travelBookings) {
            if (b->getId() == i)
                return b;
        }
        return nullptr;
    }

private:
    long id;
    long customerId;
    vector<Booking*> travelBookings;
    static const int MAX_NODES = 106;
    Graph<Booking*, MAX_NODES>* graph;
};

#endif // TRAVEL_H
