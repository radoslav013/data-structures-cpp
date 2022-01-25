#include <iostream>

using namespace std;

#include "entry.h"
#include "red-black-tree.h"

int main() {
    RBTree< Entry<int, string> > tree;
    tree.insert(10, "Maria Bakalova");
    tree.insert(5, "Kosta Tsonev");
    tree.insert(20, "Georgi Mamalev");
    tree.insert(30, "Teodora Duhovnikova");
    tree.insert(15, "Velko Kanev");
    tree.insert(25, "Konstantin Kotsev");
    tree.insert(1, "Georgi Kaloyanchev");
    tree.insert(50, "Georgi Vachkov");
    tree.print();

    cout << "-------------" << endl;
    tree.erase(30);

    tree.print();

    cout << "-------------" << endl;

    cout << tree.find(5)->value() << endl;

    cout << "-------------" << endl;

    cout << tree.begin()->value() << endl;
    return 0;
}