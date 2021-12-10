#ifndef LINKED_BINARY_TREE_H
#define LINKED_BINARY_TREE_H

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#include "gtree.exception.h"

template <typename T>
class LinkedBinaryTree {
    public:
        class Node {
            public:
                Node(const T& key);
            public:
                T key;
                Node* parent;
                Node* left;
                Node* right;
                Node() : key(), parent(nullptr), left(nullptr), right(nullptr) {}

            friend class LinkedBinaryTree<T>;
        };
        class Position {
            public:
                Position();
                Position(LinkedBinaryTree<T>::Node* node);
                Position(const Position& pos);
                Position& operator =(const Position& pos);
                T& operator*();
                bool isRoot() const;
                bool isExternal() const;
                Position parent() const;
                Position getLeft() const;
                Position getRight() const;
            private:
                Node* node;
                void copy(const Position& pos);

            friend class LinkedBinaryTree<T>;
        };
    public:
        LinkedBinaryTree();
        LinkedBinaryTree(const LinkedBinaryTree& tree);
        virtual ~LinkedBinaryTree();
        LinkedBinaryTree& operator =(const LinkedBinaryTree& tree);
        int size() const;
        bool empty() const;
        Position setRoot(const T& key);
        Position getRoot() const;
        vector<Position>& positions() const;
        Position addChild(const Position& parent, const T& key);
        void expandExternal(const Position& p);
        Position removeAboveExternal(const Position& p);
        void print(Node* node, int space) const;
        void print() const;
        int height(const Position& pos) const;
        int depth(const Position& pos) const;
        Node* setLeft(const Position& pos, const T& key);
        void setRight(const Position& pos, const T& key);
        void eulerTour();
        void eulerTour(Node* node);
    protected:
        Node* root;
        int n;
        void deleteTree(Node* node);
        void copy(const LinkedBinaryTree& tree);
        void preorder(Node* v, vector<Position>& pl) const;
};

// LinkedBinaryTree default constructor
template <typename T>
LinkedBinaryTree<T>::LinkedBinaryTree() {
    root = nullptr;
    n = 0;
}

// LinkedBinaryTree destructor
template <typename T>
LinkedBinaryTree<T>::~LinkedBinaryTree() {
    deleteTree(root);
}

template <typename T>
void LinkedBinaryTree<T>::deleteTree(LinkedBinaryTree<T>::Node* node) {
    if(node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
        node = nullptr;
        n--;
    }
}

template <typename T>
void LinkedBinaryTree<T>::expandExternal(const Position& p) {
    if(p.isExternal()) {
        Node* v = p.node;
        v->left = new Node();
        v->left->parent = v;

        v->right = new Node();
        v->right->parent = v;
        n += 2;
    }
}

template <typename T>
vector<typename LinkedBinaryTree<T>::Position>& LinkedBinaryTree<T>::positions() const {
    vector<Position> pl;
    preorder(root, pl);
    return pl;
}

template <typename T>
void LinkedBinaryTree<T>::preorder(Node* v, vector<Position>& pl) const {
    pl.push_back(v);
    if(v->left != nullptr) preorder(v->left, pl);
    if(v->right != nullptr) preorder(v->right, pl);
}

template <typename T>
void LinkedBinaryTree<T>::eulerTour(Node* node) {
    Position pos(node);
    cout << *pos << endl;
    if(pos.node->left) {
        eulerTour(pos.node->left);
        cout << *pos << endl;
    }
    if(pos.node->right) {
        eulerTour(pos.node->right);
        cout << *pos << endl;
    }
}

template <typename T>
void LinkedBinaryTree<T>::eulerTour() {
    eulerTour(root);
}

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::removeAboveExternal(const Position& p) {
    if(p.isExternal()) {
        Node* w = p.node; Node* v = w->parent;
        Node* sib = (w == v->left ? v->right : v->left);
        if(v == root) {
            root = sib;
            sib->parent = nullptr;
        } else {
            Node* u = v->parent;
            if(v == u->left){
                u->left = sib;
            } else {
                u->right = sib;
            }
            sib->parent = u;
        }

        delete w;
        delete v;
        n -= 2;

        return Position(sib);
    }
}

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::setRoot(const T& key) {
    if(root) {
        throw TreeExcept("root already set!");
    }
    root = new Node(key);
    n = 1;

    return getRoot();
}

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::getRoot() const {
    return Position(root);
}

template <typename T>
int LinkedBinaryTree<T>::size() const {
    return n;
}

template <typename T>
bool LinkedBinaryTree<T>::empty() const {
    return size() == 0;
}

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::addChild(const Position& parent, const T& key) {
    Node* node = new Node(key);
    node->parent = parent.node;
    parent.node->children.push_back(node);
    n++;

    return Position(node);
}

template <typename T>
void LinkedBinaryTree<T>::print(Node* node, int space) const {
    if(node) {
        print(node->right, space += 2);
        cout << setw(space) << node->key << endl;
        print(node->left, space);
    }
}

template <typename T>
void LinkedBinaryTree<T>::print() const {
    print(root, 0);
}

template <typename T>
int LinkedBinaryTree<T>::height(const Position& pos) const {
    if(pos.isExternal()) {
        return 0;
    }
    return 1 + max(height(pos.node->left), height(pos.node->right));
}

template <typename T>
int LinkedBinaryTree<T>::depth(const Position& pos) const {
    if(pos.isRoot()) {
        return 0;
    }
    return 1 + depth(pos.parent()); 
}

template <typename T>
LinkedBinaryTree<T>::LinkedBinaryTree(const LinkedBinaryTree& tree) {
    copy(tree);
}

template <typename T>
LinkedBinaryTree<T>& LinkedBinaryTree<T>::operator =(const LinkedBinaryTree& tree) {
    copy(tree);
}

template <typename T>
void LinkedBinaryTree<T>::copy(const LinkedBinaryTree& tree) {
    root = tree.root;
    n = tree.n;
}

// Position default constructor
template <typename T>
LinkedBinaryTree<T>::Position::Position() {
    node = nullptr;
}

// Position parameter constructor
template <typename T>
LinkedBinaryTree<T>::Position::Position(LinkedBinaryTree<T>::Node* node) {
   this->node = node;
}

// Position copy constructor
template <typename T>
LinkedBinaryTree<T>::Position::Position(const Position& pos) {
   copy(pos);
}

// Position = overloaded
template <typename T>
typename LinkedBinaryTree<T>::Position& LinkedBinaryTree<T>::Position::operator =(const Position& pos) {
    copy(pos);
    return *this;
}

// Position checks isRoot
template <typename T>
bool LinkedBinaryTree<T>::Position::isRoot() const {
    if(!node) {
        throw TreeExcept("No node!");
    }
    return (!node->parent);
}

// Position checks isExternal
template <typename T>
bool LinkedBinaryTree<T>::Position::isExternal() const {
    if(!node) {
        throw TreeExcept("No node!");
    }
    return (node->left == nullptr && node->right == nullptr);
}

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::Position::parent() const {
    if(!node) {
        throw TreeExcept("Access null position");
    }
    return Position(node->parent);
}

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::Position::getLeft() const {
    return Position(node->left);
}

template <typename T>
typename LinkedBinaryTree<T>::Node* LinkedBinaryTree<T>::setLeft(const typename LinkedBinaryTree<T>::Position& pos, const T& key) {
    if(pos.node->left) {
        throw TreeExcept("Left child already set");
    }
    pos.node->left = new Node(key);
    pos.node->left->parent = pos.node;
    n++;

    return pos.node->left;
}

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::Position::getRight() const {
    return Position(node->right);
}

template <typename T>
void LinkedBinaryTree<T>::setRight(const typename LinkedBinaryTree<T>::Position& pos, const T& key) {
    if(pos.node->right) {
        throw TreeExcept("Right child already set");
    }
    pos.node->right = new Node(key);
    pos.node->right->parent = pos.node;
    n++;
}

template <typename T>
T& LinkedBinaryTree<T>::Position::operator *() {
    if(!node) {
        throw TreeExcept("Dereference null position");
    }
    return node->key;
}

// Position copy
template <typename T>
void LinkedBinaryTree<T>::Position::copy(const Position& pos) {
    this->node = pos.node;
}

// Node constructor
template <typename T>
LinkedBinaryTree<T>::Node::Node(const T& key) {
    this->key = key;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}


#endif