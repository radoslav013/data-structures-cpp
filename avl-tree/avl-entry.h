#ifndef AVL_ENTRY_H
#define AVL_ENTRY_H

template <typename E>
class AVLEntry : public E {
    private:
        int ht; // node height
    protected: // local types
        typedef typename E::Key K; // key type
        typedef typename E::Value V; // value type
        int height() const { return ht; } // get height
        void setHeight(int h) { ht = h; } // set height
    public: // public functions
        AVLEntry(const K& k = K(), const V& v = V()) : E(k,v), ht(0) { }

    friend class AVLTree<E>;
};

#endif