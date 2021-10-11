#include "arithprogression.h"

long ArithProgression::getNext() {
    curr += incr;
    return curr;
}