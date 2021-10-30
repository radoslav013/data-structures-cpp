#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include "../circular-linked-list/circular-linked-list.h"
#include "../circular-linked-list/node.h"

template <typename T>
class LinkedQueue {
    public:
        LinkedQueue();
        ~LinkedQueue();
        bool empty() const;
        int size() const;
        const T& front() const;
        void enqueue(const T& el);
        void dequeue();
    private:
        CircularLinkedList<T>* C;
        int n;
};

template <typename T>
LinkedQueue<T>::LinkedQueue() {
    C = new CircularLinkedList<T>();
    n = 0;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    if(C) {
        delete C;
        C = nullptr;
    }
}

template <typename T>
bool LinkedQueue<T>::empty() const {
    return n == 0;
}

template <typename T>
int LinkedQueue<T>::size() const {
    return n;
}

template <typename T>
const T& LinkedQueue<T>::front() const {
    return C->front();
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& el) {
    C->add(el);
    C->advance();
    n++;
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    C->remove();
    n--;
}


#endif