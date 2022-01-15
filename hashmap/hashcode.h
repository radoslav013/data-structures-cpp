#ifndef HASHCODE_H
#define HASHCODE_H

class HashCode {
    public:
        bool operator()(int k) const {
            return k;
        }
};

#endif