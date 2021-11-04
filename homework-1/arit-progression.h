#ifndef ARIT_PROGRESSION_H
#define ARIT_PROGRESSION_H

#include "progression.h"

class AritProgression : public Progression { // arithmetic progression
    public:
        AritProgression(double i = 1) : Progression(), incr(i) {} // constructor

    protected:
        double incr; // the value which is added
        virtual double getNext(); // overriding the getNext from class Progression
};

#endif