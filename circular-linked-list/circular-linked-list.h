#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

template <typename E>
class Node;

template <typename T>
class CircularLinkedList {
    public:
        CircularLinkedList(); // constructor
        ~CircularLinkedList(); // destruct
        bool empty() const; // checks if empty?
        const T& front() const; // get value at the front 
        const T& back() const; // get value at the back 
        void advance(); // move cursor one forward
        void add(const T& e); // add after cursor
        void remove(); // remove after cursor
    private:
        Node<T>* cursor;
};

template <typename T>
CircularLinkedList<T>::CircularLinkedList() {
}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList() {
    while (!empty()) remove();
}

template <typename T>
void CircularLinkedList<T>::advance() {
    cursor = cursor->next;
}

template <typename T>
bool CircularLinkedList<T>::empty() const {
    return (cursor == nullptr);
}

template <typename T>
const T& CircularLinkedList<T>::front() const {
    return cursor->next->value;
}

template <typename T>
const T& CircularLinkedList<T>::back() const {
    return cursor->value;
}

template <typename T>
void CircularLinkedList<T>::add(const T& e) {
    Node<T>* newNode = new Node<T>;
    newNode->value = e;
    
    if(empty()) {
        newNode->next = newNode;
        cursor = newNode;
    } else {
        newNode->next = cursor->next;
        cursor->next = newNode;
    }
}

template <typename T>
void CircularLinkedList<T>::remove() {
    Node<T>* toBeRemoved = cursor->next;

    // if(empty()) throw(IndexOutOfBounds);

    if(toBeRemoved == cursor) cursor = nullptr;
    else cursor->next = toBeRemoved->next;

    delete toBeRemoved;
}


#endif