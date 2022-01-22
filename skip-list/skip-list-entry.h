#ifndef SKIP_LIST_ENTRY_H
#define SKIP_LIST_ENTRY_H

#include <vector>

using namespace std;

//! Specific Skip List Entry
/*!
    Class derived from Base Entry storing pointers to next towers
*/
template <typename E>
class SLEntry : public E {
    private:
        //! Pointers to next tower
        /*!
            Vector of pointers to next tower levels
         */
        vector<SLEntry*> next; // vector with pointers to next node vertically
    protected: // local types
        typedef typename E::Key K; // key type
        typedef typename E::Value V; // value type
    public: // public functions
        //! Constructor
        /*!
            Constructor setting the default size of next
            \param l      level
         */
        SLEntry(int l) : next(l) {}

        //! Additional Constructor
        /*!
            Additional Constructor
            \param k      key value
            \param v      data value
            \param k      level
         */
        SLEntry(const K& k, const V& v, int l) : E(k, v), next(l+1) {}

    friend class SkipList<E>;
};

#endif