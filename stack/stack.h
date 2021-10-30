#ifndef STACK_H
#define STACK_H

const int MAX = 100000;
template <typename T>
class Stack {
    public:
        Stack();
        ~Stack();
        int size() const;
        bool empty() const;
        const T& top() const;
        void push(const T& el);
        void pop();
        void clear();
    private:
        T* elements;
        int t;
};

template<typename T>
Stack<T>::Stack() {
    elements = new T[MAX];
    t = -1;
}

template<typename T>
Stack<T>::~Stack() {
    if(elements) {
        delete[] elements;
        elements = nullptr;
    }
}

template<typename T>
int Stack<T>::size() const {
    return t + 1;
}

template<typename T>
bool Stack<T>::empty() const {
    return t == -1;
}

template<typename T>
const T& Stack<T>::top() const {
    return elements[t];
}

template<typename T>
void Stack<T>::push(const T& el) {
    elements[++t] = el;
    
}

template<typename T>
void Stack<T>::pop() {
    if(empty()) return;
    --t;
}

template<typename T>
void Stack<T>::clear() {
    if(!empty()) {
        pop();
        clear();
    }
}

#endif