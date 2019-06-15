#include "customer.h"

Customer::Customer(long id, string name)
    : id(id), name(name)
{

}

Customer::~Customer()
{
    for (Travel* t : travelList)
        delete t;
}

void Customer::addTravel(Travel *travel)
{
    this->travelList.push_back(travel);
}

long Customer::getId() const
{
    return id;
}

long Customer::getNumberOfTravel() const
{
    return this->travelList.size();
}
