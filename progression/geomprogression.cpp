#include "geomprogression.h"

long GeomProgression::getNext() {
    curr *= incr;
    return curr;
}