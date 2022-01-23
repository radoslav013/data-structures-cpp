#include <iostream>
#include <string>

using namespace std;

#include "skip-list.h"
#include "entry.h"

int main() {
    // create skip list object
    SkipList< Entry<int, string> > sl;
    // insert some writer names with their artist_id
    sl.put(1, "Pencho Slaveykov");
    sl.put(2, "Ivan Vazov");
    sl.put(10, "Nikola Vaptsarov");
    sl.put(5, "Nikolay Haytov");
    sl.put(7, "Yordan Radichkov");
    sl.put(4, "Hristo Botev");
    
    // find an element
    SkipList< Entry<int, string> >::Iterator ten = sl.find(10);

    // Get the value(name) and print it
    cout << ten->value() << endl;

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