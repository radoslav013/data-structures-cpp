#include <iostream>

using namespace std;

void swapArr(int arr[], int start, int end) {
    if(start < end) {
        swap(arr[start], arr[end]);
        swapArr(arr, start+1, end-1);
    } else {
        // trivial case / base case
    }
}

void printArr(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void iterativeSwapArr(int arr[], int start, int end) {
    while(start < end) {
        swap(arr[start], arr[end]);
        ++start;
        --end;
    }
}

int main() {
    int a[] = {5, 6, 7, 8, 9};
    int size = sizeof(a)/sizeof(a[0]);

    // Iterative
    // iterativeSwapArr(a, 0, size - 1);
    // printArr(a, size);

    // Recursive
    swapArr(a, 0, size - 1);
    printArr(a, size);
    return 0;
}