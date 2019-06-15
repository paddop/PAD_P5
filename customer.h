#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "travel.h"

class Customer
{
public:
    Customer(long id, string name);
    ~Customer();
    void addTravel(Travel* travel);
    long getId() const;
    long getNumberOfTravel() const;
    string getName() {return name;}
private:
    long id;
    string name;
    vector<Travel*> travelList;
};

#endif // CUSTOMER_H
