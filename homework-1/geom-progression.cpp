#include <iostream>
#include <cmath>

using namespace std;
#include "geom-progression.h"

// overriding the getNext from class Progression
double GeomProgression::getNext() {
    curr *= base;
    return curr;
}

// overriding the getNth from class Progression
double GeomProgression::getNth(int n) {
    return frst * pow(base, n-1);
}