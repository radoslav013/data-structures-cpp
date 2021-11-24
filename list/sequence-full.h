#include <stdexcept>

using namespace std;

class SequenceFull : public runtime_error
{
    public:
        SequenceFull(const string &msg) :
            runtime_error(msg)
    {
    }
};