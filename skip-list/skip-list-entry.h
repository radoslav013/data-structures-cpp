#ifndef SKIP_LIST_ENTRY_H
#define SKIP_LIST_ENTRY_H

#include <vector>

using namespace std;

template <typename E>
class SLEntry : public E {
    private:
        vector<SLEntry*> next; // vector with pointers to next node vertically
    protected: // local types
        typedef typename E::Key K; // key type
        typedef typename E::Value V; // value type
    public: // public functions
        SLEntry(int l) : next(l) {}
        SLEntry(const K& k, const V& v, int l) : E(k, v), next(l+1) {}

    friend class SkipList<E>;
};

#endif