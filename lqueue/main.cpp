#include <iostream>

using namespace std;

#include "lqueue.h"

int main() {
    LQueue<int> lq;
    lq.enqueue(23);
    lq.dequeue();
    
    // cout << ls.top() << endl;
    return 0;
}