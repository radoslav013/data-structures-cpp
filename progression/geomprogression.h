#ifndef GEOM_PROGRESSION_H
#define GEOM_PROGRESSION_H

#include "progression.h"

class GeomProgression : public Progression {
    public:
        GeomProgression(long i = 1) : Progression(1), incr(i) {}

    protected:
        long incr;
        virtual long getNext();
};

#endif