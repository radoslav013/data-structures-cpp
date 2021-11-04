#ifndef GEOM_PROGRESSION_H
#define GEOM_PROGRESSION_H

#include "progression.h"

class GeomProgression : public Progression { // geometric progression
    public:
        GeomProgression(double b = 2) : Progression(1), base(b) {} // constructor
        virtual double getNth(int n); // overriding the getNth from class Progression

    protected:
        double base; // base to multiply with
        virtual double getNext(); // overriding the getNext from class Progression
};

#endif