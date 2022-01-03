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
    cout << heap.min() << endl;
    return 0;
}