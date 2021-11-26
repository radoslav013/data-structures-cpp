#include <iostream>

using namespace std;

#include "array.h"

int main() {
    int a[] = {12, 13, 14, 15, 16};
    Array<int> arr(a, sizeof(a) / sizeof(a[0]));

    // arr.reverse();
    // cout << arr[3] << endl;
    arr.rotate(1);
    arr.print();
    return 0;
}