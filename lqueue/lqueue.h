#ifndef LSTACK_H
#define LSTACK_H

#include "../linked-list/linked-list.h"
#include "../linked-list/node.h"

template <typename T>
class LQueue : protected LinkedList<T> {
    public:
        LQueue() : LinkedList<T>() {};
        int size() const;
        bool empty() const;
        void enqueue(const T& el);
        void dequeue();
        const T& top() const;
};

template <typename T>
void LQueue<T>::enqueue(const T& el) {
    LinkedList<T>::pushFront(el);
}

template <typename T>
void LQueue<T>::dequeue() {
    LinkedList<T>::popFront();
}

template <typename T>
const T& LQueue<T>::top() const {
    return LinkedList<T>::front();
}


#endif