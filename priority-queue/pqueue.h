#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <iostream>
#include <stdexcept>
#include <list>

using namespace std;

class PQueueExcpt : public runtime_error {
    public:
        PQueueExcpt(const string& msg) : runtime_error(msg) {}
};

template <typename Tk, typename Tv>
class ListPriorityQueue {
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
        list<pair<Tk, Tv>> L; // std::list, for keeping the elements.
        void copy(const ListPriorityQueue<Tk, Tv>& pq); // copies all elements from on priority queue to another
};

template <typename Tk, typename Tv>
ListPriorityQueue<Tk, Tv>::~ListPriorityQueue() {
    L.~list<pair<Tk, Tv>>();
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
    typename list<pair<Tk, Tv>>::iterator p;
    p = L.begin();
    while(p != L.end() && k > (*p).first) ++p;
    pair<Tk, Tv> toInsert(k, v);
    L.insert(p, toInsert);
} // insert

template <typename Tk, typename Tv>
const Tv& ListPriorityQueue<Tk, Tv>::min() const {
    if(!empty()) {
        return L.front().second;
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