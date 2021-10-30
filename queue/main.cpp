#include <iostream>

using namespace std;

#include "queue.h"

int main() {
    Queue<int>* q = new Queue<int>();
    q->enqueue(23);
    q->dequeue();
    q->enqueue(24);
    cout << q->front() << endl;

    return 0;
}