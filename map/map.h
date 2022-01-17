#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <list>
#include <stdexcept>

using namespace std;

#include "../hashmap/entry.h"

class MapExcpt : public runtime_error {
    public:
        MapExcpt(const string& msg) : runtime_error(msg) {}
};

template <typename K, typename V>
class Map {
    public:
        typedef Entry<const K,V> Entry; // a (key,value) pair
        typedef list<Entry> List;
        typedef typename List::iterator Iterator; // an iterator (and position)
    public:
        int size() const { return L.size(); } // number of entries in the map
        bool empty() const { return size() == 0; } // is the map empty?
        Iterator find(const K& k); // find entry with key k
        Iterator put(const K& k, const V& v); // insert/replace pair (k,v)
        void erase(const K& k); // remove entry with key k
        void erase(const Iterator& p); // erase entry at p
        Iterator begin() { return L.begin(); } // iterator to first entry
        Iterator end() { return L.end(); }
    private:
        List L;
};

template <typename K, typename V>
typename Map<K, V>::Iterator Map<K, V>::find(const K& k) {
    Iterator result;
    for(result = begin(); result != end(); ++result) {
        if(result->key() == k) {
            break;
        }
    }
    return result;
}

template <typename K, typename V>
typename Map<K, V>::Iterator Map<K, V>::put(const K& k, const V& v) {
    bool found = false;
    Iterator result;
    for(result = begin(); !found && result != end(); ++result) {
        if(result->key() == k) {
            result->setValue(v);
            found = true;
        }
    }
    if(!found) {
        Entry ent(k, v);
        L.push_back(ent);
        result = L.end();

        --result;
    }
    return result;
}

template <typename K, typename V>
void Map<K, V>::erase(const K& k) {
    bool found = false;
    for(Iterator it = begin(); it != end() && !found; ++it) {
        if(it->key() == k) {
            found = true;
            L.erase(it);
        }
    }
    if(!found) {
        throw MapExcpt("Attempted to remove a non-existent key");
    }
}

template <typename K, typename V>
void Map<K, V>::erase(const Iterator& p) {
    if(p == L.end()) {
        throw MapExcpt("Attempted to remove the end position");
    }
    L.erase(p);
    p = L.end();
}

#endif