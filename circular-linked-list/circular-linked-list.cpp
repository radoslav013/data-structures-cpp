#include <iostream>

using namespace std;

#include "circular-linked-list.h"
#include "node.h"

CircularLinkedList::CircularLinkedList() {
}

CircularLinkedList::~CircularLinkedList() {
    while (!empty()) remove();
}

void CircularLinkedList::advance() {
    cursor = cursor->next;
}

bool CircularLinkedList::empty() const {
    return (cursor == nullptr);
}

const int& CircularLinkedList::front() const {
    return cursor->next->value;
}

const int& CircularLinkedList::back() const {
    return cursor->value;
}

void CircularLinkedList::add(const int& e) {
    Node<int>* newNode = new Node<int>;
    newNode->value = e;
    
    if(empty()) {
        newNode->next = newNode;
        cursor = newNode;
    } else {
        newNode->next = cursor->next;
        cursor->next = newNode;
    }
}

void CircularLinkedList::remove() {
    Node<int>* toBeRemoved = cursor->next;

    // if(empty()) throw(IndexOutOfBounds);

    if(toBeRemoved == cursor) cursor = nullptr;
    else cursor->next = toBeRemoved->next;

    delete toBeRemoved;
}
