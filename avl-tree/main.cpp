
#include <iostream>
#include <string>

using namespace std;

#include "../search-tree/entry.h"
#include "avl-tree.h"

int main() {
    AVLTree< Entry<int, string> > tree;
    tree.insert(1, "Rado");
    tree.insert(2, "Stefanela");
    return 0;
}