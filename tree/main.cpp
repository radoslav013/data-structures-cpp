#include <iostream>
#include <string>

using namespace std;

// #include "gtree.h"
#include "linked-binary-tree.h"
#include "linked-binary-search-tree.h"

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

    // LinkedBinaryTree<int> btree;
    // btree.setRoot(0);
    // LinkedBinaryTree<int>::Position pos = btree.getRoot();
    // btree.setLeft(pos, -1);
    // btree.setRight(pos, 1);
    // pos = pos.getLeft();
    // btree.setLeft(pos, -2);
    // btree.setRight(pos, 2);
    // btree.print();
    // cout << "--------------------" << endl;
    // btree.eulerTour();

    LinkedBinarySearchTree<int> bstree;
    bstree.insert(8);
    bstree.insert(10);
    bstree.insert(3);
    bstree.insert(1);
    bstree.print();
    // LinkedBinarySearchTree<int> bstree1;
    // bstree1 = bstree;

    return 0;
}