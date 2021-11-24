#include <iostream>

using namespace std;

// #include "list.h"
// #include "node-sequence.h"
#include "array-sequence.h"

int main() {
    // NodeList<int> list;
    // list.insertBack(5);
    // list.insertBack(6);

    // NodeList<int>::Iterator it = list.begin();
    // NodeList<int>::Iterator it2 = ++it;

    // cout << *(it2) << endl;

    // NodeList<int> listB;
    // listB = list;

    // cout << *(listB.begin()) << endl;

    // NodeSequence<int> nodeList;
    // nodeList.insertBack(12);
    // nodeList.insertBack(13);
    // nodeList.insertBack(15);

    // cout << *(nodeList.atIndex(1)) << endl;

    // NodeSequence<int>::Iterator it3 = ++nodeList.begin();
    // cout << nodeList.indexOf(it3) << endl;

    ArraySequence a;
    
    a.insertBack(9);
    a.insertBack(10);
    a.insertBack(11);
    a.insertFront(7);
    a.insertBack(8);

    a.print();
    cout << "---------" << endl;
    a.eraseFront();
    a.eraseBack();
    a.print();

    return 0;
}