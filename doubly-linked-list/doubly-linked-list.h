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

#endif