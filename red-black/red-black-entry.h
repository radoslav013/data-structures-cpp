#ifndef RB_ENTRY_H
#define RB_ENTRY_H

enum Color {RED, BLACK}; // node colors

template <typename E>
class RBEntry : public E { // a red-black entry
    private:
        Color col; // node color
    protected: // local types
        typedef typename E::Key K; // key type
        typedef typename E::Value V; // value type
        Color color() const { return col; } // get color
        bool isRed() const { return col == RED; }
        bool isBlack() const { return col == BLACK; }
        void setColor(Color c) { col = c; }
    public: // public functions
        RBEntry(const K& k = K(), const V& v = V()) : E(k,v), col(BLACK) { }

    friend class RBTree<E>; // allow RBTree access
};

#endif