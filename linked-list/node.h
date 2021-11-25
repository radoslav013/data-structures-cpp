#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
    private:
        T el;
        Node<T>* next;
    
    friend class LinkedList<T>;
};

#endif