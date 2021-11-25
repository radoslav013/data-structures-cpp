#include <iostream>

using namespace std;

#include "aqueue.h"

int main() {
    AQueue<int> aq;
    aq.enqueue(12);
    aq.enqueue(13);
    aq.enqueue(15);

    AQueue<int> aq2(aq);
    cout << aq2.front() << endl;

    AQueue<int> aq3 = aq;
    cout << aq3.front() << endl;
    return 0;
}