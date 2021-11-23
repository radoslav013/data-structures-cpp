#ifndef DEQUE_H
#define DEQUE_H

template <typename T>
class Deque;

#include "../doubly-linked-list/doubly-linked-list.h"
#include "../doubly-linked-list/node.h"

template <typename T>
class Deque {
    public:
        Deque();
        ~Deque();
        Deque(const Deque<T>& d);
        bool empty() const;
        int size() const;
        const T& front() const;
        const T& back() const;
        void insertFront(const T& el);
        void insertBack(const T& el);
        void removeFront();
        void removeBack();
        const Node<T>* getHead() const;
        const Node<T>* getTail() const;
        Deque &operator =(const Deque<T> &deq);
    private:
        DoublyLinkedList<T>* D;
        int n;
        void free();
        void copy(const Deque<T>& d);
};

template <typename T>
Deque<T>::Deque() {
    D = new DoublyLinkedList<T>();
    n = 0;
}

template <typename T>
Deque<T>::~Deque() {
    free();
}

template <typename T>
Deque<T>::Deque(const Deque<T>& d) {
    copy(d);
}

template <typename T>
Deque<T> &Deque<T>::operator =(const Deque<T> &deq) {
    if(this != &deq) {
        free();
        copy(deq);
    }
    return *this;
}

template <typename T>
void Deque<T>::copy(const Deque<T>& d) {
    D = new DoublyLinkedList<T>();
    n = 0;

    Node<T>* curr = d.getHead()->next;
    while(curr != d.getTail()) {
        D->addFront(curr->value);
        curr = curr->next;
    }
}

template <typename T>
void Deque<T>::free() {
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

template <typename T>
const Node<T>* Deque<T>::getHead() const {
    return D->getHead();
}

template <typename T>
const Node<T>* Deque<T>::getTail() const {
    return D->getTail();
}

#endif