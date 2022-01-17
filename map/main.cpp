#include <iostream>
#include <string>

using namespace std;

#include "map.h"

int main() {
    Map<int, string> map;
    Map<int, string>::Iterator rado = map.put(1, "Rado2");
    Map<int, string>::Iterator stefanela = map.put(2, "Stefanela");

    Map<int, string>::Iterator it = map.find(2);
    cout << it->value() << endl;
    return 0;
}