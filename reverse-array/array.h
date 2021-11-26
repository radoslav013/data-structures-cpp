#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

using namespace std;

template <typename T>
class Array {
    public:
        Array();
        Array(const T arr[], int size);
        int size() const;
        bool empty() const;
        void reverse();
        void shuffle();
        void rotate(int dist);
        void print() const;
        T& operator [](int indx);
    private:
        enum {N = 256};
        T arr[N];
        int n;
};

template <typename T>
Array<T>::Array() {
    n = 0;
}

template <typename T>
Array<T>::Array(const T arr[], int size) {
    n = size;
    for(int i = 0; i < n; i++) {
        this->arr[i] = arr[i];
    }
}

template <typename T>
int Array<T>::size() const {
    return n;
}

template <typename T>
bool Array<T>::empty() const {
    return size() == 0;
}

template <typename T>
T& Array<T>::operator [](int indx) {
    return arr[indx];
}

template <typename T>
void Array<T>::reverse() {
    for(int i = 0; i < n/2; i++) {
        T temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

template <typename T>
void Array<T>::shuffle() {

}

template <typename T>
void Array<T>::rotate(int dist) {
    for(int curr = 0; curr < n; curr++) {
        int destination = curr + dist; // 5
        if(destination >= n) {
            destination = destination - n;
        }
        T temp = arr[curr];
        arr[curr] = arr[destination];
        arr[destination] = temp;
    }
}

template <typename T>
void Array<T>::print() const {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
#endif