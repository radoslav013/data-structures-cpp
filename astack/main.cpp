#include <iostream>

using namespace std;

#include "astack.h"

int main() {
    AStack<int> a;
    a.push(12);
    a.push(13);
    a.pop();
    a.pop();
    a.pop();

    cout << a.top() << endl;
    return 0;
}