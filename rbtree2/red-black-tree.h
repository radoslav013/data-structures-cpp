#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <iostream>
#include <stdexcept> // for runtime_error

using namespace std;

//! Tree exception class
/*!
    Custom Exception class for tree exceptions, extending runtime_error
*/
class TreeExcept : public runtime_error {
    public:
        TreeExcept(const string& msg) : runtime_error(msg) {}
};

template <typename E>
class RBTree;

#include "red-black-entry.h"

//! Red black tree class
/*!
    Class implementing the red-black tree functionalities
*/
template <typename E>
class RBTree {
    public:
        typedef RBEntry<E> RBEntry; // an entry
        typedef typename RBEntry::Key K; // a key
        typedef typename RBEntry::Value V; // a value
        class Position;
    private:
        //! Node class
        /*!
            Node holding the data of each node in the tree
            \param k      key value
            \param v      data value
            \return       iterator to the position of the modified or new entry
        */
        class Node {
            private:
                //! Default Constructor
                /*!
                    Default constructor
                */
                Node() : entry(), left(nullptr), right(nullptr), parent(nullptr) {}

                //! Parameter constructor
                /*!
                    Construct the node object
                    \param k      key value
                    \param v      data value
                    \param l      left pointer
                    \param r      right pointer
                    \param p      parent pointer
                */
                Node(const K& k, const V& v, Node* l = nullptr, Node* r = nullptr, Node* p = nullptr)
                    : entry(k, v), left(l), right(r), parent(p) {}

                RBEntry entry;
                Node* parent;
                Node* left;
                Node* right;

            friend class RBTree<E>;
        };
    public:
        //! Default constructor
        /*!
            Default constructor
        */
        RBTree();

        //! Destructor
        /*!
            Destructor
        */
        ~RBTree();

        //! Get size
        /*!
            Returns size
            \return       size
        */
        int size() const { return n; }

        //! Checks if empty
        /*!
            Checks if empty
            \return       true if empty
        */
        bool empty() const { return size() == 0; }

        //! Get root position
        /*!
            Get root position
            \return       position of root
        */
        Position root() const { return Position(_root); }

        //! Leftmost node
        /*!
            Get leftmost node
            \return       position of the first in in-order traversal
        */
        Position begin() const;

        //! Find position of entry by its key
        /*!
            Find position of entry by its key
            \param k      key value
            \return       position to the found entry, or exception
        */
        Position find(const K& k) const;

        //! Insert a new entry
        /*!
            Insert a new entry
            \param k      key value
            \param v      data value
        */
        void insert(const K& k, const V& v);

        //! Erase a position
        /*!
            Erase position
            \param pos    position to remove
        */
        void erase(const Position& pos);

        //! Erase by key
        /*!
            Erase by key
            \param k      key value
        */
        void erase(const K& k);

        //! Recover the broken red-black trees after insertion
        /*!
            Recover the broken red-black trees after insertion
            \param pos      position
        */
        void restructureAfterDelete(Position& pos);

        //! Recover the broken red-black trees after deletion
        /*!
            Recover the broken red-black trees after deletion
            \param pos      position
        */
        void restructureAfterInsert(Position& pos);

        //! Left transform
        /*!
            Left transform, demonstrated in the documentation under Self-balancing Binary Search Trees
            \param pos      position to flip
        */
        void leftTransform(Position pos);

        //! Right transform
        /*!
            Right transform, demonstrated in the documentation under Self-balancing Binary Search Trees
            \param pos      position to flip
        */
        void rightTransform(Position pos);

        //! Swap positions
        /*!
            Swap positions
            \param u      position 1
            \param v      position 2
        */
        void swap(Position u, Position v);

        //! Find position of minimum in left subtree
        /*!
            Find position of minimum in left subtree
            \param pos      position
            \return       position to the found entry
        */
        Position minInLeftSubTree(const Position& pos) const;

        //! Prints a tree(demonstrative function)
        /*!
            Prints a tree(demonstrative function)
        */
        void print() const;
        void print(const Position& pos, string ind, bool last) const;
    private:
        Node* _root;
        Node* RBNULL;

        int n;
    public:
        //! Position class
        /*!
            Position class helpping with moving around nodes
        */
        class Position {
            public:
                //! Default constructor
                /*!
                    Default constructor, initializing empty node
                */
                Position() : node(nullptr) { }

                //! Parameter constructor
                /*!
                    Parameter constructor
                    \param nide      node pointer
                */
                Position(Node* node) : node(node) { }

                //! Copy constructor
                /*!
                    Copy constructor
                    \param pos      position
                */
                Position(const Position& pos) : node(pos.node) { }

                //! Overloaded = operator
                /*!
                    Overloaded = operator
                    \param pos      position
                    \return         Position reference
                */
                Position& operator =(const Position& pos) { node = pos.node; return *this; }

                //! Check if two positions are equal
                /*!
                    Check if two positions are equal
                    \param p      position
                    \return       true if equal
                */
                bool operator ==(const Position& p) const { return node == p.node; }

                //! Check if two positions are not equal
                /*!
                    Check if two positions are not equal
                    \param p      position
                    \return       true if not equal
                */
                bool operator !=(const Position& p) const { return node != p.node; }

                //! Compare the keys of two positions
                /*!
                    Compare the keys of two positions
                    \param p      position
                    \return       true if left smaller
                */
                bool operator <(const Position& p) { return node->entry.key() < p.node->entry.key(); }

                //! Compare the keys of two positions
                /*!
                    Compare the keys of two positions
                    \param p      position
                    \return       true if left smaller or equal
                */
                bool operator <=(const Position& p) { return node->entry.key() <= p.node->entry.key(); }

                //! Compare the keys of two positions
                /*!
                    Compare the keys of two positions
                    \param p      position
                    \return       true if left bigger
                */
                bool operator >(const Position& p) { return node->entry.key() > p.node->entry.key(); }

                //! Compare the keys of two positions
                /*!
                    Compare the keys of two positions
                    \param p      position
                    \return       true if left bigger or equal
                */
                bool operator >=(const Position& p) { return node->entry.key() >= p.node->entry.key(); }

                //! Get the entry
                /*!
                    Get the entry
                    \return       entry reference
                */
                RBEntry& operator*() { return node->entry; }

                //! Get the entry
                /*!
                    Get the entry, idea gotten from std vector
                    \return       entry pointer
                */
                RBEntry* operator->() const { return &node->entry; }

                //! Checks if position exists
                /*!
                    Checks if position exists
                    \return       true if pointer exists
                */
                bool exist() const { return node != nullptr; }

                //! Checks if position is red
                /*!
                    Checks if position is red
                    \return       true if red
                */
                bool isRed() const { return node->entry.color() == RED; }

                //! Checks if position is black
                /*!
                    Checks if position is black
                    \return       true if black
                */
                bool isBlack() const { return node->entry.color() == BLACK; }

                //! Checks if position is root
                /*!
                    Checks if position is root
                    \return       true if root
                */
                bool isRoot() const { return !node->parent; }

                //! Get position of root
                /*!
                    Get position of root
                    \return       position of parent
                */
                Position parent() const { return Position(node->parent); }

                //! Get position of left child
                /*!
                    Get position of left child
                    \return       position of left
                */
                Position left() const { return Position(node->left); }

                //! Get position of right child
                /*!
                    Get position of right child
                    \return       position of right
                */
                Position right() const { return Position(node->right); }

                //! Set parent position
                /*!
                    Set parent position
                    \param chNode      position
                */
                void setParent(const Position& chNode) { node->parent = chNode.node; }

                //! Set left position
                /*!
                    Set left position
                    \param chNode      position
                */
                void setLeft(const Position& chNode) { node->left = chNode.node; }

                //! Set right position
                /*!
                    Set right position
                    \param chNode      position
                */
                void setRight(const Position& chNode) { node->right = chNode.node; }
            private:
                Node* node;

            friend class RBTree<E>;
        };
};

template <typename E>
RBTree<E>::RBTree() {
    RBNULL = new Node();
    _root = RBNULL;
}

template <typename E>
RBTree<E>::~RBTree() {
    if(_root) { // delete the root pointer
        delete _root;
    }

    if(RBNULL) { // delete the red-black tree null pointer
        delete RBNULL;
    }
}

template <typename E>
typename RBTree<E>::Position RBTree<E>::begin() const {
    Position rootPos(_root);
    return minInLeftSubTree(rootPos);
}

template <typename E>
void RBTree<E>::insert(const K& k, const V& v) {
    // Insert as every basic Binary Search Tree does
    Node* node = new Node(k, v, RBNULL, RBNULL);
    node->entry.setColor(RED);

    Position pos(node);

    Position y(nullptr);
    Position rootPos(_root);

    // find position to add insert the node
    while(rootPos != Position(RBNULL)) {
        y = rootPos;
        // if smaller, go to left
        if(pos < rootPos) {
            rootPos = rootPos.left();
        } else { // otherwise, go to right >=
            rootPos = rootPos.right();
        }
    }

    // y is the parent of x
    pos.setParent(y);
    if(!y.exist()) { // if the new entry is positioned as a root
        _root = pos.node;
    } else if(pos < y) {
        y.setLeft(pos);
    } else {
        y.setRight(pos);
    }

    // The tree is empty, in this case pos is set to be root and it is painted black.
    if(!pos.parent().exist()) { // if the new node happens to be the root node
        pos->setColor(BLACK);
    } else if(pos.parent().parent().exist()) { // if there is a grandmonther
        restructureAfterInsert(pos); // fix the tree, 
        // making sure all red-black tree properties are met
    }
    n++;
}

template <typename E>
void RBTree<E>::erase(const Position& pos) {
    // simply use the other function calling it by key
    erase(pos->key());
}

template <typename E>
void RBTree<E>::erase(const K& key) {
    Position rootPos(_root); // root position
    Position z = find(key); // find the entry to delete
    Position x(new Node);
    Position y(z);

    Color yFirstColor = y->color();
    if (z.left() == Position(RBNULL)) { // if z's left child is external
        x = z.right();
        swap(z, x); // in this case, simply replace z with its right child
    } else if (z.right() == Position(RBNULL)) {
        x = z.left();
        swap(z, x); // in this case, simply replace z with its left child
    } else {
        // find the leftmost key
        y = minInLeftSubTree(z.right());
        yFirstColor = y->color();
        x = y.right();

        // if y is a child of z
        if (y.parent() == z) {
            x.setParent(y);
        } else { 
            swap(y, y.right());
            y.setRight(z.right());
            y.right().setParent(y);
        }

        swap(z, y);
        y.setLeft(z.left());
        y.left().setParent(y);
        y->setColor(z->color());
    }
    delete z.node;
    if (yFirstColor == BLACK){
        restructureAfterDelete(x);
    }
    n--;
}

template <typename E>
typename RBTree<E>::Position RBTree<E>::find(const K& key) const {
    // The usual search procedure in a binary search tree
    // Starting from the root
    Position current(_root);
    Position z(RBNULL); // initially empty node

    // move down until external node is encountered
    while (current != Position(RBNULL)){
        // check if this is the key, otherwise move left or right
        if (current->key() == key) {
            z = current;
        }
        
        // If smaller, go to right
        if (current->key() <= key) {
            current = current.right();
        } else { // otherwise, go to left
            current = current.left();
        }
    }

    // If external node, throw exception for missing key
    if (z == RBNULL) {
        throw TreeExcept("Couldn't find key in the tree");
    } else {
        // otherwise, return the position of the key
        return Position(z);
    }
}

template <typename E>
void RBTree<E>::restructureAfterDelete(Position& pos) {
    Position s(new Node);
    // move up until the root or until black node
    while (pos != Position(_root) && pos.isBlack()) {
        if (pos == pos.parent().left()) {
            s = pos.parent().right();
            // If pos's sister is a red node, simply delete it, 
            // because removing red nodes, doesn't break the rules
            if (s.isRed()) {
                // 3.1 in the documentation
                s->setColor(BLACK);
                pos.parent()->setColor(RED);
                leftTransform(pos.parent());
                s = pos.parent().right();
            }

            // if both children are black
            if (s.left().isBlack() && s.right().isBlack()) {
                // 3.2 in the documentation
                s->setColor(RED);
                pos = pos.parent();
            } else {
                // if only the right is black
                if (s.right().isBlack()) {
                    // 3.3 in the documentation
                    s.left()->setColor(BLACK);
                    s->setColor(RED);
                    rightTransform(s);
                    s = pos.parent().right();
                } 

                // if only the right is red
                // 3.4 in the documentation
                s->setColor(pos.parent()->color());
                pos.parent()->setColor(BLACK);
                s.right()->setColor(BLACK);
                leftTransform(pos.parent());
                pos.node = _root;
            }
        } else { // symmetric to above
            s = pos.parent().left();
            // If pos's sister is a red node, simply delete it, 
            // because removing red nodes, doesn't break the rules
            if (s.isRed()) {
                // 3.1 in the documentation
                s->setColor(BLACK);
                pos.parent()->setColor(RED);
                rightTransform(pos.parent());
                s = pos.parent().left();
            }

            // if both children are black
            if (s.right().isBlack() && s.right().isBlack()) {
                // 3.2 in the documentation
                s->setColor(RED);
                pos = pos.parent();
            } else {
                // if only the right is black
                if (s.left().isBlack()) {
                    // 3.3 in the documentation
                    s.right()->setColor(BLACK);
                    s->setColor(RED);
                    leftTransform(s);
                    s = pos.parent().left();
                } 
                // if only the right is red
                // 3.4 in the documentation
                s->setColor(pos.parent()->color());
                pos.parent()->setColor(BLACK);
                s.left()->setColor(BLACK);
                rightTransform(pos.parent());
                pos.node = _root;
            }
        } 
    }
    pos->setColor(BLACK);
}

template <typename E>
void RBTree<E>::swap(Position u, Position v) {
    // a bit special case when the upper entry is the current root
    if (!u.parent().exist()) {
        _root = v.node; 
    } else if (u == u.parent().left()){
        u.parent().setLeft(v);
    } else {
        u.parent().setRight(v);
    }
    v.setParent(u.parent());
}

template <typename E>
typename RBTree<E>::Position RBTree<E>::minInLeftSubTree(const Position& pos) const {
    Position result(pos);
    while (result.left() != Position(RBNULL)) {
        result = result.left();
    }
    return result;
}

template <typename E>
void RBTree<E>::leftTransform(Position pos) {
    Position y = pos.right(); // the node on the right
    pos.setRight(y.left()); // move b to the right of pos
    if (y.left() != Position(RBNULL)) { // if left child of y is not empty
        y.left().setParent(pos); // set the parent to the pos
    }
    y.setParent(pos.parent()); // y gets the same parent as pos
    if (!pos.parent().exist()) { // if pos parent doesn't exist, it's the root
        _root = y.node; // the root becomes y
    } else if (pos == pos.parent().left()) {
        pos.parent().setLeft(y);
    } else {
        pos.parent().setRight(y);
    }
    y.setLeft(pos); // put pos to the left of y
    pos.setParent(y);
}

template <typename E>
void RBTree<E>::rightTransform(Position pos) {
    Position y = pos.left(); // the node on the left
    pos.setLeft(y.right()); // move b to the left of pos
    if (y.right() != Position(RBNULL)) { // if right child of y is not empty
        y.right().parent() = pos; // set the parent to the pos
    }
    y.setParent(pos.parent()); // y gets the same parent as pos
    if (!pos.parent().exist()) { // if pos parent doesn't exist, it's the root
        _root = y.node; // the root becomes y
    } else if (pos == pos.parent().right()) {
        pos.parent().setRight(y);
    } else {
        pos.parent().setLeft(y);
    }
    y.setRight(pos); // put pos to the right of y
    pos.setParent(y);
}

template <typename E>
void RBTree<E>::restructureAfterInsert(Position& pos) {
    Position aunt;
    while(pos.parent().isRed()) {
        if (pos.parent() == pos.parent().parent().right()) {
            aunt = pos.parent().parent().left();
            if (aunt.isRed()) {
                // 3.1 in the documentation
                aunt->setColor(BLACK);
                pos.parent()->setColor(BLACK);
                pos.parent().parent()->setColor(RED);
                pos = pos.parent().parent();
            } else {
                if (pos == pos.parent().left()) {
                    // 3.2.2 in the documentation
                    pos = pos.parent();
                    rightTransform(pos);
                }
                // 3.2.1 in the documentation
                pos.parent()->setColor(BLACK);
                pos.parent().parent()->setColor(RED);
                leftTransform(pos.parent().parent());
            }
        } else { // symmetric
            aunt = pos.parent().parent().right();

            if (aunt.isRed()) {
                // 3.1 in the documentation
                aunt->setColor(BLACK);
                pos.parent()->setColor(BLACK);
                pos.parent().parent()->setColor(RED);
                pos = pos.parent().parent();	
            } else {
                if (pos == pos.parent().right()) {
                    // 3.2.2 in the documentation
                    pos = pos.parent();
                    leftTransform(pos);
                }
                // 3.2.1 in the documentation
                pos.parent()->setColor(BLACK);
                pos.parent().parent()->setColor(RED);
                rightTransform(pos.parent().parent());
            }
        }
        if (pos.isRoot()) { 
            break;
        }
    }
    Position rootPos(_root);
    rootPos->setColor(BLACK);
}

template <typename E>
void RBTree<E>::print() const {
    Position pos(_root);
    if(pos.exist()) {
        print(pos, "", true);
    }
}

template <typename E>
void RBTree<E>::print(const Position& pos, string ind, bool last) const {
    if(pos != Position(RBNULL)) {
        cout << ind;
        if(last) {
            cout <<"R----";
            ind +=  "     ";
        } else {
            cout<<"L----";
		    ind += "|    ";
        }

        string sColor = pos.isRed() ? "RED" : "BLACK";
        cout << pos->key() << "(" << sColor << ")" << endl;
        print(pos.left(), ind, false);
        print(pos.right(), ind, true);
    }
}

#endif