#include <iostream>
#include <string>

using namespace std;

#include "skip-list.h"
#include "entry.h"

int main() {
    // create skip list object
    SkipList< Entry<int, string> > sl;
    // insert some names with ids
    sl.put(1, "Rado");
    sl.put(2, "Ivan");
    sl.put(10, "Yasen");
    sl.put(5, "Georgi");
    sl.put(7, "Martin");
    sl.put(4, "Hristo");
    
    // find an element
    SkipList< Entry<int, string> >::Iterator ten = sl.find(10);

    // Visualize
    sl.print();
    sl.erase(5); // erase by key
    sl.erase(ten); // erase by iterator
    // sl.erase(11); // erase by key that doesn't exist

    cout << "------------" << endl;

    // Visualize the change after deletion
    sl.print();
    return 0;
}