#ifndef ARIT_PROGRESSION_H
#define ARIT_PROGRESSION_H

#include "progression.h"

class AritProgression : public Progression { // arithmetic progression
    public:
        AritProgression(double d = 1) : Progression(), d(d) {} // constructor
        void print(int n = 10); // dummy
        virtual double getNth(int n); // overriding the getNth from class Progression

    protected:
        double d; // the value which is added
        virtual double getNext(); // overriding the getNext from class Progression
};

#endif