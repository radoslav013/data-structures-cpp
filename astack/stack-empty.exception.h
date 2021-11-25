#ifndef STACK_EMPTY_EXC_H
#define STACK_EMPTY_EXC_H

#include <stdexcept>

using namespace std;

class StackEmpty : public runtime_error {
    public:
        StackEmpty(const string &msg) :
            runtime_error(msg)
    {
    }
};

#endif