#ifndef LIST_H
#define LIST_H

template <typename T>
class NodeList {
    private:
        struct Node {
            T elem;
            Node* prev;
            Node* next;
        };
    public:
        class Iterator {
            public:
                Iterator();
                Iterator(Node* u);
                Iterator(const Iterator& u);
                T& operator*();
                bool operator ==(const Iterator& p) const;
                bool operator !=(const Iterator& p) const;
                Iterator& operator =(const Iterator& p);
                Iterator& operator ++(); // prefix
                Iterator& operator --(); // prefix
                Iterator operator ++(int); // postfix
                Iterator operator --(int); // postfix

                friend class NodeList;
            private:
                Node* v;
                void copy(const Iterator& u);
        };
    public:
        NodeList();
        ~NodeList();
        NodeList(const NodeList<T>& b);
        int size() const;
        bool empty() const;
        Iterator begin() const;
        Iterator end() const;
        void push_front(const T& e);
        void push_back(const T& e);
        void insert(const Iterator& p, const T& e);
        void pop_front();
        void pop_back();
        void erase(const Iterator& p);
        NodeList& operator =(const NodeList<T>& b);
    private: 
        int n;
        Node* header;
        Node* trailer;
        void copy(const NodeList<T>& b);
        void free();
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
    for(NodeList<T>::Iterator it = b.begin(); it != b.end(); ++it) {
        push_back(*it);
    }
}

template <typename T>
void NodeList<T>::free() {
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
    insert(begin(), e);
}

template <typename T>
void NodeList<T>::push_back(const T& e) {
    insert(end(), e);
}

template <typename T>
void NodeList<T>::insert(const Iterator& p, const T& e) {
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
    erase(begin());
}

template <typename T>
void NodeList<T>::pop_back() {
    erase(--end());
}

template <typename T>
void NodeList<T>::erase(const Iterator& p) {
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
    Iterator r = *this;
    ++*this;

    return r;
}

template <typename T>
typename NodeList<T>::Iterator NodeList<T>::Iterator::operator --(int) {
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
    return p.v != v;
}

template <typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator ++() {
    v = v->next;
    return *this;
}

template <typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator --() {
    v = v->prev;
    return *this;
}

#endif