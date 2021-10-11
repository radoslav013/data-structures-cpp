#ifndef PROGRESSION_H
#define PROGRESSION_H

class Progression {
    public:
        Progression(long f = 0) : frst(f), curr(f) {}
        virtual ~Progression() {}
        void print(int n);

    protected:
        virtual long getFirst();
        virtual long getNext();
        long frst;
        long curr;
};

#endif