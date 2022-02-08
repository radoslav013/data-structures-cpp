#include <iostream>
#include <string>

using namespace std;

#include "entry.h"
#include "red-black-tree.h"

int main() {
    RBTree< Entry<int, string> > tree;
    tree.insert(1, "Rado");
    tree.insert(2, "Stefanela");

    SearchTree< Entry<int, string> > stree;
    stree.insert(1, "Rado");
    stree.insert(2, "Stefanela");
    stree.erase(1);

    // cout << (*stree.find(2)).value() << endl;
    // cout << stree.size() << endl;

    stree.print();
    return 0;
}