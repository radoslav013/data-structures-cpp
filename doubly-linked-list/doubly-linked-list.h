#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

template <typename E>
class Node;

template <typename T>
class DoublyLinkedList {
    public:
        DoublyLinkedList(); // constructor
        ~DoublyLinkedList(); // destructor
        bool empty() const; // checks if empty?
        const T& front() const; // get value at the front 
        const T& back() const; // get value at the back
        void addFront(const T& value); // add to the front
        void addBack(const T& value); // add to the back
        void removeFront(); // remove from the front
        void removeBack(); // remove from the back
    private:
        Node<T>* head; //special node that holds the first dummy node
        Node<T>* tail; //special node that holds the last dummy node
    protected:
        void add(Node<T>* v, const T& value); // add before v
        void remove(Node<T>* v); // remove v
};

#endif