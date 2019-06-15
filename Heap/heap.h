/* 
 * File:   heap.h
 * Author: arnim
 *
 * Created on 13. Dezember 2013, 07:51
 */

#ifndef HEAP_H
#define	HEAP_H
#include <stdexcept>

template <class T>
class Heap
{
public:
    // Erstelle einen Heap aus dem Array a[] mit size Elementen
    Heap(T a[], unsigned int size);
    ~Heap();
    T pop();
    
private:
    void heapify(unsigned int start);
    T data;
    unsigned int pointer;
};
#endif	/* HEAP_H */

