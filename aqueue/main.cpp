#include <iostream>

using namespace std;

#include "aqueue.h"

int main() {
    AQueue<int> aq;
    aq.enqueue(12);
    aq.enqueue(13);
    aq.enqueue(15);
    cout << aq.front() << endl;
    return 0;
}