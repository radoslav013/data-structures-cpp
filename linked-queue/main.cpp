#include <iostream>

using namespace std;

#include "linked-queue.h"

int main() {
    LinkedQueue<int>* lq = new LinkedQueue<int>();
    lq->enqueue(12);
    lq->enqueue(14);
    lq->dequeue();

    cout << lq->size() << endl;
    return 0;
}