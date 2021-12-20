#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <iostream>

using namespace std;

class CLLExcpt : public runtime_error {
    public:
        CLLExcpt(const string& msg) : runtime_error(msg) {}
};

template <typename E>
class Node;

template <typename T>
class CircularLinkedList {
    public:
        CircularLinkedList() : cursor(nullptr) {}; // constructor
        virtual ~CircularLinkedList(); // destructor
        bool empty() const; // returns if empty?
        const T& curr() const; // get value at the cursor 
        const T& next() const; // get value next of cursor
        void advance(); // move cursor one forward
        void add(const T& e); // add after cursor
        void remove(); // remove after cursor
    private:
        Node<T>* cursor;
};

template <typename T>
CircularLinkedList<T>::~CircularLinkedList() {
    while (!empty()) remove();
} // destructor

template <typename T>
void CircularLinkedList<T>::advance() {
    if(empty()) {
        throw CLLExcpt("List is empty.");
    }
    cursor = cursor->next;
} // advance

template <typename T>
bool CircularLinkedList<T>::empty() const {
    return (cursor == nullptr);
} // empty

template <typename T>
const T& CircularLinkedList<T>::curr() const {
    if(empty()) {
        throw CLLExcpt("List is empty.");
    }
    return cursor->value;
} // curr

template <typename T>
const T& CircularLinkedList<T>::next() const {
    if(empty()) {
        throw CLLExcpt("List is empty.");
    }
    return cursor->next->value;
} // next

template <typename T>
void CircularLinkedList<T>::add(const T& e) {
    Node<T>* newNode = new Node<T>;
    newNode->value = e;
    
    if(empty()) {
        newNode->next = newNode;
        cursor = newNode;
    } else {
        newNode->next = cursor->next;
        cursor->next = newNode;
    }
} // add

template <typename T>
void CircularLinkedList<T>::remove() {
    if(!empty()) {
        Node<T>* toBeRemoved = cursor->next;

        if(toBeRemoved == cursor) {
            cursor = nullptr;
        } else {
            cursor->next = toBeRemoved->next;
        }

        delete toBeRemoved;
    } else {
        throw CLLExcpt("List is empty.");
    }
} // remove

#endif