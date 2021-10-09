#include "doubly-linked-list.h"
#include "node.h"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = new Node<T>;
    tail = new Node<T>;

    head->next = tail;
    tail->prev = head;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while(!empty()) removeFront();
    delete head;
    delete tail;
}

template <typename T>
bool DoublyLinkedList<T>::empty() const {
    return (head->next == tail);
}

template <typename T>
const T& DoublyLinkedList<T>::front() const {
    return head->next->value;
}

template <typename T>
const T& DoublyLinkedList<T>::back() const {
    return tail->prev->value;
}

template <typename T>
void DoublyLinkedList<T>::add(Node<T>* v, const T& value) {
    Node<T>* newNode = new Node<T>;

    newNode->value = value;
    newNode->next = v;
    newNode->prev = v->prev;

    v->prev->next = newNode;
    v->prev = newNode;
}

template <typename T>
void DoublyLinkedList<T>::addFront(const T& value) {
    add(head->next, value);
}

template <typename T>
void DoublyLinkedList<T>::addBack(const T& value) {
    add(tail, value);
}

template <typename T>
void DoublyLinkedList<T>::removeFront() {
    remove(head->next);
}

template <typename T>
void DoublyLinkedList<T>::removeBack() {
    remove(tail->prev);
}

template <typename T>
void DoublyLinkedList<T>::remove(Node<T>* v) {
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v;
}
