#include <iostream>

using namespace std;

#include "deque.h"

int main() {
    Deque<int> d;
    d.insertFront(123);
    d.insertFront(1234);
    d.removeBack();
    

    cout << d.front() << endl;

    Deque<int> d1(d);

    Deque<int> d2 = d1;

    cout << d2.front() << endl;

    return 0;
}