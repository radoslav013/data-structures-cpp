#include <iostream>

using namespace std;

int fibbin(int n) {
    return n <= 2 ? 1 : fibbin(n - 1) + fibbin(n - 2);
}

int fib(int term, int val = 1, int prev = 0) {
    if(term == 0) {
        return prev;
    }
    return fib(term - 1, val+prev, val);
}

int main() {
    int n = 10;
    cout << fib(10) << endl;
    return 0;
}