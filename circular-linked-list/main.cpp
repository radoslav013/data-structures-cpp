#include <iostream>

using namespace std;

#include "circular-linked-list.h"

int main() {
    CircularLinkedList* list = new CircularLinkedList();
    list->add(5);
    cout << list->back() << endl;
    list->add(10);

    list->advance();
    cout << list->back() << endl;
    list->advance();
    list->remove();

    cout << list->back() << endl;
    return 0;
}