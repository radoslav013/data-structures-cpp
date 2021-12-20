#ifndef NODE_H
#define NODE_H

template <typename E>
class Node {
    private:
        E value;
        Node<E>* next;

        friend class CircularLinkedList<E>;
};

#endif