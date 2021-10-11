#ifndef ARITH_PROGRESSION_H
#define ARITH_PROGRESSION_H

#include "progression.h"

class ArithProgression : public Progression {
    public:
        ArithProgression(long i = 1) : Progression(), incr(i) {}

    protected:
        long incr;
        virtual long getNext();
};

#endif