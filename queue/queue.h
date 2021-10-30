#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {
    public:
        Queue(int MAX = 100);
        ~Queue();
        void enqueue(const T& el); // inserts at the rear
        void dequeue(); // removes from the front
        const T& front() const; // returns the most front element
        int size() const;
        bool empty() const;
    private:
        T* elements;
        int n;
        int f;
        int r;
        int N;
};

template <typename T>
Queue<T>::Queue(int MAX) {
    elements = new T[MAX];
    n = 0;
    r = 0;
    f = 0;
    N = MAX;
}

template <typename T>
Queue<T>::~Queue() {
    if(elements) {
        delete[] elements;
        elements = nullptr;
    }
}

template <typename T>
void Queue<T>::enqueue(const T& el) {
    elements[r] = el;
    r = (r + 1) % N;
    n++;
}

template <typename T>
void Queue<T>::dequeue() {
    n--;
    f = (f+1) % N;
}

template <typename T>
const T& Queue<T>::front() const {
    return elements[f];
}

template <typename T>
int Queue<T>::size() const {
    return n;
}

template <typename T>
bool Queue<T>::empty() const {
    return size() == 0;
}

#endif