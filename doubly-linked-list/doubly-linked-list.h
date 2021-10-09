#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

template <typename T>
class Node;

template <typename T>
class DoublyLinkedList {
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        bool empty() const;
        const T& front() const;
        const T& back() const;
        void addFront(const T& value);
        void addBack(const T& value);
        void removeFront();
        void removeBack();
    private:
        Node<T>* head;
        Node<T>* tail;
    protected:
        void add(Node<T>* v, const T& value);
        void remove(Node<T>* v);
};

#endif