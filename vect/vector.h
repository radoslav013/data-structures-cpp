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

#endif