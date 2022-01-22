#include <iostream>
#include <string>

using namespace std;

#include "skip-list.h"
#include "entry.h"

int main() {
    SkipList< Entry<int, string> > sl;
    sl.put(1, "Rado");
    sl.put(2, "Ivan");
    sl.put(10, "Yasen");
    sl.put(5, "Georgi");
    sl.put(7, "Martin");
    sl.put(4, "Hristo");

    SkipList< Entry<int, string> >::Iterator ten = sl.find(10);

    sl.print();
    sl.erase(5); // erase by key
    sl.erase(ten); // erase by iterator
    // sl.erase(11); // erase by key that doesn't exist

    sl.print();
    return 0;
}