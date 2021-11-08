#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <iostream>

using namespace std;

template <typename E>
class Node;

template <typename T>
class CircularLinkedList {
    public:
        CircularLinkedList(); // constructor
        ~CircularLinkedList(); // destruct
        bool empty() const; // checks if empty?
        const T& currValue() const; // get value at the cursor 
        const T& nextValue() const; // get value next of cursor
        const Node<T>* curr() const; // get at cursor
        const Node<T>* next() const; // get next of cursor
        void advance(); // move cursor one forward
        void add(const T& e); // add after cursor
        void remove(); // remove after cursor

        // sorts with reverse-insertion sort algorithm, 
        // since singly-linked lists don't have prev property in their nodes
        void sort(); 
        void print(); // prints all elements
    private:
        Node<T>* cursor;

        // generally speaking a circular list doesn't have start and end, but these help with printing
        Node<T>* head; // first inserted (helps when sorting and printing)
        Node<T>* tail; // last inserted (helps when sorting and printing)
};

template <typename T>
CircularLinkedList<T>::CircularLinkedList() {
}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList() {
    while (!empty()) remove();
}

template <typename T>
void CircularLinkedList<T>::advance() {
    cursor = cursor->next;
}

template <typename T>
void CircularLinkedList<T>::print() {
    if(!empty()) {
        cursor = head;
        do {
            cout << currValue() << " ";
            advance();
        } while(cursor != head);
        cout << endl;
    } else {
        cout << "The list is empty" << endl;
    }
}

template <typename T>
void CircularLinkedList<T>::sort() {
    if(!empty()) {
        while(true) {
            Node<T>* curr = cursor->next;
            while(curr != head) {
                if(cursor->value > curr->value) {
                    // Swapping
                    T temp = cursor->value;
                    cursor->value = curr->value;
                    curr->value = temp;
                }
                curr = curr->next; // one step forward, without changing the member property cursor
            }
            advance();
            if(cursor->next == head) {
                break;
            }
        }
    } else {
        cout << "The list is empty" << endl;
    }
}

template <typename T>
bool CircularLinkedList<T>::empty() const {
    return (cursor == nullptr);
}

template <typename T>
const T& CircularLinkedList<T>::currValue() const {
    return curr()->value;
}

template <typename T>
const T& CircularLinkedList<T>::nextValue() const {
    return next()->value;
}

template <typename T>
const Node<T>* CircularLinkedList<T>::curr() const {
    return cursor;
}

template <typename T>
const Node<T>* CircularLinkedList<T>::next() const {
    return cursor->next;
}

template <typename T>
void CircularLinkedList<T>::add(const T& e) {
    Node<T>* newNode = new Node<T>;
    newNode->value = e;
    
    if(empty()) {
        newNode->next = newNode;
        cursor = newNode;
        head = newNode;
    } else {
        newNode->next = cursor->next;
        cursor->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void CircularLinkedList<T>::remove() {
    if(!empty()) {
        Node<T>* toBeRemoved = cursor->next;

        if(toBeRemoved == cursor) {
            cursor = nullptr;
            head = nullptr;
            tail = nullptr;
        }
        else {
            cursor->next = toBeRemoved->next;
            tail = cursor;
        }

        delete toBeRemoved;
    }
}


#endif