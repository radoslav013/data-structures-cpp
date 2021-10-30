#include <iostream>

using namespace std;

#include "deque.h"

int main() {
    Deque<int>* d = new Deque<int>();
    d->insertFront(123);
    d->insertFront(1234);
    d->removeBack();
    

    cout << d->front() << endl;
    return 0;
}