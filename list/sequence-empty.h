#include <stdexcept>

using namespace std;

class SequenceEmpty : public runtime_error
{
    public:
        SequenceEmpty(const string &msg) :
            runtime_error(msg)
    {
    }
};