#ifndef CIRCULAR_ARRAY_SEQUENCE
#define CIRCULAR_ARRAY_SEQUENCE

#include <iostream>

using namespace std;

#include "array-sequence.h"

class CircularArraySequence : public ArraySequence {
    public:
        virtual void insertFront(int e);
        virtual void insertBack(int e);
        virtual void eraseFront();
        virtual void eraseBack();
};

void CircularArraySequence::insertFront(int e) {
    f--;
    Pair toInsert;
    toInsert.e = e;
    toInsert.i = f;
    A[f] = toInsert;
    n++;
}

void CircularArraySequence::insertBack(int e) {
    Pair toInsert;
    toInsert.e = e;
    toInsert.i = r;
    A[r] = toInsert;
    r++;
    n++;
}

void CircularArraySequence::eraseFront() {
    f = (f + 1) % n;
    n--;
}

void CircularArraySequence::eraseBack() {
    r--;
    n--;
}

#endif