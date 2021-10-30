#include <iostream>
#include <string>

using namespace std;

#include "stack.h"

bool doSymbolsMatch(char a, char b) {
    char c;
    switch(a) {
        case ')': c = '('; break;
        case ']': c = '['; break;
        case '}': c = '{'; break;
        default: c = ')';
    }
    return c == b;
}

bool isOpening(char a) {
    return a == '(' || a == '{' || a == '[';
}

bool isClosing(char a) {
    return a == ')' || a == '}' || a == ']';
}

bool doParenMatch(Stack<char>* s, const string& text) {
    for(int i = 0; i < text.length(); i++) {
        char a = text[i];
        if(isOpening(a)) {
            s->push(a);
        } else if(isClosing(a)) {
            if(s->empty() || !doSymbolsMatch(a, s->top())) {
                return false;
            }
            s->pop();
        }
    }
    return s->empty();
}

int main() {
    Stack<char>* s = new Stack<char>();
    string text = "({[]}){[]}{[]}{[]}";
    cout << doParenMatch(s, text) << endl;
    // s->push(5);
    // s->push(2);
    // s->pop();
    // s->push(10);

    // cout << "Size: " << s->size() << endl;
    // cout << "Top: " << s->top() << endl;

    return 0;
}