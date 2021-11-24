#ifndef ARRAY_SEQUENCE_H
#define ARRAY_SEQUENCE_H

#include <iostream>

using namespace std;

class ArraySequence {
    private:
        struct Pair {
            int i;
            int e;
        };
    public:
        class Iterator {
            public:
                Iterator(const ArraySequence* o);
                Iterator(Pair* u, const ArraySequence* o);
                Iterator(const Iterator& u, const ArraySequence* o);
                int& operator*();
                bool operator ==(const Iterator& p) const;
                bool operator !=(const Iterator& p) const;
                Iterator& operator =(const Iterator& p);
                Iterator& operator ++(); // prefix
                Iterator& operator --(); // prefix
                Iterator operator ++(int); // postfix
                Iterator operator --(int); // postfix

                friend class ArraySequence;
            private:
                Pair* el;
                const ArraySequence* outer;
                void copy(const Iterator& u);
        };
    public:
        ArraySequence();
        ~ArraySequence();
        int size() const;
        bool empty() const;
        Iterator atIndex(int i) const;
        int indexOf(const Iterator& it) const;
        Iterator begin() const;
        Iterator end() const;
        void insertFront(int e);
        void insertBack(int e);
        void insert(const Iterator& it, int e);
        void eraseFront();
        void eraseBack();
        void erase(const Iterator& it);
        void print() const;
    private:
        Pair* A;
        int n; // size of sequence
        int f; // index of first element
        int r; // index of element after the last
        void free();
};

ArraySequence::ArraySequence() {
    A = new Pair[NULL];
    n = 0;
    f = 0;
    r = 0;
}

ArraySequence::~ArraySequence() {
    free();
}

int ArraySequence::size() const {
    return n;
}

bool ArraySequence::empty() const {
    return size() == 0;
}

ArraySequence::Iterator ArraySequence::atIndex(int i) const {
    Pair* a = &A[i]; 
    ArraySequence::Iterator it(a, this);
    return it;
}

int ArraySequence::indexOf(const Iterator& it) const {
    return it.el->i;
}

ArraySequence::Iterator ArraySequence::begin() const {
    return atIndex(f);
}

ArraySequence::Iterator ArraySequence::end() const {
    Pair* a = &A[r]; 
    a->i = r;
    ArraySequence::Iterator it(a, this);
    return it;
}

void ArraySequence::insertFront(int e) {
    insert(begin(), e);
}

void ArraySequence::insertBack(int e) {
    insert(end(), e);
}

void ArraySequence::insert(const Iterator& it, int e) {
    int indx = indexOf(it);
    Pair toInsert;
    toInsert.e = e;
    toInsert.i = indx;

    int curr = r;
    while(curr != indx) {
        A[curr] = A[curr-1];
        A[curr].i = curr;
        --curr;
    }

    A[indx] = toInsert;
    n++;
    r++;
}

void ArraySequence::print() const {
    Iterator it = begin();
    while(it != end()) {
        cout << it.el->i << ": " << it.el->e << endl;
        ++it;
    }
}

void ArraySequence::eraseFront() {
    erase(begin());
}

void ArraySequence::eraseBack() {
    erase(end());
}

void ArraySequence::erase(const Iterator& it) {
    int indx = indexOf(it);

    int curr = indx;
    while(curr != r) {
        A[curr] = A[curr+1];
        A[curr].i = curr;
        ++curr;
    }

    n--;
    r--;
}

void ArraySequence::free() {
    if(A) {
        delete[] A;
        A = nullptr;
    }
}


// Iterator
ArraySequence::Iterator::Iterator(const ArraySequence* o) {
    el = new Pair();
    outer = o;
}

ArraySequence::Iterator::Iterator(Pair* u, const ArraySequence* o) {
    el = u;
    outer = o;
}

ArraySequence::Iterator::Iterator(const Iterator& u, const ArraySequence* o) {
    copy(u);
}

void ArraySequence::Iterator::copy(const Iterator& u) {
    el = u.el;
}

int& ArraySequence::Iterator::operator *() {
    return el->e;
}

bool ArraySequence::Iterator::operator ==(const Iterator& p) const {
    return el == p.el;
}

bool ArraySequence::Iterator::operator !=(const Iterator& p) const {
    return el != p.el;
}

ArraySequence::Iterator& ArraySequence::Iterator::operator =(const Iterator& p) {
    copy(p);
    return *this;
}


ArraySequence::Iterator& ArraySequence::Iterator::operator ++() {
    el = &outer->A[el->i + 1];
    return *this;
} // prefix

ArraySequence::Iterator& ArraySequence::Iterator::operator --() {
    el = &outer->A[el->i - 1];
    return *this;
} // prefix

ArraySequence::Iterator ArraySequence::Iterator::operator ++(int) {
    Iterator temp = *this;
    ++*this;
    return temp;
} // postfix

ArraySequence::Iterator ArraySequence::Iterator::operator --(int) {
    Iterator temp = *this;
    --*this;
    return temp;
} // postfix


#endif
