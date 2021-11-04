#include <iostream>

using namespace std;

#include "arit-progression.h"

// overriding the getNext from class Progression
double AritProgression::getNext() {
    curr += d;
    return curr;
}

// dummy
void AritProgression::print(int n) {
    cout << "I will never be executed..." << endl;
}

// overriding the getNth from class Progression
double AritProgression::getNth(int n) {
    return frst + ((n - 1)* d);
}