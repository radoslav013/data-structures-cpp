#ifndef NODE_H
#define NODE_H

template <typename E>
class Node {
    private:
        Node<E>* prev;
        E value;
        Node<E>* next;

        friend class DoublyLinkedList<E>;
};

#endif