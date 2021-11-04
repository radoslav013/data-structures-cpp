#include "harm-progression.h"

// overriding the getNext from class Progression
double HarmProgression::getNext() {
    curr = 1 / (prev + d);
    prev += d;
    return curr;
}

// overriding the getNth from class Progression
double HarmProgression::getNth(int n) {
    return 1 / (frst + ((n - 1) * d));
}