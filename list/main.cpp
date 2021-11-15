#include <iostream>

using namespace std;

#include "list.h"

int main() {
    NodeList<int> list;
    list.insertBack(5);
    list.insertBack(6);

    NodeList<int>::Iterator it = list.begin();
    NodeList<int>::Iterator it2 = ++it;

    cout << *(it2) << endl;

    // NodeList<int> listB;
    // listB = list;

    // cout << *(listB.begin()) << endl;
    return 0;
}