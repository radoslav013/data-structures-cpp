#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

template <typename E>
class Node;

class CircularLinkedList {
    public:
        CircularLinkedList(); // constructor
        ~CircularLinkedList(); // destruct
        bool empty() const; // checks if empty?
        const int& front() const; // get value at the front 
        const int& back() const; // get value at the back 
        void advance(); // move cursor one forward
        void add(const int& e); // add after cursor
        void remove(); // remove after cursor
    private:
        Node<int>* cursor;
};

#endif