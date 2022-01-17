#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

template <typename E>
class RBTree;

#include "search-tree.h"
#include "red-black-entry.h"


template <typename E> // a red-black tree
class RBTree : public SearchTree< RBEntry<E> > {
    public: // public types
        typedef RBEntry<E> RBEntry; // an entry
        typedef typename SearchTree<RBEntry>::Iterator Iterator; // an iterator
    protected: // local types
        typedef typename RBEntry::Key K; // a key
        typedef typename RBEntry::Value V; // a value
        typedef SearchTree<RBEntry> ST; // a search tree
        typedef typename ST::TPos TPos; // a tree position
    public: // public functions
        RBTree(); // constructor
        Iterator insert(const K& k, const V& x); // insert (k,x)
        void erase(const K& k); // remove key k entry
        void erase(const Iterator& p); // remove entry at p
    protected: // utility functions
        void remedyDoubleRed(const TPos& z); // fix double-red z
        void remedyDoubleBlack(const TPos& r); // fix double-black r
        void setBlack(const TPos& v);
        void setRed(const TPos& v);
};

template <typename E>
void RBTree<E>::setBlack(const TPos& v) {
    (*v).setColor(Color.BLACK);
}

template <typename E>
void RBTree<E>::setRed(const TPos& v) {
    (*v).setColor(Color.RED);
}

template <typename E>
typename RBTree<E>::Iterator RBTree<E>::insert(const K& k, const V& x) {
    TPos v = ST::inserter(k, x); // insert in base tree
    if (v.isRoot())
        setBlack(v); // root is always black
    else {
        setRed(v);
        remedyDoubleRed(v); // rebalance if needed
    }
    return Iterator(v);
}

template <typename E>
void RBTree<E>::remedyDoubleRed(const TPos& z) {
    TPos v = z.parent(); // v is z’s parent
    if (v.isRoot() || (*v).isBlack()) return; // v is black, all ok
    // z, v are double-red
    if ((*ST::sibling(v)).isBlack()) { // Case 1: restructuring
        v = ST::restructure(z);
        setBlack(v); // top vertex now black
        setRed(v.left()); setRed(v.right()); // set children red
    } else { // Case 2: recoloring
        setBlack(v); setBlack(ST::sibling(v)); // set v and sibling black
        TPos u = v.parent(); // u is v’s parent
        if (u.isRoot()) return;
        setRed(u); // make u red
        remedyDoubleRed(u); // may need to fix u now
    }
}

template <typename E>
void RBTree<E>::erase(const K& k) {
    TPos u = finder(k, ST::root()); // find the node
    if (Iterator(u) == ST::end())
        throw runtime_error("Erase of nonexistent");
    TPos r = eraser(u); // remove u
    if (r == ST::root() || r->isRed() || wasParentRed(r))
        setBlack(r); // fix by color change
    else // r, parent both black
        remedyDoubleBlack(r); // fix double-black r
}

template <typename E>
void RBTree<E>::remedyDoubleBlack(const TPos& r) {
    TPos x = r.parent(); // r’s parent
    TPos y = sibling(r); // r’s sibling
    if (y->isBlack()) {
        if (y.left()->isRed() || y.right()->isRed()) { // Case 1: restructuring
            // z is y’s red child
            TPos z = (y.left()->isRed() ? y.left() : y.right());
            Color topColor = x->color(); // save top vertex color
            z = restructure(z); // restructure x,y,z
            setColor(z, topColor); // give z saved color
            setBlack(r); // set r black
            setBlack(z.left()); setBlack(z.right()); // set z’s children black
        }
        else { // Case 2: recoloring
            setBlack(r); setRed(y); // r=black, y=red
            if (x->isBlack() && !(x == ST::root()))
                remedyDoubleBlack(x); // fix double-black x
            setBlack(x);
        }
    }
    else { // Case 3: adjustment
        TPos z = (y == x.right() ? y.right() : y.left()); // grandchild on y’s side
        restructure(z); // restructure x,y,z
        setBlack(y); setRed(x); // y=black, x=red
        remedyDoubleBlack(r); // fix r by Case 1 or 2
    }
}

#endif