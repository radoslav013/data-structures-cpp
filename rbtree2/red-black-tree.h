#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <iostream>
#include <stdexcept> // for runtime_error

using namespace std;

class TreeExcept : public runtime_error {
    public:
        TreeExcept(const string& msg) : runtime_error(msg) {}
};

template <typename E>
class RBTree;

#include "red-black-entry.h"

template <typename E>
class RBTree {
    public:
        typedef RBEntry<E> RBEntry; // an entry
        typedef typename RBEntry::Key K; // a key
        typedef typename RBEntry::Value V; // a value
        class Position;
    private:
        class Node {
            private:
                Node() : entry(), left(nullptr), right(nullptr), parent(nullptr) {}
                RBEntry entry;
                Node* parent;
                Node* left;
                Node* right;

            friend class RBTree<E>;
        };
    public:
        RBTree();
        ~RBTree();
        int size() const { return n; }
        bool empty() const { return size() == 0; }
        Position root() const { return _root; }
        Position begin() const;
        Position find(const K& k) const;
        void insert(const K& k, const V& v);
        void erase(const Position& pos);
        void erase(const K& k);
        void restructureAfterDelete(Position& pos);
        void restructureAfterInsert(Position& pos);

        // this algorithm is demonstrated in the 
        // documentation under Self-balancing Binary Search Trees
        void leftTransform(const Position& pos);
        void rightTransform(const Position& pos);
        void swap(const Position& u, const Position& v);
        Position minInLeftSubTree(const Position& pos) const;
        void print() const;
        void print(const Position& pos, string ind, bool last) const;
    private:
        Node* _root;
        Node* RBNULL;

        int n;
    public:
        class Position {
            public:
                Position() : node(nullptr) {}
                Position(Node* node) : node(node) {}
                Position(const Position& pos) : node(pos.node) {}
                Position& operator =(const Position& pos) { node = pos.node; return *this; }
                bool operator ==(const Position& p) const { return node == p.node; }
                bool operator !=(const Position& p) const { return node != p.node; }
                bool operator <(const Position& p) { return node->entry.key() < p.node->entry.key(); }
                bool operator <=(const Position& p) { return node->entry.key() <= p.node->entry.key(); }
                bool operator >(const Position& p) { return node->entry.key() > p.node->entry.key(); }
                bool operator >=(const Position& p) { return node->entry.key() >= p.node->entry.key(); }
                RBEntry& operator*() { return node->entry; }
                RBEntry* operator->() const { return &node->entry; }
                bool exist() const { return node != nullptr; }
                bool isRed() const { return node->entry.color() == RED; }
                bool isBlack() const { return node->entry.color() == BLACK; }
                bool isRoot() const { return !node->parent; }
                Position parent() const { return Position(node->parent); }
                Position left() const { return Position(node->left); }
                Position right() const { return Position(node->right); }
                void setParent(Position chNode){ node->parent = chNode.node; }
                void setLeft(Position chNode){ node->left = chNode.node; }
                void setRight(Position chNode){ node->right = chNode.node; }
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
    Node* node = new Node();
    node->left = RBNULL;
    node->right = RBNULL;
    node->entry.setKey(k);
    node->entry.setValue(v);
    node->entry.setColor(RED);

    Position pos(node);

    Position y(nullptr);
    Position x(_root);

    // find position to add insert the node
    while(x != Position(RBNULL)) {
        y = x;
        // if smaller, go to left
        if(pos < x) {
            x = x.left();
        } else { // otherwise, go to right >=
            x = x.right();
        }
    }

    // y is the parent of x
    pos.setParent(y);
    if(!y.exist()) {
        _root = pos.node;
    } else if(pos < y) {
        y.setLeft(pos);
    } else {
        y.setRight(pos);
    }

    // The tree is empty, in this case pos is set to be root and it is painted black.
    if(!pos.parent().exist()) { // if the new node happens to be the root node
        pos->setColor(BLACK);
    } else if(pos.parent().parent().exist()) {
        restructureAfterInsert(pos);
    }
}

template <typename E>
void RBTree<E>::erase(const Position& pos) {
    erase(pos->key());
}

template <typename E>
void RBTree<E>::erase(const K& key) {
    Position rootPos(_root);
    Position z(RBNULL);
    Position x(new Node);
    Position y(new Node);

    while (rootPos != Position(RBNULL)){
        if (rootPos->key() == key) {
            z = rootPos;
        }

        if (rootPos->key() <= key) {
            rootPos = rootPos.right();
        } else {
            rootPos = rootPos.left();
        }
    }

    if (z == RBNULL) {
        throw TreeExcept("Couldn't find key in the tree");
    } 

    y = z;
    Color y_original_color = y->color();
    if (z.left() == Position(RBNULL)) {
        x = z.right();
        swap(z, z.right());
    } else if (z.right() == Position(RBNULL)) {
        x = z.left();
        swap(z, z.left());
    } else {
        y = minInLeftSubTree(z.right());
        y_original_color = y->color();
        x = y.right();
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
    if (y_original_color == BLACK){
        restructureAfterDelete(x);
    }
}

template <typename E>
typename RBTree<E>::Position RBTree<E>::find(const K& key) const {
    Position rootPos(_root);
    Position z(RBNULL); // initially empty node

    while (rootPos != Position(RBNULL)){
        if (rootPos->key() == key) {
            z = rootPos;
        }

        if (rootPos->key() <= key) {
            rootPos = rootPos.right();
        } else {
            rootPos = rootPos.left();
        }
    }

    if (z == RBNULL) {
        throw TreeExcept("Couldn't find key in the tree");
    } else {
        return Position(z);
    }
}

template <typename E>
void RBTree<E>::restructureAfterDelete(Position& pos) {
    Position s(new Node);
    while (pos != Position(_root) && pos.isBlack()) {
        if (pos == pos.parent().left()) {
            s = pos.parent().right();
            if (s.isRed()) {
                // case 3.1
                s->setColor(BLACK);
                pos.parent()->setColor(RED);
                leftTransform(pos.parent());
                s = pos.parent().right();
            }

            if (s.left().isBlack() && s.right().isBlack()) {
                // case 3.2
                s->setColor(RED);
                pos = pos.parent();
            } else {
                if (s.right().isBlack()) {
                    // case 3.3
                    s.left()->setColor(BLACK);
                    s->setColor(RED);
                    rightTransform(s);
                    s = pos.parent().right();
                } 

                // case 3.4
                s->setColor(pos.parent()->color());
                pos.parent()->setColor(BLACK);
                s.right()->setColor(BLACK);
                leftTransform(pos.parent());
                pos.node = _root;
            }
        } else {
            s = pos.parent().left();
            if (s.isRed()) {
                // case 3.1
                s->setColor(BLACK);
                pos.parent()->setColor(RED);
                rightTransform(pos.parent());
                s = pos.parent().left();
            }

            if (s.right().isBlack() && s.right().isBlack()) {
                // case 3.2
                s->setColor(RED);
                pos = pos.parent();
            } else {
                if (s.left().isBlack()) {
                    // case 3.3
                    s.right()->setColor(BLACK);
                    s->setColor(RED);
                    leftTransform(s);
                    s = pos.parent().left();
                } 

                // case 3.4
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
void RBTree<E>::swap(const Position& u, const Position& v) {
    if (!u.parent().exist()) {
        _root = v.node;
    } else if (u == u.parent().left()){
        u.parent().setLeft(v);
    } else {
        u.parent().setRight(v);
    }
    v.parent() = u.parent();
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
void RBTree<E>::leftTransform(const Position& pos) {
    Position y = pos.right(); // the node on the right
    pos.right() = y.left(); // move b to the right of pos
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
    pos.parent() = y;
}

template <typename E>
void RBTree<E>::rightTransform(const Position& pos) {
    Position y = pos.left(); // the node on the left
    pos.left() = y.right(); // move b to the left of pos
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
    pos.parent() = y;
}

template <typename E>
void RBTree<E>::restructureAfterInsert(Position& pos) {
    Position aunt;
    while(pos.parent().isRed()) {
        if (pos.parent() == pos.parent().parent().right()) {
            aunt = pos.parent().parent().left();
            if (aunt.isRed()) {
                // case 3.1
                aunt->setColor(BLACK);
                pos.parent()->setColor(BLACK);
                pos.parent().parent()->setColor(RED);
                pos = pos.parent().parent();
            } else {
                if (pos == pos.parent().left()) {
                    // case 3.2.2
                    pos = pos.parent();
                    rightTransform(pos);
                }
                // case 3.2.1
                pos.parent()->setColor(BLACK);
                pos.parent().parent()->setColor(RED);
                leftTransform(pos.parent().parent());
            }
        } else {
            aunt = pos.parent().parent().right();

            if (aunt.isRed()) {
                // mirror case 3.1
                aunt->setColor(BLACK);
                pos.parent()->setColor(BLACK);
                pos.parent().parent()->setColor(RED);
                pos = pos.parent().parent();	
            } else {
                if (pos == pos.parent().right()) {
                    // mirror case 3.2.2
                    pos = pos.parent();
                    leftTransform(pos);
                }
                // mirror case 3.2.1
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