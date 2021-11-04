#include "geom-progression.h"

// overriding the getNext from class Progression
double GeomProgression::getNext() {
    curr *= base;
    return curr;
}