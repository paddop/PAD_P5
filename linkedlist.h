#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"


template <class T>
class LinkedList
{
public:
    LinkedList();
    void insertNode(T data);
    bool isAtEnd() {
        return (cur == nullptr);
    }
    void advance() {
        if (cur != nullptr)
            cur = cur->getNextNode();
    }

    //void deleteNode();

    T getNode() {return cur->getData();}

    void reset() {cur = head;}

    void empty()
    {
        head = nullptr;
        tail = nullptr;
        cur = nullptr;
        size = 0;
    }

    void clearWithoutDelete() {head = nullptr;}

    T operator[](const int index);

    int getSize() const {return size;}

protected:
    Node<T>* head;
    Node<T>* cur;
    Node<T>* tail;
    int size;
};

template <class T>
LinkedList<T>::LinkedList()
{
    empty();
}

template <class T>
void LinkedList<T>::insertNode(T data)
{
    size++;
    this->reset();
    Node<T>* neu = new Node<T>(data);
    if (head == nullptr)
    {
        // erstes Element das hinzugefügt wird
        head = neu;
        tail = neu;
        cur = neu;
        return;
    }
    else
    {
        // es existiert schon min. 1 Element in der Liste

        // gehört neu an den Anfang?
        if (neu->getData()->getId() < head->getData()->getId()) {
            neu->setNextNode(head);
            head->setPrevNode(neu);
            head = neu;
            return;
        }

        // gehört neu an das Ende?
        if (neu->getData()->getId() >= tail->getData()->getId()) {
            neu->setPrevNode(tail);
            tail->setNextNode(neu);
            tail = neu;            
            return;
        }

        // neu gehört in die Mitte!
        while (neu->getData()->getId() >= cur->getData()->getId()) {
            cur = cur->getNextNode();
        }
        // cur zeigt jetzt auf Node vor der Neu kommen soll
        neu->setNextNode(cur);
        neu->setPrevNode(cur->getPrevNode());
        cur->getPrevNode()->setNextNode(neu);
        cur->setPrevNode(neu);
    }
}

template <class T>
T LinkedList<T>::operator[](const int index)
{
    int ctr = 0;
    cur = head;
    while(cur) {
        if(ctr==index)
            return cur->getData();
        cur = cur->getNextNode();
        ctr++;
    }
    //index out of range
    throw out_of_range("Letztes Element an Position " + to_string(ctr));
}


#endif // LINKEDLIST_H
