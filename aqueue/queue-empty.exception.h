#ifndef STACK_EMPTY_EXC_H
#define STACK_EMPTY_EXC_H

#include <stdexcept>

using namespace std;

class QueueEmpty : public runtime_error {
    public:
        QueueEmpty(const string &msg) :
            runtime_error(msg)
    {
    }
};

#endif