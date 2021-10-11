#include <iostream>

using namespace std;

#include "vector.cpp"
#include "algvector.cpp"

int main() {

    AlgVector<int> v1(3);
    cin >> v1;

    AlgVector<int> v2(4);
    cin >> v2;

    // cout << v1 - v2 << endl;
    return 0;
}