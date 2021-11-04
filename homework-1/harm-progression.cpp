#include <iostream>
#include <cmath>

using namespace std;

#include "harm-progression.h"

// overriding the getNext from class Progression
double HarmProgression::getNext() {
    curr++;
    curr = 1 / pow(curr, p);
    return curr;
}