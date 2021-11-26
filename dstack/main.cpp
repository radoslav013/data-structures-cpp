#include <iostream>

using namespace std;

#include "dstack.h"

int main() {
    DStack<int> ds;
    ds.push(12);
    ds.push(13);
    // ds.pop();
    cout << ds.top() << endl;
    ds.clean();

    cout << ds.top() << endl;

    return 0;
}