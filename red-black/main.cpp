#include <iostream>
#include <string>

using namespace std;

#include "entry.h"
#include "red-black-tree.h"

int main() {
    RBTree< Entry<int, string> > tree;
    tree.insert(1, "Rado");
    tree.insert(2, "Stefanela");
    return 0;
}