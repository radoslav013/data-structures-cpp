#include <iostream>
#include <string>

using namespace std;

#include "doubly-linked-list.cpp"

int main() {
    DoublyLinkedList<int>* list = new DoublyLinkedList<int>();
    list->addFront(5);
    cout << list->front() << endl;
    cout << list->back() << endl;

    list->removeFront();

    cout << list->empty() << endl;
    delete list;
    return 0;
}