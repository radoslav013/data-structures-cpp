#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <list>

using namespace std;

#include "../hashmap/entry.h"

template <typename K, typename V>
class Map {
    public:
        typedef Entry<const K,V> Entry; // a (key,value) pair
        typedef list<Entry> List;
        typedef typename List::iterator Iterator; // an iterator (and position)
    public:
        int size() const { return n; } // number of entries in the map
        bool empty() const { return size() == 0; } // is the map empty?
        Iterator find(const K& k); // find entry with key k
        Iterator put(const K& k, const V& v); // insert/replace pair (k,v)
        void erase(const K& k); // remove entry with key k
        void erase(const Iterator& p); // erase entry at p
        Iterator begin() { return L.begin(); } // iterator to first entry
        Iterator end() { return L.end(); }
    private:
        List L;
        int n;
};

template <typename K, typename V>
typename Map<K, V>::Iterator Map<K, V>::find(const K& k) {
    for(Iterator it = begin(); it != end(); ++it) {
        if((*it).key() == k) {
            return it;
        }
    }
    throw runtime_error("No key found");
}

template <typename K, typename V>
typename Map<K, V>::Iterator Map<K, V>::put(const K& k, const V& v) {
    for(Iterator it = begin(); it != end(); ++it) {
        if((*it).key() == k) {
            (*it).setValue(v);
            return it;
        }
    }
    Entry ent(k, v);
    L.push_back(ent);
    n++;

    Iterator added = end();
    return --added;
}

template <typename K, typename V>
void Map<K, V>::erase(const K& k) {
    for(Iterator it = begin(); it != end(); ++it) {
        if((*it).key() == k) {
            L.erase(it);
            --n;
        }
    }
}

template <typename K, typename V>
void Map<K, V>::erase(const Iterator& p) {
    L.erase(p);
    --n;
}

#endif