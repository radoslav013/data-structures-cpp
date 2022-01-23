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
    // stree.insert(20, "Mitko");
    // stree.insert(15, "Pesho");
    // stree.insert(30, "Stefanela");
    // stree.erase(10);

    // cout << (*stree.find(2)).value() << endl;
    // cout << stree.size() << endl;
    
    // stree.print();

    // cout << "----------" << endl;

    // Collection of bulgarian artists
    RBTree< Entry<int, string> > rbtree;
    RBTree< Entry<int, string> >::Iterator ten = rbtree.insert(10, "Maria Bakalova");
    // RBTree< Entry<int, string> >::Iterator five = rbtree.insert(5, "Kosta Tsonev");
    RBTree< Entry<int, string> >::Iterator twenty = rbtree.insert(20, "Georgi Mamalev");
    RBTree< Entry<int, string> >::Iterator thirty = rbtree.insert(30, "Teodora Duhovnikova");
    // RBTree< Entry<int, string> >::Iterator fifteen = rbtree.insert(15, "Velko Kanev");
    rbtree.print();

    // cout << (*rbtree.find(20)).value() << endl;
    return 0;
}