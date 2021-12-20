#ifndef LIST_H
#define LIST_H

template <typename T>
class NodeList {
    private:
        struct Node {
            T elem; // value
            Node* prev; // pointer to previous element
            Node* next; // pointer to next element
        };
    public:
        class Iterator {
            public:
                Iterator(); // constructor
                Iterator(Node* u); // constructor with existing node
                Iterator(const Iterator& u); // copy constructor
                T& operator*(); // reference to the element
                bool operator ==(const Iterator& p) const; // comparison operator overloaded
                bool operator !=(const Iterator& p) const; // negative comparison operator overloaded
                Iterator& operator =(const Iterator& p);
                Iterator& operator ++(); // prefix increment
                Iterator& operator --(); // prefix decrement
                Iterator operator ++(int); // postfix increment
                Iterator operator --(int); // postfix decrement

                friend class NodeList; // allow NodeList to access all properties of this class
            private:
                Node* v; // pointer to node
                void copy(const Iterator& u); // copy object
        };
    public:
        NodeList(); // constructor
        ~NodeList(); // desctructor
        NodeList(const NodeList<T>& b); // copy constructor
        NodeList& operator =(const NodeList<T>& b); // assignment operator overloaded
        int size() const; // return size
        bool empty() const; // return boolean whether empty
        Iterator begin() const; // iterator of the position next to header
        Iterator end() const; // iterator of the position previous to trailer
        void push_front(const T& e); // push to the front
        void push_back(const T& e); // push to the back
        void push(const Iterator& p, const T& e); // push element on a specifiv position
        void pop_front(); // pop first element
        void pop_back(); // pop last element
        void pop(const Iterator& p); // pop element on a specific position
    private: 
        int n; // keeps track of the size of the element
        Node* header; // pointer to the header
        Node* trailer; // pointer to the trailer
        void copy(const NodeList<T>& b); // copy object
        void free(); // free object
};

template <typename T>
NodeList<T>::NodeList() {
    n = 0;
    header = new Node;
    trailer = new Node;

    header->next = trailer;
    trailer->prev = header;
}

template <typename T>
NodeList<T>::~NodeList() {
    free();
}

template <typename T>
NodeList<T>::NodeList(const NodeList<T>& b) {
    // copy the static properties
    n = b.n;
    header = b.header;
    trailer = b.trailer;

    copy(b);
}

template <typename T>
NodeList<T>& NodeList<T>::operator =(const NodeList<T>& b) {
    if(this != &b) {
        free();
        copy(b);
    }
    return *this;
}

template <typename T>
void NodeList<T>::copy(const NodeList<T>& b) {
    // copies all elements from one list to another
    for(NodeList<T>::Iterator it = b.begin(); it != b.end(); ++it) {
        push_back(*it);
    }
}

template <typename T>
void NodeList<T>::free() {
    // pops all elements
    while(!empty()) {
        pop_back();
    }
}

template <typename T>
int NodeList<T>::size() const {
    return n;
}

template <typename T>
bool NodeList<T>::empty() const {
    return size() == 0;
}

template <typename T>
typename NodeList<T>::Iterator NodeList<T>::begin() const {
    return Iterator(header->next);
}

template <typename T>
typename NodeList<T>::Iterator NodeList<T>::end() const {
    return Iterator(trailer);
}

template <typename T>
void NodeList<T>::push_front(const T& e) {
    push(begin(), e);
}

template <typename T>
void NodeList<T>::push_back(const T& e) {
    push(end(), e);
}

template <typename T>
void NodeList<T>::push(const Iterator& p, const T& e) {
    // link the new element between the positions
    Node* w = p.v;
    Node* u = w->prev;
    Node* v = new Node;
    v->elem = e;
    v->next = w; w->prev = v;
    v->prev = u; u->next = v; 
    n++;
}

template <typename T>
void NodeList<T>::pop_front() {
    pop(begin());
}

template <typename T>
void NodeList<T>::pop_back() {
    pop(--end());
}

template <typename T>
void NodeList<T>::pop(const Iterator& p) {
    // link out element on p position
    Node* v = p.v;
    Node* w = v->next;
    Node* u = v->prev;

    u->next = w;
    w->prev = u;

    delete v; // destructing the Node
    n--;
}

template <typename T>
NodeList<T>::Iterator::Iterator() {
    v = new Node();
}

template <typename T>
NodeList<T>::Iterator::Iterator(Node* u) {
    v = u;
}

template <typename T>
NodeList<T>::Iterator::Iterator(const Iterator& u) {
    copy(u);
}

template <typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator =(const Iterator& u) {
    copy(u);
    return *this;
}

template <typename T>
void NodeList<T>::Iterator::copy(const Iterator& u) {
    v = u.v;
}

template <typename T>
typename NodeList<T>::Iterator NodeList<T>::Iterator::operator ++(int) {
    // return and then move to next
    Iterator r = *this;
    ++*this;

    return r;
}

template <typename T>
typename NodeList<T>::Iterator NodeList<T>::Iterator::operator --(int) {
    // return and then move to previous
    Iterator r = *this;
    --*this;

    return r;
}

template <typename T>
T& NodeList<T>::Iterator::operator *() {
    return v->elem;
}

template <typename T>
bool NodeList<T>::Iterator::operator ==(const Iterator& p) const {
    return p.v == v;
}

template <typename T>
bool NodeList<T>::Iterator::operator !=(const Iterator& p) const {
    // compares only the value
    return p.v != v;
}

template <typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator ++() {
    // moves to the next and then returns (prefix)
    v = v->next;
    return *this;
}

template <typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator --() {
    // moves to the previous and then returns (prefix)
    v = v->prev;
    return *this;
}

#endif