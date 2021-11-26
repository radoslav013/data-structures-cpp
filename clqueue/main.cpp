#include <iostream>

using namespace std;

#include "clqueue.h"

int main() {
    CLQueue<int> clq;
    clq.enqueue(23);
    clq.dequeue();
    
    // cout << ls.top() << endl;
    return 0;
}