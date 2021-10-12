#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

template <typename T>
class Vector {
    public:
        Vector(int numb);
        virtual ~Vector();
        Vector(const Vector<T> &vect);
        Vector &operator =(const Vector<T> &vect);
    protected:
        int numb;
        T* ptr_arr;
        void initArr();
        void free();
        void copy(const Vector<T> &vect);

    friend ostream &operator <<(ostream &out, const Vector<T> &vect) {
        out << "Size: " << vect.numb << endl;

        for(int i = 0; i < vect.numb; i++) {
            out << vect.ptr_arr[i] << " ";
        }

        out << endl;
        return out;
    }
    
    friend istream &operator >>(istream &in, Vector<T> &vect) {
        vect.free();

        in >> vect.numb;
        vect.ptr_arr = new T[vect.numb];
        for(int i = 0; i < vect.numb; i++) {
            in >> vect.ptr_arr[i];
        }
        return in;
    }
};

template <typename T>
Vector<T>::Vector(int numb) {
    this->numb = numb;
    initArr();
}

template <typename T>
void Vector<T>::initArr() {
    try {
        ptr_arr = new T[this->numb];
    } catch(bad_alloc &excpt) {
        cout << excpt.what() << endl;
		throw;
    }
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

    initArr();
    for(int i = 0; i < numb; i++) {
        ptr_arr[i] = vect.ptr_arr[i];
    }
}

#endif