#include <iostream>
#include <string>

using namespace std;

#include "entry.h"
#include "search-tree.h"

int main() {
    SearchTree< Entry<int, string> > tree;
    tree.insert(1, "Rado");
    tree.insert(2, "Stefanela");
    tree.erase(1);

    cout << (*tree.find(2)).value() << endl;
    cout << tree.size() << endl;
    return 0;
}