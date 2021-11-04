#ifndef PROGRESSION_H
#define PROGRESSION_H

class Progression { // non-specific progression
    public:
        Progression(double f = 0) : frst(f), curr(f) {} // constructor
        virtual ~Progression() {} // destructor just in case, since this is an abstract class
        void print(int n = 10); // print the first n elements of the sequence
        virtual double getNth(int n) = 0; // can be overriden by derived classes and n >= 1

    protected:
        double getFirst(); // can be overriden by derived classes
        virtual double getNext() = 0; // can be overriden by derived classes
        double frst;
        double curr;
};

#endif