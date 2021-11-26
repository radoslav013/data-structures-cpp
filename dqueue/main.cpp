#include <iostream>

using namespace std;

#include "dqueue.h"

int main() {
    DQueue<int> dq;
    dq.enqueue(12);
    dq.enqueue(13);
    // dq.dequeue();
    cout << dq.top() << endl;
    dq.empty();
    return 0;
}