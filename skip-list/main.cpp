#include <iostream>
#include <string>

using namespace std;

#include "skip-list.h"

int main() {
    SkipList<int, string> sl;
    // cout << sl.flipCoin() << endl;
    sl.put(1, "Rado");
    sl.put(2, "Ivan");
    sl.put(10, "Yasen");
    sl.put(5, "Georgi");
    sl.put(7, "Martin");
    sl.put(4, "Hristo");

    sl.find(10);

    sl.print();

    sl.erase(5);

    sl.print();
    return 0;
}