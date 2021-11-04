#include <iostream>

using namespace std;

#include "progression.h"

void Progression::print(int n) {
    cout << getFirst();
    for (int i = 2; i <= n; i++)
    {
        cout << " " << getNext();
    }
    cout << endl << endl;
}

double Progression::getFirst() {
    curr = frst;
    return curr;
}

double Progression::getNext() {
    return ++curr;
}
