#include <iostream>

using namespace std;

#include "hashc.h"

// From analysis, 33 seems to be a good choice
const int HashCode::VAR = 33;

long HashCode::operator() (const double& num) {
    int len = sizeof(num);
    // convert double to a sequence of bits
    const char* p = reinterpret_cast<const char*>(&num);
    HashCode hashCode;
    return hashCode(p, len);
}

long HashCode::operator() (const char *carr, int len) {
    long result = 0;
    for (int i = 0; i < len; i++) {
        result *= VAR;
        result += (int)carr[i];
    }

    return result;
}