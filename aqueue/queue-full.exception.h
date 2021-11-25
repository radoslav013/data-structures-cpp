#ifndef STACK_FULL_EXC_H
#define STACK_FULL_EXC_H

#include <stdexcept>

using namespace std;

class QueueFull : public runtime_error {
    public:
        QueueFull(const string &msg) :
            runtime_error(msg)
    {
    }
};

#endif