#include <iostream>
#include <string>

using namespace std;

#include "circular-linked-list.h"
#include "node.h"

int main() {
    CircularLinkedList<string>* list = new CircularLinkedList<string>();
    list->add("five");
    cout << list->back() << endl;
    list->add("ten");

    list->advance();
    cout << list->back() << endl;
    list->advance();
    list->remove();

    cout << list->back() << endl;
    return 0;
}