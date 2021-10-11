#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class Passenger {
    public:
        enum MealType {VEG, PES, MEAT};

        Passenger();
        Passenger(string name, MealType meal, bool is_freq);
        Passenger(const Passenger &pass);
        ~Passenger();
        void print() const;
    private:
        string name;
        MealType meal;
        bool is_freq;
};

#endif
