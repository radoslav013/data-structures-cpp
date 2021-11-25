#ifndef STACK_FULL_EXC_H
#define STACK_FULL_EXC_H

#include <stdexcept>

using namespace std;

class StackFull : public runtime_error {
    public:
        StackFull(const string &msg) :
            runtime_error(msg)
    {
    }
};

#endif