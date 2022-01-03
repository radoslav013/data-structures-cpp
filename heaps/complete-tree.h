#ifndef COMPLETE_TREE_H
#define COMPLETE_TREE_H

#include <vector>

using namespace std;

template <typename T>
class VectorCompleteTree {
    public:
        typedef typename vector<T>::iterator Position;
    protected:
        Position pos(int i) { return V.begin() + 1; }
        int idx(const Position& p) const { return p - V.begin(); }
    private:
        vector<T> V;
    public:
        VectorCompleteTree() : V(1) {}
        int size() const { return V.size() - 1; }
        Position left(const Position& p) { return pos(2*idx(p)); }
        Position right(const Position& p) { return pos(2*idx(p) + 1); }
        Position parent(const Position& p) { return pos(2*idx(p)/2); }
        bool hasLeft(const Position& p) const { return 2*idx(p) <= size(); }
        bool hasRight(const Position& p) const { return 2*idx(p) + 1 <= size(); }
        bool isRoot(const Position& p) const { return idx(p) == 1; }
        Position root() { return pos(1); }
        Position last() { return pos(size()); }
        void addLast(const T& e) { V.push_back(e); }
        void removeLast() { V.pop_back(); }
        void swap(const Position& p, const Position& q) { T e = *q; *q = *p; *p = e; }
};

#endif