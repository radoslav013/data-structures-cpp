#include <iostream>
#include <string>

using namespace std;

#include "gtree.h"

int main() {
    // GTree<int> tree;
    // tree.setRoot(12);
    // GTree<int>::Position root = tree.getRoot();
    // GTree<int>::Position el = tree.addChild(root, 5);
    // tree.print();
    // cout << "Depth: " << tree.depth(el) << endl;

    GTree<string> tree;
    GTree<string>::Position root = tree.setRoot("Geometric object");

    GTree<string>::Position oval = tree.addChild(root, "Oval");
    tree.addChild(oval, "Circle");

    GTree<string>::Position polygon = tree.addChild(root, "Polygon");
    tree.addChild(polygon, "Triangle");
    GTree<string>::Position quad = tree.addChild(polygon, "Quadrilateral");
    tree.addChild(quad, "Square");
    tree.addChild(quad, "Rhombus");
    tree.addChild(quad, "Trapezoid");

    tree.print();

    return 0;
}