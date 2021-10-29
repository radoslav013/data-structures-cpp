#include <iostream>

using namespace std;

#include "stack.h"

int main() {
    Stack<int>* s = new Stack<int>();
    s->push(5);
    s->push(2);
    s->pop();
    s->push(10);

    cout << "Size: " << s->size() << endl;
    cout << "Top: " << s->top() << endl;

    return 0;
}