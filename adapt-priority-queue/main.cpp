#include <iostream>

using namespace std;

#include "adapt-priority-queue.h"

class SmallerLarger {
    public:
        bool operator()(int p, int q) const {
            return p < q;
        }
};

int main() {
    AdaptPriorityQueue<int, SmallerLarger> q;
    q.insert(1);
    q.insert(2);
    return 0;
}