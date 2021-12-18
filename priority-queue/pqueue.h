#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <iostream>
#include <list>

using namespace std;

template <typename Tk, typename Tv>
class ListPriorityQueue {
    public:
        ListPriorityQueue() {};
        ~ListPriorityQueue();
        ListPriorityQueue(const ListPriorityQueue<Tk, Tv>& pq);
        ListPriorityQueue<Tk, Tv>& operator =(const ListPriorityQueue<Tk, Tv>& pq);
        int size() const;
        bool empty() const;
        void insert(const Tk& k, const Tv& v);
        const Tv& min() const;
        void removeMin();
    private:
        list<pair<Tk, Tv>> L;
        void copy(const ListPriorityQueue<Tk, Tv>& pq);
};

template <typename Tk, typename Tv>
ListPriorityQueue<Tk, Tv>::~ListPriorityQueue() {
    L.~list<pair<Tk, Tv>>();
}

template <typename Tk, typename Tv>
ListPriorityQueue<Tk, Tv>::ListPriorityQueue(const ListPriorityQueue<Tk, Tv>& pq) {
    copy(pq);
}

template <typename Tk, typename Tv>
ListPriorityQueue<Tk, Tv>& ListPriorityQueue<Tk, Tv>::operator =(const ListPriorityQueue<Tk, Tv>& pq) {
    copy(pq);
}

template <typename Tk, typename Tv>
void ListPriorityQueue<Tk, Tv>::copy(const ListPriorityQueue<Tk, Tv>& pq) {
    L = pq.L;
}


template <typename Tk, typename Tv>
int ListPriorityQueue<Tk, Tv>::size() const {
    return L.size();
}

template <typename Tk, typename Tv>
bool ListPriorityQueue<Tk, Tv>::empty() const {
    return size() == 0;
}

template <typename Tk, typename Tv>
void ListPriorityQueue<Tk, Tv>::insert(const Tk& k, const Tv& v) {
    typename list<pair<Tk, Tv>>::iterator p;
    p = L.begin();
    while(p != L.end() && k > (*p).first) ++p;
    pair<Tk, Tv> toInsert(k, v);
    L.insert(p, toInsert);
}

template <typename Tk, typename Tv>
const Tv& ListPriorityQueue<Tk, Tv>::min() const {
    return L.front().second;
}

template <typename Tk, typename Tv>
void ListPriorityQueue<Tk, Tv>::removeMin() {
    L.pop_front();
}

#endif