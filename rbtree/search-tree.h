#ifndef SEARCH_TREE_H
#define SEARCH_TREE_H

#include <iostream>

using namespace std;

#include "linked-binary-tree.h"

template <typename E>
class SearchTree {
    public:
        typedef typename E::Key K;
        typedef typename E::Value V;
        class Iterator;
    public: // public functions
        SearchTree(): T(), n(0) { T.addRoot(); T.expandExternal(T.root()); } // constructor
        int size() const { return n; } // number of entries
        bool empty() const { return size() == 0; } // is the tree empty?
        Iterator find(const K& k); // find entry with key k
        Iterator insert(const K& k, const V& x); // insert (k,x)
        void erase(const K& k); // remove key k entry
        void erase(const Iterator& p); // remove entry at p
        Iterator begin(); // iterator to first entry
        Iterator end() { return Iterator(T.root()); }  // iterator to end entry
        void print() const { T.print(); }
    public: // local utilities TODO: make protected
        typedef LinkedBinaryTree<E> BinaryTree; // linked binary tree
        typedef typename BinaryTree::Position TPos; // position in the tree

        TPos root() const { return T.root().left(); }  // get virtual root
        TPos finder(const K& k, const TPos& v); // find utility
        TPos inserter(const K& k, const V& x); // insert utility
        TPos eraser(TPos& v); // erase utility
    private: // member data
        BinaryTree T; // the binary tree
        int n;
    public:
        class Iterator { // an iterator/position
            private:
                TPos v; // which entry
            public:
                Iterator(const TPos& vv) : v(vv) { } // constructor
                const E& operator*() const { return v.element(); } // get entry (read only)
                // E& operator*() { return *v; } // get entry (read/write)
                bool operator==(const Iterator& p) const { return v == p.v; }
                Iterator& operator++(); // inorder successor

            friend class SearchTree; // give search tree access
        };
};

template <typename E>
typename SearchTree<E>::Iterator& SearchTree<E>::Iterator::operator++() {
    TPos w = v.right();
    if (w.isInternal()) { // have right subtree?
        do { v = w; w = w.left(); } // move down left chain
        while (w.isInternal());
    } else {
        w = v.parent(); // get parent
        while (v == w.right()) {  // move up right chain
            v = w; w = w.parent();
        }
        v = w; // and first link to left
    }
    return *this;
}

template <typename E>
typename SearchTree<E>::Iterator SearchTree<E>::begin() {
    TPos v = root(); // start at virtual root
    while (v.isInternal()) v = v.left(); // find leftmost node
    return Iterator(v.parent());
}

template <typename E>
typename SearchTree<E>::TPos SearchTree<E>::finder(const K& k, const TPos& v) {
    E ent = v.element();
    if (v.isExternal()) return v; // key not found
    if (k < ent.key()) return finder(k, v.left()); // search left subtree
    else if (ent.key() < k) return finder(k, v.right()); // search right subtree
    else return v; // found it here
}

template <typename E>
typename SearchTree<E>::Iterator SearchTree<E>::find(const K& k) {
    TPos v = finder(k, root()); // search from virtual root
    if (v.isInternal()) return Iterator(v); // found it
    else return end(); // didn’t find it
}

template <typename E>
typename SearchTree<E>::TPos SearchTree<E>::inserter(const K& k, const V& x) {
    TPos v = finder(k, root()); // search from virtual root
    while (v.isInternal()) // key already exists?
        v = finder(k, v.right()); // look further
    T.expandExternal(v); // add new internal node
    v.element().setKey(k); 
    v.element().setValue(x); // set entry
    n++; // one more entry
    return v; // return insert position
}

template <typename E>
typename SearchTree<E>::Iterator SearchTree<E>::insert(const K& k, const V& x) {
    TPos v = inserter(k, x);
    return Iterator(v);
}

template <typename E>
typename SearchTree<E>::TPos SearchTree<E>::eraser(TPos& v) {
    TPos w;
    if (v.left().isExternal()) w = v.left(); // remove from left
    else if (v.right().isExternal()) w = v.right(); // remove from right
    else { // both internal?
        w = v.right(); // go to right subtree
        do { w = w.left(); } while (w.isInternal()); // get leftmost node
        TPos u = w.parent();
        v.element().setKey(u.element().key()); 
        v.element().setValue(u.element().value()); // copy w’s parent to v
    }
    n--; // one less entry
    return T.removeAboveExternal(w); // remove w and parent
}

template <typename E>
void SearchTree<E>::erase(const K& k) {
    TPos v = finder(k, root()); // search from virtual root
    if (v.isExternal()) // not found?
        throw TreeExcept("Erase of nonexistent");
    eraser(v); // remove it
}

template <typename E>
void SearchTree<E>::erase(const Iterator& p) {
    eraser(p.v);
}

#endif