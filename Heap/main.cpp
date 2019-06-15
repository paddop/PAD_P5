#include <iostream>
#include "heap.h"
using namespace std;

int main() {
    int a[12] = {1, 6, 8, 3, 2, 7, 3, 4,17,26,2,99};
    Heap myHeap(a, 12);

    for (int i = 1; i <= 12; i++)
        cout << myHeap.pop() << endl;
    return 0;
}
