#include <iostream>
#include <string>

using namespace std;

#include "linked-binary-tree.h"
#include "entry.h"
#include "red-black-tree.h"
#include "red-black-entry.h"
#include "search-tree.h"

int main() {
    // LinkedBinaryTree<int> tree;
    // LinkedBinaryTree<int>::Position rootPos = tree.setRoot(1);

    // tree.setLeft(rootPos, 2);
    // LinkedBinaryTree<int>::Position left = rootPos.left();
    
    // tree.expandExternal(left);
    // *(left.left()) = 8;

    // tree.setRight(rootPos, 3);
    // LinkedBinaryTree<int>::Position right = rootPos.right();
    // tree.expandExternal(rootPos.right());

    // cout << "height: " << tree.height(rootPos) << endl;

    // tree.print();

    // cout << "----------" << endl;
    
    // Entry<int, string> entry(1, "rado");
    // cout << entry.key() << ": " << entry.value() << endl;

    // cout << "----------" << endl;
    
    // RBEntry< Entry<int, string> > rbEntry(2, "pesho");
    // cout << rbEntry.key() << ": " << rbEntry.value() << endl;

    // cout << "----------" << endl;

    // SearchTree< RBEntry< Entry<int, string> > > stree;
    // stree.insert(10, "Rado");
    // stree.insert(5, "Mitko");
    // stree.insert(20, "Pesho");
    // stree.insert(30, "Stefanela");
    // stree.insert(15, "Stefanela");
    // stree.insert(25, "Stefanela");
    // stree.insert(1, "Stefanela");

    // cout << (*stree.find(2)).value() << endl;
    // cout << stree.size() << endl;
    
    // stree.print();
    // stree.erase(10);
    // cout << "----------" << endl;
    // stree.print();  
    
    // Collection of bulgarian actors
    RBTree< Entry<int, string> > rbtree;
    RBTree< Entry<int, string> >::Iterator ten = rbtree.insert(10, "Maria Bakalova");
    RBTree< Entry<int, string> >::Iterator five = rbtree.insert(5, "Kosta Tsonev");
    RBTree< Entry<int, string> >::Iterator twenty = rbtree.insert(20, "Georgi Mamalev");
    RBTree< Entry<int, string> >::Iterator thirty = rbtree.insert(30, "Teodora Duhovnikova");
    RBTree< Entry<int, string> >::Iterator fifteen = rbtree.insert(15, "Velko Kanev");
    RBTree< Entry<int, string> >::Iterator twentyfive = rbtree.insert(25, "Konstantin Kotsev");
    RBTree< Entry<int, string> >::Iterator one = rbtree.insert(1, "Georgi Kaloyanchev");
    rbtree.print();

    cout << "----------" << endl;

    // Demonstrate the deletion by key and iterator
    // rbtree.erase(10);
    rbtree.erase(ten);
    // 15 becomes the root
    
    // Visualize the tree after the deletion
    rbtree.print();

    RBTree< Entry<int, string> >::Iterator fifty = rbtree.insert(50, "Georgi Vachkov");

    // Visualize the tree after the insertion
    rbtree.print();

    rbtree.erase(30);
    // Visualize the tree after the insertion
    // rbtree.print();

    // Demonstrate the search
    // cout << (*rbtree.find(15)).value() << endl;
    
    return 0;
}