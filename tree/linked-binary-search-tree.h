#ifndef LINKED_BINARY_SEARCH_TREE_H
#define LINKED_BINARY_SEARCH_TREE_H

#include <iostream>

using namespace std;

#include "linked-binary-tree.h"

template <typename T>
class LinkedBinarySearchTree : public LinkedBinaryTree<T> {
    public:
        LinkedBinarySearchTree() : LinkedBinaryTree<T>() {}
        typename LinkedBinaryTree<T>::Position insert(const typename LinkedBinaryTree<T>::Position& pos, const T& key);
        void insert(const T& key);
};

template <typename T>
void LinkedBinarySearchTree<T>::insert(const T& key) {
    if(LinkedBinaryTree<T>::root) {
        typename LinkedBinaryTree<T>::Position pos(LinkedBinaryTree<T>::root);
        insert(pos, key);
    } else {
        typename LinkedBinaryTree<T>::Position pos = LinkedBinaryTree<T>::setRoot(key);
        LinkedBinaryTree<T>::expandExternal(pos);
    }
}

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinarySearchTree<T>::insert(const typename LinkedBinaryTree<T>::Position& pos, const T& key) {
    if(pos) {
        if(key < *pos) {
            insert(pos.getLeft(), key);
        } else if (key > *pos) {
            typename LinkedBinaryTree<T>::Position right(node->right);
            insert(pos.getRight(), key);
        }
    } else {
        // if(pos.isExternal()) {
        //     LinkedBinaryTree<T>::expandExternal(pos);
        // }
        // return LinkedBinaryTree<T>::setLeft(pos, key);
    }
    return pos;
}

#endif