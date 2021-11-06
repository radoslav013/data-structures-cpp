#include <iostream>
#include <string>

using namespace std;

#include "doubly-linked-list.h"
#include "node.h"

int main() {
    DoublyLinkedList<int>* list = new DoublyLinkedList<int>();
    list->addFront(6);
    list->addFront(7);
    // list->addFront(8);
    // list->addFront(9);
    // list->addFront(10);
    list->addFront(11);
    list->addFront(12);
    // cout << list->frontValue() << endl;
    // cout << list->backValue() << endl;

    // list->removeFront();

    // cout << list->empty() << endl;

    list->print();
    cout << "Reversed: " << endl;
    list->reverse();
    list->print();

    if(list){
        delete list;
        list = nullptr;
    }
    
    return 0;
}