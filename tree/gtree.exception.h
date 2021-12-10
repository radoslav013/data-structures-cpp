#ifndef GTREE_EXCEPTION_H
#define GTREE_EXCEPTION_H

#include <stdexcept>
#include <string>

using namespace std;

class TreeExcept : public runtime_error {
    public:
        TreeExcept(const string& msg) : runtime_error(msg) {}
};

#endif