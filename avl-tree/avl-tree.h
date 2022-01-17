#ifndef AVL_TREE_H
#define AVL_TREE_H

template <typename E>
class AVLTree;

#include "../search-tree/search-tree.h"
#include "avl-entry.h"

template <typename E>
class AVLTree : public SearchTree< AVLEntry<E> > {
    public:
        typedef AVLEntry<E> AVLEntry; // an entry
        typedef typename SearchTree<AVLEntry>::Iterator Iterator; // an iterator
    protected: // local types
        typedef typename AVLEntry::Key K; // a key
        typedef typename AVLEntry::Value V; // a value
        typedef SearchTree<AVLEntry> ST; // a search tree
        typedef typename ST::TPos TPos; // a tree position
    public: // public functions
        AVLTree() : ST() { } // constructor
        Iterator insert(const K& k, const V& x); // insert (k,x)
        void erase(const K& k); // remove key k entry
        void erase(const Iterator& p); // remove entry at p
    protected: // utility functions
        int height(const TPos& v) const { return (v.isExternal() ? 0 : v.getValue().height()); }; // node height utility
        void setHeight(TPos v); // set height utility
        bool isBalanced(const TPos& v) const; // is v balanced?
        TPos tallGrandchild(const TPos& v) const; // get tallest grandchild
        void rebalance(const TPos& v); // rebalance utility
};

template <typename E>
void AVLTree<E>::setHeight(TPos v) {
    int hl = height(v.getLeft());
    int hr = height(v.getRight());
    (*v).setHeight(1 + std::max(hl, hr)); // max of left & right
}

template <typename E>
bool AVLTree<E>::isBalanced(const TPos& v) const {
    int bal = height(v.getLeft()) - height(v.getRight());
    return ((-1 <= bal) && (bal <= 1));
}

template <typename E>
typename AVLTree<E>::TPos AVLTree<E>::tallGrandchild(const TPos& z) const {
    TPos zl = z.getLeft();
    TPos zr = z.getRight();
    if (height(zl) >= height(zr)) // left child taller
        if (height(zl.getLeft()) >= height(zl.getRight()))
            return zl.getLeft();
        else
            return zl.getRight();
    else // right child taller
        if (height(zr.getRight()) >= height(zr.getLeft()))
            return zr.getRight();
        else
            return zr.getLeft();
}

template <typename E>
void AVLTree<E>::rebalance(const TPos& v) {
    TPos z = v;
    while (!z.isRoot()) { // rebalance up to root
        z = z.parent();
        setHeight(z); // compute new height
        if (!isBalanced(z)) { // restructuring needed
            TPos x = tallGrandchild(z);
            z = ST::restructure(x); // trinode restructure
            setHeight(z.getLeft()); // update heights
            setHeight(z.getRight());
            setHeight(z);
        }
    }
}

template <typename E>
typename AVLTree<E>::Iterator AVLTree<E>::insert(const K& k, const V& x) {
    TPos v = ST::inserter(k, x); // insert in base tree
    setHeight(v); // compute its height
    rebalance(v); // rebalance if needed
    return Iterator(v);
}

template <typename E>
void AVLTree<E>::erase(const K& k) {
    TPos v = finder(k, ST::root()); // find in base tree
    if (Iterator(v) == ST::end()) // not found?
        throw runtime_error("Erase of nonexistent");
    TPos w = eraser(v); // remove it
    rebalance(w); // rebalance if needed
}

template <typename E>
void AVLTree<E>::erase(const Iterator& p) {
    erase(p.v);
}

#endif