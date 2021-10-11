#ifndef ALGVECTOR_H
#define ALGVECTOR_H

#include "vector.h"

template <typename T>
class AlgVector : public Vector<T> {
    public:
        AlgVector(int numb) : Vector<T>(numb) {}
        AlgVector<T> operator +(const AlgVector<T> &v);
        AlgVector<T> operator -(const AlgVector<T> &v);
};

#endif