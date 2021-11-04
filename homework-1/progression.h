#ifndef PROGRESSION_H
#define PROGRESSION_H

class Progression { // non-specific progression
    public:
        Progression(double f = 0) : frst(f), curr(f) {} // constructor
        virtual ~Progression() {} // destructor
        void print(int n = 10); // print the first n elements of the sequence

    protected:
        virtual double getFirst(); // can be overriden by derived classes
        virtual double getNext() = 0; // can be overriden by derived classes
        double frst;
        double curr;
};

#endif