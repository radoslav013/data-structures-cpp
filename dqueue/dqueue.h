#ifndef LSTACK_H
#define LSTACK_H

#include "../deque/deque.h"

template <typename T>
class DQueue : protected Deque<T> {
    public:
        DQueue() : Deque<T>() {};
        void enqueue(const T& el);
        void dequeue();
        const T& top() const;
};

template <typename T>
void DQueue<T>::enqueue(const T& el) {
    Deque<T>::insertBack(el);
}

template <typename T>
void DQueue<T>::dequeue() {
    Deque<T>::removeFront();
}

template <typename T>
const T& DQueue<T>::top() const {
    return Deque<T>::front();
}


#endif