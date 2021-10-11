#ifndef FIB_PROGRESSION_H
#define FIB_PROGRESSION_H

#include "progression.h"

class FibProgression : public Progression {
    public:
        FibProgression() : Progression(0), next(1) {}

    protected:
        long next;
        virtual long getNext();
};

#endif