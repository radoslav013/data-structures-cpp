#include <iostream>

using namespace std;

#include "lstack.h"

int main() {
    LStack<int> ls;
    ls.push(23);
    ls.pop();
    
    // cout << ls.top() << endl;
    return 0;
}