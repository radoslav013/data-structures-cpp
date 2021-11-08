#include <iostream>
#include <string>

using namespace std;

#include "circular-linked-list.h"
#include "node.h"

int main() {
    CircularLinkedList<string>* list = new CircularLinkedList<string>();
    
    int n = 0;
    cout << "How many one-word strings would you like to enter: ";
    cin >> n;
    int i = 0;
    while(i < n) {
        string s;
        cin >> s;
        list->add(s);
        i++;
    }
    
    // list->add("brtz");
    // list->add("asdf");
    
    // list->add("brty");
    // list->add("zxcv");
    // list->add("zxcz");
    // list->add("erty");
    

    list->print();
    list->sort();
    list->print();

    return 0;
}