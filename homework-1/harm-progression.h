#ifndef HARM_PROGRESSION_H
#define HARM_PROGRESSION_H

#include "progression.h"


class HarmProgression : public Progression { // harmonic progression
    public:
        HarmProgression(double d = 1) : Progression(1), d(d), prev(1) {} // constructor
        virtual double getNth(int n); // overriding the getNth from class Progression

    protected:
        double d;
        double prev;
        virtual double getNext(); // overriding the getNext from class Progression
};

#endif