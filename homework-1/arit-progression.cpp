#include "arit-progression.h"

// overriding the getNext from class Progression
double AritProgression::getNext() {
    curr += incr;
    return curr;
}