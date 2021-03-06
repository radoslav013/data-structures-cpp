#ifndef LSTACK_H
#define LSTACK_H

#include "../deque/deque.h"

template <typename T>
class DStack : protected Deque<T> {
    public:
        DStack() : Deque<T>() {};
        void push(const T& el);
        void pop();
        const T& top() const;
        void clean();
};

template <typename T>
void DStack<T>::push(const T& el) {
    Deque<T>::insertBack(el);
}

template <typename T>
void DStack<T>::pop() {
    Deque<T>::removeBack();
}

template <typename T>
const T& DStack<T>::top() const {
    return Deque<T>::back();
}

template <typename T>
void DStack<T>::clean() {
    if(!Deque<T>::empty()) {
        pop();
        clean();
    }
}

#endif