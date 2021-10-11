#include <iostream>

using namespace std;

#include "arithprogression.h"
#include "geomprogression.h"
#include "fibprogression.h"

int main() {
    ArithProgression a(2);

    GeomProgression g(2);

    FibProgression f;

    f.print(10);

    return 0;
}