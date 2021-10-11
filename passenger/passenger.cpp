#include <iostream>
#include <string>

using namespace std;

#include "passenger.h"

Passenger::Passenger() : meal(VEG), is_freq(false){}

Passenger::Passenger(string name, MealType meal, bool is_freq) {
    this->name = name;
    this->meal = meal;
    this->is_freq = is_freq;
}

Passenger::Passenger(const Passenger &pass) {
    this->name = pass.name;
    this->meal = pass.meal;
    this->is_freq = pass.is_freq;
}

Passenger::~Passenger(){}

void Passenger::print() const {
    cout << "Name: " << name << endl;
}

