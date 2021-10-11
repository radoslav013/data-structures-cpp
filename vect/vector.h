#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

template <typename T>
class Vector {
    public:
        Vector(int numb);
        virtual ~Vector();
        Vector(const Vector &vect);
        Vector &operator =(const Vector &vect);
    protected:
        int numb;
        int* ptr_arr;
    private:

        void free();
        void copy(const Vector &vect);

    friend istream &operator >>(istream &in, Vector &vect);
    friend ostream &operator <<(ostream &out, const Vector &vect);
};

#endif