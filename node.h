#ifndef NODE_H
#define NODE_H

#include "booking.h"


template <class T>
class Node
{
public:
    Node(T data)
        : data(data), prev(nullptr), next(nullptr) {}

    Node* getNextNode() const {return next;}
    void setNextNode(Node* next) {this->next = next;}
    Node* getPrevNode() const {return prev;}
    void setPrevNode(Node* prev) {this->prev = prev;}

    T getData() const {return data;}
    void setData(T data) {this->data = data;}

private:
    T data;
    Node* prev;
    Node* next;
};

#endif // NODE_H
