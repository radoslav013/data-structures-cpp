#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
    private:
        Node<T>* prev;
        T value;
        Node<T>* next;

        friend class DoublyLinkedList<T>;
};

#endif