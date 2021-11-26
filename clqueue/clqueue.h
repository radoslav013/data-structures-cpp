#ifndef CLQUEUE_H
#define CLQUEUE_H

#include "../circular-linked-list/circular-linked-list.h"
#include "../circular-linked-list/node.h"

template <typename T>
class CLQueue : protected CircularLinkedList<T> {
    public:
        CLQueue() : CircularLinkedList<T>() {};
        void enqueue(const T& el);
        void dequeue();
        const T& top() const;
};

template <typename T>
void CLQueue<T>::enqueue(const T& el) {
    LinkedList<T>::pushFront(el);
}

template <typename T>
void CLQueue<T>::dequeue() {
    LinkedList<T>::popFront();
}

template <typename T>
const T& CLQueue<T>::top() const {
    return LinkedList<T>::front();
}


#endif