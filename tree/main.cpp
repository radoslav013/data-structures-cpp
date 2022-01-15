#include <iostream>
#include <string>

using namespace std;

// #include "gtree.h"
#include "linked-binary-tree.h"
// #include "linked-binary-search-tree.h"

int main() {
    // GTree<int> tree;
    // tree.setRoot(12);
    // GTree<int>::Position root = tree.getRoot();
    // GTree<int>::Position el = tree.addChild(root, 5);
    // tree.print();
    // cout << "Depth: " << tree.depth(el) << endl;

    // GTree<string> tree;
    // GTree<string>::Position root = tree.setRoot("Geometric object");

    // GTree<string>::Position oval = tree.addChild(root, "Oval");
    // tree.addChild(oval, "Circle");

    // GTree<string>::Position polygon = tree.addChild(root, "Polygon");
    // tree.addChild(polygon, "Triangle");
    // GTree<string>::Position quad = tree.addChild(polygon, "Quadrilateral");
    // tree.addChild(quad, "Square");
    // tree.addChild(quad, "Rhombus");
    // tree.addChild(quad, "Trapezoid");

    // tree.print();

    LinkedBinaryTree<int> btree;
    btree.setRoot(20);
    LinkedBinaryTree<int>::Position root = btree.getRoot();
    btree.setLeft(root, 10);
    btree.setRight(root, 26);
    LinkedBinaryTree<int>::Position left = root.getLeft();
    btree.setLeft(left, 4);
    btree.setRight(left, 18);
    LinkedBinaryTree<int>::Position leftright = left.getRight();
    btree.setLeft(leftright, 14);
    btree.setRight(leftright, 19);
    LinkedBinaryTree<int>::Position leftrightleft = leftright.getLeft();
    btree.setLeft(leftrightleft, 13);
    btree.setRight(leftrightleft, 15);
    LinkedBinaryTree<int>::Position right = root.getRight();
    btree.setLeft(right, 24);
    btree.setRight(right, 27);
    
    btree.print();
    cout << "--------------------" << endl;
    LinkedBinaryTree<int>::Position test = left.getLeft();
    cout << *test << endl;
    cout << *btree.postorderNext(test) << endl;
    // btree.eulerTour();

    // LinkedBinarySearchTree<int> bstree;
    // bstree.insert(8);
    // bstree.insert(10);
    // bstree.insert(3);
    // bstree.insert(1);
    // bstree.print();
    // LinkedBinarySearchTree<int> bstree1;
    // bstree1 = bstree;

    return 0;
}