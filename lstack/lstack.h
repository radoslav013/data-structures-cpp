#ifndef LSTACK_H
#define LSTACK_H

#include "../linked-list/linked-list.h"
#include "../linked-list/node.h"

template <typename T>
class LStack : protected LinkedList<T> {
    public:
        LStack() : LinkedList<T>() {};
        int size() const;
        bool empty() const;
        void push(const T& el);
        void pop();
        const T& top() const;
};

template <typename T>
void LStack<T>::push(const T& el) {
    LinkedList<T>::pushFront(el);
}

template <typename T>
void LStack<T>::pop() {
    LinkedList<T>::popFront();
}

template <typename T>
const T& LStack<T>::top() const {
    return LinkedList<T>::front();
}


#endif