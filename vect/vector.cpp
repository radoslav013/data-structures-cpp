#include <iostream>

using namespace std;

#include "vector.h"

template <typename T>
Vector<T>::Vector(int numb) {
    this->numb = numb;
    ptr_arr = new T[this->numb];
}

template <typename T>
Vector<T>::~Vector() {
    free();
}

template <typename T>
Vector<T>::Vector(const Vector<T> &vect) {
    copy(vect);
}

template <typename T>
Vector<T> &Vector<T>::operator =(const Vector<T> &vect) {
    if(this != &vect) {
        free();
        copy(vect);
    }
    return *this;
}

template <typename T>
void Vector<T>::free() {
    if(ptr_arr) {
        delete[] ptr_arr;
        ptr_arr = nullptr;
    }
}

template <typename T>
void Vector<T>::copy(const Vector<T> &vect) {
    this->numb = vect.numb;

    ptr_arr = new T[this->numb];
    for(int i = 0; i < numb; i++) {
        ptr_arr[i] = vect.ptr_arr[i];
    }
}
