#ifndef HASHDICT_H
#define HASHDICT_H

#include "../hashmap/hashmap.h"

template <typename K, typename V, typename H>
class HashDict : public HashMap<K, V, H> {
    public:
        typedef typename HashMap<K, V, H>::Iterator Iterator;
        typedef typename HashMap<K, V, H>::Entry Entry;

        class Range {
            private:
                Iterator _begin;
                Iterator _end;
            public:
                Range(const Iterator& b, const Iterator& e) : _begin(b), _end(e) {}
                Iterator& begin() { return _begin; }
                Iterator& end() { return _end; }
        };
    public:
    HashDict(int capacity = 100) : HashMap<K, V, H>(capacity) {}
    Range findAll(const K& k);
    Iterator insert(const K& k, const V& v);
};

template <typename K, typename V, typename H>
typename HashDict<K, V, H>::Iterator HashDict<K, V, H>::insert(const K& k, const V& v) {
    Iterator p = finder(k);
    Iterator q = inserter(p, Entry(k, v));
    return q;
}

template <typename K, typename V, typename H>
typename HashDict<K, V, H>::Range HashDict<K, V, H>::findAll(const K& k) {
    Iterator b = finder(k);
    Iterator p = b;
    while(!endOfBkt(p) && (*p).key() == (*b).key()) {
        ++p;
    }
    return Range(b, p);
}

#endif