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
        RBTree() : ST() {} // constructor
        Iterator insert(const K& k, const V& x); // insert (k,x)
        void erase(const K& k); // remove key k entry
        void erase(const Iterator& p); // remove entry at p
    public: // utility functions TODO: make protected
        void remedyDoubleRed(const TPos& z); // fix double-red z
        void remedyDoubleBlack(const TPos& r); // fix double-black r
        void setBlack(const TPos& v);
        void setRed(const TPos& v);
        void setColor(TPos& v, Color col);             // Set color
        bool wasParentRed(TPos& v);                    // Check for red parent
        bool isBlack(const TPos& v);                         // Check for black
        bool isRed(const TPos& v);
        TPos sibling(const TPos& v);
        TPos restructure(const TPos& v); // restructure trinode
        K getKey(const TPos& v);
};

template <typename E>
typename RBTree<E>::K RBTree<E>::getKey(const TPos& v) {
    return v.element().key();
}

template <typename E>
typename RBTree<E>::TPos RBTree<E>::sibling(const TPos& v) {
    TPos parent = v.parent();
    if(getKey(v) == getKey(parent.left())) {
        return parent.right();
    } else {
        return parent.left();
    }
}

template <typename E>
typename RBTree<E>::TPos RBTree<E>::restructure(const TPos& v) {
    TPos x, y, z, a, b, c, T0, T1, T2, T3;

    x = v;
    y = x.parent(); // Parent of x
    z = y.parent(); // Parent of y (Grandparent of x)

    bool xIsLeftChild = (x.element().key() == y.left().element().key());
    bool yIsLeftChild = (y.element().key() == z.left().element().key());

    if (xIsLeftChild && yIsLeftChild) // Configuration 1
    {
        a = x;
        b = y;
        c = z;
        T0 = a.left();
        T1 = a.right();
        T2 = b.right();
        T3 = c.right();
    }
    else if (!xIsLeftChild && !yIsLeftChild) // Configuration 2
    {
        a = z;
        b = y;
        c = x;
        T0 = a.left();
        T1 = b.left();
        T2 = c.left();
        T3 = c.right();
    }
    else if(!xIsLeftChild && yIsLeftChild) // Configuration 3
    {
        a = y;
        b = x;
        c = z;
        T0 = a.left();
        T1 = b.left();
        T2 = b.right();
        T3 = c.right();
    }
    else // Configuration 4
    {
        a = z;
        b = x;
        c = y;
        T0 = a.left();
        T1 = b.left();
        T2 = b.right();
        T3 = c.right();
    }

    if(z.element().key() == ST::root().element().key())
    {
        ST::root() = b;
        b.parent() = NULL;
    }
    else
    {
        TPos zParent;
        zParent = z.parent();   // Find x's parent
        if ( zParent.left().element().key() == z.element().key() )
            zParent.setLeft(b);
        else
            zParent.setRight(b);
    }

    b.setLeft(a);
    a.setParent(b);
    b.setRight(c);
    c.setParent(b);

    a.setLeft(T0);
    if ( T0.element().key() != 0 )
        T0.setParent(a);

    a.setRight(T1);
    if ( T1.element().key() != 0 )
        T1.setParent(a);

    c.setLeft(T2);
    if ( T2.element().key() != 0 )
        T2.setParent(c);

    c.setRight(T3);
    if ( T3.element().key() != 0 )
        T3.setParent(c);

    return b;
}

template <typename E>
bool RBTree<E>::wasParentRed(TPos& v) {
    return v.parent().element().isRed();
}

template <typename E>
bool RBTree<E>::isBlack(const TPos& v) {
    return v.element().color() == BLACK;
}

template <typename E>
bool RBTree<E>::isRed(const TPos& v) {
     return v.element().color() == RED;
}

template <typename E>
void RBTree<E>::setColor(TPos& v, Color col) {
   v.element().setColor(col);
}

template <typename E>
void RBTree<E>::setBlack(const TPos& v) {
    v.element().setColor(BLACK);
}

template <typename E>
void RBTree<E>::setRed(const TPos& v) {
    v.element().setColor(RED);
}

template <typename E>
typename RBTree<E>::Iterator RBTree<E>::insert(const K& k, const V& x) {
    TPos v = ST::inserter(k, x); // insert in base tree
    
    if (v == ST::root()){
        setBlack(v); // root is always black
    } else {
        setRed(v);
        remedyDoubleRed(v); // rebalance if needed
    }
    return Iterator(v);
}

template <typename E>
void RBTree<E>::remedyDoubleRed(const TPos& z) {
    TPos v = z.parent(); // v is z’s parent
    TPos sib = sibling(v);
    if (v == ST::root() || (*v).isBlack()) return; // v is black, all ok
    // z, v are double-red
    if (sibling(v).element().isBlack()) { // Case 1: restructuring
        v = restructure(z);
        setBlack(v); // top vertex now black
        setRed(v.left()); setRed(v.right()); // set children red
    } else { // Case 2: recoloring
        setBlack(v); setBlack(sibling(v)); // set v and sibling black
        TPos u = v.parent(); // u is v’s parent
        if (u == ST::root()) return;
        setRed(u); // make u red
        remedyDoubleRed(u); // may need to fix u now
    }
}

template <typename E>
void RBTree<E>::erase(const K& k) {
    TPos u = ST::finder(k, ST::root()); // find the node
    if (Iterator(u) == ST::end())
        throw runtime_error("Erase of nonexistent");
    TPos r = ST::eraser(u); // remove u
    if (r == ST::root() || r.element().isRed() || wasParentRed(r))
        setBlack(r); // fix by color change
    else // r, parent both black
        remedyDoubleBlack(r); // fix double-black r
}

template <typename E>
void RBTree<E>::erase(const Iterator& p) {
    erase((*p).key());
}

template <typename E>
void RBTree<E>::remedyDoubleBlack(const TPos& r) {
    TPos x = r.parent(); // r’s parent
    TPos y = sibling(r); // r’s sibling
    if (y.element().isBlack()) {
        if (y.left().element().isRed() || y.right().element().isRed()) { // Case 1: restructuring
            // z is y’s red child
            TPos z = (y.left().element().isRed() ? y.left() : y.right());
            Color topColor = x.element().color(); // save top vertex color
            z = restructure(z); // restructure x,y,z
            setColor(z, topColor); // give z saved color
            setBlack(r); // set r black
            setBlack(z.left()); setBlack(z.right()); // set z’s children black
        }
        else { // Case 2: recoloring
            setBlack(r); setRed(y); // r=black, y=red
            if (x.element().isBlack() && !(x == ST::root()))
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