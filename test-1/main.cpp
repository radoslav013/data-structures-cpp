#include <iostream>

using namespace std;

int main() {
    int a = 1;
    string message = "true";
    char arr[] = "false";
    cout << (a ? message : arr) << endl;
    return 0;
}