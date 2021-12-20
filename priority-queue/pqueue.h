#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include <stdexcept>

#include "list.h"

using namespace std;

class PQueueExcpt : public runtime_error {
    public:
        PQueueExcpt(const string& msg) : runtime_error(msg) {}
};

template <typename Tk, typename Tv>
class ListPriorityQueue {
    public:
        struct LPNode {
            Tk key;
            Tv value;
        };
    public:
        ListPriorityQueue() {}; // default contructor
        ~ListPriorityQueue(); // desctructor
        ListPriorityQueue(const ListPriorityQueue<Tk, Tv>& pq); // copy constructor
        ListPriorityQueue<Tk, Tv>& operator =(const ListPriorityQueue<Tk, Tv>& pq); // overloaded assignment operator
        int size() const; // returns the size
        bool empty() const; // returns if empty
        void insert(const Tk& k, const Tv& v); // inserts element with key k and value v
        const Tv& min() const; // returns the minimum value based on the prioritisation
        void removeMin(); // removes the element returned by min()
    private:
        NodeList<LPNode> L; // std::list custom, for keeping the elements.
        void copy(const ListPriorityQueue<Tk, Tv>& pq); // copies all elements from on priority queue to another
};

template <typename Tk, typename Tv>
ListPriorityQueue<Tk, Tv>::~ListPriorityQueue() {
    L.~NodeList<LPNode>();
} // destructor

template <typename Tk, typename Tv>
ListPriorityQueue<Tk, Tv>::ListPriorityQueue(const ListPriorityQueue<Tk, Tv>& pq) {
    copy(pq);
} // copy constructor

template <typename Tk, typename Tv>
ListPriorityQueue<Tk, Tv>& ListPriorityQueue<Tk, Tv>::operator =(const ListPriorityQueue<Tk, Tv>& pq) {
    copy(pq);
} // overloaded assignment operator

template <typename Tk, typename Tv>
void ListPriorityQueue<Tk, Tv>::copy(const ListPriorityQueue<Tk, Tv>& pq) {
    L = pq.L;
} // copy

template <typename Tk, typename Tv>
int ListPriorityQueue<Tk, Tv>::size() const {
    return L.size();
} // returns size

template <typename Tk, typename Tv>
bool ListPriorityQueue<Tk, Tv>::empty() const {
    return size() == 0;
} // returns if empty

template <typename Tk, typename Tv>
void ListPriorityQueue<Tk, Tv>::insert(const Tk& k, const Tv& v) {
    typename NodeList<LPNode>::Iterator p;
    p = L.begin();
    while(p != L.end() && k > (*p).key) ++p;
    LPNode lpnode;
    lpnode.key = k;
    lpnode.value = v;
    L.insert(p, lpnode);
} // insert

template <typename Tk, typename Tv>
const Tv& ListPriorityQueue<Tk, Tv>::min() const {
    if(!empty()) {
        typename NodeList<LPNode>::Iterator s = L.begin();
        return (*s).value;
    }
    throw PQueueExcpt("Priority queue is empty");
} // returns min

template <typename Tk, typename Tv>
void ListPriorityQueue<Tk, Tv>::removeMin() {
    if(!empty()) {
        L.pop_front();
    } else {
        throw PQueueExcpt("Priority queue is empty");
    }
} // removes min

#endif