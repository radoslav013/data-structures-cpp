#include <cmath>

#include "geom-progression.h"

// overriding the getNext from class Progression
double GeomProgression::getNext() {
    curr *= r;
    return curr;
}

// overriding the getNth from class Progression
double GeomProgression::getNth(int n) {
    return frst * pow(r, n-1);
}