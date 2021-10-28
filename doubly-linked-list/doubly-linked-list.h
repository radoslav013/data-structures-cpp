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
        const T& frontValue() const; // get value at the front 
        const T& backValue() const; // get value at the back
        void addFront(const T& value); // add to the front
        void addBack(const T& value); // add to the back
        void removeFront(); // remove from the front
        void removeBack(); // remove from the back
        void reverse();
        void swap(Node<T>* a, Node<T>* b);
        void print() const;
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
const T& DoublyLinkedList<T>::frontValue() const {
    return head->next->value;
}

template <typename T>
const T& DoublyLinkedList<T>::backValue() const {
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

template <typename T>
void DoublyLinkedList<T>::reverse() {
    Node<T>* current = head->next;
    Node<T>* next;

    head->next = next;
    while(current->next != tail) {
        Node<T>* prev = current->prev;
        next = current->next;
        // cout << "is head: " << (current->prev == head ? 1 : 0) << " ";
        // cout << "current: " << current->value << " ";
        // cout << "next: " << current->next->value << " ";
        prev->next = next;
        next->prev = prev;
        next->next = current;

        current->next = tail; // Wrong.
        
        current->prev = next;

        // cout << endl;
    }

    tail->prev = next;

    // cout << "first: " << head->next->value << endl;
    // cout << "second: " << head->next->next->value << endl;
}

template <typename T>
void DoublyLinkedList<T>::print() const {
    Node<T>* curr = head->next;
    while(curr != tail) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}

#endif