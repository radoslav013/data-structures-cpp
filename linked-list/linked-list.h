#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename E>
class Node;

template <typename T>
class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        void pushFront(const T& el);
        void popFront();
        const T& front() const;
        int size() const;
        bool empty() const;
    private:
        Node<T>* head; // first inserted (helps when sorting and printing)
        int n;
};

template <typename T>
LinkedList<T>::LinkedList() {
    head = new Node<T>;
    n = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    while(!empty()) {
        popFront();
    }
    delete head;
}

template <typename T>
void LinkedList<T>::pushFront(const T& el) {
    Node<T>* toBeInserted = new Node<T>;
    toBeInserted->el = el;
    toBeInserted->next = head->next;

    head->next = toBeInserted;
    n++;
}

template <typename T>
void LinkedList<T>::popFront() {
    // check if empty
    Node<T>* toBeDeleted = head->next;
    head->next = head->next->next;

    delete toBeDeleted;
    n--;
}

template <typename T>
const T& LinkedList<T>::front() const {
    // check if empty
    return head->next->el;
}

template <typename T>
int LinkedList<T>::size() const {
    return n;
}

template <typename T>
bool LinkedList<T>::empty() const {
    return size() == 0;
}

#endif