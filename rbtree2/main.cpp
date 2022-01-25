#include <iostream>

using namespace std;

#include "entry.h"
#include "red-black-tree.h"

int main() {
    RBTree< Entry<int, string> > tree;
    tree.insert(10, "Maria Bakalova");
    tree.insert(5, "Kosta Tsonev");
    tree.insert(20, "Georgi Mamalev");

    cout << "Demonstrating tree with three nodes" << endl;
    cout << "At this stage, it looks like a normal binary tree" << endl;
    tree.print();

    cout << "-------------" << endl << endl;

    tree.insert(30, "Teodora Duhovnikova");
    tree.insert(15, "Velko Kanev");
    
    cout << "It  still looks like a normal binary tree, besides some recoloring" << endl;
    tree.print();

    cout << "-------------" << endl << endl;

    tree.insert(25, "Konstantin Kotsev");
    tree.insert(1, "Georgi Kaloyanchev");
    tree.insert(50, "Georgi Vachkov");

    cout << "Still no movements" << endl;
    tree.print();

    cout << "-------------" << endl << endl;

    tree.erase(15);
    cout << "Removing 15 makes it rearrange and recolor" << endl;
    cout << "Delete node since its external" << endl;
    cout << "Double-blackness found, which can be fixed with one left transformation" << endl;
    tree.print();

    cout << "-------------" << endl << endl;

    cout << "Node to delete(30) has two children" << endl;
    cout << "Find the right-most node in the left subtree of the delete node" << endl;
    cout << "And swap it with the delete node" << endl;
    cout << "and remove the right-most" << endl;
    tree.erase(30);
    tree.print();

    cout << "-------------" << endl << endl;

    tree.insert(14, "Stefan Danailov");
    cout << "Simple binary tree insert, when adding 14" << endl;
    tree.print();

    cout << "-------------" << endl << endl;

    cout << "Demonstrating find capabilities" << endl;
    cout << tree.find(5)->value() << endl;
        
    return 0;
}