
#include "vector.h"
#include "algvector.h"

template <typename T>
AlgVector<T> AlgVector<T>::operator +(const AlgVector<T> &v) {
    AlgVector result(v.numb);
    for (int i = 0; i < v.numb; i++){
       result.ptr_arr[i] = v.ptr_arr[i] + this->ptr_arr[i];
    }
    return result;
}

template <typename T>
AlgVector<T> AlgVector<T>::operator -(const AlgVector<T> &v) {
    AlgVector<T> result(v.numb);
    for (int i = 0; i < v.numb; i++){
       result.ptr_arr[i] = v.ptr_arr[i] - this->ptr_arr[i];
    }
    return result;
}