#include <iostream>
#include <string>

using namespace std;

#include "skip-list.h"
#include "entry.h"

int main() {
    // create skip list object
    SkipList< Entry<int, string> > sl;
    // insert some writer names with their writer_id
    sl.put(1, "Pencho Slaveykov");
    sl.put(2, "Ivan Vazov");
    sl.put(10, "Nikola Vaptsarov");
    sl.put(5, "Nikolay Haytov");
    sl.put(7, "Yordan Radichkov");
    sl.put(4, "Hristo Botev");
    
    // find an element
    SkipList< Entry<int, string> >::Iterator found = sl.find(10);

    // Get the value(name) and print it
    cout << found->value() << endl;

    cout << "------------" << endl;

    // Visualize
    sl.print();
    sl.erase(5); // erase by key
    sl.erase(found); // erase by iterator
    // sl.erase(11); // erase by key that doesn't exist

    cout << "------------" << endl;

    // Visualize the change after deletion
    sl.print();

    // find an element
    found = sl.find(7);

    // Get the value(name) and print it
    cout << found->value() << endl;
    return 0;
}