#ifndef DEQUE_H
#define DEQUE_H

#include "../doubly-linked-list/doubly-linked-list.h"
#include "../doubly-linked-list/node.h"

template <typename T>
class Deque {
    public:
        Deque();
        ~Deque();
        bool empty() const;
        int size() const;
        const T& front() const;
        const T& back() const;
        void insertFront(const T& el);
        void insertBack(const T& el);
        void removeFront();
        void removeBack();
    private:
        DoublyLinkedList<T>* D;
        int n;
};

template <typename T>
Deque<T>::Deque() {
    D = new DoublyLinkedList<T>();
    n = 0;
}

template <typename T>
Deque<T>::~Deque() {
    if(D) {
        delete D;
        D = nullptr;
    }
}

template <typename T>
bool Deque<T>::empty() const {
    return n == 0;
}

template <typename T>
int Deque<T>::size() const {
    return n;
}

template <typename T>
const T& Deque<T>::front() const {
    return D->frontValue();
}

template <typename T>
const T& Deque<T>::back() const {
    return D->backValue();
}

template <typename T>
void Deque<T>::insertFront(const T& el) {
    D->addFront(el);
    n++;
}

template <typename T>
void Deque<T>::insertBack(const T& el) {
    D->addBack(el);
    n++;
}

template <typename T>
void Deque<T>::removeFront() {
    D->removeFront();
    n--;
}

template <typename T>
void Deque<T>::removeBack() {
    D->removeBack();
    n--;
}

#endif