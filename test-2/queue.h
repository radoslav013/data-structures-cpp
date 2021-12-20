#ifndef QUEUE_H
#define QUEUE_H

#include "circular-linked-list.h"

//! Queue based on circular linked list
/*!
    Queue based on circular linked list
    \tparam T    type of the elements 
 */
template <typename T>
class Queue : protected CircularLinkedList<T> {
    public:
        //! Constructor
        /*!
            Constructor on empty queue
        */
        Queue() : CircularLinkedList<T>(), n(0) {};

        //! Copy Constructor
        /*!
            Constructor on empty queue based on another queue
            \param q         queue to copy
        */
        Queue(Queue<T>& q);

        //! Assignment operator
        /*!
            Overload assignment operator
            \param q         queue to copy
        */
        Queue<T>& operator =(Queue<T>& q);

        //! Equeue/add
        /*!
            Add element to the back
            \param el         element to add
        */
        void enqueue(const T& el);

        //! Dequeue/remove
        /*!
            Remove the oldest inserted element
        */
        void dequeue();

        //! Get the oldest inserted element
        /*!
            Returns the oldest element in the queue
            \return                 value of oldest element
        */
        const T& front() const;

        //! Size
        /*!
            Returns size
            \return                 size
        */
        int size() const;

        //! Empty
        /*!
            Returns if empty
            \return                 empty
        */
        bool empty() const;
    private:
        //! Element count
        /*!
            Element count
        */
        int n;

        //! Copy elements
        /*!
            Copy elements from another Queue
            \param q         queue to copy from
        */
        void copy(Queue<T>& q);

        //! Free/set to default
        /*!
            free queue
        */
        void free();
};

template <typename T>
void Queue<T>::enqueue(const T& el) {
    // Add and advance the cursor to the just inserted element
    this->add(el);
    this->advance();
    n++;
} // enqueue

template <typename T>
void Queue<T>::dequeue() {
    this->remove();
    n--;
} // dequeue

template <typename T>
const T& Queue<T>::front() const {
    return this->next();
} // front

template <typename T>
Queue<T>::Queue(Queue<T>& q) {
    free();
    copy(q);
} // copy constructor

template <typename T>
Queue<T>& Queue<T>::operator =(Queue<T>& q) {
    free();
    copy(q);

    return *this;
} // overloaded assignment operator

template <typename T>
void Queue<T>::copy(Queue<T>& q) {
    // Use a temporary queue to store the elements and then reinsert them in the original queue
    Queue<T> temp;
    int elements = q.n;
    while(n < elements) {
        temp.enqueue(q.front());
        enqueue(q.front());
        q.dequeue();
    }
    while(temp.n > 0) {
        q.enqueue(temp.front());
        temp.dequeue();
    }
} // copy

template <typename T>
void Queue<T>::free() {
    n = 0;
    while(!empty()) {
        dequeue();
    }
} // free

template <typename T>
int Queue<T>::size() const {
    return n;
} // size

template <typename T>
bool Queue<T>::empty() const {
    return size() == 0;
} // empty

#endif