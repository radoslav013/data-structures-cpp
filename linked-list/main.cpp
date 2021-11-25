#include <iostream>

using namespace std;

#include "linked-list.h"
#include "node.h"

int main() {
    LinkedList<int> l;
    l.pushFront(10);
    l.pushFront(8);
    l.popFront();

    cout << l.size() << endl;
    return 0;
}