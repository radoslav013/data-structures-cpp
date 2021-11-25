#ifndef ASTACK_H
#define ASTACK_H

#include "stack-empty.exception.h"
#include "stack-full.exception.h"

template <typename T>
class AStack {
    public:
        AStack();
        int size() const;
        bool empty() const;
        void push(const T& el);
        void pop();
        const T& top() const;
    private:
        enum {N = 256};
        T arr[N];
        int indx_top;
};

template <typename T>
AStack<T>::AStack() {
    indx_top = -1;
}

template <typename T>
int AStack<T>::size() const {
    return indx_top + 1;
}

template <typename T>
bool AStack<T>::empty() const {
    return size() == 0;
}

template <typename T>
void AStack<T>::push(const T& el) {
    if(indx_top+1 >= N) {
        throw StackFull("it's full");
    }
    arr[++indx_top] = el;
}

template <typename T>
void AStack<T>::pop() {
    if(indx_top < 0) {
        throw StackEmpty("it's empty");
    }
    indx_top--;
}

template <typename T>
const T& AStack<T>::top() const {
    return arr[indx_top];
}

#endif