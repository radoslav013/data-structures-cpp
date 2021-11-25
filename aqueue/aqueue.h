#ifndef AQUEUE_H
#define AQUEUE_H

#include "queue-empty.exception.h"
#include "queue-full.exception.h"

template <typename T>
class AQueue {
    public:
        AQueue();
        AQueue(const AQueue<T>& aq);
        void enqueue(const T& el);
        void dequeue();
        const T& front() const;
        int size() const;
        bool empty() const;
        AQueue<T>& operator =(const AQueue<T>& aq);
    private:
        enum {N = 256};
        T arr[N];
        int indx_frnt;
        int indx_rear;
        int n;

        void copy(const AQueue<T>& aq);
        void free();
};

template <typename T>
AQueue<T>::AQueue() {
    free();
}

template <typename T>
AQueue<T>::AQueue(const AQueue<T>& aq) {
    copy(aq);
}

template <typename T>
AQueue<T>& AQueue<T>::operator =(const AQueue<T>& aq) {
    free();
    copy();
    return *this;
}

template <typename T>
void AQueue<T>::free() {
    indx_frnt = 0;
    indx_rear = 0;
    n = 0;
}

template <typename T>
void AQueue<T>::copy(const AQueue<T>& aq) {
    indx_frnt = aq.indx_frnt;
    indx_rear = aq.indx_rear;
    n = aq.n;

    for(int i = indx_frnt; i < indx_rear; i++) {
        arr[i] = aq.arr[i];
    }
}

template <typename T>
void AQueue<T>::enqueue(const T& el) {
    if(n + 1 >= N) {
        throw QueueFull("full");
    }
    arr[indx_rear] = el;
    indx_rear = (indx_rear + 1) % N;
    n++;
}

template <typename T>
void AQueue<T>::dequeue() {
    if(n == 0) {
        throw QueueEmpty("empty");
    }
    indx_frnt = (indx_frnt + 1) % N;
    n--;
}

template <typename T>
int AQueue<T>::size() const {
    return n;
}

template <typename T>
bool AQueue<T>::empty() const {
    return size() == 0;
}
template <typename T>
const T& AQueue<T>::front() const {
    return arr[indx_frnt];
}


#endif