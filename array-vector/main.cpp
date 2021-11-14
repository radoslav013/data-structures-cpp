#include <iostream>

using namespace std;

#include "array-vector.h"

int main() {
    // ArrayVector<int>* a = new ArrayVector<int>();
    // a->reserve(3);
    // a->insert(0, 5);
    // a->insert(0, 6);

    // cout << a->at(0) << endl;
    // a[0] = 5;
    // cout << a->at(0) << endl;

    ArrayVector<int> b;
    b.reserve(2);
    b.insert(0, 5);
    b.insert(0, 6);

    cout << b.at(0) << endl;
    b[0] = 5;
    cout << b.at(0) << endl;


    return 0;
}