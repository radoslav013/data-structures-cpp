#ifndef GTREE_H
#define GTREE_H

#include <iostream>
#include <list>

using namespace std;

#include "gtree.exception.h"

template <typename T>
class GTree {
    public:
        class Node {
            public:
                Node(const T& key);
            private:
                T key;
                Node* parent;
                list<Node*> children;

            friend class GTree<T>;
        };

        class Position {
            public:
                Position();
                Position(GTree<T>::Node* node);
                Position(const Position& pos);
                Position& operator =(const Position& pos);
                T& operator*();
                bool isRoot() const;
                bool isExternal() const;
                Position parent() const;
                list<GTree<T>::Node*>& children() const;
            private:
                Node* node;
                void copy(const Position& pos);

            friend class GTree<T>;
        };
    public:
        GTree();
        GTree(const GTree& tree);
        ~GTree();
        GTree& operator =(const GTree& tree);
        int size() const;
        bool empty() const;
        Position setRoot(const T& key);
        Position getRoot() const;
        Position addChild(const Position& parent, const T& key);
        void print(Node* node) const;
        void print() const;
        int height(const Position& pos) const;
        int depth(const Position& pos) const;
    private:
        Node* root;
        int n;
        void deleteTree(Node* node);
        void copy(const GTree& tree);
};

// GTree default constructor
template <typename T>
GTree<T>::GTree() {
    root = nullptr;
    n = 0;
}

// GTree destructor
template <typename T>
GTree<T>::~GTree() {
    deleteTree(root);
}

template <typename T>
void GTree<T>::deleteTree(GTree<T>::Node* node) {
    if(node) {
        for(typename list<Node*>::iterator it = node->children.begin();
            it != node->children.end();
            ++it) {
                deleteTree(*it);
        }
        delete node;
        node = nullptr;
        n--;
    }
}

template <typename T>
typename GTree<T>::Position GTree<T>::setRoot(const T& key) {
    if(root) {
        throw TreeExcept("root already set!");
    }
    root = new Node(key);
    n = 1;

    return getRoot();
}

template <typename T>
typename GTree<T>::Position GTree<T>::getRoot() const {
    return Position(root);
}

template <typename T>
int GTree<T>::size() const {
    return n;
}

template <typename T>
bool GTree<T>::empty() const {
    return size() == 0;
}

template <typename T>
typename GTree<T>::Position GTree<T>::addChild(const Position& parent, const T& key) {
    Node* node = new Node(key);
    node->parent = parent.node;
    parent.node->children.push_back(node);
    n++;

    return Position(node);
}

template <typename T>
void GTree<T>::print(Node* node) const {
    if(node) {
        cout << node->key << ": ";
        for(typename list<Node*>::iterator it = node->children.begin();
            it != node->children.end();
            ++it) {
                cout << (*it)->key << " ";
        }

        cout << endl;

        for(typename list<Node*>::iterator it = node->children.begin();
            it != node->children.end();
            ++it) {
                print(*it);
        }
    }
}

template <typename T>
void GTree<T>::print() const {
    print(root);
}

template <typename T>
int GTree<T>::height(const Position& pos) const {
    if(pos.isExternal()) {
        return 0;
    }
    int height = 0;
    list<Node*> children = pos.children();
    for(typename list<Node*>::iterator it = children.begin();
        it != children.end();
        ++it) {
            height = max(height, height(*it));
    }
    return 1 + height;
}

template <typename T>
int GTree<T>::depth(const Position& pos) const {
    if(pos.isRoot()) {
        return 0;
    }
    return 1 + depth(pos.parent()); 
}

template <typename T>
GTree<T>::GTree(const GTree& tree) {
    copy(tree);
}

template <typename T>
GTree<T>& GTree<T>::operator =(const GTree& tree) {
    copy(tree);
}

template <typename T>
void GTree<T>::copy(const GTree& tree) {
    root = tree.root;
    n = tree.n;
}

// Position default constructor
template <typename T>
GTree<T>::Position::Position() {
    node = nullptr;
}

// Position parameter constructor
template <typename T>
GTree<T>::Position::Position(GTree<T>::Node* node) {
   this->node = node;
}

// Position copy constructor
template <typename T>
GTree<T>::Position::Position(const Position& pos) {
   copy(pos);
}

// Position = overloaded
template <typename T>
typename GTree<T>::Position& GTree<T>::Position::operator =(const Position& pos) {
    copy(pos);
}

// Position checks isRoot
template <typename T>
bool GTree<T>::Position::isRoot() const {
    if(!node) {
        throw TreeExcept("No node!");
    }
    return (!node->parent);
}

// Position checks isExternal
template <typename T>
bool GTree<T>::Position::isExternal() const {
    if(!node) {
        throw TreeExcept("No node!");
    }
    return (node->children.size() == 0);
}

template <typename T>
typename GTree<T>::Position GTree<T>::Position::parent() const {
    return Position(node->parent);
}

template <typename T>
list<typename GTree<T>::Node*>& GTree<T>::Position::children() const {
    return node->children;
}

template <typename T>
T& GTree<T>::Position::operator *() {
    return node->key;
}

// Position copy
template <typename T>
void GTree<T>::Position::copy(const Position& pos) {
    this->node = pos.node;
}

// Node constructor
template <typename T>
GTree<T>::Node::Node(const T& key) {
    this->key = key;
    parent = nullptr;
}


#endif