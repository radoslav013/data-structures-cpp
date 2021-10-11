#include "fibprogression.h"

long FibProgression::getNext() {
    int temp = curr;
    curr += next;
    next = temp;
    return curr;
}