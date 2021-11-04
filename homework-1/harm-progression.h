#ifndef HARM_PROGRESSION_H
#define HARM_PROGRESSION_H

#include "progression.h"

class HarmProgression : public Progression { // harmonic progression
    public:
        HarmProgression(double p = 1) : Progression(1), p(p) {} // constructor

    protected:
        double p;
        virtual double getNext(); // overriding the getNext from class Progression
};

#endif