#include <iostream>

using namespace std;

#include "heap.h"

class SmallerLarger {
    public:
        bool operator()(int p, int q) const {
            return p < q;
        }
};

int main() {
    HeapPriorityQueue<int, SmallerLarger> heap;
    heap.insert(1);
    heap.insert(4);
    heap.insert(10);
    heap.insert(7);
    heap.insert(1);
    heap.insert(10);
    heap.insert(10);
    cout << heap.min() << endl;

    heap.removeMin();
    heap.removeMin();
    cout << heap.min() << endl;
    return 0;
}